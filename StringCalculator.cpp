#include "StringCalculator.h"
#include <sstream>
#include <regex>
#include <stdexcept>

// Helper function to split a string by delimiters
std::vector<std::string> StringCalculator::split(const std::string& s, const std::string& delimiters) {
    std::vector<std::string> tokens;
    std::regex re("[" + delimiters + "]");
    std::sregex_token_iterator it(s.begin(), s.end(), re, -1);
    std::sregex_token_iterator reg_end;
    for (; it != reg_end; ++it) {
        if (!it->str().empty()) {
            tokens.push_back(it->str());
        }
    }
    return tokens;
}

// Helper function to extract numbers from a string
std::vector<int> StringCalculator::extractNumbers(const std::string& numbers, const std::string& delimiters) {
    std::vector<int> result;
    std::vector<std::string> tokens = split(numbers, delimiters);
    for (const std::string& token : tokens) {
        result.push_back(std::stoi(token));
    }
    return result;
}

// Function to check for negative numbers and throw an exception
void StringCalculator::checkForNegatives(const std::vector<int>& nums) {
    std::vector<int> negatives;
    for (int num : nums) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }
    if (!negatives.empty()) {
        std::string error = "Negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) {
                error += ",";
            }
            error += std::to_string(negatives[i]);
        }
        throw std::runtime_error(error);
    }
}

// Function to get delimiters from the input string
std::string StringCalculator::getDelimiters(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        return numbers.substr(2, delimiterEnd - 2) + ",\n";
    }
    return ",\n";
}

// Function to remove custom delimiter syntax from the input string
std::string StringCalculator::removeDelimiterSyntax(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        return numbers.substr(delimiterEnd + 1);
    }
    return numbers;
}

// Main add function to sum up numbers from the input string
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiters = getDelimiters(numbers);
    std::string numStr = removeDelimiterSyntax(numbers);

    std::vector<int> nums = extractNumbers(numStr, delimiters);
    checkForNegatives(nums);

    int sum = 0;
    for (int num : nums) {
        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}

