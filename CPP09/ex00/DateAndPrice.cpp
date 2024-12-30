#include "DateAndPrice.hpp"

DateAndPrice::DateAndPrice() : year(0), month(0), day(0), price(0) {}

DateAndPrice::DateAndPrice(const DateAndPrice& D) : year(D.year), month(D.month), day(D.day), price(D.price)  {}

DateAndPrice& DateAndPrice::operator=(const DateAndPrice& D)
{
    if (this != &D)
    {
        year = D.year;
        month = D.month;
        day = D.day;
        price = D.price;
    }
    return *this;
}

void  DateAndPrice::isStringValid(std::string &striing)
{
    std::string::size_type start = striing.find_first_not_of(" \t\n");
    std::string::size_type end = striing.find_last_not_of(" \t\n");
    if (start != std::string::npos)
        striing = striing.substr(start, end - start + 1);
    else
        striing.clear();
    if (striing.find_first_of(" \t\n") != std::string::npos) throw std::runtime_error("bad input => " + striing);
}

void  DateAndPrice::isPriceValid(std::string &_price)
{
    isStringValid(_price);
    if (_price.empty() ||  !std::isdigit(_price[_price.size() - 1])) throw std::runtime_error("invalid number.");
    std::string::size_type dotPos = _price.find_first_of('.');
    if (dotPos == 0 || (dotPos != std::string::npos && _price.find_last_of('.') != dotPos))throw std::runtime_error("invalid number");
    std::istringstream ss(_price);
    ss >> price;
    if (!ss || !ss.eof()) throw std::runtime_error("invalid number.");
}

DateAndPrice::DateAndPrice(std::string& date, std::string& _price)
{
    isStringValid(date);
    if (date.size() != 10 || (date[4] != '-' || date[7] != '-')) throw std::runtime_error("bad input => " + date);
    std::stringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-') throw std::runtime_error("invalid date format => \"" + date + "\"");
    if (year < 0) throw std::runtime_error("invalid year => " + date);
    if (month < 1 || month > 12) throw std::runtime_error("invalid month => " + date);
    if (day < 1 || day > 31) throw std::runtime_error("invalid day => " + date);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("invalid day for month => " + date);
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && day > (isLeap ? 29 : 28))
        throw std::runtime_error("invalid day for February => " + date);
    if (date > getCurrentDate()) throw std::runtime_error("date is from the future.");
    isPriceValid(_price);
}

DateAndPrice::~DateAndPrice() {}

bool DateAndPrice::operator>(const DateAndPrice& D) const 
{
    if (year != D.year) return year > D.year;
    if (month != D.month) return month > D.month;
    return day > D.day;
}

bool DateAndPrice::operator>=(const DateAndPrice& D) const 
{
    return !(*this < D);
}

bool DateAndPrice::operator<(const DateAndPrice& D) const 
{
    if (year != D.year) return year < D.year;
    if (month != D.month) return month < D.month;
    return day < D.day;
}

bool DateAndPrice::operator<=(const DateAndPrice& D) const 
{
    return !(*this > D);
}

bool DateAndPrice::operator==(const DateAndPrice& D) const 
{
    return (year == D.year && month == D.month && day == D.day);
}

bool DateAndPrice::operator!=(const DateAndPrice& D) const 
{
    return !(*this == D);
}

int DateAndPrice::getDay( void ) const
{
    return (day);
}

int DateAndPrice::getMonth( void ) const
{
    return (month);
}

int DateAndPrice::getYear( void ) const
{
    return (year);
}

float  DateAndPrice::getPrice( void ) const
{
    return (price);
}

std::ostream& operator<<(std::ostream& os, const DateAndPrice& D)
{
    os << D.getYear() << "-" 
       << (D.getMonth() < 10 ? "0" : "") << D.getMonth() << "-"
       << (D.getDay() < 10 ? "0" : "") << D.getDay(); 
    return os;
}

#include <ctime>

std::string  getCurrentDate()
{
    std::time_t time = std::time(NULL);
    std::tm *localTime = std::localtime(&time);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
    return (std::string(buffer));
}
