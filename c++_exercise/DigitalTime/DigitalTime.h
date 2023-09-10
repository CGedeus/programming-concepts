#pragma once
#include <iostream>

using namespace std;

class DigitalTime {

	public:
		DigitalTime(int the_hour, int the_minute);
		DigitalTime();
		void advance(int minutes_added);
		void advance(int minutes_added, int hours_added);
		friend istream& operator >>(istream& ins, DigitalTime& the_object);
		friend ostream& operator <<(ostream& ins, const DigitalTime& the_object);
		friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
		// public indictes this is part of the INTERFACE

	private:
		int hour;
		int minute;
		// private indicates this is part of the IMPLEMENTATION
};