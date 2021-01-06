/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 09:37 PM
 * 
 * Chapter23_06.cc
 * Write a program that finds dates in a text file. Write out each line contain-
 * ing at least one date in the format line–number: line . Start with a regular
 * expression for a simple format, e.g., 12/24/2000, and test the program
 * with that. Then, add more formats.
 * -----------------------------------------------------------------------------
 */


#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(void) {
	const string file_name = "./Chapter23_06_File.txt";
	ifstream file {file_name};
	if (!file) {
		cerr << "Error: Cannot open \"" << file_name << "\"."
			 << " The file may not exist or the filename is incorrect.\n";
		exit(EXIT_FAILURE);
	}


	// Handles formats of aa/bb/yyyy,  aa-bb-yyyy, aa/bb/yy, and aa-bb-yy
	// const string pattern01 = R"(\d+:\s+(\d{2}[\-\/]\d{2}[\-\/]\d{2,4}$))";

	// Handles formats of yyyy/aa/bb, and yyyy-aa-bb
	// const string pattern01 = R"(\d+:\s+(\d{4}[\-\/]\d{2}[\-\/]\d{2}$))"

	// So together, the pattern is
	const string pattern = R"(\d+:\s+((\d{2}[\-\/]\d{2}[\-\/]\d{2,4})|(\d{4}[\-\/]\d{2}[\-\/]\d{2}))$)";
	regex expression {pattern};

	for (string line; getline(file, line); ) {
		if (regex_match(line, expression))
			cout <<"\033[1;34m" << "\"" << line
				 << "\" matched the regex." << "\033[0m1" << "\n";
		else
			cout << "\033[1;31m" << "\"" << line << "\" does not match."
				 << "\033[0m" << "\n";
				
	}
	
}
