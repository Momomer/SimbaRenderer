#include <iostream>
#include "../core/simba.h"

int main() {
	//std::cout << "Welcome to the Simba Renderer!\n";
	std::cout << sba::Clamp(9, 0, 100) << "\n";
	std::cout << sba::Mod(-10, 3)<< "\n";
	std::cin.get();
}