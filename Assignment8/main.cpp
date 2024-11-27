/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 8
    Description: main.cpp file implementing the War card game 
            using linked lists.
    Input: file containing pairs of cards (one for each player).
    Output: Prints the cards each player plays, 
            announces the winner of each round,
            and declares the final winner when the game ends.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "emptyList.h"
#include "LL.h"

using namespace std;

// Class representing a card, with face (rank) and suit
class cardType
{
public:
    // Constructor initializing card face and suit to null characters
    cardType() : face('\0'), suit('\0') {}

    // Constructor to initialize the card with a specific face and suit
    cardType(char f, char s) : face(f), suit(s) {}

    // Compare two cards based on their face value
    bool operator==(const cardType& rhs) const
    {
        return this->face == rhs.face;
    }

    // Compare two cards based on their face value
    bool operator<(const cardType& rhs) const
    {
        return getValueFromFace(this->face) < getValueFromFace(rhs.face);
    }

    // Getter for card face
    char getFace() const { return face; }

    // Getter for card suit
    char getSuit() const { return suit; }

private:
    // Convert face character to numerical value for comparison
    int getValueFromFace(char f) const
    {
        if (f >= '2' && f <= '9')
            return f - '0';  // Numbers 2-9

        if (f == 'T') return 10;
        if (f == 'J') return 11;
        if (f == 'Q') return 12;
        if (f == 'K') return 13;
        if (f == 'A') return 14;

        return 0;
    }

    char face;  // Face (rank) of the card
    char suit;  // Suit of the card
};

// Template function to check if a linked list is empty
template<class type>
bool isEmpty(const LL<type>& list);

int main()
{
   // Linked lists to store players' cards and the war deck
   LL<cardType> player1, player2, warDeck;  
   // Strings to store card inputs for each player
   string strCard1, strCard2;  

   // Reading cards from standard input
   while (cin >> strCard1 >> strCard2)
   {
      cardType card1(strCard1[0], strCard1[1]);
      cardType card2(strCard2[0], strCard2[1]);
      player1.push_back(card1);  // Push card to player 1's deck
      player2.push_back(card2);  // Push card to player 2's deck
   }

   // Play the war game until one player's deck is empty
   while (true)
   {
      try
      {
         // Pop cards from the front of both players' decks
         cardType c1 = player1.pop_front();
         cardType c2 = player2.pop_front();

         // Display the cards being played by both players
         cout << "Player 1 card: " << c1.getFace() 
            << c1.getSuit() << '\n';
         cout << "Player 2 card: " << c2.getFace()    
            << c2.getSuit() << '\n';

         // If both players have the same card, trigger a "War!"
         if (c1 == c2)
         {
               cout << "War!\n";

               // Push the cards involved in the war to the war deck
               warDeck.push_back(c1);
               warDeck.push_back(c2);

               // Each player draws 3 more cards for the war
               for (int i = 0; i < 3; ++i)
               {
                  if (!isEmpty(player1))
                     warDeck.push_back(player1.pop_front());
                  if (!isEmpty(player2))
                     warDeck.push_back(player2.pop_front());
               }
         }
         else if (c1 < c2) // Player 2 wins the round
         {
               player2.push_back(c1);
               player2.push_back(c2);

               // Move all war cards to Player 2's deck
               while (!isEmpty(warDeck))
               {
                  player2.push_back(warDeck.pop_front());
               }

               cout << "Player 2 wins\n";
         }
         else // Player 1 wins the round
         {
               player1.push_back(c1);
               player1.push_back(c2);

               // Move all war cards to Player 1's deck
               while (!isEmpty(warDeck))
               {
                  player1.push_back(warDeck.pop_front());
               }

               cout << "Player 1 wins\n";
         }
      }
      // Handle the case when one player runs out of cards
      catch (const exception& e) 
      {
         cout << "Game Over\n";

         // Determine which player won
         if (isEmpty(player1))
               cout << "Player 2 wins the game!\n";
         else if (isEmpty(player2))
               cout << "Player 1 wins the game!\n";

         break;  // Exit the game loop
      }
   }

   return 0;
}

// Helper function to check if a linked list is empty (using peek and 
// exception handling)
template <typename T>
bool isEmpty(const LL<T>& list)
{
   try
   {
      list.peek();  // Peek throws an exception if the list is empty
      return false; // List is not empty
   }
   catch (...)
   {
      return true;  // List is empty
   }
}
