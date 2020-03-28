/*
  checktest: Utilities for displaying the results of a test suite.
  -Robert MacDonald, The King's University (Winter 2018)
*/

#include <iostream> // for cout
#include <iomanip>  // for setw
#include <sstream> // for stringstream

using namespace std;

bool checktest(string comment, string expect, string result, bool checkresult) {
  // If checkresult is true, compares the expect and result strings.
  // Otherwise just displays everything with proper alignment.

  // Output column widths:
  static const int MATCHCOL = 6;
  static const int COMMENTCOL = 26;
  static const int EXPECTCOL = 28;

  // Trim leading/trailing whitespace from result,
  // so it doesn't mess up the match.
  size_t first, last, len;
  first = result.find_first_not_of(' ');
  if (first == std::string::npos) {
    // no spaces
    first = 0;
    last = result.length()-1;
  } else {
    last  = result.find_last_not_of(' ');
  }
  len = last - first + 1;
  result = result.substr(first, len);

  bool match = (expect == result);

  cout << left;

  cout << setw(MATCHCOL);
  if (checkresult) {
    if (match) {
      cout << "match";
    } else {
      cout << "=DIFF=";
    }
  } else {
    cout << " "; // for alignment
  }
  cout << " | ";
  cout << setw(COMMENTCOL) << comment << " | ";
  cout << setw(EXPECTCOL) << expect << " | ";
  cout << result << endl;

  return match;
} // bool checktest


bool checktest(const char comment[], const char expect[], string result, bool checkresult) {
  return checktest(string(comment), string(expect), result, checkresult);
}
bool checktest(string comment, string expect, stringstream &result, bool checkresult) {
  string s = result.str();
  result.str(string(""));
  return checktest(comment, expect, s, checkresult);
}
bool checktest(const char comment[], const char expect[], stringstream &result, bool checkresult) {
  string s = result.str();
  result.str(string(""));
  return checktest(comment, expect, s, checkresult);
}



string bool2str(bool b) {
  if (b)
    return string("true");
  else
    return string("false");
}
