/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 02:22 PM
 * 
 * Chapter23_01.cc
 * Get the email file example to run; test it using a larger file of your own
 * creation. Be sure to include messages that are likely to trigger errors, such
 * as messages with two address lines, several messages with the same ad-
 * dress and/or same subject, and empty messages. Also test the program
 * with something that simply isn’t a message according to that program’s
 * specification, such as a large file containing no –––– lines.
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
using namespace std;

int main() {
	Mail_File mail_file {"../Chapter23_01_Mail.txt"};
	
	// Now gather the messages into a multimap:
	std::multimap<string, const Message *> sender;

	for (const auto &m : mail_file) {
		string s;
		if (find_from_addr(&m, s))
			sender.insert(make_pair(s, &m));
	}
	
	// Now iterate through the multimap and extract the subjects of John Doe's
	// and extract the subjects of John Doe's messages:
	string name = "John Doe <jdoe@machine.example>";
	auto pp = sender.equal_range(name);
	if (pp.first == pp.second) {
		cerr << "Error: No messages can be found with \""
			 << name << "\"\n";
		exit(EXIT_FAILURE);
	}
	
	for (auto p = pp.first; p != pp.second; p++)
		cout << find_subject(p->second) << "\n";
	
}
