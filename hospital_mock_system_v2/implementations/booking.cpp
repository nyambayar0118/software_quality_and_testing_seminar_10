#include "Booking.h"
#include <iostream>

Booking::Booking(unsigned year, unsigned month, unsigned day,
                 unsigned beginHour, unsigned beginMinute,
                 unsigned endHour, unsigned endMinute,
                 Patient *patient, Doctor *doctor)
    : year(year), month(month), day(day),
      beginHour(beginHour), beginMinute(beginMinute),
      endHour(endHour), endMinute(endMinute),
      patient(patient), doctor(doctor) {}

Patient *Booking::getPatient() const { return patient; }
Doctor *Booking::getDoctor() const { return doctor; }

bool Booking::isValidDate() const
{
    return (year >= 2025 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

bool Booking::isValidTime() const
{
    if (beginHour > 23 || beginMinute > 59)
        return false;
    if (endHour > 23 || endMinute > 59)
        return false;

    if (endHour < beginHour)
        return false;
    if (endHour == beginHour && endMinute <= beginMinute)
        return false;

    return true;
}

int Booking::getStartMinutes() const
{
    return beginHour * 60 + beginMinute;
}

int Booking::getEndMinutes() const
{
    return endHour * 60 + endMinute;
}

unsigned Booking::getYear() const
{
    return year;
}

unsigned Booking::getMonth() const
{
    return month;
}

unsigned Booking::getDay() const
{
    return day;
}

void Booking::printBooking() const
{
    std::cout << "Booking: " << year << "-" << month << "-" << day
              << " | " << beginHour << ":" << beginMinute
              << " - " << endHour << ":" << endMinute
              << "\nDoctor: " << doctor->getName()
              << "\nPatient: " << patient->getName() << "\n";
}
