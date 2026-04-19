#pragma once
/**
 * @file Scalars.h
 * @author Alan Abraham P Kochumon
 * @date Created on: March 29, 2026
 *
 * @brief Scalar math operation between two or more operands.
 * 
 * @note To promote safety, the library forbids mixing of signed and unsigned operands, unless any of the operands is a floating point type, in which case, the type is promoted to the floating point equivalent.
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */

namespace asmmath
{
	
	template <typename T>
	struct Scalar
	{
		using value_type = T; ///< Value type of scalar.


		/**
		 * @brief Explicitly generated default constructor.
		 */
		constexpr Scalar() noexcept = default;


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


		/**
		 * @brief Perform addition of two scalars.
		 * 
		 * @tparam U The numeric type of RHS operand.
		 * 
		 * @param rhs The scalar to add.
		 * 
		 * @return The sum of two scalars.
		 */
		template <typename U>
		constexpr auto operator+(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>;


		/**
		 * @brief Perform subtraction between two scalars.
		 *
		 * @tparam U The numeric type of RHS operand.
		 *
		 * @param rhs The scalar to subtract.
		 *
		 * @return The difference between two scalars.
		 */
		template <typename U>
		constexpr auto operator-(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>;


		/**
		 * @brief Perform multiplication between two scalars.
		 * 
		 * @note The type is promoted to the wider numeric type using `std::common_type_t<T, U>`.
		 *
		 * @tparam U The numeric type of RHS operand.
		 *
		 * @param rhs The scalar to multiply.
		 *
		 * @return The product of two scalars.
		 */
		template <typename U>
		constexpr auto operator*(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>;


		/**
		 * @brief Divide a scalar by another.
		 *
		 * @note The type is promoted to the wider numeric type using `std::common_type_t<T, U>`.
		 *
		 * @tparam U The numeric type of RHS operand.
		 *
		 * @param rhs The scalar to divide by.
		 *
		 * @return The quotient from the division.
		 */
		template <typename U>
		constexpr auto operator/(Scalar<U> rhs) const noexcept -> std::common_type_t<T, U>;

	private:
		T _value; ///< Internal data store of the value.
	};
}


#include "Scalars.tpp"