#include "Selection.h"

/* ������� ������ ���������, ����� ��������������� ���������� ������� ��������� ��������
 ������� ����� ��������������� ����������, �� �������� ������ ��������� ExceedTime = ... � ����� ������� */

Subscriber* FunctionSamplingByExceedTime(int size, Subscriber* arr, int &end_size, int ExceedTime) {

	Subscriber* tmp_list = new Subscriber[size];		//�������� �������������� �������
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
	Subscriber* end_list = new Subscriber[size];		//�������� ��������� �������
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	//delete[] tmp_list;
	return end_list;
}



/* ������� ������� ������ ���������, ����������������� ������������� ������ 
������: ���� ����� ������������� ����� > 0 - ������ ��������������    */

Subscriber* FunctionSamplingByBetweenCities(int size, Subscriber* arr, int &end_size) {

	Subscriber* tmp_list = new Subscriber[size];	//�������� �������������� �������
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
	Subscriber* end_list = new Subscriber[size];//�������� ��������� �������
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	delete[] tmp_list;
	return end_list;
}

/* ������� ������� ������ ���������, ���������� � ���������� �������
������: �� � �� �
- �� �������,
�� ���� ������� 1 = ������� 2 - �� ��� � �������� �� ������, ���� ���1 = ���2 � ��1 = ��2, �� ��� � �������� �� ���������,
� ���� 1��2 = 1���2 = 1��2 - ����� ������ 1 ������� ������, � 2 ����� ���� ������ � ������. 

strcmp
���������� ����. ��������, ���. ��������� �� ��������� �����:
0 ���� ������� � ���, ��� ��� ������ �����.
> 0 ��������� �� ��, ��� ������ str1 ������ ������ str2, < 0 ��������������� �� ��������.
������� strcmp �������� ���������� �� ������ ������� � ��� ������
����� ������� ������ ������������ �������, ��� �������������� �������� ���� ���� ��������.
��� ��� �������� ������, �� ������ � ����� ��������� �������.*/

Subscriber* FunctionSamplingByAlphabet(int size, Subscriber* arr, int &end_size) { // �� �������� ��� ����.

	Subscriber* tmp_list = new Subscriber[size];		//�������� �������������� �������
	end_size = 0;
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {			//if (strcmp(pass.c_str(), "sha") == 0) ������������� ������ � const char * � ��������� ��������� � ������� strcmp.
				if (strcmp(arr[i].Get_surname().c_str(), arr[j].Get_surname().c_str()) > 0) {
					Subscriber tmp = arr[i];
					arr[i] = arr[j];					//���, ��� ������ ���������� ��������� ? ��. ���������
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
		
	Subscriber* end_list = new Subscriber[size];		//�������� ��������� �������
	for (int i = 0; i < end_size; i++) {
		end_list[i] = tmp_list[i];
	}
	//delete[] tmp_list;
	return end_list;
}




		//( ������ ������� ������� )

