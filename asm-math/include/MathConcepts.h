#pragma once
/**
 * @file MathConcepts.h
 * @author Alan Abraham P Kochumon
 * @date Created on: April 19, 2026
 *
 * @brief Define C++20 concepts for numeric types and operation safety.
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */

#include <concepts>
#include <type_traits>

namespace asmmath
{

    /**
     * @brief C++20 concept for safe numeric operations limiting LHS and RHS
     *        operand to be both signed integrals, or unsigned integrals, or
     *        either of the two being a floating-point, since at least one
     *        floating-point operand implicitly suggest the requirement of a
     *        floating-point operation.
     */
    template <typename T, typename U>
    concept SafeArithmetic =
        (std::signed_integral<T> && std::signed_integral<U>) ||
        (std::unsigned_integral<T> && std::unsigned_integral<U>) ||
        (std::floating_point<T> || std::floating_point<U>);


    /**
     * @brief Partial template specialization for promoting between numeric
     *        types using `std::common_type_t`.
     */
    template <typename T, typename U>
    struct SafeType
    {
        using type = std::common_type_t<T, U>;
    };


    /**
     * @brief Template specialization of @ref SafeType that promotes a wider
     *        integral and narrow floating-point type (32-bit float) to a wider
     *        floating-point type (64-bit float, or double).
     */
    template <typename T, typename U>
        requires std::floating_point<T> || std::floating_point<U>
    struct SafeType<T, U>
    {
        using type =
            std::conditional_t<(sizeof(T) > 4 || sizeof(U) > 4), double, float>;
    };

} // namespace asmmath
