// Carson Gedeus, 10/29/2022
// Friend Functions

#include <iostream>

using namespace std;

class DayOfYear {

	public:
		friend bool equal(DayOfYear d1, DayOfYear d2);

	private:
		int day;
		int month;
};

int main(void) {

	DayOfYear day1, day2;

	cout << equal(day1, day2) << endl;
	return 0;
}

bool equal(DayOfYear d1, DayOfYear d2) {

	d1.day = 6;
	d1.month = 11;

	d2.day = 3;
	d2.month = 5;

	return (d1.month == d2.month && d1.day == d2.day);
}
