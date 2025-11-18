#include "BookingManager.h"

bool BookingManager::hasConflict(Hospital *hospital, Booking *b) const
{
    for (auto existing : hospital->bookings)
    {
        // Only check bookings for the SAME doctor
        if (existing->getDoctor() != b->getDoctor())
            continue;

        // Only check bookings for the SAME day
        if (existing->getYear() != b->getYear() ||
            existing->getMonth() != b->getMonth() ||
            existing->getDay() != b->getDay())
            continue;

        int start1 = existing->getStartMinutes();
        int end1 = existing->getEndMinutes();
        int start2 = b->getStartMinutes();
        int end2 = b->getEndMinutes();

        // Overlap condition:
        if (start1 < end2 && start2 < end1)
        {
            return true; // conflict found
        }
    }

    return false; // no conflicts
}

bool BookingManager::addBooking(Hospital *h, Booking *b)
{
    if (!b->isValidDate() || !b->isValidTime())
        return false;

    if (hasConflict(h, b))
        return false;

    h->bookings.push_back(b);
    return true;
}
