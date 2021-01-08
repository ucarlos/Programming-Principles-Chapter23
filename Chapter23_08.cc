/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/08/2021 at 03:34 PM
 * 
 * Chapter23_08.cc
 * Modify the program from §23.8.7 so that it takes as inputs a pattern and
 * a file name. Its output should be the numbered lines ( line–number: line )
 * that contain a match of the pattern. If no matches are found, no output
 * should be produced.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

int main(void) {
	regex pattern;
	string pat;
	cout << "Enter a regex pattern: ";
	getline(cin, pat);

	// string pat = ".ne+";

	try {
		pattern = pat;
		cout << "Pattern: \"" << pat << "\"\n";
	}
	catch (regex_error) {
		cout << "\"" << pat << "\" is not a valid regular expression.\n";
		exit(EXIT_FAILURE);

	}

	string filename;
	cout << "Now enter the filename of the file you want to read.\n";
	getline(cin, filename);
	// filename = "../Example.txt";

	ifstream file {filename, ios_base::in};	
	if (!file) {
		cerr << "Error: \"" << filename << "\" cannot be opened."
			 << "The file does not exist or the filepath is incorrect.\n";
		exit(EXIT_FAILURE);

	}

	int line_num = 0;
	for (string line; getline(file, line); ) {
		line_num++;
		smatch matches;
		if ((regex_search(line, matches, pattern))) {
			for (const auto & match : matches) {
				if (match.matched)
					cout << "Line " << line_num << ": " << match << endl;
			}
		}			
	}
		
}
