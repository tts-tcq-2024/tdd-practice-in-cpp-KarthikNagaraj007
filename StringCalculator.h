#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator {
public:
    int add(const std::string& input);
    int sumTwoNumbers(const std::string& input);
    void checkNegative(const std::string& input);
    std::string handleCustomDelimiter(const std::string& input);
    std::string getDelimiters(const std::string& input);
};

#endif // STRINGCALCULATOR_H
