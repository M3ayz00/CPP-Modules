#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
    private :
        std::stack<int> operands;
    public  :
        RPN();
        ~RPN();
        RPN(const RPN& r);
        RPN&  operator=(const RPN& r);
        int evaluate(const std::string& notation);
};