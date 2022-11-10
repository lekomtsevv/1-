#pragma once
#include <iostream>
#include <fstream>
#include "Subscriber.h"
#include "Interface.h"
#include "InputValidation.h"

using namespace std;

void File_output(int& end_size, Subscriber* new_arr, int userChoiceForInput);
void Console_output(int end_size, Subscriber* new_arr);
void File_DataInputOutput(int& end_size, Subscriber* new_arr, int userChoiceForInput);


