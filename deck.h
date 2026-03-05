// ===== src/deck.h =====
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "d_node.h"

class deck
{
public:
    deck();
    ~deck();

    void shuffle();
    int size() const;

    d_node* deal();
    void replace(d_node* c);

    friend std::ostream& operator<<(std::ostream &out, const deck &d);

private:
    d_node *front;

    void clear();
};

#endif
