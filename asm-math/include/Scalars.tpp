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
		double _asm_scalar_add_f64(double a, double b);

		int8_t _asm_scalar_sub_8(int8_t a, int8_t b);
		int16_t _asm_scalar_sub_16(int16_t a, int16_t b);
		int32_t _asm_scalar_sub_32(int32_t a, int32_t b);
		int64_t _asm_scalar_sub_64(int64_t a, int64_t b);
		float _asm_scalar_sub_f32(float a, float b);
		double _asm_scalar_sub_f64(double a, double b);


		int16_t _asm_scalar_mul_16(int16_t a, int16_t b);
		int32_t _asm_scalar_mul_32(int32_t a, int32_t b);
		int64_t _asm_scalar_mul_64(int64_t a, int64_t b);
		float _asm_scalar_mul_f32(float a, float b);
		double _asm_scalar_mul_f64(double a, double b);
	}

	template <typename T>
	constexpr Scalar<T>::Scalar(const T value) noexcept : _value(value) {}


	template <typename T>
	constexpr Scalar<T>::operator T() const noexcept { return _value; }


	template <typename T>
	template <typename U>
	constexpr auto Scalar<T>::operator+(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>
	{
		using R = std::common_type_t<T, U>;

		if constexpr (std::is_same_v<R, double>)
			return _asm_scalar_add_f64(static_cast<R>(*this), static_cast<R>(rhs));
		else if constexpr (std::is_floating_point_v<T>)
			return _asm_scalar_add_f32(static_cast<R>(*this), static_cast<R>(rhs));
		else if constexpr (sizeof(R) == 1)
			return static_cast<R>(_asm_scalar_add_8(static_cast<int8_t>(*this), static_cast<int8_t>(rhs)));
		else if constexpr (sizeof(R) == 2)
			return static_cast<R>(_asm_scalar_add_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
		else if constexpr (sizeof(R) == 4)
			return static_cast<R>(_asm_scalar_add_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
		else if constexpr (sizeof(R) == 8)
			return static_cast<R>(_asm_scalar_add_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
		else // Fallback, shouldn't hit this case during normal ops.
			return *this + rhs;
	}


	template <typename T>
	template <typename U>
	constexpr auto Scalar<T>::operator-(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>
	{
		using R = std::common_type_t<T, U>;
		if constexpr (std::is_same_v<R, double>)
			return _asm_scalar_sub_f64(static_cast<R>(*this), static_cast<R>(rhs));
		else if constexpr (std::is_floating_point_v<T>)
			return _asm_scalar_sub_f32(static_cast<R>(*this), static_cast<R>(rhs));
		else if constexpr (sizeof(R) == 1)
			return static_cast<R>(_asm_scalar_sub_8(static_cast<int8_t>(*this), static_cast<int8_t>(rhs)));
		else if constexpr (sizeof(R) == 2)
			return static_cast<R>(_asm_scalar_sub_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
		else if constexpr (sizeof(R) == 4)
			return static_cast<R>(_asm_scalar_sub_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
		else if constexpr (sizeof(R) == 8)
			return static_cast<R>(_asm_scalar_sub_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
		else // Fallback, shouldn't hit this case during normal ops.
			return *this + rhs;
	}


	template <typename T>
	template <typename U>
	constexpr auto Scalar<T>::operator*(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>
	{
		using R = std::common_type_t<T, U>;
		if constexpr (std::is_same_v<R, double>)
			return static_cast<R>(_asm_scalar_mul_f32(static_cast<R>(*this), static_cast<R>(rhs)));
		else if constexpr (std::is_floating_point_v<R>)
			return static_cast<R>(_asm_scalar_mul_f64(static_cast<R>(*this), static_cast<R>(rhs)));
		else if constexpr (sizeof(R) == 1)
			// Since IMUL 2 operand variant doesn't support 1byte integral we are temporarily promoting the type, performing the operation and demoting the result.
			return static_cast<R>(_asm_scalar_mul_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs))); 
		else if constexpr (sizeof(R) == 2)
			return static_cast<R>(_asm_scalar_mul_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
		else if constexpr (sizeof(R) == 4)
			return static_cast<R>(_asm_scalar_mul_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
		else if constexpr (sizeof(R) == 8)
			return static_cast<R>(_asm_scalar_mul_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
		else // Fallback, shouldn't hit this case during normal ops.
			return (*this) * rhs;
	}


	template <typename T>
	template <typename U>
	constexpr auto Scalar<T>::operator/(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>
	{
		return *this;
	}
}

