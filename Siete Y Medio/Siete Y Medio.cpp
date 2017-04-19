#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Cards.h"


int main()
{
    std::ofstream gamelog;
    gamelog.open("gamelog.txt");
    
    srand((int)time(0)); //ensures that the random number generated isn't the same
    int player_money = 100; //initializes player with $100
    int dealer_money = 900; //initializes dealer with $900
    bool game_done = false;


    while (player_money != 0 && dealer_money != 0) {
        while (!game_done) {
            
            //Player bets
            std::cout << "You have " << player_money << ".";
            std::cout << " Enter bet: ";
            int bet;
            std::cin >> bet;
            
            //If player bets more money than they have
            while (bet > player_money) {
                std::cout << "You don't have $" << bet << ". Please enter valid amount: ";
                std::cin >> bet;
            }
            
            //Player's first card
            Hand player_hand; //initializes player hand
            Card player_card; player_hand.add_card(player_card); //adds first card to hand
            
            std::cout << "Your cards:\n";
            player_hand.print_hand();
            std::cout << "Your total is " << player_hand.hand_val() << ". ";
            std::cout << "Do you want another card (y/n)? ";
            char answer;
            std::cin >> answer;
            
            
            //Player wants more cards
            while (answer == 'y') {
                Card new_card;
                player_hand.add_card(new_card);
                
                std::cout << "New card:\n";
                new_card.print_card();
                std::cout << "Your cards:\n";
                player_hand.print_hand();
                std::cout << "Your total is " << player_hand.hand_val() << ". ";
                
                if (!player_hand.bust()) {
                    std::cout << "Do you want another card (y/n)? ";
                    std::cin >> answer;
                    std::cout << std::endl << std::endl;
                }
                
                else {
                    std::cout << std::endl << std::endl;
                    answer = 'n';
                }
            }
            
            
            //Dealer's first card
            Hand dealer_hand;
            Card dealer_card; dealer_hand.add_card(dealer_card);
            
            std::cout << "Dealer's cards:\n";
            dealer_hand.print_hand();
            std::cout << "The dealer's total is " << dealer_hand.hand_val();
            std::cout << std::endl << std::endl;
            
            
            //Dealer adds cards until hand value > 5.5
            while (dealer_hand.hand_val() < 5.5) {
                
                    Card new_card;
                    dealer_hand.add_card(new_card);
                    
                    std::cout << "New card:\n";
                    new_card.print_card(); 
                    std::cout << "Dealer's cards:\n";
                    dealer_hand.print_hand();
                    std::cout << "The dealer's total is ";
                    std::cout << dealer_hand.hand_val() << ".\n\n";
                
            }
            
            
            //Determine winner
            if (player_hand.bust()) {
                player_money -= bet;
                dealer_money += bet;
                std::cout << "Too bad. You lose " << bet << ".\n\n";
            }
            
            else if (!player_hand.bust()) {
                if (dealer_hand.bust()) {
                    player_money += bet;
                    dealer_money -= bet;
                    std::cout << "You win " << bet << ".\n\n";
                }
                
                else if (player_hand.hand_val() > dealer_hand.hand_val()) {
                    player_money += bet;
                    dealer_money -= bet;
                    std::cout << "You win " << bet << ".\n\n";
                }
                
                else if (player_hand.hand_val() < dealer_hand.hand_val()) {
                    player_money -= bet;
                    dealer_money += bet;
                    std::cout << "Too bad. You lose " << bet << ".\n\n";
                }
                
                else if (player_hand.hand_val() == dealer_hand.hand_val()) {
                    std::cout << "It's a tie.\n\n";
                }
            }
            
            if (player_money == 0 || dealer_money == 0) {
                game_done = true;
            }
        }
    }
    
    
    //Player or dealer runs out of money
    if (player_money == 0) {
        std::cout << "You have $0. GAME OVER!\n";
        std::cout << "Come back when you have more moeny.\n\n";
        std::cout << "Bye!\n";
    }
    
    else if (dealer_money == 0) {
        std::cout << "Congratulations, you win!\n";
    }
    
    gamelog.close();
    return 0;

}
