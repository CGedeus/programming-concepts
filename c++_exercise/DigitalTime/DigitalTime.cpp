#include <iostream>
#include <cctype>
#include <cstdlib>
#include "DigitalTime.h"

using namespace std;

void read_hours(istream& ins, int& the_hour);
void read_minute(istream& ins, int& the_moinute);
int digit_to_int(char c);

bool operator ==(const DigitalTime& time1, const DigitalTime& time2) {

	return (time1.hour == time2.hour && time1.minute == time2.minute);
}

DigitalTime::DigitalTime(int the_hour, int the_minute) {

	if (the_hour < 0 || the_hour > 23 || the_minute < 0 || the_minute > 59) {

		cout << "Illegal argument to DigitalTime constructor" << endl;
		exit(1);
	}
	else {

		hour = the_hour;
		minute = the_minute;
	}
}

DigitalTime::DigitalTime() : hour(0), minute(0) {
	// EMPTY
}

void DigitalTime::advance(int minutes_added) {

	int gross_minute = minute + minutes_added;
	minute = gross_minute%60;

	int hour_adjustment = gross_minute / 60;
	hour = (hour + hour_adjustment)%24;
}

void DigitalTime::advance(int hours_added, int minutes_added) {

	hour = (hour + hours_added)%24;
	advance(minutes_added);
}

ostream& operator <<(ostream& outs, const DigitalTime& the_object) {

	outs << the_object.hour << ":";
	if (the_object.minute < 10) {
		outs << '0';
	}
	outs << the_object.minute;
	return outs;
}

istream& operator >>(istream& ins, DigitalTime& the_object) {

	read_hours(ins, the_object.hour);
	read_minute(ins, the_object.minute);
	return ins;
}

int digit_to_int(char c) {
	return (int(c) - int('0'));
}

void read_minute(istream& ins, int& the_minute) {

	char c1, c2;
	ins >> c1 >> c2;

	if (!(isdigit(c1) && isdigit(c2))) {

		cout << "Error illegal input to read_minute"  << endl;
		exit(1);
	}

	the_minute = digit_to_int(c1) * 10 + digit_to_int(c2);

	if (the_minute < 0 || the_minute > 59) {

		cout << "Error illegal input to read_minute" << endl;
		exit(1);
	}
}

void read_hours(istream& ins, int& the_hour) {

	char c1, c2;
	ins >> c1 >> c2;

	if (!(isdigit(c1) && (isdigit(c2) || c2 == ':'))) {

		cout << "Error illegal input to read_minute" << endl;
		exit(1);
	}

	else {//(isdigit(c1) && isdigit(c2))

		the_hour = digit_to_int(c1) * 10 + digit_to_int(c2);
		ins >> c2;

		if (c2 != ':') {

			cout << "Error illegal input to read_minute" << endl;
			exit(1);
		}
	}

	if (the_hour < 0 || the_hour > 23) {

		cout << "Error illegal input to read_minute" << endl;
		exit(1);
	}
}