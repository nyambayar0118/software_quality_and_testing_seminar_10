#ifndef BOOKING_MANAGER_H
#define BOOKING_MANAGER_H

#include "Hospital.h"

class BookingManager
{
public:
    bool addBooking(Hospital *hospital, Booking *booking);

    bool hasConflict(Hospital *hospital, Booking *booking) const;
};

#endif
