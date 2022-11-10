/* 13 вариант
Необходимо разработать класс для указанной предметной области.
Доступ к данным реализовать с помощью методов Set, Get, Show.
Абонент: фамилия, имя, отчество, адрес, номер телефона, время внутригородских разговоров, время междугородних разговоров.
Создать массив объектов. Реализовать возможность получения:
– списка абонентов, время внутригородских разговоров которых
превышает заданное,
– списка абонентов, воспользовавшихся междугородней связью,
– списка абонентов, выведенных в алфавитном порядке.*/


#include <iostream>
#include <string>
#include "Interface.h"
#include "Subscriber.h"
#include "InputValidation.h"
#include "Input.h"
#include "Selection.h"
#include "FileOutput.h"
#include <windows.h>			//Библеотека ответственная за русскую локализацию консоли
#define QUIT 27					//Присваивание Esc значение 27

using namespace std;

enum menu {
	FileInput = 1,						//Файловый ввод
	ConsoleInput,						//Консольный ввод
	SamplingByExceed = 1,				//Выборка списка абонентов с превышающем временем внутр. разговоров
	SamplingByBetweenCities,			//Выборка списка абонентов воспользовавшихся междугородней связью
	SamplingByAlphabet,					//Выборка списка абонентов в алфавитном порядке
	FileOutput = 1,							//Файловый вывод
	yes = 1									
};



int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);							//функции для настройки локализации в переменных
	SetConsoleOutputCP(1251);
	int userChoice = 0;							//Выбор пользователя 
	int size = 0;								//Размер первоначального массива
	ShowGreeting();
	ShowTask();

	do {
		userChoice = 0;
		ShowInputOption();
		userChoice = GetUserChoice();
		Subscriber* arr = nullptr;				//Создание массива объектов класса subscriber
		switch (userChoice) {

		case(ConsoleInput):
			ShowMenuPoint();
			size = GetIntMoreThanNull();		//берем у пользователя желаемое количество абонентов
			arr = new Subscriber[size];
			cout << "Введите данные " << endl;
			arr = ConsoleInputer(size);			//Заполнение массива с консоли
			break;

		case(FileInput):
			arr = FileDatainput(&size);			//Запонение массива с файла
			break;
		}
		if (userChoice != FileInput) {
			ShowInputDataOption();					//Меню выбора сохраниения исходных данных
			userChoice = GetUserChoice();
			if (userChoice == yes) {
				File_DataInputOutput(size, arr, userChoice);		 //сохраниение исходных данных
			}
		}
		do {
			ShowMenu();								//Меню запросов
			userChoice = SetMenuPoint();
			Subscriber* new_arr = nullptr;			// Создание итогового массива
			int end_size = 0;						// конечный размер итогового массива
			int ExceedTime = 0;						// Переменная превышающего значения времени внутриг. разговоров
			switch (userChoice) {
			case SamplingByExceed:
				cout << "Введите допустимое значение времени внутригородских разговоров: " << endl;
				ExceedTime = GetPositiveInt();
				new_arr = FunctionSamplingByExceedTime(size, arr, end_size, ExceedTime);	//Функция выборки по превышающему значению времени разговора внутри города
				break;
			case SamplingByBetweenCities:
				new_arr = FunctionSamplingByBetweenCities(size, arr, end_size);				//Функция выборки абонентов воспользовавшихся междуг.связью
				break;
			case SamplingByAlphabet:
				new_arr = FunctionSamplingByAlphabet(size, arr, end_size);				    //Функция выборки по алфавиту от А до Я
				break;
			}
			// Если массив пуст,то:
			if (end_size == 0) {
				cout << "Нет элементов удовлетворяющих поиску " << endl;
				break;
			}
			else {
				Console_output(end_size, new_arr);				//Вывод итогового массива на консоль
			}
			ShowOutputType();
			userChoice = GetUserChoice();
			if (userChoice == FileOutput) {
				File_output(end_size, new_arr, userChoice);		//Сохранение итогового массива в файл
			}

			//очистка памяти
			delete[] new_arr;
			new_arr = nullptr;
			cout << "Нажмите [1], чтобы завершить работу с подменю. " << endl;
			cout << "Нажмите [2], чтобы продолжить. " << endl;
			cout << " " << endl;
			userChoice = GetUserChoice();						
			if (userChoice == 1) {
				break;
			}
		} while (userChoice != QUIT);

		delete[] arr;
		arr = nullptr;
		cout << "Нажмите [1], чтобы завершить работу программы. " << endl;
		cout << "Нажмите [2], чтобы продолжить. " << endl;
		userChoice = GetUserChoice();
		if (userChoice == 1) {
			break;
		}
		system("cls");
	} while (userChoice != QUIT);
	return 0;
}
		


