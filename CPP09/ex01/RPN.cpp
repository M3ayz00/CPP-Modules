#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& r): operands(r.operands) {}

RPN&  RPN::operator=(const RPN& r)
{
    if (this != &r)
        operands = r.operands;
    return *this;
}

int RPN::evaluate(const std::string& notation)
{
    std::istringstream ss(notation);
    std::string token;
    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            operands.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "/" || token == "*") 
        {
            if (operands.size() < 2)
                throw std::runtime_error("Error");
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            if (token == "+") operands.push(a + b);
            if (token == "-") operands.push(a - b);
            if (token == "*") operands.push(a * b);
            if (token == "/")
            {
                if (b == 0) throw std::runtime_error("Error: division by zero");
                operands.push(a / b);
            }
        }
        else
            throw std::runtime_error("Error");
    }
    if (operands.size() != 1)
        throw std::runtime_error("Error");
    return operands.top();
}
