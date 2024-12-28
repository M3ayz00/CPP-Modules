#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

class Date;

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
    std::map<Date, float> _database;
    bool  isPriceValid(const std::string& price);
    void  calculateValue(const Date& date, float value);
    const Date&  getClosestDate(const Date& targetDate);
};

bool  printError(const std::string& error);