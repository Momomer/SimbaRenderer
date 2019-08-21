//#pragma once
#include <assert.h> 
#include<algorithm>
#include "simba.h"

namespace sba {
	template<class T>
	class Vector2 {
	public:
		T x=0;
		T y=0;


		Vector2(T x, T y)
			: x(x), y(y) {
			assert(!HasNaNs() && "There are NaNs in the vector constructor");
		}

		bool HasNaNs() const {
			return std::isnan(x) || std::isnan(y) ;
		}

		T operator[](int i) const
		{
			assert(i >= 0 && i <= 1 && "Index out of bounds");
			if (i == 0) return x;
			return y;
		};

		T &operator[](int i)
		{
			assert(i >= 0 && i <= 1 && "Index out of bounds");
			if (i == 0) return x;
			return y;
		};

	};

	

	template<class T>
	class Vector3 {
	public:
		T x=0;
		T y=0;
		T z=0;
		
		Vector3() {}

		Vector3(T x, T y, T z)
			: x(x), y(y), z(z) {
			//assert(!HasNaNs()&&"There are NaNs in the vector constructor");
		}

		bool HasNaNs() const {
			return std::isnan(x) || std::isnan(y) || std::isnan(z);
		}

		T Dot(Vector3<T> rhs) {
			return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
		}
		Float Length() {
			return sqrt(x*x + y * y + z * z);
		}
		Float LengthSquared() {
			return x*x + y * y + z * z;
		}
		Vector3<T> Abs() {
			return Vector3<T>(std::abs(x), std::abs(y), std::abs(z));
		}
		Vector3<T> Cross(const Vector3<T> &v2) {
			return Vector3<T>(
				(y * v2.z) - (z * v2.y),
				(z * v2.x) - (x * v2.z),
				(x * v2.y) - (y * v2.x));
		}

		T MinComponent() {
			return std::min(x, std::min(y, z));
		}

		T MaxComponent() {
			return std::max(x, std::max(y, z));
		}

		Vector3<T> operator/(T f) const {
			//Assert(f != 0);
			Float inv = static_cast<Float>(1) / f;
			return Vector3<T>(
				x * inv,
				y * inv, 
				z * inv);
		}

		T operator[](int i) const
		{
			assert(i >= 0 && i <= 2 && "Index out of bounds");
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		};

		T &operator[](int i)
		{
			assert(i >= 0 && i <= 2 && "Index out of bounds");
			if (i == 0) return x;
			if (i == 1) return y;
			return z;
		};

		/*Overload of the plus operator to add two vectors*/
		Vector3<T> operator+(const Vector3<T> rhs) const {
			Vector3<T> result;

			result.x = this->x + rhs.x;
			result.y = this->y + rhs.y;
			result.z = this->z + rhs.z;
			return result;
		}
		Vector3<T> operator*(T rhs) const {
			Vector3<T> result;

			result.x = this->x * rhs;
			result.y = this->y * rhs;
			result.z = this->z * rhs;
			return result;
		}

		Vector3<T> &operator/=(T f) {
			//Assert(f != 0);
			Float inv = static_cast<Float>(1) / f;
			x *= inv; 
			y *= inv; 
			z *= inv;
			return *this;
		}
		Vector3<T> operator-(const Vector3<T> rhs) const {
			Vector3<T> result;

			result.x = this->x - rhs.x;
			result.y = this->y - rhs.y;
			result.z = this->z -rhs.z;
			return result;
		}

	};
	using Vector2f = Vector2<Float>;
	using Vector2i = Vector2<int>;
	using Vector3f = Vector3<Float>;
	using Vector3i = Vector3<int>;

	template <typename T> inline Vector3<T>
	operator*(T s, const Vector3<T> &v) { return v * s; }

	template<class T>
	class Point2 {
		T x=0;
		T y=0;
	};

	template<class T>
	class Point3 {
	public:
		T x=0;
		T y=0;
		T z=0;

	
		Point3() {

		}

		//Explicit constructor
		Point3(T x, T y, T z): x(x),y(y),z(z) {

		}
		
		Point3<T> operator+(const Vector3<T> &v) const {
			return Point3<T>(
				x + v.x, 
				y + v.y, 
				z + v.z);
		}
		Point3<T> &operator+=(const Vector3<T> &v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Vector3<T> operator-(const Point3<T> &p) const {
			return Vector3<T>(x - p.x, y - p.y, z - p.z);
		}
		Point3<T> operator-(const Vector3<T> &v) const {
			return Point3<T>(x - v.x, y - v.y, z - v.z);
		}
		Point3<T> &operator-=(const Vector3<T> &v) {
			x -= v.x; y -= v.y; z -= v.z;
			return *this;
		}
		
		inline Float Distance(const Point3<T> &rhs) {
			return (*this - rhs).Length();
		} 
		inline Float DistanceSquared(const Point3<T> &rhs) {
			return (*this - rhs).LengthSquared();
		}
		Point3<T> Min(const Point3<T> &p2) {
			return Point3<T>(std::min(x, p2.x), std::min(y, p2.y),
				std::min(z, p2.z));
		}
		Point3<T> Max(const Point3<T> &p2) {
			return Point3<T>(std::max(x, p2.x), std::max(y, p2.y),
				std::max(z, p2.z));
		}
		Point3<T> Floor() {
			return Point3<T>(std::floor(x), std::floor(y), std::floor(z));
		}
		Point3<T> Ceil() {
			return Point3<T>(std::ceil(x), std::ceil(y), std::ceil(z));
		}
		Point3<T> Abs() {
			return Point3<T>(std::abs(x), std::abs(y), std::abs(z));
		}


	};

	using Point2f = Point2<Float>;
	using Point2i = Point2<int>;
	using Point3f = Point3<Float>;
	using Point3i = Point3<int>;

}

