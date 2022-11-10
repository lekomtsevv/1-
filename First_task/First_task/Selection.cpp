#include "Selection.h"

/* Выборка списка абонентов, время внутригородских разговоров которых превышает заданное
 задайте время внутригородских разговоров, от которого пойдет сравнение ExceedTime = ... в мейне написал */

Subscriber* FunctionSamplingByExceedTime(int size, Subscriber* arr, int &end_size, int ExceedTime) {

	Subscriber* tmp_list = new Subscriber[size];		//создание промежуточного массива
	end_size = 0;
	for (int i = 0; i < size; i++) {
		int tmp = 0;
		tmp = arr[i].Get_talk_time_in_the_city();
		if (tmp > ExceedTime) {
			tmp_list[end_size].Set_name(arr[i].Get_name());
			tmp_list[end_size].Set_surname(arr[i].Get_surname());
			tmp_list[end_size].Set_patronymic(arr[i].Get_patronymic());
			tmp_list[end_size].Set_adress(arr[i].Get_adress());
			tmp_list[end_size].Set_phone_number(arr[i].Get_phone_number());
			tmp_list[end_size].Set_talk_time_in_the_city(arr[i].Get_talk_time_in_the_city());
			tmp_list[end_size].Set_talk_time_between_cities(arr[i].Get_talk_time_between_cities());
			end_size++;
		}
	}
	Subscriber* end_list = new Subscriber[size];		//Создание итогового массива
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	//delete[] tmp_list;
	return end_list;
}



/* Функция выборки списка абонентов, воспользовавшихся междугородней связью 
логика: если время междугородней связи > 0 - значит воспользовался    */

Subscriber* FunctionSamplingByBetweenCities(int size, Subscriber* arr, int &end_size) {

	Subscriber* tmp_list = new Subscriber[size];	//создание промежуточного массива
	end_size = 0;
	for (int i = 0; i < size; i++) {
		int tmp = 0;
		tmp = arr[i].Get_talk_time_between_cities();
		if (tmp > 0) {
			tmp_list[end_size].Set_name(arr[i].Get_name());
			tmp_list[end_size].Set_surname(arr[i].Get_surname());
			tmp_list[end_size].Set_patronymic(arr[i].Get_patronymic());
			tmp_list[end_size].Set_adress(arr[i].Get_adress());
			tmp_list[end_size].Set_talk_time_in_the_city(arr[i].Get_talk_time_in_the_city());
			tmp_list[end_size].Set_talk_time_between_cities(arr[i].Get_talk_time_between_cities());
			end_size++;
		}
	}
	Subscriber* end_list = new Subscriber[size];//Создание итогового массива
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	delete[] tmp_list;
	return end_list;
}

/* Функция выборки списка абонентов, выведенных в алфавитном порядке
Логика: от А до я
- по фамилии,
но если фамилия 1 = фамилия 2 - то еще и проверка по именам, если фам1 = фам2 и им1 = им2, то еще и проверка по отчествам,
а если 1им2 = 1фам2 = 1от2 - тогда просто 1 абонент первый, а 2 после него пойдет в списке. 

strcmp
возвращает неск. значений, кот. указывают на отношение строк:
0 знач говорит о том, что обе строки равны.
> 0 указывает на то, что строка str1 больше строки str2, < 0 свидетельствует об обратном.
Функция strcmp начинает сравнивать по одному символу и как только
будут найдены первые неодинаковые символы, она проанализирует числовые коды этих символов.
Чей код окажется больше, та строка и будет считаться большей.*/

Subscriber* FunctionSamplingByAlphabet(int size, Subscriber* arr, int &end_size) { // не работает как надо.

	Subscriber* tmp_list = new Subscriber[size];		//создание промежуточного массива
	end_size = 0;
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {			//if (strcmp(pass.c_str(), "sha") == 0) преобразовать строку в const char * и выполнить сравнение с помощью strcmp.
				if (strcmp(arr[i].Get_surname().c_str(), arr[j].Get_surname().c_str()) > 0) {
					Subscriber tmp = arr[i];
					arr[i] = arr[j];					//тот, что больше становится следующим ? да. гениально
					arr[j] = tmp;
				}
			}

			tmp_list[end_size].Set_name(arr[i].Get_name());
			tmp_list[end_size].Set_surname(arr[i].Get_surname());
			tmp_list[end_size].Set_patronymic(arr[i].Get_patronymic());
			tmp_list[end_size].Set_adress(arr[i].Get_adress());
			tmp_list[end_size].Set_phone_number(arr[i].Get_phone_number());
			tmp_list[end_size].Set_talk_time_in_the_city(arr[i].Get_talk_time_in_the_city());
			tmp_list[end_size].Set_talk_time_between_cities(arr[i].Get_talk_time_between_cities());
			end_size++;
		}
		
	Subscriber* end_list = new Subscriber[size];		//Создание итогового массива
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	//delete[] tmp_list;
	return end_list;
}




		//( иванов смирнов соболев )

