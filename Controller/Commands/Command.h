//
// Created by ahmad on 12/29/18.
//

#ifndef DNAPROJECT_COMMAND_H
#define DNAPROJECT_COMMAND_H

#include <string>
#include <vector>
#include "../../Model/SharedPtr.h"
#include "../DnaAnalyzer.h"


using namespace std;

class Command {
public:
    static SharedPtr<Command> makeCommand(const string &command);

    virtual string execute(vector<string> &strs, SharedPtr<DnaAnalyzer> dna_analyzer) = 0;

    virtual ~Command() {};


};


#endif //DNAPROJECT_COMMAND_H





#ifndef DESIGN_PATTERNS_DECORATOR_H
#define DESIGN_PATTERNS_DECORATOR_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class YummyDessert
{
public:
    virtual void order() = 0;
};


class IceCream : public YummyDessert
{
public:
    void order() { cout << "Order an Ice Cream"; }
};


class YummyDecorator : public YummyDessert
{
public:
    YummyDecorator(YummyDessert* dessert) : m_pDessert(dessert) {}
    void order() { m_pDessert->order(); }

private:
    YummyDessert* m_pDessert;
};


class WithHotChocolate : public YummyDecorator
{
public:
    WithHotChocolate(YummyDessert* dessert) : YummyDecorator(dessert) {}

    void order()
    {
        YummyDecorator::order();
        cout << " with hot chocolate";
    }
};


class WithColorfulCandies : public YummyDecorator
{
public:
    WithColorfulCandies(YummyDessert* dessert) : YummyDecorator(dessert) {}

    void order()
    {
        YummyDecorator::order();
        cout << " with colorful candies";
    }
};


class WithFalafel: public YummyDecorator
{
public:
    WithFalafel(YummyDessert* dessert) : YummyDecorator(dessert) {}

    void order()
    {
        YummyDecorator::order();
        cout << " with falafel";
    }
};

#endif //DESIGN_PATTERNS_DECORATOR_H


