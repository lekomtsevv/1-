#include "Interface.h"

void ShowGreeting() {
	cout << "������������, �������! " << endl;
	cout << "����������� ������ �1, 13 ������� " << endl;
	cout << "������� 415 � ������ �������� ������ �������� " << endl << endl;
}
void ShowTask() {
	cout << "�������: �������, ���, ��������, �����, ����� ��������, ����� ��������������� ����������, ����� ������������� ����������. " << endl;
	cout << "������� ������ ��������. ����������� ����������� ���������: " << endl;
	cout << "� ������ ���������, ����� ��������������� ���������� ������� ��������� ��������, " << endl;
	cout << "� ������ ���������, ����������������� ������������� ������, " << endl;
	cout << "� ������ ���������, ���������� � ���������� �������. " << endl << endl;
}
void ShowInputOption() {
	cout << "����� ��� ����� ������ �� ������ ������������? " << endl;
	cout << "[1] ��������" << endl;
	cout << "[2] ����������" << endl << endl;
}
void ShowMenuPoint() {
	cout << "������� ��������� �� ������ ��������? " << endl;
}
void ShowInputDataOption() {
	cout << "�� ������ ��������� �������� ������ � ����? " << endl;
	cout << "[1] �� " << endl;
	cout << "[2] ��� " << endl;
}
void ShowMenu() {
	cout << "����� ���� ���� ��������" << endl;
	cout << "[1] ������� ���������, ����� ��������������� ���������� ������� ��������� ��������" << endl;
	cout << "[2] ������� ���������, ����������������� ������������� ������" << endl;
	cout << "[3] ������� ���������, ���������� � ���������� �������" << endl;
}
void ShowOutputType() {
	cout << "�� ������ �������� ������ � ����? " << endl;
	cout << "[1] �� " << endl;
	cout << "[2] ��� " << endl;
}

void ShowOutputChoise() {
	cout << "�� ������ ������������ ������ ����? " << endl;
	cout << "[1] �� " << endl;
	cout << "[2] ������ ����� ��� (���� � �����)" << endl;
}


int SetMenuPoint() {
	int userChoice = 0;				//���� ����������, ����� ������� ������� ���������.
	while (true) {
		const int SamplingByExceed = 1;		
		const int SamplingByBetweenCities = 2;
		const int SamplingByAlphabet = 3;
		userChoice = GetInt();
		if (userChoice == SamplingByExceed || userChoice == SamplingByBetweenCities || userChoice == SamplingByAlphabet) {
			return userChoice;
			break;
		}
		else {
			cout << "������. ������� ���������� �������� " << endl;
		}
	}
}

				
