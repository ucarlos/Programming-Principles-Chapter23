/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 12/31/2020 at 07:26 PM
 * 
 * MailFile.h
 * 
 * -----------------------------------------------------------------------------
 */

#include "MailFile.h"
#include <cstdlib>
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

int is_prefix(const std::string &s, const std::string &p) {
	// Is p the first part of s?
	int n = p.size();
	if (string(s, 0, n) == p) return n;
	return 0;
}

/**
 * Finds the name of the sender in a Message and stores it in s if it is found.
 * Returns true if sender is found.
 * @param m pointer to a Message object.
 * @param s String to store the name of the sender (If found)
 */
bool find_from_addr(const Message *m, std::string &s) {
	// Initial Version
	// for (const auto &x : *m)
	// 	if (int n = is_prefix(x, "From: ")) {
	// 		s = string(x, n); return true;
	// 	}
	// return false;

	// Changed for Chapter23_03.cc
	const static string pattern = R"(^From:.)";
	static std::regex expression {pattern};

	for (const auto &x: *m) {
		smatch smatches;
		if (regex_search(x, smatches, expression)) {
			auto first_pos = smatches[0].str().length();
			s = string(x, first_pos);
			return true;
		}
			
	}

	return false; // Not found
}


/**
 */
std::string find_subject(const Message *m) {
	// Initial Version
	// for (const auto &x : *m)
	// 	if (int n = is_prefix(x, "Subject: ")) return string(x, n);
	// return std::string();

	// Changed for Chapter23_03.cc
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

std::ostream & operator<<(std::ostream &os, const Message &m) {
	for (const auto &i : m)
		os << i << "\n";

	return os;
}
