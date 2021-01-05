/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 12/31/2020 at 11:02 PM
 * 
 * TestMailFile.cc
 * 
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
using namespace std;
int main(void) {
	// initialize mail_file from a file.
	Mail_File mail_file{"./ExampleMailFile.txt"};

	// First gather messages from each sender together in a multimap.
	std::multimap<string, const Message *> sender;

	for (const auto &m : mail_file) {
		string s;
		if (find_from_addr(&m, s))
			sender.insert(make_pair(s, &m));
	}

	// Now iterate through the multimap and extract the subjects of John Doe's
	// and extract the subjects of John Doe's messages:
	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto p = pp.first; p != pp.second; p++)
		cout << find_subject(p->second) << "\n";
}
