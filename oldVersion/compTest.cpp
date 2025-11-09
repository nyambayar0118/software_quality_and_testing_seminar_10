#include <cassert>
#include <iostream>
#include "imp.h"
using namespace std;

void testDoctorValidationComponent()
{
    HospitalService service;
    Hospital hospital("Component Hospital", &service);

    Doctor *d1 = new Doctor("Dr. Valid", 45, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Invalid", 21, "Neurology");

    hospital.addDoctor(d1);
    hospital.addDoctor(d2);

    vector<Doctor *> docs = hospital.getDoctors();
    assert(docs.size() == 1);
    assert(docs[0]->getExpertise() == "Cardiology");

    delete d1;
    delete d2;
    cout << "testDoctorValidationComponent passed.\n";
}

void testPatientDoctorMatchingComponent()
{
    HospitalService service;
    Hospital hospital("Matching Hospital", &service);

    Doctor *d1 = new Doctor("Dr. Heart", 35, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Neuro", 33, "Neurology");
    hospital.addDoctor(d1);
    hospital.addDoctor(d2);

    Patient *p1 = new Patient("John", 50, "Heart Pain", "Cardiology");
    Patient *p2 = new Patient("Sam", 28, "Headache", "Neurology");
    Patient *p3 = new Patient("Alice", 25, "Flu", "Pediatrics"); // should fail

    hospital.addPatient(p1);
    hospital.addPatient(p2);
    hospital.addPatient(p3);

    hospital.printAll();

    delete d1;
    delete d2;
    delete p1;
    delete p2;
    delete p3;

    cout << "testPatientDoctorMatchingComponent passed.\n";
}

void testPolymorphicDisplayComponent()
{
    HospitalService service;
    Hospital hospital("Display Test", &service);

    Doctor *d = new Doctor("Dr. Poly", 40, "General");
    Patient *p = new Patient("John Poly", 35, "Cold", "General");

    hospital.addDoctor(d);
    hospital.addPatient(p);

    cout << "\nExpected polymorphic output:\n";
    hospital.printAll();

    delete d;
    delete p;
    cout << "testPolymorphicDisplayComponent passed.\n";
}

int main()
{
    cout << "--- Running Component / Interface Tests ---\n";
    testDoctorValidationComponent();
    testPatientDoctorMatchingComponent();
    testPolymorphicDisplayComponent();
    cout << "All component/interface tests passed successfully.\n";
    return 0;
}
