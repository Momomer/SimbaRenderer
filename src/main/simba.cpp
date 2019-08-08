#include <iostream>
#include "../core/simba.h"

int main() {
	//std::cout << "Welcome to the Simba Renderer!\n";
	std::cout << sba::Clamp(9, 0, 100) << "\n";
	std::cout << sba::Mod(-10, 3)<< "\n";
	std::cout << sba::Log2(10) << "\n";
	std::cout << std::log(10)/std::log(2)<<"\n";
	std::cout << sba::Log2Int(8) << "\n";
	std::cout << sba::IsPowerOf2(1) << "\n";
	std::cout << sba::RoundUpPow2(192) << "\n";
	std::cin.get();
}