#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <regex>

// Convert a string to an integer.
int StringCalculator::convertStringToInt(const std::string& str) {
    return std::stoi(str);
}

// Sum two integers.
int StringCalculator::sumTwoNumbers(int a, int b) {
    return a + b;
}

// Check if a number is negative and throw an exception if it is.
void StringCalculator::checkNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("Negatives not allowed: " + std::to_string(num));
    }
}

// Handle custom delimiter from the input string.
std::string StringCalculator::handleCustomDelimiter(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        return numbers.substr(delimiterEnd + 1);
    }
    return numbers;
}

// Get delimiters from the input string if custom delimiters are specified.
std::string StringCalculator::getDelimiters(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        return numbers.substr(2, delimiterEnd - 2);
    }
    return ",\n";
}

// Main add function to sum up numbers from the input string.
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string numStr = handleCustomDelimiter(numbers);
    std::string delimiters = getDelimiters(numbers);
    std::regex re("[" + delimiters + "]");
    std::sregex_token_iterator it(numStr.begin(), numStr.end(), re, -1);
    std::sregex_token_iterator reg_end;

    int sum = 0;

    for (; it != reg_end; ++it) {
        std::string token = it->str();
        if (!token.empty()) {
            int num = convertStringToInt(token);
            checkNegative(num);
            if (num <= 1000) {
                sum = sumTwoNumbers(sum, num);
            }
        }
    }

    return sum;
}
