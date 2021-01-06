/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 12/31/2020 at 07:26 PM
 * 
 * MailFile.h
 * 
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <regex>

const std::string message_seperator = "----";

using Line_iter = std::vector<std::string>::const_iterator;
class Message {
public:
	Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
	Line_iter begin() const { return first; }
	Line_iter end() const {return last; }
private:
	Line_iter first;
	Line_iter last;
	friend std::ostream& operator<<(std::ostream &os, const Message &m);

};

// Mail File:
using Mess_iter = std::vector<Message>::const_iterator;
//------------------------------------------------------------------------------

// A Mail File holds all the lines from a file and simplifies
// access to messages.
struct Mail_File { 
	std::string name; // File Name
	std::vector<std::string> lines; // Lines in Order
	std::vector<Message> m; // Messages in Order


	explicit Mail_File(const std::string &n); // Read File n into lines

	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }
};


int is_prefix(const std::string& s, const std::string& p);
/**
 * Finds the name of the sender in a Message and stores it in s if it is found.
 * Returns true if sender is found.
 * @param m pointer to a Message object.
 * @param s String to store the name of the sender (If found)
 */
bool find_from_addr(const Message *m, std::string &s);

std::string find_subject(const Message *m);
