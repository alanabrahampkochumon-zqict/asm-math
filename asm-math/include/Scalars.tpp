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

#include "MathConcepts.h"
#include <cstdint>
#include <type_traits>


namespace asmmath
{
    extern "C" {
        // NOLINTBEGIN(readability-identifier-naming)
        int8_t _scalar_add_8(int8_t a, int8_t b);

        int16_t _scalar_add_16(int16_t a, int16_t b);

        int32_t _scalar_add_32(int32_t a, int32_t b);

        int64_t _scalar_add_64(int64_t a, int64_t b);

        float _scalar_add_fp32(float a, float b);

        double _scalar_add_fp64(double a, double b);

        int8_t _scalar_sub_8(int8_t a, int8_t b);

        int16_t _scalar_sub_16(int16_t a, int16_t b);

        int32_t _scalar_sub_32(int32_t a, int32_t b);

        int64_t _scalar_sub_64(int64_t a, int64_t b);

        float _scalar_sub_fp32(float a, float b);

        double _scalar_sub_fp64(double a, double b);

        int8_t _scalar_mul_8(int8_t a, int8_t b);

        int16_t _scalar_mul_16(int16_t a, int16_t b);

        int32_t _scalar_mul_32(int32_t a, int32_t b);

        int64_t _scalar_mul_64(int64_t a, int64_t b);

        float _scalar_mul_fp32(float a, float b);

        double _scalar_mul_fp64(double a, double b);


        // Division
        int8_t _scalar_div_8(int8_t a, int8_t b);

        int16_t _scalar_div_16(int16_t a, int16_t b);

        int32_t _scalar_div_32(int32_t a, int32_t b);

        int64_t _scalar_div_64(int64_t a, int64_t b);

        uint8_t _scalar_div_8u(uint8_t a, uint8_t b);

        uint16_t _scalar_div_16u(uint16_t a, uint16_t b);

        uint32_t _scalar_div_32u(uint32_t a, uint32_t b);

        uint64_t _scalar_div_64u(uint64_t a, uint64_t b);

        float _scalar_div_fp32(float a, float b);

        double _scalar_div_fp64(double a, double b);

        // NOLINTEND(readability-identifier-naming)
    }


    template <typename T>
    constexpr Scalar<T>::Scalar(const T value) noexcept : _value(value) {}


    template <typename T>
    constexpr Scalar<T>::operator T() const noexcept { return _value; }


    template <typename T>
    constexpr Scalar<T>::operator T() noexcept { return _value; }


    template <typename T>
    template <typename U>
    constexpr SafeType<T, U>::type Scalar<T>::operator+(Scalar<U> rhs) const noexcept
        requires SafeArithmetic<T, U>
    {
        using R = SafeType<T, U>::type;

        if constexpr (std::is_same_v<R, double>)
            return _scalar_add_fp64(static_cast<R>(*this), static_cast<R>(rhs));
        else if constexpr (std::is_floating_point_v<T>)
            return _scalar_add_fp32(static_cast<R>(*this), static_cast<R>(rhs));
        else if constexpr (sizeof(R) == 1)
            return static_cast<R>(_scalar_add_8(static_cast<int8_t>(*this), static_cast<int8_t>(rhs)));
        else if constexpr (sizeof(R) == 2)
            return static_cast<R>(_scalar_add_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
        else if constexpr (sizeof(R) == 4)
            return static_cast<R>(_scalar_add_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
        else if constexpr (sizeof(R) == 8)
            return static_cast<R>(_scalar_add_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
        else // Fallback, shouldn't hit this case during normal ops.
            return *this + rhs;
    }


    template <typename T>
    template <typename U>
    constexpr SafeType<T, U>::type Scalar<T>::operator-(Scalar<U> rhs) const noexcept
        requires SafeArithmetic<T, U>
    {
        using R = SafeType<T, U>::type;

        if constexpr (std::is_same_v<R, double>)
            return _scalar_sub_fp64(static_cast<R>(*this), static_cast<R>(rhs));
        else if constexpr (std::is_floating_point_v<T>)
            return _scalar_sub_fp32(static_cast<R>(*this), static_cast<R>(rhs));
        else if constexpr (sizeof(R) == 1)
            return static_cast<R>(_scalar_sub_8(static_cast<int8_t>(*this), static_cast<int8_t>(rhs)));
        else if constexpr (sizeof(R) == 2)
            return static_cast<R>(_scalar_sub_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
        else if constexpr (sizeof(R) == 4)
            return static_cast<R>(_scalar_sub_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
        else if constexpr (sizeof(R) == 8)
            return static_cast<R>(_scalar_sub_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
        else // Fallback, shouldn't hit this case during normal ops.
            return *this + rhs;
    }


    template <typename T>
    template <typename U>
    constexpr SafeType<T, U>::type Scalar<T>::operator*(Scalar<U> rhs) const noexcept
        requires SafeArithmetic<T, U>
    {
        using R = SafeType<T, U>::type;
        if constexpr (std::is_same_v<R, double>)
            return static_cast<R>(_scalar_mul_fp64(static_cast<R>(*this), static_cast<R>(rhs)));
        else if constexpr (std::is_floating_point_v<R>)
            return static_cast<R>(_scalar_mul_fp32(static_cast<R>(*this), static_cast<R>(rhs)));
        else if constexpr (sizeof(R) == 1)
            // Since IMUL 2 operand variant doesn't support byte (8-bit) integrals we
            // are temporarily promoting the type, performing the operation and
            // demoting the result.
            return static_cast<R>(_scalar_mul_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
        else if constexpr (sizeof(R) == 2)
            return static_cast<R>(_scalar_mul_16(static_cast<int16_t>(*this), static_cast<int16_t>(rhs)));
        else if constexpr (sizeof(R) == 4)
            return static_cast<R>(_scalar_mul_32(static_cast<int32_t>(*this), static_cast<int32_t>(rhs)));
        else if constexpr (sizeof(R) == 8)
            return static_cast<R>(_scalar_mul_64(static_cast<int64_t>(*this), static_cast<int64_t>(rhs)));
        else // Fallback, shouldn't hit this case during normal ops.
            return *this * rhs;
    }


    template <typename T>
    template <typename U>
    constexpr SafeType<T, U>::type Scalar<T>::operator/(Scalar<U> rhs) const noexcept
        requires SafeArithmetic<T, U>
    {
        using R = SafeType<T, U>::type;
        // Double precision floats
        if constexpr (std::is_same_v<R, double>)
        {
            return _scalar_div_fp64(static_cast<R>(*this), static_cast<R>(rhs));
        }
        else if constexpr (std::is_floating_point_v<R>)
        {
            return _scalar_div_fp32(static_cast<R>(*this), static_cast<R>(rhs));
        }
        else if constexpr (std::is_signed_v<R>)
        {
            if constexpr (sizeof(R) == 1)
                return _scalar_div_8(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 2)
                return _scalar_div_16(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 4)
                return _scalar_div_32(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 8)
                return _scalar_div_64(static_cast<R>(*this), static_cast<R>(rhs));
        }
        else if constexpr (std::is_unsigned_v<R>)
        {
            if constexpr (sizeof(R) == 1)
                return _scalar_div_8u(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 2)
                return _scalar_div_16u(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 4)
                return _scalar_div_32u(static_cast<R>(*this), static_cast<R>(rhs));
            else if constexpr (sizeof(R) == 8)
                return _scalar_div_64u(static_cast<R>(*this), static_cast<R>(rhs));
        }
    }
} // namespace asmmath
