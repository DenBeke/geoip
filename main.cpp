/*
Main script for matching IP's to Countries
This main is just to show GeoIP works well and fast.

Author: Mathias Beke - denbeke.be
Date: May 2013
*/

#include "geoip.h"
#include "ip.h"
#include <vector>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[]) {
	
	
	
	
	
	if(argc > 2) {
		std::cout << "Usage: " << argv[0] << " <ip>" << std::endl;
		return 0;
	}
	else if(argc == 2) {
	
		//Build database
		GeoIP database("GeoIPCountryWhois.csv");	
		
		//Get country
		std::cout << "IP " << argv[1] << " is from country " << database.getCountry(argv[1]) << std::endl;
	
	
	}
	else {
		
		//Build database
		GeoIP database("GeoIPCountryWhois.csv");
		
		
		//Keep asking IP's and get country
		while(true) {
			
			std::string ip;
			
			std::cout << "IP: ";
			std::cin >> ip;
						
			std::cout << "IP " << ip << " is from country " << database.getCountry(ip) << std::endl;
			
			
		}
		
		
	}

	
	return 0;
	
}