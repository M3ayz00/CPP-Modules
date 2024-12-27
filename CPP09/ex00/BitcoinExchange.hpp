#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

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
    std::map<std::string, float> _database;
    bool  isDateValid(const std::string& date);
    bool  isPriceValid(float price);
    void  calculateValue(const std::string& _date, float value);
    const std::string&  getClosestDate(const std::string& targetDate);
    bool  printError(const std::string& error);
};