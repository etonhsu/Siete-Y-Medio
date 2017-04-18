#include <iostream>
#include <string>
#include <vector>
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
    
    while (player_money > 0 && dealer_money > 0)
    {
        std::cout << "You have $" << player_money << ". Enter bet: ";
        int bet;
        std::cin >> bet;
        while (bet > player_money) { //case where player bets more money than they have
            std::cout << "You don't have that much money. Please enter valid amount: ";
            std::cin >> bet;
        }
        
        
        //Player's turn to play
        Hand player_hand; //initializes a hand for the player
        Card cardA; player_hand.add_card(cardA); //adds first card to player hand
        
        std::cout << "Your cards: \n";
        player_hand.print_hand(); //prints the one card in the player's hand
        
        std::cout << "Your total is " << player_hand.hand_val() << ". ";
        std::cout << "Do you want another card (y/n)? ";
        
        char answer;
        std::cin >> answer;
        
        while (answer == 'y' && player_hand.hand_val() <= 7.5) {
            Card new_card; player_hand.add_card(new_card);
            std::cout << "New card:\n"; new_card.print_card(); std::cout << std::endl;
            
            
            std::cout << "Your cards: \n";
            player_hand.print_hand();
            
            std::cout << "Your total is " << player_hand.hand_val() << ". ";
            
            if (!player_hand.bust()) { //if player hand value < 7.5
                std::cout << "Do you want another card (y/n)? ";
                std::cin >> answer;
            }
            
            else if (player_hand.bust()) {answer = 'n';}
        }
        
        
        //Dealer's turn to play
        Hand dealer_hand;
        Card cardB; player_hand.add_card(cardB);
        while (dealer_hand.hand_val() < 5.5) {
            Card new_card;
            dealer_hand.add_card(new_card);
        }
        
        std::cout << "\nDealer's cards: \n";
        dealer_hand.print_hand(); //prints the one card in the player's hand
        
        std::cout << "Dealer's total is " << dealer_hand.hand_val() << ".\n\n";
    
        
        //Testing comparisons
        if (player_hand.bust()) {
            std::cout << "player has busted!" << std::endl;
        }
        
        if (dealer_hand.bust()) {
            std::cout << "dealer has busted!" << std::endl;
        }
        
        if (player_hand.hand_val() > dealer_hand.hand_val()) {
            std::cout << "player has won!" << std::endl;
        }
        
        if (player_hand.hand_val() < dealer_hand.hand_val()) {
            std::cout << "dealer has won!" << std::endl;
        }
        
    }
    
    
    
    
    
    
    
    
    gamelog.close();
    return 0;

}
