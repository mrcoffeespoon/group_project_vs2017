#include "DateAndTime.h"

class Reserve_Data {
public:
	Reserve_Data() {}
	Reserve_Data(string person, string address, int phone_no, char room, unsigned int no_Participants,
		Date Booked_date, int Start_time, int End_time) {
		SetData(person, address, phone_no, room, no_Participants, Booked_date, Start_time, End_time);
		Cal_Cost();
	}
	explicit Reserve_Data(const Reserve_Data& rhs) {
		SetData(rhs.R_person, rhs.R_address, rhs.R_phone_no, rhs.R_room, rhs.R_no_Participants, rhs.R_date, rhs.R_Start_time, rhs.R_End_time);
	}
	~Reserve_Data() {

	}
	inline Reserve_Data operator = (const Reserve_Data& rhs) { SetData(rhs.R_person,rhs.R_address,rhs.R_phone_no,rhs.R_room, rhs.R_no_Participants, rhs.R_date, rhs.R_Start_time, rhs.R_End_time); }

	void SetData(string person, string address, int phone_no, char room, unsigned int no_Participants,
		Date Booked_date, int Start_time, int End_time)
	{
		R_person = person;
		R_address = address;
		R_phone_no = phone_no;
		R_room = room;
		R_date = Booked_date;
		R_Start_time = Start_time;
		R_End_time = End_time;
		R_no_Participants = no_Participants;
	}


	void viewData() {






	} //print the Data as R1.7.
	bool confirm(){
	
	
	}
	void alterPerson(string name){R_person = name;}
	void alterAddress(string address){R_address = address;}
	void alterphoneNo(int num){R_Phone_no = num;}
	void alterDate(Date newdate) { R_date = newdate; }
	void alterRoom(char newRoom) {
		R_room = newRoom;
		Cal_Cost();
	}
	void alterno_Participants(int new_no) { R_no_Participants = new_no; }
	void alterStart_time(int New_startTime) { R_Start_time = New_startTime; }
	void alterEnd_time(int New_EndTime) { R_End_time = New_EndTime; }
	void alterDuration(int start, int End) { R_Start_time = start; R_End_time = End; Cal_Cost(); }

	int getcost() { return R_Cost; } // using this function to get cost


private:
	string R_person;
	string R_address;
	int R_phone_no;
	char R_room;                    //reserved room
	unsigned int R_no_Participants;
	Date R_date;
	int R_Start_time;
	int R_End_time;
	int R_Cost;

	void Cal_Cost() {
		int cost;





		R_Cost = cost;
	}                               //function to calculate cost
};
