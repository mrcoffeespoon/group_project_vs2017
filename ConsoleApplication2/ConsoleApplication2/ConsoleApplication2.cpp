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
#include <iomapic>
using namespace std;



inline void print_time(int hours,int mins=0){
	if(hours<10)cout<<'0'<<hours;
	else cout<<hours;
	cout<<':';
	if(mins=0)cout<<"00";
	else if(mins<10)cout<<'0'<<mins;
	else cout<<mins;
}
class BookingSystem {
public:
	BookingSystem() {
		BookingSystem() {
		time_t t = time(0);
		localtime_s(&now, &t);
		Date temp;
		date = new Date[8];
		date[0] = Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
		for (int i = 1; i < 8; i++)
			date[i] = date[i - 1].nextday();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 7; j++)
				for (int k = 0; k < 13; k++)
					timetable[i][j][k] = 0;
	}
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
			Reservation_menu();
			break;                                          //continue.........

		}
	}
	void Reservation_menu(){}
	void Reservation() {
		//get data (cin>>)
		Reserve_Data data;                //use data.set(xxx) to set data
		int Start = 0;     // Start.hours=?  Start.mins =?
		int End = 0;
		int id = reserve_datas.size();    //id aotumate generated



		//check vaild
		if (1)                      // if no Room available
		{
			int suggest = get_suggest(End - Start, Start);
			cout << "***Reservation *** \n"
				<< "Sorry, no room is available at the time slot.\n"
				<< "Suggestions:" << endl;
		}

		//confirm
		if (data.confirm()){
			reserve_datas.push_back(data);          //finish reservation
			for(int i = Start-9; i<End-9 ;i++){
				
			} //scheduling
		}
	}                               //R1.3
	void  Modify_Reservation() {

	}    //R.11

	void  Cancel_Reservation() {


	}

	void print_record(char c){
		cout << "\nRoom " << c << "\n\n";
		int x;
		if (c == 'A')x = 0;
		else if (c == 'B')x = 1;
		else x = 2;
		cout << setw(6) << left << ' ';
		int i;
		for (i = 1; i <= 7; i++) {
			cout << date[i] << "  ";
		}
		cout << endl;

		for (i = 0; i < 13; i++) {
			print_time(i + 9);
			cout << "  ";
			for (int j = 0; j < 7; j++)
			{
				if (timetable[x][j][i] > 0)
					cout << "  x    ";
				else cout << "      ";
			}
			cout << endl;
		}

	}

	void Show_Reservation_Record() {
		cout << "*** Reservation Record ***\n" <<
			"Display Which Room (A - C):" << endl;
		char c =' ';
		while (1) {
			cin >> c;
			if (c == 'A')print_record('A');
			else if (c == 'B')print_record('B');
			else if (c == 'C')print_record('C');
			else if (c == 'x' || c == 'X')break;
			else cout << "invalid input" << endl;
			cout <<"Option(A - C), X to exit :";
		}
	
	}//R.2
	
	void Show_Staff_Requirements() {vbsdbvdjsbs;

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


	inline int get_suggestion(int duration, int conf_time_Start) {
		int suggestion;


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
