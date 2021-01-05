/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/05/2021 at 04:34 PM
 * 
 * Chapter23_03.cc
 * Modify the email example from §23.4 to use regular expressions to find
 * the subject and sender.
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
#include <regex>
using namespace std;

std::string find_subject_regex(const Message *m) {
	const static string pattern = R"(^Subject:.)";
	static std::regex expression {pattern};

	for (const auto &x : *m) {
		smatch matches;
		if (regex_search(x, matches, expression)) {
			// Return the rest of the string
			auto first_pos = matches[0].str().length();
			return string(x, first_pos);

		}
	}

	return string(); // If not found	
	
}

bool find_from_addr_regex(const Message *m, std::string &s) {
	const static string pattern = R"(^From:.*$)";
	static std::regex expression {pattern};

	for (const auto &x: *m) {
		if (regex_match(x, expression)) {
			s = x;
			return true;
		}
			
	}

	return false; // Not found
}

int main(void) {
	cout << "Replace the code in the find_subject and find_from_addr "
		 << "functions in the MailFile.cc file and run any program that "
		 << "uses it.\n";
	
}
