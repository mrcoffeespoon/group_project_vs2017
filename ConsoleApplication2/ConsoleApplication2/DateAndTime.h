#pragma once
#include<iostream>
using namespace std;
class Date {
public:
	Date() {}
	Date(string dd_mm_yyyy) {
		string::iterator itr = dd_mm_yyyy.begin();
		Day = (((int)*itr) - 48) * 10 + ((int)(*(++itr) - 48));
		itr += 2;
		Month = (((int)*itr) - 48) * 10 + ((int)(*(++itr)) - 48);
		itr += 2;
		Year = (((int)*itr) - 48) * 1000 + ((int)(*(++itr)) - 48) * 100 + ((int)(*(++itr)) - 48) * 10 + ((int)(*(++itr)) - 48);

		find_lastday();
	}                   //convert str to year
	Date(const Date& rhs) {
		Year = rhs.Year;
		Month = rhs.Month;
		Day = rhs.Day;
		last_day = rhs.last_day;
	}
	Date(int year, int month, int day) :Year(year), Month(month), Day(day) {
		find_lastday();
	}
	bool operator ==(const Date &rhs) {
		if (Day != rhs.Day)return 0;
		else if (Month != rhs.Month) return 0;
		else if (Year != rhs.Year) return 0;

		return 1;
	}
	friend ostream& operator<<(ostream &a, const Date &th)
	{
		if(th.Month<10)
			a<<'0'<<th.Month;
		else a<<th.Month;
		
		if( th.Day < 10)
			a <<'0'<<th.Day;
		else 
			a<<th.Day;
		
		return  a;
	}
	void print_date(){
		cout<< th.Day << '-' << th.Month << '-' << th.Year;
	}
	

	void setdate(int year, int month, int day) {
		Year = year;
		Month = month;
		Day = day;
		find_lastday();
	}

	Date nextday() {
		int d = Day + 1;
		int m = Month;
		int y = Year;
		if (d > last_day) {
			d = 1;
			m += 1;
			if (m > 12){
				m = 1;
				y++;
			}
		}
		Date next(y, m, d);
		return next;
	}    //function to find next day


private:
	void find_lastday() {


	}
	int Year;
	int Month;
	int Day;
	int last_day = 30;       // last day of the month
};
