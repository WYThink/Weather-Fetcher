#include "Aliases.h"
#include "CityInput.h"
#include "string"
#include "ErrorHandling.h"

/* <--- Fetch Response ---> */
bool cityInput::getWeather() {

    /* <--- Try & Catch ---> */
    try {

        /* <--- Asynchronous Get Request ---> */
        cpr::AsyncResponse ASYNC_RESPONE = cpr::GetAsync(
            cpr::Url{ URL }, 
            cpr::Parameters{ 
                {"q" , CITY_Name.c_str()}, 
                {"key" , apiInfo::ret_APIKey().c_str()}
            },
            cpr::Timeout{ 3500 }
        );


        /* <--- RESPONSE Object ---> */
        cpr::Response RESPONSE{ ASYNC_RESPONE.get()};
        status_code = RESPONSE.status_code;


        /* <--- Error Checking ---> */
        if (!status_code) throw RequestTimeout{ "Request TimeOut" };                                                 // Throw Error , If Request TimeOut
        if (status_code >= 400) 
        {
            error_code = json::parse(RESPONSE.text).at("error").at("code").get<int>();

            if (status_code == 400 && error_code == 1006) throw InvalidCity{"Invalid City {" + CITY_Name + "}"};    // Throw Error , If Invalid City Name
            if (status_code == 403 && error_code == 2008) throw APIKeyDisabled{"API Key Disabled"};                 // Throw Error , If API Key Is Disabled
            if (status_code == 403 && error_code == 2006) throw InvalidAPIKey{ "Invalid API Key" };                 // Throw Error , If API Key Is Invalid
        }


        /* <--- JSON Object ---> */
        json Obj{ json::parse(RESPONSE.text) };

        /* <--- Calling Assign Info ---> */
        assignInfo(Obj);


        /* <--- Weather Info ---> */        
        std::cout << "\n\n🌍 **Weather Update for " << city << ", " << country << "** 🌍\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "🕒 **Local Time**: " << localtime << "\n";
        std::cout << "🌡️ **Temperature**: " << temp_c << "°C (" << temp_f << "°F)\n";
        std::cout << "🌡️ **Feels Like**: " << feelslike_c << "°C (" << feelslike_f << "°F)\n";
        std::cout << "☀️ **Condition**: " << condition << "\n";
        std::cout << "💧 **Humidity**: " << humidity << "%\n";
        std::cout << "🌬️ **Wind**: " << wind_kph << " kph (" << wind_dir << ")\n";
        std::cout << "-----------------------------------------\n";
    }
    catch (const std::exception& e) {
        throw;
    }

    return true;
}


/* <--- Assign Info ---> */
void cityInput::assignInfo(const json& OBJ) {

    /* <--- Temp Object ---> */
    json locationObj = OBJ["location"];
    json currentObj  = OBJ["current"];

    /* <--- City Information ---> */
    localtime       = locationObj.at("localtime");
    city            = locationObj.at("name");
    region          = locationObj.at("region");
    country         = locationObj.at("country");


    /* <--- Temprature Information ---> */
    temp_c          = currentObj.at("temp_c");
    temp_f          = currentObj.at("temp_f");
    feelslike_c     = currentObj.at("feelslike_c");
    feelslike_f     = currentObj.at("feelslike_f");


    /* <--- Wind & Humidity ---> */
    condition       = currentObj.at("condition").at("text");
    wind_dir        = currentObj.at("wind_dir");
    wind_kph        = currentObj.at("wind_kph");
    humidity        = currentObj.at("humidity");
}

/* <--- Constructor ---> */
cityInput::cityInput() {


    /* <--- Welcome Message ---> */
    std::cout << "*********************************************\n";
    std::cout << "*                                           *\n";
    std::cout << "*        🌤️  Welcome to Weatherly! 🌤️       *\n";
    std::cout << "*                                           *\n";
    std::cout << "*  Your tool for instant weather updates.   *\n";
    std::cout << "*                                           *\n";
    std::cout << "*********************************************\n\n";


    /* <--- Prompt Message ---> */
    std::cout << "Enter the name of the city to get the current weather:\n\n";
    std::cout << ">> ";
    std::getline(std::cin >> std::ws, CITY_Name);


    /* <--- Try & Catch ---> */
    try {
        getWeather();
    }
    catch (const std::exception& e) {
        throw;
    }
}


/* <--- Destructor ---> */
cityInput::~cityInput() {}