#include "FileOutput.h"
#include"GetFileName.h"

void File_output(int& end_size, Subscriber* new_arr, int userChoiceForInput) {
	ofstream  out;
	ifstream out2;
	string file_name;
	out.exceptions(ofstream::badbit | ofstream::failbit);
	out2.exceptions(ifstream::badbit | ifstream::failbit);
	const int Yes = 1;
	const int NewTurn = 2;

	while (true) {
		cout << "������� ��� �����: ";
		file_name = GetFileName(output);
		try {
			out2.open(file_name);			//������� �������� �����
			cout << "���� � ����� ������ ��� ���������� " << endl;
			ShowOutputChoise();
			userChoiceForInput = GetUserChoice();
			switch (userChoiceForInput) {
			case Yes:
				out.open(file_name);			//�������� ����� ��� ������
				out << end_size << endl;		//������ ������
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					cout << " " << endl;
				}
				out.close();
				cout << "������ ������� ��������� " << endl;
				break;
			case NewTurn:
				continue;
			}
			break;
		}
		catch (const exception&) {
			try {
				//�������� ����� � ������ ������
				out.open(file_name);
				out << end_size << endl;
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					cout << " " << endl;
				}
				out.close();
				cout << "������ ���������: " << endl;
				break;
			}
			//��������� ���������� ��������� � ��������� ������ �����
			catch (const exception&) {
				cout << "�� ������� ���������, ������� ����� ����: ";
				continue;
			}
		}

	}
}

void File_DataInputOutput(int& end_size, Subscriber* new_arr, int userChoiceForInput) {
	ofstream out;
	ifstream out2;
	string file_name;
	out.exceptions(ofstream::badbit | ofstream::failbit);
	out2.exceptions(ifstream::badbit | ifstream::failbit);
	const int Yes = 1;
	const int NewTurn = 2;

	while (true) {
		cout << "������� ��� �����: ";									
		file_name = GetFileName(output);				//����� ������ ������� ����� ������� ���� ���� �� ���������� ����� � ���?
		try {
			out2.open(file_name);
			cout << "���� � ����� ������ ��� ���������� " << endl;
			ShowOutputChoise();
			userChoiceForInput = GetUserChoice();
			switch (userChoiceForInput) {
			case Yes:
				out.open(file_name);
				out << end_size << endl;
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					out << new_arr[i].Get_adress() << endl;
					out << new_arr[i].Get_phone_number() << endl;
					out << new_arr[i].Get_talk_time_in_the_city() << endl;
					out << new_arr[i].Get_talk_time_between_cities() << endl;
				}
				out.close();
				cout << "������ ������� ��������� " << endl;
				break;
			case NewTurn:
				continue;
			}
			break;
		}
		catch (const exception&) {
			try {
				out.open(file_name);
				out << end_size << endl;
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					out << new_arr[i].Get_adress() << endl;
					out << new_arr[i].Get_phone_number() << endl;
					out << new_arr[i].Get_talk_time_in_the_city() << endl;
					out << new_arr[i].Get_talk_time_between_cities() << endl;
				}
				out.close();
				cout << "������ ���������: ";
				break;
			}
			catch (const exception&) {
				cout << "�� ������� ���������, ������� ����� ����: ";
				continue;
			}
		}

	}
}





































void Console_output(int end_size, Subscriber* new_arr) {
	//����� �� ������� ��������� ����������
	for (int i = 0; i < end_size; i++) {
		new_arr[i].Show_name();
		new_arr[i].Show_surname();
		new_arr[i].Show_patronymic();
		cout << " " << endl;
	}
	cout << " " << endl;
}