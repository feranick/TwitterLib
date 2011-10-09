/*
  Twitter.cpp - Arduino library to Post messages to Twitter using OAuth.
  Copyright (c) NeoCat 2010. All right reserved.
 
  Mofidied by feranick <feranick@hotmail.com> to add compatibility with Arduino IDE v.1.0
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
*/

// ver1.2 - Use <Udp.h> to support IDE 0019 or later
// ver1.2.2_nf1 - Added support for Arduino IDE v.1.0

#ifndef TWITTER_H
#define TWITTER_H

#include <inttypes.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO > 18   // Arduino 0019 or later
#include <SPI.h>
#endif
#include <Ethernet.h>
#if defined(ARDUINO) && ARDUINO < 100
#include <EthernetDNS.h>
#endif

class Twitter
{
private:
	uint8_t parseStatus;
	int statusCode;
	const char *token;
    #if defined(ARDUINO) && ARDUINO < 100
	Client client;
    #else
    EthernetClient client;
    #endif
public:
	Twitter(const char *user_and_passwd);
	
	bool post(const char *msg);
	bool checkStatus(Print *debug = NULL);
	int  wait(Print *debug = NULL);
	int  status(void) { return statusCode; }
};

#endif	//TWITTER_H
