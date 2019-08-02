#include <assert.h> 
#include<iostream>
#include "../../core/simba.h"

namespace test {
	
	bool test_clamp() {
		int low = 5;
		int high = 100;
		assert(sba::Clamp(20, low, high) == 20 && "Clamp function is not clamping properly");
		assert(sba::Clamp(2, low, high) == 5 && "Clamping doesn't work on the lower end of the interval.");
		assert(sba::Clamp(110, low, high) == 100 && "Clamp doesn't work on the higher end of the interval.");
		std::cout << "test_clamp successful!\n";
		return true;
	}
	bool test_mod() {
		assert(sba::Mod(10, 3) == 1 && "The remainder of the mod function is not correct.");
		assert(sba::Mod(-10, 3) == 2 && "The remainder of the mod function is not correct.");
		std::cout << "test_mod successful!\n";
		return true;
	}
}