#include "BitcoinExchange.hpp"
#include "Date.hpp"
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
            try
            {
                _database[Date(date)] = static_cast<float>(realPrice);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
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

bool  printError(const std::string& error)
{
    std::cout << "Error: " << error << "\n";
    return false;
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
        std::getline(ss, date, '|');
        std::getline(ss, value);
        if (date.empty() || value.empty()) return printError("bad input => " + date);
        try
        {
            Date _date(date);
            if (isPriceValid(value))
                calculateValue(_date, strtod(value.c_str(), NULL));
        }
        catch(const std::exception& e)
        {
            printError(e.what());
        }
    }
    file.close();
    return true;
}

void  BitcoinExchange::calculateValue(const Date& date, float value)
{
    try
    {
        Date closestDate = getClosestDate(date);
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
        std::cout << date << " => " << value << " = " << finalOutput << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const Date&  BitcoinExchange::getClosestDate(const Date& targetDate)
{
    std::map<Date, float>::const_iterator it = _database.lower_bound(targetDate);
    if ((it != _database.end() && it->first == targetDate))
        return it->first;
    if (it == _database.begin())
        throw std::runtime_error("Error: no earlier date exists in the database.");
    --it;
    return it->first;
}