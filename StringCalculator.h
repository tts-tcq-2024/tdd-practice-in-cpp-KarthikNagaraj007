#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<std::string> split(const std::string& s, const std::string& delimiters);
    std::vector<int> extractNumbers(const std::string& numbers, const std::string& delimiters);
    void checkForNegatives(const std::vector<int>& nums);
    std::string getDelimiters(const std::string& numbers);
    std::string removeDelimiterSyntax(const std::string& numbers);
};

#endif // STRINGCALCULATOR_H
