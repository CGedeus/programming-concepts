// Carson Gedeus, 04/04/2020
// constructors.cpp
// Exmaples of various constructors in c-plus-plus 

#include <cstdio>
#include <string>

const int defaultAge = 0;
const std::string unknown = "unknown";

class Patient {

    public:
     int age;
     std::string dob;
     std::string name;

    public:
     Patient();                                                                      // Default Constructor
     Patient(int years, const std::string &birthdate, const std::string &aliase);    // Argument-List Constructor
     Patient(Patient &);
     Patient & operator = (const Patient &);
     void print();
};

Patient::Patient() : age(defaultAge), dob(unknown), name(unknown) {
    puts("Patient information from default constructor:");
}

Patient::Patient(int years, const std::string &birthdate, const std::string &aliase) 
: age(years), dob(birthdate), name(aliase) {
    puts("Patient information from move-constructor constructor:");
}

Patient::Patient(Patient &rValue) {
    puts("Patient information from copy constructor:");
    age  = 57;
    dob  = "January 21, 1963";
    name = "Hakeem Olajuwon";
}

void Patient::print() {
    printf(" Name - %d\n DOB  - %s\n Name - %s\n\n", age, dob.c_str(), name.c_str());
}

Patient &Patient::operator = (const Patient &rValue) {
    puts("Patient information from copy operator");
    if(this != &rValue) {
        age  = 72;
        dob  = "April 16, 1947";
        name = "Kareem Abdul-Jabbar";
    }
    return *this;
}

int main(void) {

    Patient p0;
    p0.print();
    
    Patient p1(57, "February 17, 1963", "Michael Jordan");
    p1.print();

    Patient p2 = p1;
    p2.print();

    p0 = p2;
    p2.print();
    
    return 0;
}
