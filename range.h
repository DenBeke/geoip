/*
Class representing an IP range.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/


#ifndef INC_RANGE_H
#define INC_RANGE_H

#include <string>
#include <iostream>
#include "ip.h"

class Range {

private:
	
	Ip rangeStart;
	Ip rangeEnd;
	
	std::string country;
	
	
public:
	Range(const Ip&, const Ip&, std::string);
		/*
			Constructor
		*/
	
	bool isInRange(const Ip&) const;
		/*
			Check if the given IP is in this range
		*/
	
	bool isInLowerRange(const Ip&) const;
		/*
			Check if the given IP is in the lower range
		*/
	
	bool isInHigherRange(const Ip&) const;
		/*
			Check if the given IP is in the higher range
		*/
	
	std::string getCountry() const;
		/*
			Returns the country of this IP range
		*/
	
	friend std::ostream& operator << (std::ostream&, Range& range);
};

#endif
