/*
Class representing an IP.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/


#ifndef INC_IP_H
#define INC_IP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

typedef unsigned char uint8;

class Ip {
	
	uint8 a;
	uint8 b;
	uint8 c;
	uint8 d;
	
	
public:
	Ip(uint8, uint8, uint8, uint8);
		/*
		Constructor with four integers
		*/
	
	Ip(std::string);
		/*
		Constructor with a string representing an IP
		*/
	
	bool operator==(const Ip&) const;
	
	bool operator<(const Ip&) const;
	
	bool operator>(const Ip&) const;
	
	bool operator<=(const Ip&) const;

	bool operator>=(const Ip&) const;
	
	friend std::ostream& operator <<(std::ostream&, Ip&);

	std::vector< uint8 > split(const std::string&, char);
		/*
			Splits a string with a given sperator.
			Returns a vector containing integers.
		*/

};

#endif
