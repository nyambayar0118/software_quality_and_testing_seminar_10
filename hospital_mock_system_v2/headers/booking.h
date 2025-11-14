#ifndef BOOKING_H
#define BOOKING_H

#include "doctor.h"
#include "patient.h"

class Booking
{
private:
    // The booking has a date and time
    unsigned year;
    unsigned month;
    unsigned day;

    unsigned beginHour;
    unsigned beginMinute;

    unsigned endHour;
    unsigned endMinute;

    Patient *patient; // Patient who is booking the time
    Doctor *doctor;   // The doctor who was chosen

public:
    Booking(unsigned year, unsigned month, unsigned day, unsigned beginHour, unsigned beginMinute, unsigned endHour, unsigned endMinute, Patient *patient, Doctor *doctor);

    bool checkValidTime(unsigned beginHour, unsigned beginMinute, unsigned endHour, unsigned endMinute);
    bool checkValidDate(unsigned year, unsigned month, unsigned day);
    void printBooking() const;
};

#endif
