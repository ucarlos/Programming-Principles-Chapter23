/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/03/2021 at 09:33 PM
 *
 * Regex_Tester.cc
 *
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Accept a pattern and a set of lines from input.
// Check the pattern and search for lines with that pattern.
int main() {
	regex pattern;
	string pat;

	cout << "Enter a Regex Pattern: ";
	getline(cin, pat);
	cout << pat << endl;
	
	try {
		pattern = pat;
		cout << "Pattern: " << pat << "\n";
	}
	catch (regex_error) {
		cout << pat << " is not a valid regular expression.\n";
		exit(EXIT_FAILURE);

	}

	cout << "Now enter some lines: \n";
	int line_num = 0;

	for (string line; getline(cin, line); ) {
		line_num++;
		smatch matches;

		if (regex_search(line, matches, pattern)) {
			cout << "Line " << line_num << ": " << line << "\n";
			for (int i = 0; i < matches.size(); i++) {
				cout << "\tmatches[" << i << "]: "
					 << matches[i] << "\n";
			}
		}
		else
			cout << "No matches found.\n";
	}
}
