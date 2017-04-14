#ifndef Cards_h
#define Cards_h

enum suit_t {OROS, BASTOS, ESPADAS, COPAS};
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};

class Card {
public:
    Card();
    
    //Accessors
    std::string get_spanish_suit() const;
    std::string get_spanish_rank() const;
    std::string get_english_suit() const;
    std::string get_english_rank() const;
    
    //Sorting
    int get_rank() const;
    bool operator< (Card card2) const;
    
    //Siete Y Medio Value
    double get_value() const;
    
private:
    suit_t suit;
    rank_t rank;
    int value;
    
};


class Hand {
public:
    Hand();
    
private:
    
};



#endif /* Cards_h */
