#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
protected:
    std::string name;
    unsigned age;

public:
    Human();
    Human(const std::string &name, unsigned age);

    std::string getName() const;
    unsigned getAge() const;

    virtual void displayInfo() const = 0; // abstract

    virtual ~Human() {}
};

#endif
