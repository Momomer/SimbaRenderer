#pragma once
#include <cmath>


/*This file is equivalent to pbrt.h*/


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



	
	
}