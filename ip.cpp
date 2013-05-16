/*
Class representing an IP.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/

#include "ip.h"
#include <iostream>

Ip::Ip(uint8 a, uint8 b, uint8 c, uint8 d) : a(a), b(b), c(c), d(d) {
}


Ip::Ip(std::string inputIp) {
	
	std::vector< uint8 > parsedIp = split(inputIp, '.');
	
	a = parsedIp[0];
	b = parsedIp[1];
	c = parsedIp[2];
	d = parsedIp[3];
	
}

bool Ip::operator==(const Ip& other) const {
	
	return a == other.a && b == other.b && c == other.c && d == other.d;
	
}

bool Ip::operator<(const Ip& other) const {
	
	if(a < other.a) {
		return true;
	}
	else if(a == other.a) {
		
		if(b < other.b) {
			return true;
		}
		else if(b == other.b) {
			
			if(c < other.c) {
				return true;
			}
			else if(c == other.c) {
				
				if(d < other.d) {
					return true;
				}
				else {
					return false;
				}
				
			}
			else {
				return false;
			}
			
		}
		else {
			return false;
		}
		
	}
	else {
		return false;
	}
	
}

bool Ip::operator>(const Ip& other) const {
	
	return !(*this < other) && !(*this == other);
	
}


bool Ip::operator<=(const Ip& other) const {

	return (*this == other) || (*this < other); 
	
}


bool Ip::operator>=(const Ip& other) const {
	
	return *this == other || (*this > other);
	
}


std::ostream& operator <<(std::ostream& output, Ip& ip) {
	
	output << int(ip.a) << "." << int(ip.b) << "." << int(ip.c) << "." << int(ip.d); 
	
	return output;
}



std::vector< uint8 > Ip::split(const std::string& string, char seperator) {
	std::vector< uint8 > output;
	std::string tempString;
	
	for(unsigned int i = 0; i <= string.size(); i++) {
		if(string[i] == seperator || i == string.size()) {
			output.push_back(atoi(tempString.c_str()));
			tempString.clear();
		}
		else {
			tempString.push_back(string[i]);
		}
	}
	
	return output;
}

