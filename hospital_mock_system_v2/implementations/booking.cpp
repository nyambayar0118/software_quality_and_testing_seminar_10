#include "doctor.h"
#include "patient.h"
#include "booking.h"

Booking::Booking(unsigned year, unsigned month, unsigned day, unsigned beginHour, unsigned beginMinute, unsigned endHour, unsigned endMinute, Patient *patient, Doctor *doctor) {

};

bool Booking::checkValidTime(unsigned beginHour, unsigned beginMinute, unsigned endHour, unsigned endMinute) {

};
bool Booking::checkValidDate(unsigned year, unsigned month, unsigned day) {

};
void Booking::printBooking() const {

};

//    // Get current time
// std::time_t t = std::time(nullptr);
// std::tm* now = std::localtime(&t);

// // Extract date components
// int year  = now->tm_year + 1900;  // tm_year is years since 1900
// int month = now->tm_mon + 1;      // tm_mon is 0–11
// int day   = now->tm_mday;         // tm_mday is 1–31
