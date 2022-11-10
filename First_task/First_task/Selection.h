#pragma once

#include <iostream>
#include "Subscriber.h"
#include <string>
#include "Input.h"
#include "InputValidation.h"

Subscriber* FunctionSamplingByExceedTime(int size, Subscriber* arr, int &end_size, int ExceedTime);
Subscriber* FunctionSamplingByBetweenCities(int size, Subscriber* arr, int &end_size);
Subscriber* FunctionSamplingByAlphabet(int size, Subscriber* arr, int &end_size);


