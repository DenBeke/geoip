/*
Class to match an IP to a country.

This product includes GeoLite data created by MaxMind, available from http://www.maxmind.com.
But you can use your own database if you organize it the same way as MaxMind's, or if you change the constructor.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/


#include "geoip.h"

GeoIP::GeoIP(std::string input_file) {
	
	//Open file
	std::ifstream inputFile(input_file.c_str());
	
	//Check file
	if(!inputFile.good()) {
		std::cerr << "Could not open input file '" << input_file << "'.\n";
	}
	
	std::string line;
	
	
	//Loop through lines of the IP database file
	while(inputFile.good() && std::getline(inputFile, line)) {
		
		//Info
		std::vector< std::string > parsedLine;
		const std::string seperators = "\",\"";
		
		//Split lines
		split(parsedLine, line, seperators, true);
		
		//Make new IP Range and add range to the 'database'
		database.push_back(Range(Ip(parsedLine[0]), Ip(parsedLine[1]), parsedLine[5]));
	
	}
	
	
	std::cout << "Database constructed with " << database.size() << " items." << std::endl;
	
}


std::string GeoIP::binarySearch(unsigned int start, unsigned int end, const std::string& input_ip) const {
	
	Ip ip = input_ip;
	
	if( end-start <= 1) {
		//Base case
		if(database[start].isInRange(ip)) {
			//IP found
			return database[start].getCountry();
		}
		else {
			//No IP found in the database
			return "Unknown";
		}
	}
	
	else if(database[(start+end)/2].isInRange(ip)) {
		//IP found
		return database[(start+end)/2].getCountry();
	}
	else if(database[(start+end)/2].isInLowerRange(ip)) {
		//IP must be in the lower range. Recursive call
		return binarySearch(start, (start+end)/2, input_ip);
	}
	else {
		//IP must be in the higher range. Recursive call
		return binarySearch((start+end)/2, end, input_ip);
	}
}


std::string GeoIP::getCountry(std::string input_ip) const {
	
	return binarySearch(0, database.size()-1, input_ip);
	
}


std::ostream& operator << (std::ostream& output, GeoIP& geoip) {
	
	for(unsigned int i = 0; i < geoip.database.size(); i++) {
		output << geoip.database[i] << std::endl;
	}
	
	return output;
	
}




void split(std::vector<std::string>& lst, const std::string& input, const std::string& separators, bool remove_empty)
{
	std::ostringstream word;
	for (unsigned int n = 0; n < input.size(); ++n)
	{
		if (std::string::npos == separators.find(input[n]))
			word << input[n];
		else
		{
			if (!word.str().empty() || !remove_empty)
				lst.push_back(word.str());
			word.str("");
		}
	}
	if (!word.str().empty() || !remove_empty) {
		lst.push_back(word.str());
	}
}



void removeChar(std::string& input_string, char remove) {
	
	
	std::string tempString;
	
	for(unsigned int i = 0; i < input_string.size(); i++) {
		if(input_string[i] != remove) {
			tempString.push_back(input_string[i]);
		}
	}
	
	input_string = tempString;
	
}
