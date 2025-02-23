#pragma once
#ifndef API_INFO
#define API_INFO

#include "Aliases.h"

/* <--- City Information ---> */
class apiInfo {
	
	private:
		string API_Token{ "343ecf393e6143fb9fc94342252302" };			// API Key

	public:
		string ret_APIKey();											// Return API Key
};

#endif 