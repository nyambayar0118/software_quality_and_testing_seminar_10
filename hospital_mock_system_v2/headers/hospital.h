#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include "human.h"
#include "doctor.h"
#include "patient.h"
#include "hospitalService.h"

class Hospital
{
private:
    // The hospital has a name
    std::string name;
    std::vector<Human *> people;   // All the patient
    std::vector<Doctor *> doctors; // All the doctors

    // A hospital service for doing all the logic
    HospitalService *service;

public:
    Hospital(std::string name, HospitalService *service);

    void addDoctor(Doctor *doctor);
    void addPatient(Patient *patient);
    void printAll() const;
    std::vector<Doctor *> getDoctors() const;

    friend class HospitalService;
};

#endif
