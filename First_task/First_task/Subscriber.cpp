#include <iostream> 
#include <string>
#include "Subscriber.h"
using namespace std;


Subscriber::Subscriber(string name, string surname, string patronymic, string adress, string phone_number, int talk_time_in_the_city, int talk_time_between_cities) {
	Subscriber::name = name;
	Subscriber::surname = surname;
	Subscriber::patronymic = patronymic;
	Subscriber::adress = adress;
	Subscriber::phone_number = phone_number;
	Subscriber::talk_time_in_the_city = talk_time_in_the_city;
	Subscriber::talk_time_between_cities = talk_time_between_cities;
} // создал тогда, когда конструктор еще создавал, подсказка вылетела желтая

string Subscriber::Get_surname() {
		return surname;
	}
	void Subscriber::Set_surname(string surname) {
		this->surname = surname;
	}
	void Subscriber::Show_surname() {
		cout << surname << endl;
	}

	string Subscriber::Get_name() {
		return name;
	}
	void Subscriber::Set_name(string name) {
		this->name = name;
	}
	void Subscriber::Show_name() {
		cout << name << endl;
	}

	string Subscriber::Get_patronymic() {
		return patronymic;
	}
	void Subscriber::Set_patronymic(string patronymic) {
		this->patronymic = patronymic;
	}
	void Subscriber::Show_patronymic() {
		cout << patronymic << endl;
	}

	string Subscriber::Get_adress() {
		return adress;
	}
	void Subscriber::Set_adress(string adress) {
		this->adress = adress;
	}
	void Subscriber::Show_adress() {
		cout << adress << endl;
	}

	string Subscriber::Get_phone_number() {
		return phone_number;
	}
	void Subscriber::Set_phone_number(string phone_number) {
		this->phone_number = phone_number;
	}
	void Subscriber::Show_phone_number() {
		cout << phone_number << endl;
	}

	int Subscriber::Get_talk_time_in_the_city() {
		return talk_time_in_the_city;
	}
	void Subscriber::Set_talk_time_in_the_city(int talk_time_in_the_city) {
		this->talk_time_in_the_city = talk_time_in_the_city;
	}
	void Subscriber::Show_talk_time_in_the_city() {
		cout << talk_time_in_the_city << endl;
	}

	int Subscriber::Get_talk_time_between_cities() {
		return talk_time_between_cities;
	}
	void Subscriber::Set_talk_time_between_cities(int talk_time_between_cities) {
		this->talk_time_between_cities = talk_time_between_cities;
	}
	void Subscriber::Show_talk_time_between_cities() {
		cout << talk_time_between_cities << endl;
	}

