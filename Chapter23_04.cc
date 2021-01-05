/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 05:37 PM
 * 
 * Chapter23_04.cc
 * Find a real email message file (containing real email messages) and mod-
 * ify the email example to extract subject lines from sender names taken as
 * input from the user.
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
using namespace std;

int main(void) {
	const std::string input_file = "./Chapter23_04_Mail.txt";
	Mail_File mail_file {input_file};

	// Now gather the messages into a multimap:
	std::multimap<string, const Message *> sender;

	for (const auto &m : mail_file) {
		string s;
		if (find_from_addr(&m, s))
			sender.insert(make_pair(s, &m));
	}
	
	if (sender.empty()) {
		cerr << "Error: Could not populate multimap."
			 << " Please make sure that the input file uses "
			 << " the appropriate message separator \""
			 << message_seperator << "\"\n";
		exit(EXIT_FAILURE);
	}
	else
		cout << "Multimap populated from " << input_file << "\n";

	cout << "Now, please search for a sender name. To quit, enter \"quit\"\n";

	cout << "Query: ";
	string input;
	getline(cin, input);

	while (input != "quit") {
	
		// Now iterate through the multimap and extract the subjects of John Doe's
		// and extract the subjects of John Doe's messages:
		auto pp = sender.equal_range(input);
		if (pp.first == pp.second) {
			cerr << "Error: No messages can be found with \""
				 << input << "\"\n";
		}
		else {		  
			for (auto p = pp.first; p != pp.second; p++)
				cout << "\tSubject: " << find_subject(p->second) << "\n";
		}

		cout << "Next Query: ";
		getline(cin, input);
	}

	cout << "Complete.\n";
}
