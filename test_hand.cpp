/*
  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.

*/

#include <iostream>
#include <sstream> // for stringstream, for capturing output.

#include "hand.h"
#include "card.h"
#include "checktest.h"

using namespace std;

int main() {

  // Create some cards to work with.
  card_type heartsA("A", "H"); // Highest possible card.
  card_type heartsQ("Q", "H");
  card_type hearts2("2", "H");
  card_type diamondsA("A", "D");
  card_type diamonds10("10", "D");
  card_type diamonds4("4", "D");
  card_type spadesA("A", "S");
  card_type spadesQ("Q", "S");
  card_type spades2("2", "S");
  card_type clubsA("A", "C");
  card_type clubs9("9", "C");
  card_type clubs2("2", "C"); // Lowest possible card.

  // For capturing non-string output.
  stringstream result;
  hand_type hand;
  // checktest(string comment, string expect, string result, bool checkresult=true)

  checktest("TEST COMMENTS", "EXPECTED", "ACTUAL", false);

  hand.add_card(spades2);
  checktest("Add one card", "2S", hand.to_string());

  hand.add_card(clubs2);
  checktest("Add new, lowest card", "2C 2S", hand.to_string());

  hand.add_card(clubs9);
  hand.add_card(clubs9);
  checktest("Add duplicate cards", "2C 9C 9C 2S", hand.to_string());

  hand.remove_card(clubs9);
  checktest("Remove only one card", "2C 9C 2S", hand.to_string());

  hand.remove_card(clubs2);
  checktest("Remove first card", "9C 2S", hand.to_string());

  hand.remove_card(spadesQ);
  checktest("Remove card not present", "9C 2S", hand.to_string());

  hand.remove_card(spades2);
  checktest("Remove last card", "9C", hand.to_string());

  result << hand.size();
  checktest("Check hand size", "1", result);

  hand.add_card(heartsA);
  hand.add_card(diamonds4);
  hand.add_card(hearts2);
  checktest("Add multiple high cards", "9C 4D 2H AH", hand.to_string());

  result.str("");
  result << hand.size();
  checktest("Check hand size", "4", result);

  checktest("Check has_card (true)", "true", bool2str(hand.has_card(clubs9)));

  checktest("Check has_card (false)", "false", bool2str(hand.has_card(clubs2)));

  checktest("Check is_empty (false)", "false", bool2str(hand.is_empty()));

  hand.discard_hand();
  checktest("Discard hand", "", hand.to_string());

  checktest("Check is_empty (true)", "true", bool2str(hand.is_empty()));

  return 0;
}
