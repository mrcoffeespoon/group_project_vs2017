/*
	 commend:


*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include"DateAndTime.h"
#include"Reserve_Data.h"
#include<vector>
using namespace std;




class BookingSystem {
public:
	BookingSystem() {
		time_t t = time(0);
		localtime_s(&now, &t);
		Date temp;
		date = new Date[8];
		date[0] = Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
		for (int i = 1; i < 8; i++)
			date[i] = date[i - 1].nextday();
	}
	~BookingSystem() {
		delete[] date;
	}

	void mainmethod() {
		while (true) {
			menu();     //print , get input ,  and call the right function
			Date a("11_10_2011");                                                           //debug message
			for (int i = 0; i < 10; i++) a = a.nextday();
			cout << a << endl;
			cout << "today is :" << date[0] << "   tommorow is :" << date[1] << endl;
		}
	}
protected:
	void menu() {
		int x;

		// print menu



		cin >> x;
		switch (x) {
		case 1:
			Reservation();
			break;                                          //continue.........

		}
	}
	void Reservation() {
		//get data (cin>>)
		Reserve_Data data;                //use data.set(xxx) to set data
		int Start = 0;     // Start.hours=?  Start.mins =?
		int End = 0;
		int id = reserve_datas.size();    //id aotumate generated



		//check vaild
		if (1)                      // if no Room available
		{
			vector<int>* suggest = get_suggest(End - Start, Start);
			cout << "***Reservation *** \n"
				<< "Sorry, no room is available at the time slot.\n"
				<< "Suggestions:" << endl;
			for (int i = 0; i < suggest->size(); i++) {

			}

			delete suggest;
		}

		//confirm
		if (data.confirm())
			reserve_datas.push_back(data);          //finish reservation
	}                               //R1.3
	void  Modify_Reservation() {

	}    //R.11

	void  Cancel_Reservation() {


	}

	void Show_Reservation_Record() {

	}

	void Show_Staff_Requirements() {

	}

private:

	inline bool Confirm_Change(const Reserve_Data &date) {

		return 1;
	}
	inline bool date_is_vaild(Date date) {

		return 1;
	}
	inline bool time_is_vaild(int time) {

		return 1;
	}


	inline vector<int>* get_suggest(int duration, int conf_time_Start) {
		vector<int>* suggestion = new vector<int>;


		return suggestion;
	}                       //find the nearest avalible time form conflict time.  R1.5



	vector<Reserve_Data> reserve_datas;  //dynamic array vector
	int timetable[3][7][13];           //[Room]:[Day]:[time] : number of people 
	Date* date;                        //jest read it as (Date date[8];) today to next7 day
	tm now;                            //time now
};

int main() {
	BookingSystem bs;
	bs.mainmethod();                     //dont insert code here
	return 0;
}
