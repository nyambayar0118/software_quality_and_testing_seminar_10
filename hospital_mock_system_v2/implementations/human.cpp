#include "Human.h"

Human::Human() : name(""), age(0) {}
Human::Human(const std::string &name, unsigned age) : name(name), age(age) {}

std::string Human::getName() const { return name; }
unsigned Human::getAge() const { return age; }
