#pragma once
#include <iostream>
#include <string>
#include "Subscriber.h"
#include "InputValidation.h"
#include <fstream>
#include "GetFileName.h"

using namespace std;

Subscriber* ConsoleInputer(int size);
Subscriber* FileDatainput(int* size);

