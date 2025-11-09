#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HospitalService;

// ------------------ Human (Abstract Base Class) ------------------
class Human
{
private:
    string name;
    unsigned age;

public:
    Human() : name(""), age(0) {}
    Human(string name, unsigned age) : name(name), age(age) {}

    string getName() const { return name; }
    unsigned getAge() const { return age; }

    virtual void displayInfo() const = 0;
    virtual ~Human() {}
};

// ------------------ Patient ------------------
class Patient : public Human
{
private:
    string diagnosis;
    string needs; // type of doctor needed

public:
    Patient(string name, unsigned age, string diagnosis, string needs)
        : Human(name, age), diagnosis(diagnosis), needs(needs) {}

    string getDiagnosis() const { return diagnosis; }
    string getNeeds() const { return needs; }

    void displayInfo() const override
    {
        cout << "Patient: " << getName()
             << ", Age: " << getAge()
             << ", Diagnosis: " << diagnosis
             << ", Needs: " << needs << endl;
    }
};

// ------------------ Doctor ------------------
class Doctor : public Human
{
private:
    string expertise;

public:
    Doctor(string name, unsigned age, string expertise)
        : Human(name, age), expertise(expertise) {}

    string getExpertise() const { return expertise; }

    void displayInfo() const override
    {
        cout << "Doctor: " << getName()
             << ", Age: " << getAge()
             << ", Expertise: " << expertise << endl;
    }
};

// ------------------ Hospital ------------------
class Hospital
{
private:
    string name;
    vector<Human *> people;
    vector<Doctor *> doctors;
    HospitalService *service;

public:
    Hospital(string name, HospitalService *service)
        : name(name), service(service) {}

    void addDoctor(Doctor *doctor);
    void addPatient(Patient *patient);
    void printAll() const;
    vector<Doctor *> getDoctors() const { return doctors; }

    friend class HospitalService;
};

// ------------------ HospitalService ------------------
class HospitalService
{
public:
    bool checkDoctor(Doctor *doctor) const
    {
        // Doctor must be at least 25 years old
        return doctor && doctor->getAge() >= 25;
    }

    bool checkPatient(Patient *patient, const vector<Doctor *> &doctors) const
    {
        if (!patient)
            return false;
        for (auto d : doctors)
        {
            if (d->getExpertise() == patient->getNeeds())
            {
                return true;
            }
        }
        return false;
    }
};

// ------------------ Hospital Implementations ------------------
void Hospital::addDoctor(Doctor *doctor)
{
    if (service->checkDoctor(doctor))
    {
        doctors.push_back(doctor);
        people.push_back(doctor);
        cout << "Doctor " << doctor->getName()
             << " (" << doctor->getExpertise()
             << ") added to " << name << endl;
    }
    else
    {
        cout << "Doctor " << doctor->getName()
             << " is too young to join the hospital." << endl;
    }
}

void Hospital::addPatient(Patient *patient)
{
    if (service->checkPatient(patient, doctors))
    {
        people.push_back(patient);
        cout << "Patient " << patient->getName()
             << " (needs: " << patient->getNeeds()
             << ") added to " << name << endl;
    }
    else
    {
        cout << "Patient " << patient->getName()
             << " could not be added — no doctor with expertise in '"
             << patient->getNeeds() << "' available." << endl;
    }
}

void Hospital::printAll() const
{
    cout << "\n--- People in " << name << " ---" << endl;
    for (auto person : people)
    {
        person->displayInfo();
    }
}

// ------------------ main ------------------
int main()
{
    HospitalService service;
    Hospital hospital("CityCare Hospital", &service);

    Doctor *d1 = new Doctor("Dr. Watson", 40, "Cardiology");
    Doctor *d2 = new Doctor("Dr. Brown", 22, "Pediatrics"); // too young
    Doctor *d3 = new Doctor("Dr. Grey", 36, "Neurology");

    hospital.addDoctor(d1);
    hospital.addDoctor(d2);
    hospital.addDoctor(d3);

    Patient *p1 = new Patient("John Doe", 45, "Heart Disease", "Cardiology");
    Patient *p2 = new Patient("Alice Green", 30, "Flu", "Pediatrics");
    Patient *p3 = new Patient("Sam Blue", 29, "Headache", "Neurology");

    hospital.addPatient(p1);
    hospital.addPatient(p2);
    hospital.addPatient(p3);

    hospital.printAll();

    delete d1;
    delete d2;
    delete d3;
    delete p1;
    delete p2;
    delete p3;

    return 0;
}
