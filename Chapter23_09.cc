/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/08/2021 at 04:44 PM
 *
 * Chapter23_09.cc
 * Using eof() (§B.7.2), it is possible to determine which line of a table is
 * the last. Use that to (try to) simplify the table-checking program
 * from §23.9. Be sure to test your program with files that end with empty
 * lines after the table and with files that don’t end with a newline at all.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <regex>
using namespace std;

int main(void) {
	ifstream file {"Table.txt"};
	if (!file) {
		cerr << "Cannot open \"Table.txt\".\n";
		exit(EXIT_FAILURE);
	}

	string line;
	int line_num = 0;

	string header_pattern = R"(^[\w ]+(   [\w ]+*$)";
	string row_pattern = R"(^[\w ]+(      \d+)( \d+)( \d+)$)";

	regex header {header_pattern};
	regex row {row_pattern};

	if (getline(file, line)) {
		smatch matches;
		if (!regex_match(line, matches, header))
			throw runtime_error("No header found.");		
	}

	while (getline(file, line)) {
		line_num++;
		smatch matches;
		if (!regex_match(line, matches, row)) {
			ostringstream err;
			err << "Error: \"" << line << "\" is bad line.\n";
			throw runtime_error(err.str());			
		}

	}
}
