#pragma once
#include <iostream>
#include <string>
using namespace std;

class Subscriber {						
private:								//поля класса
	string surname;
	string name;
	string patronymic;
	string adress;
	string phone_number;
	int talk_time_in_the_city = 0;		// будет в секундах.
	int talk_time_between_cities = 0;
public:
	Subscriber() {
		surname = "unknown";			//конструктор по умолчанию . . 
		name = "unknown";
		patronymic = "unknown";
		adress = "unknown";
		phone_number = "unknown";
		talk_time_in_the_city = 0;
		talk_time_in_the_city = 0;
	}
	 
	Subscriber(string name, string surname, string patronymic, string adress, string phone_number, int talk_time_in_the_city, int talk_time_between_cities);

	string Get_surname();
	void Set_surname(string surname);
	void Show_surname();

	string Get_name();
	void Set_name(string name);
	void Show_name();

	string Get_patronymic();
	void Set_patronymic(string patronymic);
	void Show_patronymic();

	string Get_adress();
	void Set_adress(string adress);
	void Show_adress();

	string Get_phone_number();
	void Set_phone_number(string phone_number);
	void Show_phone_number();

	int Get_talk_time_in_the_city();
	void Set_talk_time_in_the_city(int talk_time_in_the_city);
	void Show_talk_time_in_the_city();

	int Get_talk_time_between_cities();
	void Set_talk_time_between_cities(int talk_time_between_cities);
	void Show_talk_time_between_cities();

};

/*
	Subscriber Ruslan;				 //объект классса Subscriber
	Ruslan.Set_surname("Лекомцев");
	Ruslan.Set_name("Руслан");
	Ruslan.Set_patronymic("Олегович");
	Ruslan.Set_adress("г. Санкт-Петербург");
	Ruslan.Set_phone_number("8-931-963-34-18");

	Ruslan.Set_talk_time_in_the_city(350);
	Ruslan.Set_talk_time_between_cities(573);

	Ruslan.Show_surname();
	Ruslan.Show_name();
	Ruslan.Show_patronymic();
	Ruslan.Show_adress();
	Ruslan.Show_phone_number();

	Ruslan.Show_talk_time_in_the_city();
	Ruslan.Show_talk_time_between_cities();

	Subscriber Mark;
	Mark.Show_surname();
	Mark.Show_name();
	Mark.Show_patronymic();
	Mark.Show_adress();
	Mark.Show_phone_number();
	Mark.Show_talk_time_between_cities();
	

	const int LENGHT = 5;			//статический массив
	Subscriber arr[LENGHT];
	arr[0].Show_name();
	arr[1].Show_name();
	arr[2].Show_name();
	arr[3].Show_name();
	arr[4].Show_name();
	arr[0].Set_name("thor");
	arr[0].Show_name();
	*/



