#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <memory>
#include "Aliases.h"
#include "CityInput.h"

/* <--- Main ---> */
int main() {

	try {
		/* <--- cityInput Object ---> */
		std::shared_ptr<cityInput> cityOBJ{ std::make_shared<cityInput>() };
	}
	catch (const std::exception& e) {
		std::cout << "{+} Error : " << e.what() << std::endl;
	}

	return 0;
}