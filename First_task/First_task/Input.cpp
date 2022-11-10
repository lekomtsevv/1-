#include "Input.h"

//���������� � �������� ����

Subscriber* ConsoleInputer(int size) {
	string name;
	string surname;
	string patronymic;
	string adress;
	string phone_number;
	int talk_time_in_the_city = 0;		
	int talk_time_between_cities = 0;

	Subscriber* array = new Subscriber[size];
	for (int i = 0; i < size; i++) {
		if (i > 0) {
			cout << "������� ������ ���������� �������� " << endl;
		}
		cout << "������� ��� " << endl;
		name = EnterNameSurnamePatronymic();					// ���� ������� �������� ����� cin - �. ������ - �� ���� ������� ����� ��������, ������� ������� ����
		cout << "������� ������� " << endl;
		surname = EnterNameSurnamePatronymic();
		cout << "������� �������� " << endl;
		patronymic = EnterNameSurnamePatronymic();

		cout << "������� ����� " << endl;						// �� ���� � �������� ����� ��� ���������?
		adress = EnterAdress();
		cout << "������� ����� �������� " << endl;					//������� ��� �����
		phone_number = EnterPhoneNumber();


		cout << "������� ����� ���������� ������ ������ " << endl;
		talk_time_in_the_city = GetPositiveInt();
		cout << "������� ����� ������������� ���������� " << endl;
		talk_time_between_cities = GetPositiveInt();

		array[i].Set_name(name);
		array[i].Set_surname(surname);
		array[i].Set_patronymic(patronymic);
		array[i].Set_adress(adress);
		array[i].Set_phone_number(phone_number);
		array[i].Set_talk_time_in_the_city(talk_time_in_the_city);
		array[i].Set_talk_time_between_cities(talk_time_between_cities);
	}
	return array;
}

Subscriber* FileDatainput(int* size) {
	
	string file_name;
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	while (true) {
		cout << "������� ��� ����� " << endl;
		try {
			file_name = GetFileName(input);
			file.open(file_name); 
			cout << "���� ������ �������: " << endl;
			
		}
		catch (const exception&) {
			cout << "��������� ������ ��� �������� �����. ��������� �������: " << endl;
			continue;
		}
		string name;
		string surname;
		string patronymic;
		string adress;
		string phone_number;
		int talk_time_in_the_city = 0;
		int talk_time_between_cities = 0;
		Subscriber* array = nullptr;
		try {
			int tmp = CheckLineInt(file);
			*size = tmp;
			array = new Subscriber[tmp];
			for (int i = 0; i < tmp; i++) {							
				name = CheckLineStr(file);
				surname = CheckLineStr(file);
				patronymic = CheckLineStr(file);
				adress = CheckLineStr(file);
				phone_number = CheckLineStr(file);
				talk_time_in_the_city = CheckLineInt(file);
				talk_time_between_cities = CheckLineInt(file);
				array[i] = Subscriber(name, surname, patronymic, adress, phone_number, talk_time_in_the_city, talk_time_between_cities);
			}

		}
		catch (const exception&) {
			cout << "��������� ������ ��� ������ ����������. ��������� �������: " << endl;
			file.close();
			continue;
		}
		catch (int) {
			file.close();
			continue;
		}
		file.close();
		return array;
	}
}