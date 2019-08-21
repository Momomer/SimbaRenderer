#include <assert.h> 
#include<iostream>
#include "../../core/geometry.h"
#include "../../core/simba.h"
#include <cmath>
#include<limits>
#include<cstdint>

namespace test {

	bool test_vector3_has_nans() {
		sba::Vector3f v1(1,2,3);
		assert(v1.HasNaNs() == false && "The hasNans function is false, even though the vector entries are numbers.");
		//sba::Vector3f v2(std::numeric_limits<sba::Float>::quiet_NaN(), std::numeric_limits<sba::Float>::quiet_NaN(), 1.0);
		//assert(v2.HasNaNs() == true && "The hasNans function did not find the NaNs.");
		std::cout << "test_vector3_has_nans successful!\n";
		return true;
	}
	bool test_vector2_has_nans() {
		sba::Vector2f v1(1, 2);
		assert(v1.HasNaNs() == false && "The hasNans function is false, even though the vector entries are numbers.");
		//sba::Vector3f v2(std::numeric_limits<sba::Float>::quiet_NaN(), std::numeric_limits<sba::Float>::quiet_NaN(), 1.0);
		//assert(v2.HasNaNs() == true && "The hasNans function did not find the NaNs.");
		std::cout << "test_vector2_has_nans successful!\n";
		return true;
	}
	bool test_vector3_add() {
		sba::Vector3<int> v1(1, 2, 5);
		sba::Vector3<int> v2(1, 2, 5);
		
		sba::Vector3<int> result = v1 + v2;
		assert(result.x == 2 && "The x value of the result is false.");
		assert(result.y == 4 && "The y value of the result is false.");
		assert(result.z == 10 && "The z value of the result is false.");
	
		std::cout << "test_vector3_add successful!\n";
		return true;
	}
	bool test_vector3_scalar_mult() {
		sba::Vector3<int> v1(1, 2, 5);
		
		sba::Vector3<int> result = v1 * 5;
		assert(result.x == 5 && "The x value of the result is false.");
		assert(result.y == 10 && "The y value of the result is false.");
		assert(result.z == 25 && "The z value of the result is false.");

		std::cout << "test_vector3_scalar_mult successful!\n";
		return true;
	}
	
	bool test_vector3_scalar_div_assignment() {
		sba::Vector3<int> v1(3, 6, 15);

		v1 /= 3;

		assert(v1.x == 1 && "The x value of the result is false.");
		assert(v1.y == 2 && "The y value of the result is false.");
		assert(v1.z == 5 && "The z value of the result is false.");

		std::cout << "test_vector3_scalar_div_assignment successful!\n";
		return true;
	}

	bool test_vector3_dot() {
		sba::Vector3<int> v1(1, 2, 5);
		sba::Vector3<int> v2(3, 1, 4);
	
		assert(v1.Dot(v2) == 25  && "The value of the result is false.");

		std::cout << "test_vector3_dot successful!\n";
		return true;
	}
	bool test_vector3_length() {
		sba::Vector3<int> v1(1, 2, 5);
	
		assert(abs(v1.Length() -5.47722)<0.01  && "The calculated magnitude of the vector is not correct.");

		std::cout << "test_vector3_length successful!\n";
		return true;
	}

	bool test_vector3_length_squared() {
		sba::Vector3<int> v1(1, 2, 5);

		assert(abs(v1.LengthSquared() - 30) < 0.001  && "The calculated squared magnitude of the vector is not correct.");

		std::cout << "test_vector3_length_squared successful!\n";
		return true;
	}
	bool test_vector3_sub() {
		sba::Vector3<int> v1(3, 6, 15);
		sba::Vector3<int> v2(1, 2, 5);

		sba::Vector3<int> result = v1 - v2;
		assert(result.x == 2 && "The x value of the result is false.");
		assert(result.y == 4 && "The y value of the result is false.");
		assert(result.z == 10 && "The z value of the result is false.");

		std::cout << "test_vector3_sub successful!\n";
		return true;
	}
	bool test_vector3_abs() {
		sba::Vector3<int> v1(-3, 6, -15);

		sba::Vector3<int> magnitude = v1.Abs();
		assert(magnitude.x == 3 && "The x value of the result is false.");
		assert(magnitude.y == 6 && "The y value of the result is false.");
		assert(magnitude.z == 15 && "The z value of the result is false.");

		std::cout << "test_vector3_abs successful!\n";
		return true;
	}

	bool test_vector3_cross() {
		sba::Vector3<int> v1(1, 2, 5);
		sba::Vector3<int> v2(3, 1, 4);
		sba::Vector3<int> result = v1.Cross(v2);
		assert(result.Dot(v2) == 0 && "The dot product of the result should be zero.");
		assert(result.Dot(v1) == 0 && "The dot product of the result should be zero.");
		std::cout << "test_vector3_cross successful!\n";
		return true;
	}


	bool test_vector3_max_component() {
		sba::Vector3<int> v1(1, 2, 5);
		sba::Vector3<float> v2(-3, -1.00001, -1);
		assert(v1.MaxComponent() == 5 && "The element returned is not the largest.");
		assert(v2.MaxComponent() == -1 && "The element returned is not the largest.");
		std::cout << "test_vector3_max_component successful!\n";
		return true;
	}
	bool test_vector3_min_component() {
		sba::Vector3<int> v1(1, 2, 5);
		sba::Vector3<float> v2(-3.1, -1.00001, -1);
		assert(abs(v1.MinComponent()-1)<0.01 && "The element returned is not the smallest.");
		assert(abs(v2.MinComponent()+3.1)<0.1 && "The element returned is not the smallest.");
		
		std::cout << "test_vector3_min_component successful!\n";
		return true;
	}
	bool test_point3_add() {
		sba::Point3<int> p1(3, 5, 9);
		sba::Vector3<int> v2(1, 2, 5);
		sba::Point3<int> result = p1 + v2;
		assert(result.x == 4 && "The x value of the result is false.");
		assert(result.y == 7 && "The y value of the result is false.");
		assert(result.z == 14 && "The z value of the result is false.");
		std::cout << "test_Point3_add successful!\n";
		
		return true;
	}
	bool test_point3_sub() {
		sba::Point3<int> p1(3, 5, 9);
		sba::Point3<int> p2(1, 2, 5);
		sba::Vector3<int> result = p1 - p2;
		assert(result.x == 2 && "The x value of the result is false.");
		assert(result.y == 3 && "The y value of the result is false.");
		assert(result.z == 4 && "The z value of the result is false.");
		std::cout << "test_Point3_sub successful!\n";

		return true;
	}
	bool test_point3_dist() {
		sba::Point3<int> p1(3, 5, 9);
		sba::Point3<int> p2(5, 6, 3);
		assert(abs(p1.Distance(p2)- sqrt(41))<0.001 && "The distance value of the result is false.");
		std::cout << "test_Point3_dist successful!\n";
		return true;
	}
	bool test_point3_dist_squared() {
		sba::Point3<int> p1(3, 5, 9);
		sba::Point3<int> p2(5, 6, 3);
		assert(abs(p1.DistanceSquared(p2) - 41) < 0.000001 && "The squared distance value of the result is false.");
		std::cout << "test_Point3_dist_squared successful!\n";
		return true;
	}


	bool test_point3_max() {
		sba::Point3<int> p1(1,4, 5);
		sba::Point3<int> p2(-1, -2, -5);
		sba::Point3<int> result = p1.Max(p2);
		assert(result.x == 1 && "The element returned is not the largest.");
		assert(result.y == 4 && "The element returned is not the largest.");
		assert(result.z == 5 && "The element returned is not the largest.");
		std::cout << "test_point3_max successful!\n";
		return true;
	}
	bool test_point3_min() {
		sba::Point3<int> p1(1, 4, 5);
		sba::Point3<int> p2(-1, -2, -5);
		sba::Point3<int> result = p1.Min(p2);
		assert(result.x == -1 && "The element returned is not the smallest.");
		assert(result.y == -2 && "The element returned is not the smallest.");
		assert(result.z == -5 && "The element returned is not the smallest.");
		std::cout << "test_point3_min successful!\n";
		return true;
	}
	bool test_point3_floor() {
		sba::Point3<float> p1(-3.1, 1.0, 2.2);
		sba::Point3<float> result = p1.Floor();
		assert(abs(result.x + 4) < 0.01 && "The element returned is not rounded down correctly.");
		assert(abs(result.y -1) < 0.01 && "The element returned is not rounded down correctly.");
		assert(abs(result.z - 2) < 0.01 && "The element returned is not rounded down correctly.");
		std::cout << "test_point3_floor successful!\n";
		return true;
	}
	bool test_point3_ceil() {
		sba::Point3<float> p1(-3.1, 1.0, 2.2);
		sba::Point3<float> result = p1.Ceil();
		assert(abs(result.x + 3) < 0.01 && "The element returned is not rounded up correctly.");
		assert(abs(result.y - 1) < 0.01 && "The element returned is not rounded up correctly.");
		assert(abs(result.z - 3) < 0.01 && "The element returned is not rounded up correctly.");
		std::cout << "test_point3_ceil successful!\n";
		return true;
	}
	bool test_point3_abs() {
		sba::Point3<float> p1(-3.1, 0.0, 2.2);
		sba::Point3<float> result = p1.Abs();
		assert(abs(result.x + -3.1) < 0.01 && "The element returned is incorrect.");
		assert(abs(result.y - 0.0) < 0.01 && "The element returned is incorrect.");
		assert(abs(result.z - 2.2) < 0.01 && "The element returned is incorrect.");
		std::cout << "test_point3_abs successful!\n";
		return true;
	}
}