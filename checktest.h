/*
  checktest: Utilities for displaying the results of a test suite.
  -Robert MacDonald, The King's University (Winter 2018)
*/

#include <string>
#include <sstream> // for stringstream

using namespace std;

bool checktest(string comment, string expect, string result, bool checkresult=true);
// Display a test description, the expected result, the actual result,
// and MATCH/DIFFERENT, using cout.
// The test is checked by comparing the expect and result strings.

bool checktest(const char comment[], const char expect[], string result, bool checkresult=true);
// Wrapper for checktest function, that allows direct string literals for
// comment and expect.

// More wrappers, that allow one to pass a stringstream for the result.
// These wipe out the stream for you as well.
bool checktest(string comment, string expect, stringstream &result, bool checkresult=true);
bool checktest(const char comment[], const char expect[], stringstream &result, bool checkresult=true);

string bool2str(bool b);
// Returns "true" or "false" as appropriate.
