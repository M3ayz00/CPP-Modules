#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

class DateAndPrice;

class BitcoinExchange
{
  public  :
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& BE);
    BitcoinExchange&  operator=(const BitcoinExchange& BE);
    ~BitcoinExchange();

    bool  loadDatabase(const std::string& filename);
    bool  processInput(const std::string& filename);

  private :
    std::map<DateAndPrice, float> _database;
    void  calculateValue(const DateAndPrice& date, float value);
    const DateAndPrice&  getClosestDate(const DateAndPrice& targetDate);
};

bool  printError(const std::string& error);