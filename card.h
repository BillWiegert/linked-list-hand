/*
  card.h: Provides the card_type class, which describes a single playing card.
  
  -RPM, The King's University, Winter 2018

  The "numerical value" of the rank represents an index into the
  array of card ranks.  The index is 0-12, and the actual ranks
  are 2-10, J, Q, K, A.
  
  The "numerical value" of the suit represents an index into the
  array of card suits.  The index is 0-3, and the actual ranks
  are C, S, D, H (clubs, spades, diamonds, hearts).
  
  
  MEMBER DATA TYPES (all public):
  rank_type: Data type for numerical rank of the card (the "rank index").
  suit_type: Data type for numerical suit of the card (the "suit index").

  
  STATIC MEMBER VARIABLES
  
  RANK_LIST: Array of card rank labels, stored as strings.
  SUIT_LIST: Array of card suit labels, stored as (single-character) strings.
  
  NUMRANKS: Number of possible card ranks (13 in a standard deck).
  NUMSUITS: Number of possible card suits (4 in a standard deck).
  
  
  STATIC MEMBER FUNCTIONS
  
  static rank_type rank_str2idx(string rank):
  PRECONDITIONS: Input is a valid "rank" string ("2", "10", "K", etc).
  POSTCONDITIONS: Returns the corresponding numerical rank index (0-12).
  
  static suit_type suit_str2idx(string suit):
  PRECONDITIONS: Input is a valid "suit" string ("C", "S", "D", or "H").
  POSTCONDITIONS: Returns the corresponding numerical suit index (0-3).
    
  
  CONSTRUCTORS:
  
  card_type(rank_type r=0, suit_type s=0):  
  PRECONDITIONS:  Inputs are valid card parameters:
    - r is a numerical rank value (0-12, ace high)
    - s is a numerical suit value (0-3: C, S, D, H)
  POSTCONDITIONS: Constructor with optional parameters; also functions as default ctor (needed for initializing arrays etc).
    Default represents 2 of Clubs.
    
  card_type(string r_str, string s_str) and
  card_type(char r_str[], char s_str[]):
  PRECONDITIONS: r_str and s_str are valid rank and suit labels (e.g. "10" and "D").
  POSTCONDITIONS: Constructs a card with the given rank and suit.

    
  GETTERS:
  
  rank_type get_rank() const
    POSTCONDITION: Returns the card's numerical rank index (0-12, ace high).
  
  suit_type get_suit() const
    POSTCONDITION: Returns the card's numerical suit index (0-3).
  
  string get_rank_str() const
    POSTCONDITION: Returns the card's rank as 2-10, J, Q, K, A.
  
  string get_suit_str() const
    POSTCONDITION: Returns the cards suit as C, S, D, H

  string to_string() const
    POSTCONDITION: Returns a single string representing this card (e.g. "4H" for "four of clubs", "AS" for "ace of spades", etc.).


  COMPARISON OPERATORS (non-member):
  operator==: Returns true if the two cards have the same rank and suit.
  operator<: Returns true if the left card has lower "value", meaning:
  - lower suit, regardless of rank, or
  - lower rank, if the suits are the same.
  Other operators are defined as you'd expect (using these two!).

*/

#ifndef __CARD_H__
#define __CARD_H__

#include<string> // for string class

using namespace std;


/**********************************************************/
/***                  CLASS DEFINITION                  ***/
/**********************************************************/

class card_type {
public:
  
  /***********************************/
  /***  Defined types  ***/

  typedef unsigned short rank_type;
  typedef unsigned short suit_type;


  /***************************************/
  /***  Static public member variables ***/

  // These are defined in the .cpp file.
  // (It turns out that is how you have to initialize static const's that
  // are objects (or arrays).)
  static const rank_type NUMRANKS = 13;
  static const suit_type NUMSUITS = 4;
  static const string RANK_LIST[NUMRANKS];
  static const string SUIT_LIST[NUMSUITS];
  

  /***************************************/
  /***  Static public member functions ***/
  // These are functions that you can call directly from the class,
  // without an object!

  static rank_type rank_str2idx(string rank);
  static suit_type suit_str2idx(string suit);


  /***********************************/
  /***  Constructors  ***/
  
  card_type(rank_type r=0, suit_type s=0);
  card_type(string r_str, string s_str);
  card_type(const char r_str[], const char s_str[]);


  /***********************************/
  /***  Getters  ***/

  string rank() const { return RANK_LIST[rank_idx]; }
  string suit() const { return SUIT_LIST[suit_idx]; }
  rank_type rank_value() const { return rank_idx; }
  suit_type suit_value() const { return suit_idx; }
  string to_string() const;

private:

  rank_type rank_idx; // Numerical card rank index (0-12)
  suit_type suit_idx; // Numerical card suit index (0-3)
  
  void set_rank(rank_type r);
  void set_suit(suit_type c);

}; // class card_type

//////////////////////////////////////////////////
// NON-MEMBER FUNCTIONS

// Comparison operators:
bool operator==(const card_type &card_l, const card_type &card_r);
bool operator<(const card_type &card_l, const card_type &card_r);
bool operator>(const card_type &card_l, const card_type &card_r);
bool operator<=(const card_type &card_l, const card_type &card_r);
bool operator>=(const card_type &card_l, const card_type &card_r);

#endif // defined __CARD_H__
