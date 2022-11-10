#include "Input.h"

//консольный и файловый ввод

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
			cout << "Введите данные следующего абонента " << endl;
		}
		cout << "Введите имя " << endl;
		name = EnterNameSurnamePatronymic();					// если вводить напрямую через cin - г. Москва - не дает вписать номер телефона, поэтому гетлайн взял
		cout << "Введите фамилию " << endl;
		surname = EnterNameSurnamePatronymic();
		cout << "Введите отчество " << endl;
		patronymic = EnterNameSurnamePatronymic();

		cout << "Введите адрес " << endl;						// но если я поставлю энтер что произодет?
		adress = EnterAdress();
		cout << "Введите номер телефона " << endl;					//сделать без буков
		phone_number = EnterPhoneNumber();


		cout << "Введите время разговоров внутри города " << endl;
		talk_time_in_the_city = GetPositiveInt();
		cout << "Введите время междугородних разговоров " << endl;
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
		cout << "Введите имя файла " << endl;
		try {
			file_name = GetFileName(input);
			file.open(file_name); 
			cout << "Файл открыт успешно: " << endl;
			
		}
		catch (const exception&) {
			cout << "Произошла ошибка при открытии файла. Повторите попытку: " << endl;
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
			cout << "Произошла ошибка при чтении информации. Повторите попытку: " << endl;
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