#include <cassert>
#include <iostream>

#include "./headers/Hospital.h"
#include "./headers/PeopleManager.h"
#include "./headers/BookingManager.h"
#include "./headers/Doctor.h"
#include "./headers/Patient.h"
#include "./headers/Booking.h"

using namespace std;

// g++ main.cpp implementations/*.cpp -Iheaders -o main

void testAddDoctor()
{
    cout << "\n=== TEST: Add Doctors ===\n";

    Hospital h("EmGiEl Hospital");
    PeopleManager pm;

    Doctor *d1 = new Doctor("Dr. Who", 30, "Cardiology");
    Doctor *d2 = new Doctor("Resident", 20, "Neurology");

    // test accepted doctor
    bool result1 = pm.addDoctor(&h, d1);
    assert(result1 == true);
    assert(h.doctors.size() == 1);

    // test rejected doctor
    bool result2 = pm.addDoctor(&h, d2);
    assert(result2 == false);
    assert(h.doctors.size() == 1);

    cout << "+++ Doctor tests passed.\n";

    delete d1;
    delete d2;
}

void testAddPatient()
{
    cout << "\n=== TEST: Add Patient ===\n";

    Hospital h("EmGiEl Hospital");
    PeopleManager pm;

    Doctor *d1 = new Doctor("Dr. Murphy", 40, "Cardiology");
    pm.addDoctor(&h, d1);

    Patient *p1 = new Patient("Elisabeth", 50, "Heart Issue", "Cardiology");
    Patient *p2 = new Patient("Jack Sparrow", 25, "Brain Issue", "Neurology");

    // patient 1 should succeed
    bool result1 = pm.addPatient(&h, p1);
    assert(result1 == true);
    assert(h.patients.size() == 1);

    // patient 2 fails — no Neurology doctor
    bool result2 = pm.addPatient(&h, p2);
    assert(result2 == false);
    assert(h.patients.size() == 1);

    cout << "+++ Patient tests passed.\n";

    delete d1;
    delete p1;
    delete p2;
}

void testAddBooking()
{
    cout << "\n=== TEST: Add Booking ===\n";

    Hospital h("EmGiEl Hospital");
    PeopleManager pm;
    BookingManager bm;

    Doctor *d1 = new Doctor("Dr. Robotnik", 40, "Neurology");
    pm.addDoctor(&h, d1);

    Patient *p1 = new Patient("Sonic", 30, "Headache", "Neurology");
    pm.addPatient(&h, p1);

    // Valid booking: 10:00–11:00
    Booking *b1 = new Booking(2025, 11, 20, 10, 0, 11, 0, p1, d1);
    bool added1 = bm.addBooking(&h, b1);
    assert(added1 == true);
    assert(h.bookings.size() == 1);

    // Conflict booking: 10:30–11:30 (overlaps)
    Booking *b2 = new Booking(2025, 11, 20, 10, 30, 11, 30, p1, d1);
    bool added2 = bm.addBooking(&h, b2);
    assert(added2 == false);
    assert(h.bookings.size() == 1);

    // Valid booking: 11:00–12:00
    Booking *b3 = new Booking(2025, 11, 20, 11, 0, 12, 0, p1, d1);
    bool added3 = bm.addBooking(&h, b3);
    assert(added3 == true);
    assert(h.bookings.size() == 2);

    cout << "+++ Booking tests passed.\n";

    delete d1;
    delete p1;
    delete b1;
    delete b2;
    delete b3;
}

int main()
{
    testAddDoctor();
    testAddPatient();
    testAddBooking();

    cout << "\n============ ALL TESTS PASSED SUCCESSFULLY! ============\n";

    return 0;
}
