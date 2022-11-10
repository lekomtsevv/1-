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
		cout << "Введите имя файла: ";
		file_name = GetFileName(output);
		try {
			out2.open(file_name);			//Попытка открытия файла
			cout << "Файл с таким именем уже существует " << endl;
			ShowOutputChoise();
			userChoiceForInput = GetUserChoice();
			switch (userChoiceForInput) {
			case Yes:
				out.open(file_name);			//открытие файла для записи
				out << end_size << endl;		//Запись данных
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					cout << " " << endl;
				}
				out.close();
				cout << "Данные успешно сохранены " << endl;
				break;
			case NewTurn:
				continue;
			}
			break;
		}
		catch (const exception&) {
			try {
				//Создание файла и запись данных
				out.open(file_name);
				out << end_size << endl;
				for (int i = 0; i < end_size; i++) {
					out << new_arr[i].Get_name() << endl;
					out << new_arr[i].Get_surname() << endl;
					out << new_arr[i].Get_patronymic() << endl;
					cout << " " << endl;
				}
				out.close();
				cout << "Данные сохранены: " << endl;
				break;
			}
			//Обработка исключений связанных с созданием нового файла
			catch (const exception&) {
				cout << "Не удалось сохранить, введите новый путь: ";
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
		cout << "Введите имя файла: ";									
		file_name = GetFileName(output);				//может просто сделать чтобы гетфайл нейм было на нормальные имена и все?
		try {
			out2.open(file_name);
			cout << "Файл с таким именем уже существует " << endl;
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
				cout << "Данные успешно сохранены " << endl;
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
				cout << "Данные сохранены: ";
				break;
			}
			catch (const exception&) {
				cout << "Не удалось сохранить, введите новый путь: ";
				continue;
			}
		}

	}
}





































void Console_output(int end_size, Subscriber* new_arr) {
	//Вывод на консоль итогового результата
	for (int i = 0; i < end_size; i++) {
		new_arr[i].Show_name();
		new_arr[i].Show_surname();
		new_arr[i].Show_patronymic();
		cout << " " << endl;
	}
	cout << " " << endl;
}