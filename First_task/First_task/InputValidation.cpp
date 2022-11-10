#include "InputValidation.h"

const int error = 1;			// � ��������� 

int GetInt() {
	int userInput;
	cin >> userInput;
	if (cin.fail()) {	// ���������� failbit, ������� ����� ������� ������ ������, ����� �����������, cin ����� ����� ������� ���� ������������� ����� ���������.
		cout << "�������� ������, ���������� ��� ���. " << endl;
		while (cin.fail()) {
			cin.clear();	// ��������� ���� ����� ���������, � ��� � ���� goodbit. ������ ����� ����� ����� ���������� ������ ���-�� ������.
			cin.ignore(INT_MAX, '\n'); // ��������� ������� �� ������� ������������������ � ����������� �� �� ��� ���, ���� ���� int_max ������� �� ����� ���������, ���� ���� �� ��� �� ���������� � ������
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');		//� ������ �������� �����, � ��������� ���� ����� ����������, ����� ���������� � ������ - ����� � ���� ���������� �����, � ��� ������!!
	return userInput;
}
int GetPositiveInt() {			// �������, ����� �������� ���������� �������� ������� ���������� ( 0 ��� +�����)
	int userInput = GetInt();	
	while (true) {
		if (userInput > 0 || userInput == 0) {
			return userInput;
		}
		else {
			cout << "������� ������������� ����� " << endl;
			userInput = GetInt();
		}
	}
	
}
int GetIntMoreThanNull() {				//�������, ����� ��������� ������ �������� (�� 1 ��������) 
	int userInput = GetInt();
	while (true) {
		if (userInput > 1 || userInput == 1) {
			return userInput;
		}
		else {
			cout << "������� ����� ����� ������ 0  " << endl;
			userInput = GetInt();
		}
	}

}
int GetUserChoice() {
	int userInput = GetInt();
	while (true) {
		if (userInput == 1 || userInput == 2) {
			return userInput;
		}
		else {
			cout << "������ ������ ���� �� ����������. ������� 1 ��� 2 " << endl;
			userInput = GetInt();
		}
	}

}

string CheckLineStr(ifstream& file) {
	string temp_v = "";
	try {
		getline (file, temp_v);
		return temp_v;
	}
	catch (const exception&) {
		cout << "��������� ������ ��� ������ ���������� �� �����: " << endl;
		throw 1;
	}
}
int CheckLineInt(ifstream& file) {
	string temp_v = "";
	int temp_i = 0;
	try {
		getline(file, temp_v);
	}
	catch (const exception&) {
		cout << "��������� ������ ��� ������ ���������� �� �����: " << endl;
		throw error;
	}
	try {
		temp_i = stoi(temp_v);
		if (temp_i < 0) {
			throw  error;
		}
		else {
			return temp_i;
		}
	}
	catch (const exception&) {
		cout << "�������� ��� ������ " << endl;
		throw error;
	}
}

string EnterNameSurnamePatronymic() {
	string temp = "";
	while (true) {
		bool is_correct = true;
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (isdigit(c)) {					//isdigit ��������� ��������, ������������ ����� �������� �haracter, �������� �� �� ���������� ������, ���� ��������� � ������� �������.
				cout << "��� �� ������ ��������� ����. ��������� ����." << endl;
				is_correct = false;
				break;
			}
		}
		if (!is_correct)
			continue;
		break;
	}
	return temp;
}
string EnterPhoneNumber() {				// , ������� �������� 12 ��������?
	string temp = "";
	while (true) {
		bool is_correct = true;
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		for (unsigned char c : temp) {
			if (!isdigit(c)) {					//isdigit ��������� ��������, ������������ ����� �������� �haracter, �������� �� �� ���������� ������, ���� ��������� � ������� �������.
				cout << "����� �������� �� ������ ��������� �����. ��������� ����." << endl;
				is_correct = false;
				break;
			}
		}
		if (!is_correct)
			continue;
		break;
	}
	return temp;
}
string EnterAdress() {
	string temp = "";
	while (true) {
		getline(cin, temp);
		if (temp.empty()) {
			cout << "������� ���������� ������: ";
			continue;
		}
		break;	
	}
	return temp;
}










/*
template<typename T>
T GetValue(){
	T temp = static_cast<T>(0.0);
	do {
		try {
			cin >> temp;
			cout << endl;
			if (cin.peek() != '\n')
				throw exception("IncorrectValue");
			return temp;
		}
		catch (const exception&){
			cout << "������� ������������ ������. ��������� ����: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}
*/








