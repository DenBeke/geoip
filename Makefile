CC=g++
CFLAGS=-c --pedantic -g -Wall


all: geoip


geoip: ip.o range.o geoip.o main.o
	g++ $^ -o GeoIP

ip.o: ip.cpp ip.h
	$(CC) $(CFLAGS) $<

range.o: range.cpp range.h
	$(CC) $(CFLAGS) $<

geoip.o: geoip.cpp geoip.h
	$(CC) $(CFLAGS) $<

main.o: main.cpp
	$(CC) $(CFLAGS) $<


clean:
	rm -f *.o *.*~