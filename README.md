# Weather-Fetcher

**Weather-Fetcher** is a C++ command-line application that provides real-time weather updates for any city worldwide. It fetches weather data from a public weather API, parses the JSON response, and displays the information in a clean and user-friendly format.

---

## Features

- **Real-Time Weather Data**: Fetches current weather information, including temperature, humidity, wind speed, and weather conditions.
- **Global Coverage**: Supports weather queries for cities across the globe.
- **User-Friendly Interface**: Displays weather data in a visually appealing format using emojis and structured layouts.
- **Error Handling**: Gracefully handles API errors, invalid inputs, and network issues.

---

## Technologies

- **C++**: Core programming language used for developing the application.
- **CPR (C++ Requests Library)**: Used to make HTTP requests to the WeatherAPI for fetching weather data.
- **nlohmann/json**: A modern C++ JSON library for parsing and manipulating JSON responses from the API.
- **WeatherAPI**: Provides accurate and up-to-date weather information through its RESTful API.

---

## How It Works

1. The user inputs a city name.
2. The application sends an HTTP GET request to the WeatherAPI using CPR.
3. The JSON response is parsed using nlohmann/json to extract relevant weather details.
4. The weather information is displayed in a beautifully formatted output.

---

## Usage

1. **Run the Application**:
   - Compile and run the Weather-Fetcher application.
2. **Enter City Name**:
   - When prompted, enter the name of the city for which you want weather information.
3. **View Weather Data**:
   - The application will display the current weather conditions in a clean and structured format.

---

## Installation

### Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
- **CPR Library**: Install the CPR library for making HTTP requests.
- **nlohmann/json Library**: Install the nlohmann/json library for JSON parsing.

### Steps

1. **Download the Project Files**:
   - Clone or download the Weather-Fetcher repository.

2. **Install Dependencies**:
   - Install CPR and nlohmann/json using your preferred package manager (e.g., vcpkg, Conan, or manually).

3. **Configure the Project**:
   - Open the project in your IDE (e.g., Visual Studio, CLion, or any text editor with build tools).
   - Link the CPR and nlohmann/json libraries to your project.

4. **Build the Project**:
   - Compile the project using your C++ compiler.

5. **Run the Application**:
   - Execute the compiled binary to start using Weather-Fetcher.

---

## Example Output

```plaintext
🌍 **Weather Update for London, United Kingdom** 🌍
-----------------------------------------
🕒 **Local Time**: 2023-10-15 14:30
🌡️ **Temperature**: 15.0°C (59.0°F)
🌡️ **Feels Like**: 13.5°C (56.3°F)
🌧️ **Condition**: Light Rain
💧 **Humidity**: 87%
🌬️ **Wind**: 12.3 kph (SW)
-----------------------------------------
