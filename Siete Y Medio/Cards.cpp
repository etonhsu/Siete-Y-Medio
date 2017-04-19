#include <iostream>
#include <cstdlib>
#include "Cards.h"


//Card Class Functions

Card::Card() {
    int x = 1 + rand() % 4; //determines card suit
    switch(x) {
        case 1: suit = OROS; break;
        case 2: suit = BASTOS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = COPAS; break;
        default: break;
    }
    
    int y = 1 + rand() % 10; //determines card rank
    switch(y) {
        case 1: rank = AS; break;
        case 2: rank = DOS; break;
        case 3: rank = TRES; break;
        case 4: rank = CUATRO; break;
        case 5: rank = CINCO; break;
        case 6: rank = SEIS; break;
        case 7: rank = SIETE; break;
        case 8: rank = SOTA; break;
        case 9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}


std::string Card::get_spanish_suit() const {
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}


std::string Card::get_spanish_rank() const {
    std::string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break; 
        case REY: 
            rankName = "Rey"; 
            break; 
        default: break;
    }
    return rankName;
}


std::string Card::get_english_suit() const {
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "coins";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "spades";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}


std::string Card::get_english_rank() const {
    std::string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}


void Card::print_card() const {
    std::cout << "\t" << get_spanish_rank() << " de " << get_spanish_suit();
    std::cout << "\t\t(" << get_english_rank();
    std::cout << " of " << get_english_suit() << ")\n";
}


int Card::get_rank() const {
    int card_rank;
    switch (rank) {
        case AS:
            card_rank = 1;
            break;
        case DOS:
            card_rank = 2;
            break;
        case TRES:
            card_rank = 3;
            break;
        case CUATRO:
            card_rank = 4;
            break;
        case CINCO:
            card_rank = 5;
            break;
        case SEIS:
            card_rank = 6;
            break;
        case SIETE:
            card_rank = 7;
            break;
        case SOTA:
            card_rank = 10;
            break;
        case CABALLO:
            card_rank = 11;
            break;
        case REY:
            card_rank = 12;
            break;
        default: break;
    }
    
    return card_rank;
}


bool Card::operator < (Card card2) const {
    return get_rank() < card2.get_rank();
}


double Card::get_value() const {
    double card_val;
    switch (rank) {
        case AS:
            card_val = 1;
            break;
        case DOS:
            card_val = 2;
            break;
        case TRES:
            card_val = 3;
            break;
        case CUATRO:
            card_val = 4;
            break;
        case CINCO:
            card_val = 5;
            break;
        case SEIS:
            card_val = 6;
            break;
        case SIETE:
            card_val = 7;
            break;
        case SOTA:
            card_val = 0.5;
            break;
        case CABALLO:
            card_val = 0.5;
            break;
        case REY:
            card_val = 0.5;
            break;
        default: break;
    }
    
    return card_val;
}



//Hand Class Functions

Hand::Hand() {}


double Hand::hand_val() const //calculates the value of each player's hand
{
    double total_value = 0.0;
    for (auto x : play_hand)
    {
        total_value += x.get_value();
    }
    
    return total_value;
}


void Hand::add_card(Card a)
{
    play_hand.insert(a);
}


void Hand::print_hand() const
{
    for (auto x : play_hand)
    {
        std::cout << "\t" << x.get_spanish_rank() << " de " << x.get_spanish_suit();
        std::cout << "\t\t(" << x.get_english_rank();
        std::cout << " of " << x.get_english_suit() << ")\n";
    }
}


bool Hand::bust() const
{
    if (hand_val() > 7.5) {
        return true;
    }
    
    else {
        return false;
    }
}
















