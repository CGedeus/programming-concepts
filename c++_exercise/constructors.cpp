// Carson Gedeus, 04/04/2020
// constructors.cpp
// Exmaples of various constructors in c-plus-plus 

#include <cstdio>
#include <string>

const int defaultAge = 0;
const std::string unknown = "unknown";

class Player {

    public:
     int age;
     std::string dob;
     std::string name;

    public:
     Player();                                                                      // Default Constructor
     Player(int years, const std::string &birthdate, const std::string &aliase);    // Argument-List Constructor
     Player(Player &);
     Player & operator = (const Player &);
     void print();
};

Player::Player() : age(defaultAge), dob(unknown), name(unknown) {
    puts("Player information from default constructor:");
}

Player::Player(int years, const std::string &birthdate, const std::string &aliase) 
: age(years), dob(birthdate), name(aliase) {
    puts("Player information from move-constructor constructor:");
}

Player::Player(Player &rValue) {
    puts("Player information from copy constructor:");
    age  = 57;
    dob  = "January 21, 1963";
    name = "Hakeem Olajuwon";
}

void Player::print() {
    printf(" Name - %d\n DOB  - %s\n Name - %s\n\n", age, dob.c_str(), name.c_str());
}

Player &Player::operator = (const Player &rValue) {
    puts("Player information from copy operator");
    if(this != &rValue) {
        age  = 72;
        dob  = "April 16, 1947";
        name = "Kareem Abdul-Jabbar";
    }
    return *this;
}

int main(void) {

    Player p0;
    p0.print();
    
    Player p1(57, "February 17, 1963", "Michael Jordan");
    p1.print();

    Player p2 = p1;
    p2.print();

    p0 = p2;
    p2.print();
    
    return 0;
}
