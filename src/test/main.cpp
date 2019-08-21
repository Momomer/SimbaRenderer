#include "core/test_simba.h"
#include "core/test_geometry.h"
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

bool run_geometry_tests() {
	bool test1 = test::test_vector3_has_nans();
	bool test2 = test::test_vector2_has_nans();
	bool test3 = test::test_vector3_add();
	bool test4 = test::test_vector3_scalar_mult();
	bool test5 = test::test_vector3_dot();
	bool test6 = test::test_vector3_length();
	bool test7 = test::test_vector3_length_squared();
	bool test8 = test::test_vector3_sub();
	bool test9 = test::test_vector3_scalar_div_assignment();
	bool test10 = test::test_vector3_abs();
	bool test11 = test::test_vector3_cross();
	bool test12 = test::test_vector3_max_component();
	bool test13 = test::test_vector3_min_component();
	bool test14 = test::test_point3_add();
	bool test15 = test::test_point3_sub();
	bool test16 = test::test_point3_dist();
	bool test17 = test::test_point3_dist_squared();
	bool test18 = test::test_point3_max();
	bool test19 = test::test_point3_min();
	bool test20 = test::test_point3_floor();
	bool test21 = test::test_point3_abs();
	bool test22 = test::test_point3_ceil();

	return test1 && test2&&test3&&test4&&test5&&test6&&test7&&test8&&test9&&test10&&test11&&test12
		&&test13&&test14&&test15&&test16&&test17&&test18&&test19&&test20&&test21&&test22;
}

int main() {
	bool core_tests=run_core_tests();
	bool geometry_tests = run_geometry_tests();
	if (core_tests) {
		std::cout << "Core tests successful!\n";
	}
	else {
		std::cout << "Core tests failed!\n";
	}

	if (geometry_tests) {
		std::cout << "Geometry tests successful!\n";
	}
	else {
		std::cout << "Geometry tests failed!\n";
	}

	
}