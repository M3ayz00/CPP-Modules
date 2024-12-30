#include "BitcoinExchange.hpp"
#include "DateAndPrice.hpp"

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
            isFirstLine = false;
            if (line.find("date") != std::string::npos)
                continue;
        }
        std::istringstream ss(line);
        std::string date, price;
        if (std::getline(ss, date, ',') && std::getline(ss, price))
        {
            try
            {
                DateAndPrice actualDate(date, price);
                _database.insert(actualDate);
            }
            catch(const std::exception& e)
            {
                printError(e.what());
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
            isFirstLine = false;
            if (line.find("date") != std::string::npos)
                continue;
        }
        std::istringstream ss(line);
        std::string date, value;
        std::getline(ss, date, '|');
        std::getline(ss, value);
        try
        {
            DateAndPrice _date(date, value);
            calculateValue(_date, _date.getPrice());
        }
        catch(const std::exception& e)
        {
            printError(e.what());
        }
    }
    file.close();
    return true;
}

void  BitcoinExchange::calculateValue(const DateAndPrice& date, float value)
{
    try
    {
        if (date.getPrice() < 0) throw std::runtime_error("not a positive number.");
        if (date.getPrice() > 1000) throw std::runtime_error("too large a number.");
        DateAndPrice closestDate = getClosestDate(date);
        std::ostringstream formattedRes;
        formattedRes << std::fixed << std::setprecision(3) << value * closestDate.getPrice();
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
        printError(e.what());
    }
}

const DateAndPrice&  BitcoinExchange::getClosestDate(const DateAndPrice& targetDate)
{
    std::set<DateAndPrice>::const_iterator it = _database.lower_bound(targetDate);
    if ((it != _database.end() && *it == targetDate))
        return *it;
    if (it == _database.begin())
        throw std::runtime_error("no earlier date exists in the database.");
    --it;
    return *it;
}