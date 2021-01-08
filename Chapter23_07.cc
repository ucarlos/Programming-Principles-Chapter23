/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 11:44 PM
 *
 * Chapter23_07.cc
 * Write a program (similar to the one in the previous exercise) that finds
 * credit card numbers in a file. Do a bit of research to find out what credit
 * card formats are really used.
 *
 * The credit card formats came from the following site:
 * https://medium.com/hootsuite-engineering/a-comprehensive-guide-to-validating-and-formatting-credit-cards-b9fa63ec7863
 * 
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;
int main(void) {
	const string file_name = "./Chapter23_07_File.txt";
	ifstream file {file_name, ios_base::in};

	if (!file) {
		cerr << "Error: Cannot open \"" << file_name << "\"."
			 << "File does not exist or filename is incorrect.\n";
		exit(EXIT_FAILURE);
	}
	
	string mastercard_pattern = R"(^5[1-5]\d{14}$)";
	string american_express_pattern = R"(^3[47]\d{13})";
	string visa_pattern = R"(^4[0-9]{12}(?:[0-9]{3})?)";
	string discover_pattern = R"(^65[4-9][0-9]{13}|^6011[0-9]{12})";

	ostringstream os;
	os << "(" << "(" <<  mastercard_pattern << ")"
	   << "|" << "(" << american_express_pattern << ")"
	   << "|" << "("  <<visa_pattern << ")"
	   << "|" << "(" << discover_pattern << ")"
	   << ")";

	string full_pattern = os.str();
	cout << "Complete string: " << full_pattern << endl;

	regex regular_expression{full_pattern};

	for (string line; getline(file, line); ) {
		if (regex_match(line, regular_expression)) 
			cout <<"\033[1;34m" << "\"" << line
				 << "\" matched the regex." << "\033[0m" << "\n";		
		else 
			cout << "\033[1;31m" << "\"" << line << "\" does not match."
				 << "\033[0m" << "\n";
		
	}	
}
