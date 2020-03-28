/*
  Bill Wiegert
  CMPT 276
  Lab #4
  03-27-2020

  Class definition for hand_type class which represents a hand of playing cards
*/

#ifndef __HAND_H__
#define __HAND_H__

#include <string>
#include "card.h"

using namespace std;

class hand_type {
public:

  //////////////////////////////////////////////////
  // Constructor & destructor
  hand_type();
  // PRECONDITIONS: None
  // POSTCONDITIONS: Creates an empty hand with head_ptr = NULL

  ~hand_type();
  // PRECONDITIONS: None
  // POSTCONDITIONS: Deallocates all card_nodes used by hand

  //////////////////////////////////////////////////
  // Getters
  size_t size() const;
  // PRECONDITIONS: None
  // POSTCONDITIONS: Returns the number of cards in the hand

  bool has_card(card_type target) const;
  // PRECONDITIONS: None
  // POSTCONDITIONS: Returns true if target is within hand, false otherwise

  bool is_empty() const;
  // PRECONDITIONS: None
  // POSTCONDITIONS: Returns true if hand is empty, false otherwise

  string to_string() const;
  // PRECONDITIONS: None
  // POSTCONDITIONS: Returns a string representation of the hand

  //////////////////////////////////////////////////
  // Modifiers
  void add_card(const card_type &newcard);
  // PRECONDITIONS: None
  // POSTCONDITIONS: Adds the card to hand,
  // hand remains in order from lowest to highest value card

  void remove_card(const card_type &target);
  // PRECONDITIONS: None
  // POSTCONDITIONS: Removes one copy of target from hand, if present

  void discard_hand();
  // PRECONDITIONS: None
  // POSTCONDITIONS: Removes and deallocates all cards, hand is now empty


private:

  //////////////////////////////////////////////////
  // Node struct for storing a card in the linked list.
  // (Normally this would be a class since it has functions (constructors),
  // but since those are just used to initialize the members we might as well
  // keep it a struct.)
  struct card_node {
    card_type card;
    card_node *link_ptr;
    card_node();
    card_node(const card_type &newcard, card_node *next_ptr = NULL);
  };

  card_node *head_ptr; // First card in the hand.
  size_t hand_size; // Number of cards in the hand.

};



#endif  // defined __HAND_H__
