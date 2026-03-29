#pragma once
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
	template <typename T>
	constexpr Scalar<T>::Scalar(const T value) noexcept : _value(value)
	{
	}


	template <typename T>
	constexpr Scalar<T>::operator T() const noexcept { return _value; }
}

