#ifndef dateType_H
#define dateType_H

#include <iostream>
using namespace std;

class dateType
{
    friend ostream& operator<<(ostream&, const dateType&);
    friend istream& operator>>(istream&, dateType&);

public:
    void setDate(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Overload increment and decrement operators
    dateType& operator++(); // Prefix increment
    dateType operator++(int); // Postfix increment
    dateType& operator--(); // Prefix decrement
    dateType operator--(int); // Postfix decrement

    // Overload relational operators
    bool operator==(const dateType& other) const;
    bool operator!=(const dateType& other) const;
    bool operator<(const dateType& other) const;
    bool operator<=(const dateType& other) const;
    bool operator>(const dateType& other) const;
    bool operator>=(const dateType& other) const;

    // Function to check if a year is a leap year
    bool isLeapYear() const;

    dateType(int = 1, int = 1, int = 1900);

private:
    int dMonth;
    int dDay;
    int dYear;
};

#endif
