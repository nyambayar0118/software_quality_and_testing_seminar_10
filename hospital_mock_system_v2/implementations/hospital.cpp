#include "Hospital.h"

Hospital::Hospital(const std::string &name) : name(name) {}

void Hospital::printHumans() const
{
    for (auto h : humans)
        h->displayInfo();
}
