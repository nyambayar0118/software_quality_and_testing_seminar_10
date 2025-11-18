#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include "Human.h"
#include "Doctor.h"
#include "Patient.h"
#include "Booking.h"

class Hospital
{
public:
    std::string name;

    std::vector<Human *> humans;
    std::vector<Doctor *> doctors;
    std::vector<Patient *> patients;
    std::vector<Booking *> bookings;

    Hospital(const std::string &name);
    void printHumans() const;
};

#endif
