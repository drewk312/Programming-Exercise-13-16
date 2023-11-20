#include "dateType.h"

// Constructor
dateType::dateType(int month, int day, int year)
{
    // Initialize the member variables with the provided values
    dMonth = month;
    dDay = day;
    dYear = year;
}

// Function to check if a year is a leap year
bool dateType::isLeapYear() const
{
    if ((dYear % 4 == 0 && dYear % 100 != 0) || (dYear % 400 == 0))
        return true;
    else
        return false;
}

// Overload the prefix increment operator
dateType& dateType::operator++()
{
    // Increment the date by one day
    dDay++;
    if (dMonth == 2 && isLeapYear())
    {
        if (dDay > 29)
        {
            dMonth++;
            dDay = 1;
        }
    }
    else if ((dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11) && dDay > 30)
    {
        dMonth++;
        dDay = 1;
    }
    else if (dDay > 31)
    {
        dMonth++;
        dDay = 1;
        if (dMonth > 12)
        {
            dYear++;
            dMonth = 1;
        }
    }

    return *this;
}

// Overload the postfix increment operator
dateType dateType::operator++(int)
{
    dateType temp = *this; // Create a temporary copy
    ++(*this); // Use the prefix increment operator
    return temp; // Return the original value
}

// Overload the prefix decrement operator
dateType& dateType::operator--()
{
    // Decrement the date by one day
    dDay--;
    if (dDay < 1)
    {
        dMonth--;
        if (dMonth < 1)
        {
            dYear--;
            dMonth = 12;
        }

        if (dMonth == 2 && isLeapYear())
            dDay = 29;
        else if (dMonth == 2)
            dDay = 28;
        else if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11)
            dDay = 30;
        else
            dDay = 31;
    }

    return *this;
}

// Overload the postfix decrement operator
dateType dateType::operator--(int)
{
    dateType temp = *this; // Create a temporary copy
    --(*this); // Use the prefix decrement operator
    return temp; // Return the original value
}

// Overload the equality operator
bool dateType::operator==(const dateType& other) const
{
    return (dYear == other.dYear && dMonth == other.dMonth && dDay == other.dDay);
}

// Overload the inequality operator
bool dateType::operator!=(const dateType& other) const
{
    return !(*this == other);
}

// Overload the less than operator
bool dateType::operator<(const dateType& other) const
{
    if (dYear < other.dYear)
        return true;
    else if (dYear == other.dYear)
    {
        if (dMonth < other.dMonth)
            return true;
        else if (dMonth == other.dMonth)
        {
            return dDay < other.dDay;
        }
    }
    return false;
}

// Overload the less than or equal to operator
bool dateType::operator<=(const dateType& other) const
{
    return (*this == other || *this < other);
}

// Overload the greater than operator
bool dateType::operator>(const dateType& other) const
{
    return !(*this <= other);
}

// Overload the greater than or equal to operator
bool dateType::operator>=(const dateType& other) const
{
    return !(*this < other);
}
