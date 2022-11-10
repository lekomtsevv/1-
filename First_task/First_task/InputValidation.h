#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int GetInt();
int GetIntMoreThanNull();
int GetPositiveInt();


int GetUserChoice();
string EnterNameSurnamePatronymic();
string EnterPhoneNumber();

string EnterAdress();

int CheckLineInt(ifstream& file);
string CheckLineStr(ifstream& file);
