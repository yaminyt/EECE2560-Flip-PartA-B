// ===== src/main.cpp =====
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"

int main()
{
   srand((unsigned)time(0));

   deck d;

   std::cout << "Deck before shuffle:" << std::endl;
   std::cout << d << std::endl;

   d.shuffle();
   d.shuffle();
   d.shuffle();

   std::cout << "Deck after shuffle:" << std::endl;
   std::cout << d << std::endl;

   // deal 24 cards into a new deck
   deck table;

   for (int i = 0; i < 24; i++)
   {
      d_node *c = d.deal();
      table.replace(c);
   }

   std::cout << "Cards dealt to table:" << std::endl;
   std::cout << table << std::endl;

   std::cout << "Remaining deck:" << std::endl;
   std::cout << d << std::endl;

   return 0;
}
