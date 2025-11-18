#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Patient.h"
#include "Doctor.h"

class Booking
{
private:
    unsigned year, month, day;
    unsigned beginHour, beginMinute;
    unsigned endHour, endMinute;

    Patient *patient;
    Doctor *doctor;

public:
    Booking(unsigned year, unsigned month, unsigned day,
            unsigned beginHour, unsigned beginMinute,
            unsigned endHour, unsigned endMinute,
            Patient *patient, Doctor *doctor);

    Patient *getPatient() const;
    Doctor *getDoctor() const;

    bool isValidTime() const;
    bool isValidDate() const;

    int getStartMinutes() const;
    int getEndMinutes() const;

    unsigned getYear() const;
    unsigned getMonth() const;
    unsigned getDay() const;

    void printBooking() const;
};

#endif
