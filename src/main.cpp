#include <iostream>

#include "PCH.h"
#include "WTimer/WTimer.h"

int main() {
	spdlog::info("hello");
	std::cout << "Hello, World!" << std::endl;
	WTimer wtimer;
	std::cout << wtimer.getDay() << std::endl;
	return 0;
}
