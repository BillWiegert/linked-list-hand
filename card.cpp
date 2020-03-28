/*
  card.cpp: Implements the card_type class, which describes a single playing card.
  
  See card.h for documentaiton.
  
  -RPM 16.02.24

*/

#include<cassert>
#include<iostream>
#include "card.h"

using namespace std;


/**********************************************************/
/***               CLASS MEMBER VARIABLES.              ***/
/**********************************************************/

/***************************************/
/***  Initialize static public member variables ***/

const string card_type::RANK_LIST[card_type::NUMRANKS] 
    = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

const string card_type::SUIT_LIST[card_type::NUMSUITS] = {"C", "S", "D", "H"};



/**********************************************************/
/***               CLASS MEMBER FUNCTIONS.              ***/
/**********************************************************/

/***************************************/
/***  Static public member functions ***/

card_type::rank_type card_type::rank_str2idx(string rank) {
  rank_type i = 0;
  for (i = 0; i < NUMRANKS; i++) {
    if (RANK_LIST[i] == rank) break;
  }
  return i; // If rank is not found, will return NUMRANKS.
}


card_type::suit_type card_type::suit_str2idx(string suit) {
  suit_type i = 0;
  for (i = 0; i < NUMSUITS; i++) {
    if (SUIT_LIST[i] == suit) {
      //cout << "Found suit " << suit << " at " << i << endl; // FIXME
      break;
    }
  }
  //if (i==NUMSUITS) cout << "Bork! suit " << suit << " i=" << i << endl; // FIXME
  return i; // If suit is not found, will return NUMSUITS.
}


/***********************************/
/***  Constructors  ***/

card_type::card_type(rank_type r, suit_type s) {
  // Constructor.
  set_rank(r);
  set_suit(s);
} // constructor

card_type::card_type(string r_str, string s_str) {
  set_rank(rank_str2idx(r_str));
  set_suit(suit_str2idx(s_str));
}


card_type::card_type(const char r_str[], const char s_str[]) {
  set_rank(rank_str2idx(string(r_str)));
  set_suit(suit_str2idx(string(s_str)));
}



/***********************************/
/***  Setters (private)  ***/

//////////
void card_type::set_rank(rank_type r) {
  // Assign the given (numerical) rank to this card.
  assert( (r >= 0) && (r < NUMRANKS) ); // Check for valid rank.
  rank_idx = r;
} // set_rank()


//////////
void card_type::set_suit(suit_type s) {
  // Assign the given suit to this card.
  assert( (s >= 0) && (s < NUMSUITS) ); // Check for valid suit.
  suit_idx = s;
} // set_suit()




/***********************************/
/***  Getters  ***/

//////////
string card_type::to_string() const {
  // Returns a string representation of the card.
  return rank() + suit();
} // card_type::to_string()



//////////////////////////////////////////////////
// NON-MEMBER FUNCTIONS

bool operator==(const card_type &card_l, const card_type &card_r) {
  return (card_l.rank() == card_r.rank()) && 
    (card_l.suit() == card_r.suit());
}

bool operator<(const card_type &card_l, const card_type &card_r) {
  if (card_l.suit_value() == card_r.suit_value()) {
    return card_l.rank_value() < card_r.rank_value();
  } else {
    return card_l.suit_value() < card_r.suit_value();
  }
}

bool operator>(const card_type &card_l, const card_type &card_r) {
  return !(card_l < card_r);
}

bool operator<=(const card_type &card_l, const card_type &card_r) {
  return (card_l < card_r) || (card_l == card_r);
}

bool operator>=(const card_type &card_l, const card_type &card_r) {
  return (card_l > card_r) || (card_l == card_r);
}

