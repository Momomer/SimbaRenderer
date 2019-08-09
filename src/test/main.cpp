#include "core/test_simba.h"
#include<iostream>

bool run_core_tests() {
	bool test1=test::test_clamp();
	bool test2 = test::test_mod();
	bool test3 = test::test_log2();
	bool test4=test::test_log2int();
	bool test5=test::test_ispoweroftwo();
	bool test6 = test::test_rounduppow2();
	bool test7 = test::test_findinterval();
	return test1&&test2&&test3&&test4&&test5&&test6&&test7;
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