// ===== src/card.cpp =====
#include "card.h"

card::card(const card& c)
{
    value = c.value;
    suit = c.suit;
}

card& card::operator=(const card& c)
{
    if(this != &c)
    {
        value = c.value;
        suit = c.suit;
    }
    return *this;
}

card::card(int v, int s)
{
   value = v;
   suit = s;
}

void card::setValue(int v)
{
   value = v;
}

void card::setSuit(int s)
{
   suit = s;
}

int card::getValue() const
{
   return value;
}

int card::getSuit() const
{
   return suit;
}

std::ostream &operator<<(std::ostream &out, const card &c)
{
   const char *vals[] =
   {
      "A","2","3","4","5","6","7","8","9","10","J","Q","K"
   };

   const char *suits[] =
   {
      "C","D","H","S"
   };

   out << vals[c.getValue() - 1] << suits[c.getSuit()];
   return out;
}

