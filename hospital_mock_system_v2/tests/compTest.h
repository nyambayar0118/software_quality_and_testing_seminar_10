#ifndef COMPTEST_H
#define COMPTEST_H

#include <cassert>
#include <iostream>
#include "../headers/hospital.h"
#include "../headers/hospitalService.h"
#include "../headers/doctor.h"
#include "../headers/patient.h"

using namespace std;

void runComponentTest()
{
    cout << "\n---------- Running Component / Interface Tests ----------\n";

    // ---------- Hospital Component / Interface ----------
    HospitalService service;
    Hospital hospital("Comp Test Hospital", &service);

    // Create and add doctors
    Doctor *d1 = new Doctor("Dr. Luffy", 40, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Law", 30, "Neurology");
    Doctor *d3 = new Doctor("Dr. Kid", 20, "Pediatrics"); // Should fail

    hospital.addDoctor(d1);
    hospital.addDoctor(d2);
    hospital.addDoctor(d3);

    // Create and add patients
    Patient *p1 = new Patient("Robin", 32, "Headache", "Neurology");
    Patient *p2 = new Patient("Chopper", 50, "Heart Problem", "Cardiology");
    Patient *p3 = new Patient("Doflamingo", 5, "Flu", "Pediatrics"); // Should fail

    hospital.addPatient(p1);
    hospital.addPatient(p2);
    hospital.addPatient(p3);

    // Print to check the data
    cout << "\nChecking polymorphic print:\n";
    hospital.printAll();

    // Check doctor count
    vector<Doctor *> docs = hospital.getDoctors();
    assert(docs.size() == 2);
    cout << "Doctor validation component passed.\n";

    delete d1;
    delete d2;
    delete d3;
    delete p1;
    delete p2;
    delete p3;

    cout << "All component tests passed successfully.\n";
}

#endif
