#include <cassert>
#include <iostream>
#include "imp.h"

using namespace std;

// ---------- Human Tests ----------
void testHumanPolymorphism()
{
    Human *d = new Doctor("Dr. Watson", 50, "Cardiology");
    Human *p = new Patient("John Doe", 40, "Flu", "Pediatrics");

    d->displayInfo();
    p->displayInfo();

    assert(d->getName() == "Dr. Watson");
    assert(p->getName() == "John Doe");

    assert(d->getAge() == 50);
    assert(p->getAge() == 40);

    delete d;
    delete p;

    cout << "testHumanPolymorphism passed.\n";
}

// ---------- Doctor Tests ----------
void testDoctor()
{
    Doctor d("Dr. Grey", 36, "Neurology");
    assert(d.getName() == "Dr. Grey");
    assert(d.getAge() == 36);
    assert(d.getExpertise() == "Neurology");
    cout << "testDoctor passed.\n";
}

// ---------- Patient Tests ----------
void testPatient()
{
    Patient p("Alice", 28, "Cold", "Pediatrics");
    assert(p.getName() == "Alice");
    assert(p.getAge() == 28);
    assert(p.getDiagnosis() == "Cold");
    assert(p.getNeeds() == "Pediatrics");
    cout << "testPatient passed.\n";
}

// ---------- HospitalService Tests ----------
void testHospitalService()
{
    HospitalService service;
    Doctor good("Dr. Brown", 30, "Cardiology");
    Doctor young("Dr. Kid", 22, "Dermatology");

    assert(service.checkDoctor(&good));
    assert(!service.checkDoctor(&young));

    vector<Doctor *> doctors = {&good};
    Patient p1("John", 45, "Heart", "Cardiology");
    Patient p2("Alice", 30, "Flu", "Pediatrics");

    assert(service.checkPatient(&p1, doctors));
    assert(!service.checkPatient(&p2, doctors));

    cout << "testHospitalService passed.\n";
}

// ---------- Hospital Tests ----------
void testHospital()
{
    HospitalService service;
    Hospital hospital("Test Hospital", &service);

    Doctor *d1 = new Doctor("Dr. Old", 40, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Young", 22, "Neurology");

    hospital.addDoctor(d1);
    hospital.addDoctor(d2);

    vector<Doctor *> docs = hospital.getDoctors();
    assert(docs.size() == 1);
    assert(docs[0]->getExpertise() == "Cardiology");

    Patient *p1 = new Patient("John", 45, "Heart", "Cardiology");
    Patient *p2 = new Patient("Alice", 30, "Flu", "Pediatrics");

    hospital.addPatient(p1);
    hospital.addPatient(p2);

    hospital.printAll();

    delete d1;
    delete d2;
    delete p1;
    delete p2;

    cout << "testHospital passed.\n";
}

// ---------- main ----------
int main()
{
    cout << "--- Running Unit Tests ---\n";
    testHumanPolymorphism();
    testDoctor();
    testPatient();
    testHospitalService();
    testHospital();
    cout << "All unit tests passed successfully.\n";
    return 0;
}
