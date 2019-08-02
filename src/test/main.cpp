#include "core/test_simba.h"
#include<iostream>

bool run_core_tests() {
	bool test1=test::test_clamp();
	bool test2 = test::test_mod();
	return test1&&test2;
}

int main() {
	bool core_tests=run_core_tests();
	if (core_tests) {
		std::cout << "Core tests successful!\n";
	}
	else {
		std::cout << "Core tests failed!\n";
	}

	
}