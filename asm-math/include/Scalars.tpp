#pragma once
#include "Scalars.h"
/**
 * @file Scalars.tpp
 * @author Alan Abraham P Kochumon
 * @date Created on: March 29, 2026
 *
 * @brief Implementation of member functions defined in "Scalars.h"
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */


namespace asmmath
{

	extern "C" {
		int8_t _asm_scalar_add_8(int8_t a, int8_t b);
		int16_t _asm_scalar_add_16(int16_t a, int16_t b);
		int32_t _asm_scalar_add_32(int32_t a, int32_t b);
		int64_t _asm_scalar_add_64(int64_t a, int64_t b);
		float _asm_scalar_add_f32(float a, float b);
		float _asm_scalar_add_f64(float a, float b);
	}

	template <typename T>
	constexpr Scalar<T>::Scalar(const T value) noexcept : _value(value) {}


	template <typename T>
	constexpr Scalar<T>::operator T() const noexcept { return _value; }


	template <typename T>
	constexpr Scalar<T> Scalar<T>::operator+(Scalar rhs) const noexcept
	{
		if constexpr (std::is_same_v<T, double>)
			return _asm_scalar_add_f64(*this, rhs);
		else if constexpr (std::is_floating_point_v<T>)
			return _asm_scalar_add_f32(*this, rhs);
		else if constexpr (sizeof(T) == 1)
			return static_cast<T>(_asm_scalar_add_8(static_cast<int8_t>(*this), static_cast<int8_t>(rhs)));
		else if constexpr (sizeof(T) == 2)
			return static_cast<T>(_asm_scalar_add_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
		else if constexpr (sizeof(T) == 4)
			return static_cast<T>(_asm_scalar_add_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
		else if constexpr (sizeof(T) == 8)
			return static_cast<T>(_asm_scalar_add_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
		else // Fallback, shouldn't hit this case during normal ops.
			return *this + rhs;
	}
}

