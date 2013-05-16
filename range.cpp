/*
Class representing an IP range.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/


#include "range.h"

Range::Range(const Ip& input_rangeStart, const Ip& input_rangeEnd, std::string input_country) : rangeStart(input_rangeStart), rangeEnd(input_rangeEnd), country(input_country) {
}


bool Range::isInRange(const Ip& input_ip) const {
	
	return rangeStart <= input_ip && input_ip <= rangeEnd; 
	
}


bool Range::isInLowerRange(const Ip& input_ip) const {
	
	return input_ip < rangeStart;
}


bool Range::isInHigherRange(const Ip& input_ip) const {
	
	
	return input_ip > rangeEnd;
}


std::string Range::getCountry() const {
	
	return country;
	
}


std::ostream& operator << (std::ostream& output, Range& range) {
	
	output << range.rangeStart;
	output << ", ";
	output << range.rangeEnd;
	output << ", ";
	output << range.country;
	
	return output;
	
}
