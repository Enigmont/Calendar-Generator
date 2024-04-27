#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int index;
unsigned int year;
int month;
string day_of_week;
vector<string> monthVec = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
vector<string> dayVec = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {

	//User input
	cout << "Please enter year (YYYY): " << endl;
	cin >> year;
	cout << "Please enter month (MM): " << endl;
	cin >> month;
	cout << "Please enter first day-of-week (SUN): " << endl;
	cin >> day_of_week;

	//Capitalizes day of week to match vector
	transform(day_of_week.begin(), day_of_week.end(), day_of_week.begin(), toupper);
	cout << endl;

	//Finds first day of week and converts to integer for processing the days of the calendar
	auto it = find(dayVec.begin(), dayVec.end(), day_of_week);
	if (it != dayVec.end()) {
		index = distance(dayVec.begin(), it);
	}

	//Center align Month and Year
	string yearStr = to_string(year);
	string calTitle = monthVec[month - 1] + " " + yearStr;
	int centerAlign = ((27 / 2) + calTitle.length() / 2) + 1;

	//Leap year algorithm
	if (year % 4 != 0) {
	} else if (year % 100 != 0) {
		month = 13;
	} else if (year % 400 != 0) {
	} else {
		month = 13;
	}
	cout << endl;

	//Switch for certain month
	int currDay = 1;
	int days = 0;
	switch (month) {
	case 1: days = 31;
		break;
	case 2: days = 28;
		break;
	case 3: days = 31;
		break;
	case 4: days = 30;
		break;
	case 5: days = 31;
		break;
	case 6: days = 30;
		break;
	case 7: days = 31;
		break;
	case 8: days = 31;
		break;
	case 9: days = 30;
		break;
	case 10: days = 31;
		break;
	case 11: days = 30;
		break;
	case 12: days = 31;
		break;
	case 13: days = 29;
		break;
	}

	//Switch for starting day
	int startPosition = 0;
	string i;
	switch(index) {
	case 0: startPosition = 0;
		i = "";
		break;
	case 1: startPosition = 4;
		i = " ";
		break;
	case 2: startPosition = 8;
		i = " ";
		break;
	case 3: startPosition = 12;
		i = " ";
		break;
	case 4: startPosition = 16;
		i = " ";
		break;
	case 5: startPosition = 20;
		i = " ";
		break;
	case 6: startPosition = 24;
		i = " ";
		break;
	}

	//Calendar output
	cout << setw(centerAlign) << calTitle << endl;
	cout << "Sun" << " " << "Mon" << " " << "Tue" << " " << "Wed" << " " << "Thu" << " " << "Fri" << " " << "Sat" << endl;
	cout << setw(startPosition) << i;
	while (currDay <= days) {
		cout << setw(3) << right << currDay << " ";
		if (index == 6) {
			cout << endl;
			index = 0;
		} else {
			index = index + 1;
		}
		currDay++;
	}
	cout << endl;

	system("pause");
	return 0;
}