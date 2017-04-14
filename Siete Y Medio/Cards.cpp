#include <iostream>
#include <cstdlib>
#include "Cards.h"


Card::Card() {
    int x = 1 + rand() % 3;
    switch(x) {
        case 1: suit = OROS; break;
        case 2: suit = BASTOS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = COPAS; break;
        default: break;
    }
    
    int y = 1 + rand() % 9;
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
