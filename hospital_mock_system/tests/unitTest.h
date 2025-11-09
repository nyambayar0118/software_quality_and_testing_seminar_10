#ifndef UNITTEST_H
#define UNITTEST_H

#include <cassert>
#include <iostream>
#include "../headers/human.h"
#include "../headers/doctor.h"
#include "../headers/patient.h"
#include "../headers/hospital.h"
#include "../headers/hospitalService.h"

using namespace std;

void runUnitTest()
{
    cout << "\n---------- Running Unit Tests ----------\n";

    // ---------- Human Unit (Polymorphism) ----------
    Human *h1 = new Doctor("Dr. Ken Takakura", 45, "Cardiology");
    Human *h2 = new Patient("Momo", 30, "Cold", "Pediatrics");

    assert(h1->getName() == "Dr. Ken Takakura");
    assert(h2->getAge() == 30);
    cout << "Human polymorphism test passed.\n";

    delete h1;
    delete h2;

    // ---------- Doctor Unit ----------
    Doctor d("Dr. Turbo Granny", 40, "Neurology");
    assert(d.getExpertise() == "Neurology");
    cout << "Doctor test passed.\n";

    // ---------- Patient Unit ----------
    Patient p("Jiji", 25, "Flu", "General");
    assert(p.getDiagnosis() == "Flu");
    assert(p.getNeeds() == "General");
    cout << "Patient test passed.\n";

    // ---------- HospitalService Unit ----------
    HospitalService service;
    Doctor d1("Dr. Naruto", 35, "Cardiology");
    Doctor d2("Dr. Boruto", 22, "Neurology");

    assert(service.checkDoctor(&d1));
    assert(!service.checkDoctor(&d2));
    cout << "HospitalService doctor check passed.\n";

    vector<Doctor *> docs = {&d1};
    Patient valid("Sakura", 40, "Heart", "Cardiology");
    Patient invalid("Sasuke", 22, "Cold", "Pediatrics");

    assert(service.checkPatient(&valid, docs));
    assert(!service.checkPatient(&invalid, docs));
    cout << "HospitalService patient check passed.\n";

    cout << "All unit tests passed successfully.\n";
}

#endif
