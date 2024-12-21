#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

std::string timeConversion(const std::string& s) {
    // Extract the components
    std::string zone = s.substr(s.size() - 2); // AM or PM
    int hour = std::stoi(s.substr(0, 2));      // Extract hour as integer
    int minute = std::stoi(s.substr(3, 2));   // Extract minute as integer
    int second = std::stoi(s.substr(6, 2));   // Extract second as integer

    // Convert based on AM/PM
    if (zone == "PM" && hour != 12) {
        hour += 12;
    } else if (zone == "AM" && hour == 12) {
        hour = 0;
    }

    // Format the result can also be done using buffer[9] and sprintf
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << minute << ":"
        << std::setfill('0') << std::setw(2) << second;

    return oss.str();
}

int main() {
    std::string time = "12:01:00PM";
    std::cout << timeConversion(time) << std::endl; // Output: 12:01:00
    return 0;
}


