// Carson Gedeus, 11/13/2021

#include <iostream>
#include <cstdlib>

using namespace std;

class Team {

	public:
		Team();
		Team(int age, int number);
		friend Team operator +(const Team& a, const Team& b);
		void output(ostream& outs);

	private:
		int age;
		int number;
};

Team::Team() : age(0), number(0) {

	//Body intentionally blank.
}

Team::Team(int player_ages, int player_number) {

	age = player_ages;
	number = player_number;
}

Team operator +(const Team& a, const Team& b) {

	Team team;
	team.age = a.age + b.age;
	return team;
}

void Team::output(ostream& outs) {

	outs << "Team-mate: " << age << endl;
}

int main(void) {

	Team miami_heat(33, 5), ny_knicks(7, 23), total;

	total = miami_heat + ny_knicks;

	total.output(cout);

	return 0;
}