// Carson Gedeus, Lecture 17

#include <iostream>

using namespace std;

class Money {

    public:
        Money();
        Money(double);
        
        friend istream& operator >>(istream&, Money&);
        friend ostream& operator <<(ostream&, Money&);
        friend double operator *(Money&, double);

    private:
        double money;
};

Money::Money() : money(0) {
    //EMPTY
}

Money::Money(double money_in) {
    
    money = money_in;
}

istream& operator >>(istream& ins, Money& money1) {

    ins >> money1.money;
    return ins;
}

ostream& operator <<(ostream& outs, Money& money1) {

    outs << money1.money;
    return outs;
}

double operator *(Money& money1, double two) {
    return (money1.money * two);
}

int main(void) {
    
    Money cash[5];
    
    for (int i = 0; i < 5; i++) {

        cin >> cash[i];
        cash[i] = cash[i] * 2;
        cout << cash[i] << endl;
    }

    return 0;
}