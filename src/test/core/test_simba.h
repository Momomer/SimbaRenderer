#include <assert.h> 
#include<iostream>
#include "../../core/simba.h"
#include <cmath>

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
	bool test_log2() {
		assert(abs(sba::Log2(10)-3.32193)<0.0001 && "The result of the Log2 function is not correct.");
		std::cout << "test_log2 successful!\n";
		return true;
	}
	bool test_log2int() {
		assert(sba::Log2Int(8)==3 && "The result of the Log2Int function is not correct.");
		assert(sba::Log2Int(1) == 0 && "The result of the Log2Int function is not correct.");
		assert(sba::Log2Int(9) == 3 && "The result of the Log2Int function is not correct.");
		std::cout << "test_log2int successful!\n";
		return true;
	}
	bool test_ispoweroftwo() {
		assert(sba::IsPowerOfTwo(8)==true && "The result of the IsPowerOfTwo function is not correct.");
		assert(sba::IsPowerOfTwo(7)==false && "The result of the IsPowerOfTwo function is not correct.");
		assert(sba::IsPowerOfTwo(0)==false && "The result of the IsPowerOfTwo function is not correct.");	
		std::cout << "test_ispoweroftwo successful!\n";
		return true;
	}

	bool test_rounduppow2() {
		assert(sba::RoundUpPow2(8) == 8 && "The result of the RoundUpPow2 function is not correct.");
		assert(sba::RoundUpPow2(7) == 8 && "The result of the RoundUpPow2 function is not correct.");
		assert(sba::RoundUpPow2(12) == 16 && "The result of the RoundUpPow2 function is not correct.");
		std::cout << "test_rounduppow2 successful!\n";
		return true;
	}

	bool test_findinterval() {
		auto f = [](int x) {
			if (6 > x) {
				return true;
			}
			else {
				return false;
			}
		};
		assert(sba::FindInterval(7,f) == 5 && "The result of the FindInterval function is not correct.");
		auto f2 = [](int x) {
			if (72 > x) {
				return true;
			}
			else {
				return false;
			}
		};
		assert(sba::FindInterval(100, f2) == 71 && "The result of the FindInterval function is not correct.");
		std::cout << "test_findinterval successful!\n";
		return true;
	}

}