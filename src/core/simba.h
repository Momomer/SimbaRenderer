//#pragma once
#include <cmath>
#include <cstdint>


/*This file is equivalent to pbrt.h*/

#ifndef SIMBA_PBRT_H
#define SIMBA_PBRT_H

namespace sba{

	#ifdef PBRT_FLOAT_AS_DOUBLE
		using Float=double;
	#else
		using Float=float;
	#endif // PBRT_FLOAT_AS_DOUBLE
		constexpr Float Pi = 3.14159265358979323846;
		constexpr Float InvPi = 0.31830988618379067154;
		constexpr Float Inv2Pi = 0.15915494309189533577;
		constexpr Float Inv4Pi = 0.07957747154594766788;
		constexpr Float PiOver2 = 1.57079632679489661923;
		constexpr Float PiOver4 = 0.78539816339744830961;
		constexpr Float Sqrt2 = 1.41421356237309504880;

	#if defined(__clang__)
		inline int Log2Int(uint32_t v) {
			return 31 - __builtin_clz(v);
		}
	#elif defined(__GNUC__) || defined(__GNUG__)
		inline int Log2Int(uint32_t v) {
			return 31 - __builtin_clz(v);
}
	#elif defined(_MSC_VER)
#include<intrin.h>
	inline int Log2Int(uint32_t  x) {
		unsigned long index;
		_BitScanReverse(&index, x); //VCC Befehl
		return static_cast<int>(index); //GCC hat __builtin_clz 
	}
	#endif


	//Clamping a value into the interval [low,high]
	template <typename T, typename U, typename V>
	inline T Clamp(T val, U low, V high) {
		if (val < low) return low;
		else if (val > high) return high;
		else return val;
	}

	//Calculating the true remainder (modulos) of two integers a,b
	template <typename T> inline T Mod(T a, T b) {
		T result = a%b;
		if (result < 0) {
			return result + b;
		}
		else {
			return result;
		}
	}

	//Calculating the floating point remainder. See the documentation for std::fmd for details
	inline Float Mod(Float a, Float b) {
		return std::fmod(a, b);
	}

	//Calculating the logarithm with respect to base 2.
	inline Float Log2(Float x) {
		const Float invLog2 = 1.442695040888963387004650940071;
		return std::log(x) * invLog2;
	}

	//Converting degrees into radians
	inline Float Radians(Float deg) {
		return (Pi / 180) * deg;
	}


	//Converting radians into degrees
	inline Float Degrees(Float rad) {
		return (180 / Pi) * rad;
	}
	template <typename T> inline bool IsPowerOfTwo(T v) {
		return v && !(v & (v - 1));
	}
	inline int32_t RoundUpPow2(int32_t v) {
		v--;
		v |= v >> 1;    v |= v >> 2;
		v |= v >> 4;    v |= v >> 8;
		v |= v >> 16;
		return v + 1;
	}	
	template <typename Predicate> int FindInterval(int size, const Predicate &pred) {
		int first = 0, len = size;
		while (len > 0) {
			int half = len >> 1, middle = first + half;
				if (pred(middle)) {
					first = middle + 1;
					len -= half + 1;
				}
				else
					len = half;
		}
		return Clamp(first - 1, 0, size - 2);
	}

	
}


#endif