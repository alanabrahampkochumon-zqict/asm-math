#pragma once
/**
 * @file Scalars.h
 * @author Alan Abraham P Kochumon
 * @date Created on: March 29, 2026
 *
 * @brief Definitions of all scalar math functions.
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */

namespace asmmath
{
	extern "C" {
		int _asm_scalar_add_8(int a, int b);
		int _asm_scalar_add_16(int a, int b);
		int _asm_scalar_add_32(int a, int b);
		int _asm_scalar_add_64(int a, int b);
	}


	template <typename T>
	struct Scalar
	{
		using value_type = T; ///< Value type of scalar.


		/**
		 * @brief Instantiate a @ref Scalar with a passed-in parameter.
		 * 
		 * @param value The value to initialize the scalar with.
		 */
		constexpr Scalar(T value) noexcept;

		/**
		 * @brief Treat a @ref Scalar instance as the fundamental `value_type` primitive.
		 *		  
		 * @return The current value held by the current instance. 
		 */
		constexpr operator T() const noexcept;

	private:
		T _value; ///< Internal data store of the _value.
	};

}


#include "Scalars.tpp"