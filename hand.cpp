/*
  Bill Wiegert
  CMPT 276
  Lab #4
  03-27-2020

  CLASS INVARIANTS:
  - Cards are stored in card_node objects in a linked list.
  - head_ptr points to the first node in the list, or NULL if the list is empty.
  - Each node in the list contains a pointer to the next node, or NULL if it's the last node in the list.
  - Cards are stored in increasing order, with the "lowest" card at the head.
*/

#include <iostream> // for debugging
#include <string>

#include "hand.h"
#include "card.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
// HAND_TYPE MEMBERS

//////////////////////////////////////////////////
// Constructor
hand_type::hand_type() {
  head_ptr = NULL;
  hand_size = 0;
}



//////////////////////////////////////////////////
// Destructor
hand_type::~hand_type() {
  discard_hand();
}



//////////////////////////////////////////////////
// Getters
size_t hand_type::size() const {
  return hand_size;
}

bool hand_type::has_card(card_type target) const {
  card_node *current_node = head_ptr; // Start at head_ptr

  // Iterate through every card in the hand
  while (current_node != NULL) {
    if (current_node->card == target) {
      return true; // Match found
    }

    // Advance pointer
    current_node = current_node->link_ptr;
  }

  return false; // Reached end of hand, no match found
}

bool hand_type::is_empty() const {
  return head_ptr == NULL;
}

string hand_type::to_string() const {
  string result = "";
  card_node *current_node = head_ptr;

  // Iterate through every card in the hand
  while (current_node != NULL) {
    result += current_node->card.to_string() + " ";
    current_node = current_node->link_ptr;
  }

  return result;
}



//////////////////////////////////////////////////
// Modifiers
void hand_type::add_card(const card_type &newcard) {
  card_node *current_node = head_ptr;
  card_node *prev_node = NULL;

  card_node *new_card_node = new card_node;
  new_card_node->card = newcard;

  hand_size++; // Increment hand_size, we're adding a card

  // If hand is empty simply set head_ptr to new card
  if (head_ptr == NULL) {
    head_ptr = new_card_node;
    return;
  }

  // Iterate until end of hand
  while (current_node != NULL) {
    // Find a card with a greater value than newcard
    if (newcard < current_node->card) {
      // If current node is the first node reassign head_ptr instead of dealing with prev_node
      current_node == head_ptr ?
      head_ptr = new_card_node : prev_node->link_ptr = new_card_node;
      new_card_node->link_ptr = current_node; // Either way link new_card_node to current_node
      return; // Our work here is done
    }

    // Advance pointers
    prev_node = current_node;
    current_node = current_node->link_ptr;
  }

  // If newcard has a greater value than all cards in hand, add it at the end
  prev_node->link_ptr = new_card_node;
}

void hand_type::remove_card(const card_type &target) {
  card_node *current_node = head_ptr;
  card_node *prev_node = NULL;

  while (current_node != NULL) {
    // If target found
    if (current_node->card == target) {
      // If target was first in hand reassign head_ptr instead of prev_node
      current_node == head_ptr ?
      head_ptr = current_node->link_ptr : prev_node->link_ptr = current_node->link_ptr;
      delete current_node; // Delete the target card
      --hand_size; // Decrease hand_size
      return; // Our work here is done
    }

    // Advance pointers
    prev_node = current_node;
    current_node = current_node->link_ptr;
  }
}

void hand_type::discard_hand() {
  card_node *current_node;

  // Iterate until hand is empty
  while (head_ptr != NULL) {
    current_node = head_ptr; // Save pointer to first card
    head_ptr = head_ptr->link_ptr; // Move head_ptr forward
    delete current_node; // Delete card
  }

  hand_size = 0;
}



//////////////////////////////////////////////////
// Private member functions (if any)




//////////////////////////////////////////////////////////////////////////
// CARD_NODE CONSTRUCTORS

hand_type::card_node::card_node() {
  link_ptr = NULL;
}

hand_type::card_node::card_node(const card_type &newcard, card_node *next_ptr) {
  card = newcard;
  link_ptr = next_ptr;
}
