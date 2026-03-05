// ===== src/deck.cpp =====
#include "deck.h"
#include <vector>
#include <cstdlib>

deck::deck()
{
   front = nullptr;

   d_node *tail = nullptr;

   // order: ace..king, club..diamond..heart..spade
   for (int s = 0; s < 4; s++)
   {
      for (int v = 1; v <= 13; v++)
      {
         d_node *p = new d_node(card(v, s));

         if (front == nullptr)
         {
            front = p;
            tail = p;
         }
         else
         {
            tail->next = p;
            tail = p;
         }
      }
   }
}

deck::~deck()
{
   clear();
}

void deck::clear()
{
   while (front != nullptr)
   {
      d_node *tmp = front;
      front = front->next;
      delete tmp;
   }
}

int deck::size() const
{
   int count = 0;
   d_node *p = front;

   while (p != nullptr)
   {
      count++;
      p = p->next;
   }

   return count;
}

void deck::shuffle()
{
   std::vector<card> v;
   v.reserve(size());

   d_node *p = front;
   while (p != nullptr)
   {
      v.push_back(p->data);
      p = p->next;
   }

   for (int i = (int)v.size() - 1; i > 0; i--)
   {
      int j = rand() % (i + 1);
      card tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
   }

   p = front;
   int i = 0;
   while (p != nullptr)
   {
      p->data = v[i];
      i++;
      p = p->next;
   }
}

std::ostream &operator<<(std::ostream &out, const deck &d)
{
   d_node *p = d.front;
   int count = 0;

   while (p != nullptr)
   {
      out << p->data << " ";
      count++;

      if (count % 13 == 0)
      {
         out << std::endl;
      }

      p = p->next;
   }

   return out;
}
