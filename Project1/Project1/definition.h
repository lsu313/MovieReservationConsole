#pragma once
#include <iostream>
#include <string>

using namespace std;
class Seat;
class Person;
class Point;
class Cnt;

class Movie {
public:
	int movie_choice = 0;
	int theater = -1;
	string time[8][3]{
		"1.     10 : 30 ~ 12: 30.","2.     15 : 30 ~ 17: 30." ,"3.     21 : 30 ~ 23: 30.",
		"1.     10 : 00 ~ 12: 00.","2.     15 : 30 ~ 17: 30." ,"3.     20 : 30 ~ 22: 30.",
		"1.     9 : 30 ~ 12 : 00.","2.     15 : 00 ~ 17 : 30.","3.     21 : 30 ~ 24 : 00.",
		"1.     8 : 30 ~ 11 : 00.","2.     15 : 20 ~ 17 : 50.","3.     22 : 00 ~ 24 : 30.",
		"1.     8 : 30 ~ 10 : 00.","2.     14 : 00 ~ 15 : 30.","3.     22 : 30 ~ 24 : 00.",
		"1.     9 : 30 ~ 11 : 00.","2.     13 : 00 ~ 14 : 30.","3.     21 : 30 ~ 23 : 00.",
		"1.     8 : 30 ~ 10 : 00.","2.     14 : 00 ~ 15 : 30.","3.     22 : 30 ~ 24 : 00.",
		"1.     10 : 30 ~ 12 : 00.","2.     16 : 00 ~ 17 : 30.","3.     19 : 30 ~ 21 : 00."
	}; //1~8관 상영시간
	int time_idx = -1;
	int price = 10000;

public:
	
	void Movie_choice();
	void Delete();
	friend Seat;
	friend Person;
};
class Seat_info
{

	int gender = 0;
	string name = "";
	string phone_num = "";
	int seat_row = 0;
	int seat_col = 0;
	void Update_seatInfo(string name, int gender, string phone_num, int seat_row, int seat_col);
	void Delete_seatInfo(string name, int gender, string phone_num, int seat_row, int seat_col);
	bool Compare(string name, string phone_num);
	friend Seat;
	friend Cnt;
};

class Seat
{
	Seat_info info[6][6];
	char input_seat[2] = { 0 };
	int temp_x = 0;
	int temp_y = 0; // time

public:
	char seat_ui[6][6];
	int cnt_seat[6][6] = { 0 };
	int cnt_gender_seat[2][6][6] = { 0 };
	Seat();
	void Reset();
	void Seat_cancle(string name, int gender, string phone_num);

	void Seat_output();
	void Seat_check();
	void Seat_check_for_cancle();
	void Seat_input_hard(char x, char y, int gender, string name, string phone_num);
	void Seat_input(string name, int gender, string phone_num);
	friend Cnt;
};

class Point
{
	int charge_money;
	int charge_point;

public:
	Point();
	void Payment(int price);
	void Save(string name);
	void Cancle_payment(int price);
	void Cacle_save(string name);


};
class Person {
	string name;
	string phone_num;
	int gender;  //1.남자 2.여자
	Point pnt;

public:
	Movie m1;
	static Seat seat[8][3];       //8개 상영관 3타임
public:
	
	bool Check_info(string name, string phone_num);
	void Set_hard(string name, int gender, string phone_num, int movie_choice, int theater, int time_idx);
	void personal_information();
	void Reservation();
	void Reservation_hard(char x, char y);

	void PayandSave();
	void Reservation_cancel();
	void Refund();


};


class Cnt   //하루 동안 8상영관 3개의 시간대의 좌석 수의 합을 구하기 위한 클래스
{
	Seat *s1 = new Seat;
	Movie* m = new Movie;
	static Seat s2[8][3];
	char x, y;
	int row, col;
	int theater; int time_idx;
	int n;
	int value[4] = { 0 };
	int man_ratio = 0;
	int woman_ratio = 0;

public:
	int Sum_seat_most[8][6][6] = { 0 };
	int Sum_seat_movie[4][6][6] = { 0 };
	int Sum_seat_gender[2][6][6] = { 0 };
	int t1[8];
	int t2[8];
	int t3[8];
	int top1[8][2] = { 0 };
	int top2[8][2] = { 0 };
	int top3[8][2] = { 0 };
	int mtop1[4][2] = { 0 };
	int mtop2[4][2] = { 0 };
	int mtop3[4][2] = { 0 };
	int mt1[4] = { 0 };
	int mt2[4] = { 0 };
	int mt3[4] = { 0 };
	int gt1[2] = { 0 };
	int gt2[2] = { 0 };
	int gt3[2] = { 0 };
	int gtop1[2][2] = { 0 };
	int gtop2[2][2] = { 0 };
	int gtop3[2][2] = { 0 };
public:
	~Cnt();
	void Sum_seats();
	void ChartoInt();
	void Out_sum();
	void Set_gender();
	void Cnt_gender();
	void Set_movie();
	void Cnt_movie();
	void Set_most();
	void Cnt_most();
	void Out_gender();
	void Out_most();
	void Out_movie();
	void Cnt_ratio();
};
void Reset_Seat();
void Day1();
void Day2();
void Day3();
void Day4();
void Day5();
void Day6();
class Execution
{

	Cnt c1, c2, c3, c4, c5, c6, c7, c8;
public:
	void Day1To7_Execution();
	friend Cnt;
};
