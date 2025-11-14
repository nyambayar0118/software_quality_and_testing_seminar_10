#include "./headers/human.h"
#include "./headers/doctor.h"
#include "./headers/patient.h"
#include "./headers/hospital.h"
#include "./tests/unitTest.h"
#include "./tests/compTest.h"

int main()
{
    // Run tests
    runUnitTest();
    runComponentTest();

    // Run main
    std::cout << "\n===== Running System =====\n";

    HospitalService service;
    Hospital hospital("EmGiEl Hospital", &service);

    Doctor *d1 = new Doctor("Dr. Lovenstein", 40, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Murphy", 22, "Pediatrics"); // too young
    Doctor *d3 = new Doctor("Dr. Who", 36, "Neurology");

    hospital.addDoctor(d1);
    hospital.addDoctor(d2);
    hospital.addDoctor(d3);

    Patient *p1 = new Patient("Alastor", 45, "Heart Disease", "Cardiology");
    Patient *p2 = new Patient("Rick", 30, "Flu", "Pediatrics");
    Patient *p3 = new Patient("Trump", 29, "Headache", "Neurology");

    hospital.addPatient(p1);
    hospital.addPatient(p2);
    hospital.addPatient(p3);

    hospital.printAll();

    // Cleanup
    delete d1;
    delete d2;
    delete d3;
    delete p1;
    delete p2;
    delete p3;

    std::cout << "\n===== System is functional =====\n";
    return 0;
}
