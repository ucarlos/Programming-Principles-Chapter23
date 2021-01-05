/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/03/2021 at 06:10 PM
 * 
 * Regex_Example.cc
 * 
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main() {
	ifstream input {"Regex_File.txt"};
	if (!input) {
		cerr << "Error: Cannot open file.\n";
		exit(EXIT_FAILURE);
	}

	regex pattern {R"(\w{2}\s*\d{5}(-\d{4})?)"};
	int line_num = 0;
	for (string line; getline(input, line); ) {
		line_num++;
		smatch matches;
		if (regex_search(line, matches, pattern)) { 
			cout << line_num << ": " << matches[0] << "\n";
			cout << "Also, for your convenience: \n";
			for (int i = 1; i < matches.length(); i++)
				if (matches[i].matched)
					cout << "Match " << i << ": " << matches[i] << endl;
		}

		
	}
}
