/*
Class to match an IP to a country.

This product includes GeoLite data created by MaxMind, available from http://www.maxmind.com.
But you can use your own database if you organize it the same way as MaxMind's, or if you change the constructor.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/

#ifndef INC_GEOIP_H
#define INC_GEOIP_H


#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h> 
#include "range.h"

class GeoIP {


private:

	std::vector< Range > database;
	
public:
	
	GeoIP(std::string);
		/*
			Constructor. Gets filename as input
		*/
	
	std::string binarySearch(unsigned int start, unsigned int end, const std::string& input_ip) const;
		/*
			Binary Search the database
		*/
	
	std::string getCountry(std::string) const;
		/*
			Get the country where the given IP comes from
		*/
	
	friend std::ostream& operator << (std::ostream&, GeoIP&);
};

void split(std::vector<std::string>& lst, const std::string& input, const std::string& separators, bool remove_empty = true);
	/*
		Split a string by the given seperator(s)
	*/

void removeChar(std::string&, char);
	/*
		Remove every occurance of the given char from a string
	*/


#endif
