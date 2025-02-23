#pragma once
#ifndef ERROR_HANDLING
#define ERROR_HANDLING

#include <exception>
#include "Aliases.h"

/* <--- Request TimeOut Exception ---> */
class RequestTimeout : public std::exception {
	
	private:
		string m_ErrorMessage;

	public:

		/* <--- Constructor ---> */
		RequestTimeout(string_view Message) : m_ErrorMessage{ Message } {}

		/* <--- what() ---> */
		const char* what() const noexcept override {
			return m_ErrorMessage.c_str();
		}
};


/* <--- Invalid City Exception ---> */
class InvalidCity : public std::exception {
	
	private:
		string m_ErrorMessage;
	
	public:

		/* <--- Constructor ---> */
		InvalidCity(string_view Message) : m_ErrorMessage{ Message } {}

		/* <--- what() ---> */
		const char* what() const noexcept override {
			return m_ErrorMessage.c_str();
		}
};


/* <--- API Key Disabled Exception ---> */
class APIKeyDisabled : public std::exception {

	private:
		string m_ErrorMessage;

	public:

		/* <--- Constructor ---> */
		APIKeyDisabled(string_view Message) : m_ErrorMessage{ Message } {}

		/* <--- what() ---> */
		const char* what() const noexcept override {
			return m_ErrorMessage.c_str();
		}
};


/* <--- API Key Disabled Exception ---> */
class InvalidAPIKey : public std::exception {

	private:
		string m_ErrorMessage;

	public:

		/* <--- Constructor ---> */
		InvalidAPIKey(string_view Message) : m_ErrorMessage{ Message } {}

		/* <--- what() ---> */
		const char* what() const noexcept override {
			return m_ErrorMessage.c_str();
		}
};

#endif 