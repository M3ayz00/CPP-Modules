#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& BE) : _database(BE._database) {}

BitcoinExchange&  BitcoinExchange::operator=(const BitcoinExchange& BE)
{
    _database = BE._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


bool  BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Error opening database file\n";
        return false;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (isFirstLine)
        {
            if (line.find("date") != std::string::npos)
            {
                isFirstLine = false;
                continue;
            }
        }
        std::istringstream ss(line);
        std::string date, price;
        if (std::getline(ss, date, ',') && std::getline(ss, price))
        {
            if (date.empty() || price.empty()) return printError("invalid line in database.");
            double realPrice = strtod(price.c_str(), NULL);
            if (isDateValid(date) && realPrice >= 0)
                _database[date] = static_cast<float>(realPrice);
        }
        else
            printError("invalid line in database.");
    }
    file.close();
    if (_database.empty())
    {
        std::cout << "Error: database is empty or contains no valid entries.\n";
        return false;
    }
    return true;
}

bool  BitcoinExchange::printError(const std::string& error)
{
    std::cout << "Error: " << error << "\n";
    return false;
}

bool  BitcoinExchange::isDateValid(const std::string& date)
{
    // if (date[4] != '-' || date[7] != '-') return printError("bad input => " + date);
    std::stringstream ss(date);
    int mounth, day, year;
    char dash1, dash2;
    ss >> year >> dash1 >> mounth >> dash2 >> day;
    if (day < 1 || day > 31 || mounth < 1 || mounth > 12) return printError("bad input => " + date);
    if ((mounth == 4 || mounth == 6 || mounth == 9|| mounth == 11) && day > 30) return printError("bad input => " + date);
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (mounth == 2 && day > (isLeap ? 29 : 28)) return printError("bad input => " + date);
    return true;
}


bool  BitcoinExchange::isPriceValid(const std::string& value)
{
    char *end;
    double price = strtod(value.c_str(), &end);
    if (*end != '\0') return printError("not a valid number.");
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
    bool isFirstLine = true;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (isFirstLine)
        {
            if (line.find("date") != std::string::npos)
            {
                isFirstLine = false;
                continue;
            }
        }
        std::istringstream ss(line);
        std::string date, value;
        if (std::getline(ss, date, '|') && std::getline(ss, value))
        {
            if (date.empty() || value.empty()) return printError("invalid line in database.");
            if (isDateValid(date) && isPriceValid(value))
                calculateValue(date, strtod(value.c_str(), NULL));
        }
        else
            printError("invalid line in input.");
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
        std::ostringstream formattedRes;
        formattedRes << std::fixed << std::setprecision(3) << result;
        std::string finalOutput = formattedRes.str();
        size_t pos = finalOutput.find_last_not_of('0');
        if (pos != std::string::npos && finalOutput[pos] == '.')
            finalOutput.erase(pos);
        else
            finalOutput.erase(pos + 1);
        std::cout << closestDate << " => " << value << " = " << finalOutput << std::endl;
        
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
        throw std::runtime_error("Error: no earlier date exists in the database.");
    --it;
    return it->first;
}