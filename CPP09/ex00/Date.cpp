#include "Date.hpp"
#include "BitcoinExchange.hpp"

Date::Date() : year(0), month(0), day(0) {}

Date::Date(const Date& D) : year(D.year), month(D.month), day(D.day)  {}

Date& Date::operator=(const Date& D)
{
    if (this != &D)
    {
        year = D.year;
        month = D.month;
        day = D.day;
    }
    return *this;
}

Date::Date(const std::string& date)
{
    std::stringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-') throw std::runtime_error("invalid date format => \"" + date + "\"");

    if (month < 1 || month > 12) throw std::runtime_error("invalid month => " + date);
    if (day < 1 || day > 31) throw std::runtime_error("invalid day => " + date);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("invalid day for month => " + date);
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && day > (isLeap ? 29 : 28))
        throw std::runtime_error("invalid day for February => " + date);
}

Date::~Date() {}

bool Date::operator>(const Date& D) const 
{
    if (year != D.year) return year > D.year;
    if (month != D.month) return month > D.month;
    return day > D.day;
}

bool Date::operator>=(const Date& D) const 
{
    return !(*this < D);
}

bool Date::operator<(const Date& D) const 
{
    if (year != D.year) return year < D.year;
    if (month != D.month) return month < D.month;
    return day < D.day;
}

bool Date::operator<=(const Date& D) const 
{
    return !(*this > D);
}

bool Date::operator==(const Date& D) const 
{
    return (year == D.year && month == D.month && day == D.day);
}

bool Date::operator!=(const Date& D) const 
{
    return !(*this == D);
}

int Date::getDay( void ) const
{
    return (day);
}

int Date::getMonth( void ) const
{
    return (month);
}

int Date::getYear( void ) const
{
    return (year);
}


std::ostream& operator<<(std::ostream& os, const Date& D)
{
    os << D.getYear() << "-" 
       << (D.getMonth() < 10 ? "0" : "") << D.getMonth() << "-"
       << (D.getDay() < 10 ? "0" : "") << D.getDay(); 
    return os;
}
