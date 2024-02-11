#include "firstApp.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
	realm::FirstApp app;
	
	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}