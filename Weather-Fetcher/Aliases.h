#pragma once

#ifndef ALIAS_S
#define ALIAS_S

#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

/* <--- JSON Library ---> */
using json = nlohmann::json;

/* <--- STD Library ---> */
using string_view	= std::string_view;
using string		= std::string;

#endif