#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& BE) : _database(BE._database) {}

BitcoinExchange&  BitcoinExchange::operator=(const BitcoinExchange& BE)
{
    _database = BE._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    _database.clear();
}


bool  BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Error opening database file\n";
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        float price;
        std::getline(ss, date, ',');
        ss >> price;
        if (isDateValid(date) && price > 0)
            _database[date] = price;
        // std::cout << date << "  " << price << '\n';
    }
    file.close();
    return true;
}

bool  BitcoinExchange::printError(const std::string& error)
{
    std::cout << "Error: " << error << "\n";
    return false;
}

bool  BitcoinExchange::isDateValid(const std::string& date)
{
    if (date[4] != '-' || date[7] != '-') return printError("bad input => " + date);
    std::stringstream ss(date);
    int mounth, day, year;
    char dash1, dash2;
    ss >> year >> dash1 >> mounth >> dash2 >> day;
    if (day < 1 || day > 31 || mounth < 1 || mounth > 12) return printError("bad input => " + date);
    return true;
}

bool  BitcoinExchange::isPriceValid(float price)
{
    if (price < 0) return printError("not a positive number.");
    if (price > 1000) return printError("too large a number.");
    return true;
}

bool  BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Error opening input file\n";
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        float value;
        std::getline(ss, date, '|');
        ss >> value;
        if (isDateValid(date) && isPriceValid(value))
            calculateValue(date, value);
    }
    file.close();
    return true;
}

void  BitcoinExchange::calculateValue(const std::string& _date, float value)
{
    try
    {
        std::string closestDate = getClosestDate(_date);
        float exchangeRate = _database[closestDate];
        float result = value * exchangeRate;
        std::cout << closestDate << " => " << value << " = " << std::fixed << std::setprecision(3) << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const std::string&  BitcoinExchange::getClosestDate(const std::string& targetDate)
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(targetDate);
    if ((it != _database.end() && it->first == targetDate))
        return it->first;
    if (it == _database.begin())
        throw std::runtime_error("Error: No earlier date exists in the database.");
    --it;
    return it->first;
}