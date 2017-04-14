#include <iostream>
#include <cstdlib>
#include "Cards.h"


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















