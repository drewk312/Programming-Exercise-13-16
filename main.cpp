#include <iostream>
#include <iomanip>
#include "dateType.h"

int main() {
    dateType myDate(11, 8, 2023);

    std::cout << "Original Date: " << myDate << std::endl;

    ++myDate;
    std::cout << "Date after increment: " << myDate << std::endl;

    --myDate;
    std::cout << "Date after decrement: " << myDate << std::endl;

    dateType anotherDate;
    std::cout << "Enter a date (MM-DD-YYYY): ";
    std::cin >> anotherDate;

    if (myDate.operator==(anotherDate))
        std::cout << "The two dates are equal." << std::endl;
    else if (myDate.operator<(anotherDate))
        std::cout << "The entered date is in the future." << std::endl;
    else
        std::cout << "The entered date is in the past." << std::endl;

    return 0;
}
