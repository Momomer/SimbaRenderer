#pragma once
#include <assert.h> 
#include<algorithm>
#include<memory>
#include "simba.h"
#include "medium.h"

namespace sba {
	
	/*Two dimensional vector with generic elements.*/
	template<class T>
	class Vector2 {
	public:
		T x = 0;
		T y = 0;


		Vector2<T>() {}

		Vector2<T>(T x, T y)
			: x(x), y(y) {
			//assert(!HasNaNs() && "There are NaNs in the vector constructor");
		}

		bool HasNaNs() const {
			return std::isnan(x) || std::isnan(y);
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
		Vector2<T> operator+(const Vector2<T> rhs) const {
			Vector2<T> result;

			result.x = this->x + rhs.x;
			result.y = this->y + rhs.y;
			return result;
		}
		Vector2<T> operator*(T rhs) const {
			Vector2<T> result;

			result.x = this->x * rhs;
			result.y = this->y * rhs;
			return result;
		}

		Vector2<T> &operator/=(T f) {
			//Assert(f != 0);
			Float inv = static_cast<Float>(1) / f;
			x *= inv;
			y *= inv;
			return *this;
		}
		Vector2<T> operator-(const Vector2<T> rhs) const {
			Vector2<T> result;

			result.x = this->x - rhs.x;
			result.y = this->y - rhs.y;
			return result;
		}

	};

	/*Three dimensional vector with generic arguments.*/
	template<class T>
	class Vector3 {
	public:
		T x = 0;
		T y = 0;
		T z = 0;

		Vector3() {}

		Vector3(T x, T y, T z)
			: x(x), y(y), z(z) {
			//assert(!HasNaNs()&&"There are NaNs in the vector constructor");
		}

		bool HasNaNs() const {
			return std::isnan(x) || std::isnan(y) || std::isnan(z);
		}

		/*Returns the dot product between two vectors.*/
		T Dot(Vector3<T> rhs) {
			return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
		}

		/*Returns the Euclidian norm of a vector.*/
		Float Length() {
			return sqrt(x*x + y * y + z * z);
		}

		/*Returns the squared Euclidian norm of a vector. This is in many situations
		preferred to the true length, as the square root does not have to be calculated.*/
		Float LengthSquared() {
			return x * x + y * y + z * z;
		}

		/*Returns a new vector, that has the absolute value of all elements of the old vector as elements.*/
		Vector3<T> Abs() {
			return Vector3<T>(std::abs(x), std::abs(y), std::abs(z));
		}

		/*Calculates the cross vector between two vectors.*/
		Vector3<T> Cross(const Vector3<T> &v2) {
			return Vector3<T>(
				(y * v2.z) - (z * v2.y),
				(z * v2.x) - (x * v2.z),
				(x * v2.y) - (y * v2.x));
		}

		/*Extracts the minimum element of the vector.*/
		T MinComponent() {
			return std::min(x, std::min(y, z));
		}
		/*Extracts the maximum element of the vector.*/
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
			result.z = this->z - rhs.z;
			return result;
		}

	};
	using Vector2f = Vector2<Float>;
	using Vector2i = Vector2<int>;
	using Vector3f = Vector3<Float>;
	using Vector3i = Vector3<int>;
	
	template <typename T> 
	inline Vector3<T> operator*(T s, const Vector3<T> &v) { return v * s; }

		//Forward declaration of Point3. Might have to change it to extern?
		template<class T>
		class Point3;

		template<class T>
		class Point2 {
		public:
			T x = 0;
			T y = 0;



			Point2() { x = y = 0; }
			Point2(T x, T y) : x(x), y(y) {
				//Assert(!HasNaNs());
			}

			explicit Point2<T>(const Point3<T>& p) : x(p.x), y(p.y) {

			}

			bool HasNaNs() const {
				return std::isnan(x) || std::isnan(y);
			}

			Point2<T> operator+(const Vector2<T> &v) const {
				return Point2<T>(
					x + v.x,
					y + v.y);
			}
			Point2<T> &operator+=(const Vector2<T> &v) {
				x += v.x;
				y += v.y;
				return *this;
			}
			Vector2<T> operator-(const Point2<T> &v) const {
				return Vector2<T>(x - v.x, y - v.y);
			}


		};

		template<class T>
		class Point3 {
		public:
			T x = 0;
			T y = 0;
			T z = 0;




			//Explicit constructor

			Point3() { x = y = z = 0; }
			Point3(T x, T y, T z) : x(x), y(y), z(z) {
				//Assert(!HasNaNs());
			}

			bool HasNaNs() const {
				return std::isnan(x) || std::isnan(y) || std::isnan(z);
			}

			Point3<T> operator+(const Vector3<T> &v) const {
				return Point3<T>(
					x + v.x,
					y + v.y,
					z + v.z);
			}
			Point3<T> operator+(const Point3<T> &v) const {
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

			Point3<T> operator*(T rhs) const {
				Point3<T> result;

				result.x = this->x * rhs;
				result.y = this->y * rhs;
				result.z = this->z * rhs;
				return result;
			}
			inline Float Distance(const Point3<T> &rhs) {
				return (*this - rhs).Length();
			}
			inline Float DistanceSquared(const Point3<T> &rhs) {
				return (*this - rhs).LengthSquared();
			}
			//Returns elementwise minimum of two points
			Point3<T> Min(const Point3<T> &p2) {
				return Point3<T>(std::min(x, p2.x), std::min(y, p2.y),
					std::min(z, p2.z));
			}

			//Returns elementwise maximum of two points
			Point3<T> Max(const Point3<T> &p2) {
				return Point3<T>(std::max(x, p2.x), std::max(y, p2.y),
					std::max(z, p2.z));
			}
			//Floors all elements of a Point. Useful if elements are floating point number
			Point3<T> Floor() {
				return Point3<T>(std::floor(x), std::floor(y), std::floor(z));
			}

			//Ceils all elements of a Point. Useful if elements are floating point number
			Point3<T> Ceil() {
				return Point3<T>(std::ceil(x), std::ceil(y), std::ceil(z));
			}
			//Makes all elements positive. 
			Point3<T> Abs() {
				return Point3<T>(std::abs(x), std::abs(y), std::abs(z));
			}

			//Line equation between points p0 and p1
			Point3<T> Lerp(Float t, const Point3<T> &p1) {
				return  (*this)*(1 - t) + p1 * t;
			}

			//Casting operator so you can cast a Point3 to a Vector3 like auto v=(Vector3f)p1;
			template <typename U> explicit operator Vector3<U>() const {
				return Vector3<U>(x, y, z);
			}


		};

		using Point2f = Point2<Float>;
		using Point2i = Point2<int>;
		using Point3f = Point3<Float>;
		using Point3i = Point3<int>;

		template<class T>
		class Normal3 {
		public:
			T x = 0;
			T y = 0;
			T z = 0;


			Normal3() {  }
			Normal3(T x, T y, T z) : x(x), y(y), z(z) {

			}
			explicit Normal3<T>(const Vector3<T> &v) : x(v.x), y(v.y), z(v.z) {
				//Assert(!v.HasNaNs());
			}
 
			
			Normal3<T> Faceforward(const Vector3<T> &v) {
				return ((*this).Dot(v) < 0.f) ? -(*this) : (*this);
			}
		};

		using Normal3f = Normal3<Float>;
		Float  Infinity=std::numeric_limits<Float>::infinity();

		/*The ray class represents a line segment limited by t in [0,tMax].*/
		template<class T>
		class Ray {
		public:
			Point3f o;
			Vector3f d;
			mutable Float tMax;
			Float time;
			const std::shared_ptr<Medium> medium;

			Ray() : tMax(Infinity), time(0.f), medium(nullptr) { }
			Ray(const Point3f &o, const Vector3f &d, Float tMax = Infinity,
				Float time = 0.f, const Medium *medium = nullptr)
				: o(o), d(d), tMax(tMax), time(time), medium(medium) { }

			Point3f operator()(Float t) const { return o + d * t; }


		};
}

