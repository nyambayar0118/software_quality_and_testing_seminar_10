#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <iostream>

// Abstract class
class Human
{
private:
    // Human has name and age
    std::string name;
    unsigned age;

public:
    Human();
    Human(std::string name, unsigned age);

    std::string getName() const;
    unsigned getAge() const;

    virtual void displayInfo() const = 0;
    virtual ~Human();
};

#endif
