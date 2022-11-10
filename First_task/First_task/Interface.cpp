#include "Interface.h"

void ShowGreeting() {
	cout << "Здравствуйте, коллеги! " << endl;
	cout << "Контрольная работа №1, 13 вариант " << endl;
	cout << "Студент 415 А группы Лекомцев Руслан Олегович " << endl << endl;
}
void ShowTask() {
	cout << "Абонент: фамилия, имя, отчество, адрес, номер телефона, время внутригородских разговоров, время междугородних разговоров. " << endl;
	cout << "Создать массив объектов. Реализовать возможность получения: " << endl;
	cout << "– списка абонентов, время внутригородских разговоров которых превышает заданное, " << endl;
	cout << "– списка абонентов, воспользовавшихся междугородней связью, " << endl;
	cout << "– списка абонентов, выведенных в алфавитном порядке. " << endl << endl;
}
void ShowInputOption() {
	cout << "Какой вид ввода данных вы хотите использовать? " << endl;
	cout << "[1] Файловый" << endl;
	cout << "[2] Консольный" << endl << endl;
}
void ShowMenuPoint() {
	cout << "Сколько абонентов вы хотите добавить? " << endl;
}
void ShowInputDataOption() {
	cout << "Вы хотите сохранить исходные данные в файл? " << endl;
	cout << "[1] Да " << endl;
	cout << "[2] Нет " << endl;
}
void ShowMenu() {
	cout << "Перед вами меню запросов" << endl;
	cout << "[1] Выборка абонентов, время внутригородских разговоров которых превышает заданное" << endl;
	cout << "[2] Выборка абонентов, воспользовавшихся междугородней связью" << endl;
	cout << "[3] Выборка абонентов, выведенных в алфавитном порядке" << endl;
}
void ShowOutputType() {
	cout << "Вы хотите записать данные в файл? " << endl;
	cout << "[1] Да " << endl;
	cout << "[2] Нет " << endl;
}

void ShowOutputChoise() {
	cout << "Вы хотите перезаписать данный файл? " << endl;
	cout << "[1] Да " << endl;
	cout << "[2] Ввести новое имя (путь к файлу)" << endl;
}


int SetMenuPoint() {
	int userChoice = 0;				//Ввод переменной, чтобы сделать выборки абонентов.
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
			cout << "Ошибка. Введите корректное значение " << endl;
		}
	}
}

				
