#pragma once

#include <iostream>
#include <sstream>

class Date
{
    private :
        int year, month, day;
        Date();
    public  :
        Date(const Date& D);
        Date& operator=(const Date& D);
        Date(const std::string& date);
        ~Date();
        bool operator>(const Date& D) const;
        bool operator>=(const Date& D) const;
        bool operator<(const Date& D) const;
        bool operator<=(const Date& D) const;
        bool operator==(const Date& D) const;
        bool operator!=(const Date& D) const;

        int getDay( void ) const;
        int getMonth( void ) const;
        int getYear( void ) const;
        
};

std::ostream& operator<<(std::ostream& os, const Date& D);