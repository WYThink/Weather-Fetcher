#pragma once
#ifndef CITY_INPUT
#define CITY_INPUT

#include "Aliases.h"
#include "APIInfo.h"

/* <--- CITY Class ---> */
class cityInput : public apiInfo {

	private:

		/* <--- City Name & URL ---> */
		string		CITY_Name{};							// City Name
		string		URL{ "https://api.weatherapi.com/v1/current.json" };		// URL To Fetch City

	public:

		/* <--- City Information ---> */
		string city;
		string region;
		string country;
		string localtime;


		/* <--- Temprature Information ---> */
		double temp_c;
		double temp_f;
		double feelslike_c;
		double feelslike_f;


		/* <--- Wind & Humidity ---> */
		string	condition;
		string	wind_dir;
		double	wind_kph;
		int	humidity;

		/* <--- Response Status Code  ---> */
		int	status_code;

		/* <--- Response Error Code ---> */
		int	error_code;
	
	public:

		/* <--- Member Methods ---> */
		cityInput();					// Constructor
		~cityInput();					// Destructor
		void assignInfo(const json& OBJ);		// Assign Info
		bool getWeather();				// Verify City
};

#endif
