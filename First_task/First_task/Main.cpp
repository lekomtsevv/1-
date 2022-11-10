/* 13 �������
���������� ����������� ����� ��� ��������� ���������� �������.
������ � ������ ����������� � ������� ������� Set, Get, Show.
�������: �������, ���, ��������, �����, ����� ��������, ����� ��������������� ����������, ����� ������������� ����������.
������� ������ ��������. ����������� ����������� ���������:
� ������ ���������, ����� ��������������� ���������� �������
��������� ��������,
� ������ ���������, ����������������� ������������� ������,
� ������ ���������, ���������� � ���������� �������.*/


#include <iostream>
#include <string>
#include "Interface.h"
#include "Subscriber.h"
#include "InputValidation.h"
#include "Input.h"
#include "Selection.h"
#include "FileOutput.h"
#include <windows.h>			//���������� ������������� �� ������� ����������� �������
#define QUIT 27					//������������ Esc �������� 27

using namespace std;

enum menu {
	FileInput = 1,						//�������� ����
	ConsoleInput,						//���������� ����
	SamplingByExceed = 1,				//������� ������ ��������� � ����������� �������� �����. ����������
	SamplingByBetweenCities,			//������� ������ ��������� ����������������� ������������� ������
	SamplingByAlphabet,					//������� ������ ��������� � ���������� �������
	FileOutput = 1,							//�������� �����
	yes = 1									
};



int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);							//������� ��� ��������� ����������� � ����������
	SetConsoleOutputCP(1251);
	int userChoice = 0;							//����� ������������ 
	int size = 0;								//������ ��������������� �������
	ShowGreeting();
	ShowTask();

	do {
		userChoice = 0;
		ShowInputOption();
		userChoice = GetUserChoice();
		Subscriber* arr = nullptr;				//�������� ������� �������� ������ subscriber
		switch (userChoice) {

		case(ConsoleInput):
			ShowMenuPoint();
			size = GetIntMoreThanNull();		//����� � ������������ �������� ���������� ���������
			arr = new Subscriber[size];
			cout << "������� ������ " << endl;
			arr = ConsoleInputer(size);			//���������� ������� � �������
			break;

		case(FileInput):
			arr = FileDatainput(&size);			//��������� ������� � �����
			break;
		}
		if (userChoice != FileInput) {
			ShowInputDataOption();					//���� ������ ����������� �������� ������
			userChoice = GetUserChoice();
			if (userChoice == yes) {
				File_DataInputOutput(size, arr, userChoice);		 //����������� �������� ������
			}
		}
		do {
			ShowMenu();								//���� ��������
			userChoice = SetMenuPoint();
			Subscriber* new_arr = nullptr;			// �������� ��������� �������
			int end_size = 0;						// �������� ������ ��������� �������
			int ExceedTime = 0;						// ���������� ������������ �������� ������� �������. ����������
			switch (userChoice) {
			case SamplingByExceed:
				cout << "������� ���������� �������� ������� ��������������� ����������: " << endl;
				ExceedTime = GetPositiveInt();
				new_arr = FunctionSamplingByExceedTime(size, arr, end_size, ExceedTime);	//������� ������� �� ������������ �������� ������� ��������� ������ ������
				break;
			case SamplingByBetweenCities:
				new_arr = FunctionSamplingByBetweenCities(size, arr, end_size);				//������� ������� ��������� ����������������� ������.������
				break;
			case SamplingByAlphabet:
				new_arr = FunctionSamplingByAlphabet(size, arr, end_size);				    //������� ������� �� �������� �� � �� �
				break;
			}
			// ���� ������ ����,��:
			if (end_size == 0) {
				cout << "��� ��������� ��������������� ������ " << endl;
				break;
			}
			else {
				Console_output(end_size, new_arr);				//����� ��������� ������� �� �������
			}
			ShowOutputType();
			userChoice = GetUserChoice();
			if (userChoice == FileOutput) {
				File_output(end_size, new_arr, userChoice);		//���������� ��������� ������� � ����
			}

			//������� ������
			delete[] new_arr;
			new_arr = nullptr;
			cout << "������� [1], ����� ��������� ������ � �������. " << endl;
			cout << "������� [2], ����� ����������. " << endl;
			cout << " " << endl;
			userChoice = GetUserChoice();						
			if (userChoice == 1) {
				break;
			}
		} while (userChoice != QUIT);

		delete[] arr;
		arr = nullptr;
		cout << "������� [1], ����� ��������� ������ ���������. " << endl;
		cout << "������� [2], ����� ����������. " << endl;
		userChoice = GetUserChoice();
		if (userChoice == 1) {
			break;
		}
		system("cls");
	} while (userChoice != QUIT);
	return 0;
}
		


