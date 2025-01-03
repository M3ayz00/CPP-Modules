#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <set>

class DateAndPrice;

class BitcoinExchange
{
  public  :
    BitcoinExchange();
    ~BitcoinExchange();

    bool  loadDatabase(const std::string& filename);
    bool  processInput(const std::string& filename);

  private :
    BitcoinExchange(const BitcoinExchange& BE);
    BitcoinExchange&  operator=(const BitcoinExchange& BE);
    std::set<DateAndPrice> _database;
    void  calculateValue(const DateAndPrice& date);
    const DateAndPrice&  getClosestDate(const DateAndPrice& targetDate);
};

bool  printError(const std::string& error);