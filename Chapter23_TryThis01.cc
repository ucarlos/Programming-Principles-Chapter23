/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/02/2021 at 08:43 PM
 *
 * Chapter23_TryThis01.cc
 * We really mean it: do run this example and make sure you understand the re-
 * sult. What would be “better error handling”? Modify Mail_file ’s constructor
 * to handle likely formatting errors related to the use of –––– .
 *
 * I modified the constructor so that if a line contains the message sperator,
 * then seperates into an new Message object. However, this does not consider
 * the scenrio where a message contains multiple message seperators. Also, in
 * my opinion, the seperator should be some character that is not used 
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
using namespace std;

/**
 * Mail_File Constructor
 * @param n string containing the filename of the mail file to be read.
 */
Mail_File::Mail_File(const std::string &n) {
	// Open file named n and read its lines into the vector<string> lines.
	// Find the messages in the lines and compose them in m.
	// For simplicity, assume that every message is ended by a ____ line.

	std::ifstream in {n, ios_base::in};
	if (!in) {
		cerr << "Error: \"" << n << "\" cannot be opened."
			 << "Please make sure that the file exists or "
			 << "that the filename is correct.\n";
		exit(EXIT_FAILURE);
	}

	for (string s; getline(in, s); ) // Build the vector of lines.
		lines.push_back(s);

	auto first = lines.begin();
	for (auto p = lines.begin(); p!= lines.end(); p++) {
		// If the string contains the message seperator, then 
		if (p->find(message_seperator) != string::npos) {
			m.push_back(Message(first, p));
			first = p + 1;
		}
		// if (*p == message_seperator) {
		// 	m.push_back(Message(first, p));
		// 	first = p + 1;

		// }

	}
}


int main(void) {



}
