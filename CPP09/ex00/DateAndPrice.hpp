#pragma once

#include <iostream>
#include <sstream>

class DateAndPrice
{
    private :
        int year, month, day;
        float   price;
        DateAndPrice();
        void  isStringValid(std::string &date);
        void  isPriceValid(std::string &price);
    public  :
        DateAndPrice(const DateAndPrice& D);
        DateAndPrice& operator=(const DateAndPrice& D);
        DateAndPrice(std::string& date, std::string& price);
        ~DateAndPrice();
        bool operator>(const DateAndPrice& D) const;
        bool operator>=(const DateAndPrice& D) const;
        bool operator<(const DateAndPrice& D) const;
        bool operator<=(const DateAndPrice& D) const;
        bool operator==(const DateAndPrice& D) const;
        bool operator!=(const DateAndPrice& D) const;

        int getDay( void ) const;
        int getMonth( void ) const;
        int getYear( void ) const;
        float  getPrice( void ) const;
        
};

std::ostream& operator<<(std::ostream& os, const DateAndPrice& D);
std::string  getCurrentDate();
