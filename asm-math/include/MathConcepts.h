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


 /**
  * @brief Concept for safe numeric operations limiting LHS and RHS operand to be both signed integrals, or unsigned integrals,
  *        or either of the two being a floating point, since at least one floating point operand implicitly suggest
  *        the requirement of a floating point operation.
  */
template<typename T, typename U>
concept SafeArithmetic = (std::signed_integral<T> && std::signed_integral<U>) || (std::unsigned_integral<T> && std::unsigned_integral<U>) || (std::floating_point<T> || std::floating_point<U>);
