#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    int sumTwoNumbers(int a, int b);
    void checkNegative(int num);
    int convertStringToInt(const std::string& str);
    std::string handleCustomDelimiter(const std::string& numbers);
    std::string getDelimiters(const std::string& numbers);
};

#endif // STRINGCALCULATOR_H
