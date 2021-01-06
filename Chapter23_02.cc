/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 03:40 PM
 * 
 * Chapter23_02.cc
 * Add a multimap and have it hold subjects. Let the program take an input
 * string from the keyboard and print out every message with that string as
 * its subject.
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
#include <cctype>
using namespace std;

const std::string input_file = "ExampleMailFile.txt";

string string_to_lower(const string &str) {
	if (str.empty()) return string {};

	string temp {};
	for (const char &c : str)
		temp += tolower(c);
	

	return temp;
}

int main(void) {
	Mail_File mail_file {input_file};

	multimap<std::string, const Message *> the_map;

	// Populate the multimap with the messages from mail_file

	for (const auto &i : mail_file) {
		string s = find_subject(&i);
		if (s != string())
			the_map.insert(make_pair(s, &i));		
	}

	if (the_map.empty()) {
		cerr << "Error: Could not populate multimap."
			 << " Please make sure that the input file uses "
			 << " the appropriate message separator \""
			 << message_seperator << "\"\n";
		exit(EXIT_FAILURE);
	}
	else
		cout << "Multimap populated from " << input_file << "\n";

	cout << "Now, please search for a subject. To quit, enter \"quit\"\n";
	cout << "Query: ";										  
	string input;
	getline(cin, input);

	while (string_to_lower(input) != "quit") {
		// Search multimap for string:
		
		auto pp = the_map.equal_range(input);
		if (pp.first == pp.second)
			cerr << "Error: No messages can be found with \""
				 << input << "\"\n";
		else {
			cout << "Some messages were found with subject "
				 << "\"" << input << "\" :\n";

			for (auto p = pp.first; p != pp.second; p++)
				cout << "\n\"\"\"\n" << *p->second << "\"\"\"\n";
					   
		}
		cout << "Next Query: ";
		getline(cin, input);
				
	}
	
	cout << "Complete.\n";
}
