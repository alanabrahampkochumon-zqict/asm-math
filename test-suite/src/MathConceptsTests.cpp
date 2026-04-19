/**
 * @file MathConceptsTests.cpp
 * @author Alan Abraham P Kochumon
 * @date Created on: April 19, 2026
 *
 * @brief Verify the mathematical concepts defined in MathConcepts.h constraints
 *        and promotes types as expected.
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */


#include "MathConcepts.h"

#include <cstdint>


namespace
{
    /**
     * @brief Verify that concepts support same signed integral and/or floating
     *        as operands.
     */
    namespace
    {
        /**************************************
         *                                    *
         *            SIGNED TYPES            *
         *                                    *
         **************************************/

        // Same types
        static_assert(asmmath::SafeArithmetic<int8_t, int8_t> == true);
        static_assert(asmmath::SafeArithmetic<int16_t, int16_t> == true);
        static_assert(asmmath::SafeArithmetic<int32_t, int32_t> == true);
        static_assert(asmmath::SafeArithmetic<int64_t, int64_t> == true);

        // Cross signed types
        static_assert(asmmath::SafeArithmetic<int8_t, int16_t> == true);
        static_assert(asmmath::SafeArithmetic<int8_t, int32_t> == true);
        static_assert(asmmath::SafeArithmetic<int8_t, int64_t> == true);

        static_assert(asmmath::SafeArithmetic<int16_t, int8_t> == true);
        static_assert(asmmath::SafeArithmetic<int16_t, int32_t> == true);
        static_assert(asmmath::SafeArithmetic<int16_t, int64_t> == true);

        static_assert(asmmath::SafeArithmetic<int32_t, int8_t> == true);
        static_assert(asmmath::SafeArithmetic<int32_t, int16_t> == true);
        static_assert(asmmath::SafeArithmetic<int32_t, int64_t> == true);

        static_assert(asmmath::SafeArithmetic<int64_t, int8_t> == true);
        static_assert(asmmath::SafeArithmetic<int64_t, int16_t> == true);
        static_assert(asmmath::SafeArithmetic<int64_t, int32_t> == true);



        /**************************************
         *                                    *
         *           UNSIGNED TYPES           *
         *                                    *
         **************************************/

        // Same types
        static_assert(asmmath::SafeArithmetic<uint8_t, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<uint16_t, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<uint32_t, uint32_t> == true);
        static_assert(asmmath::SafeArithmetic<uint64_t, uint64_t> == true);

        // Cross signed types
        static_assert(asmmath::SafeArithmetic<uint8_t, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<uint8_t, uint32_t> == true);
        static_assert(asmmath::SafeArithmetic<uint8_t, uint64_t> == true);

        static_assert(asmmath::SafeArithmetic<uint16_t, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<uint16_t, uint32_t> == true);
        static_assert(asmmath::SafeArithmetic<uint16_t, uint64_t> == true);

        static_assert(asmmath::SafeArithmetic<uint32_t, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<uint32_t, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<uint32_t, uint64_t> == true);

        static_assert(asmmath::SafeArithmetic<uint64_t, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<uint64_t, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<uint64_t, uint32_t> == true);



        /**************************************
         *                                    *
         *        FLOATING POINT TYPES        *
         *                                    *
         **************************************/

        // Floating point types
        static_assert(asmmath::SafeArithmetic<float, float> == true);
        static_assert(asmmath::SafeArithmetic<double, double> == true);
        static_assert(asmmath::SafeArithmetic<float, double> == true);
        static_assert(asmmath::SafeArithmetic<double, float> == true);

        // Floating and integral types
        static_assert(asmmath::SafeArithmetic<float, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<float, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<float, uint32_t> == true);
        static_assert(asmmath::SafeArithmetic<float, uint64_t> == true);


        static_assert(asmmath::SafeArithmetic<double, uint8_t> == true);
        static_assert(asmmath::SafeArithmetic<double, uint16_t> == true);
        static_assert(asmmath::SafeArithmetic<double, uint32_t> == true);
        static_assert(asmmath::SafeArithmetic<double, uint64_t> == true);

    } // namespace


    /**
     * @brief Verify that the concept does not support opposite signed
     *        integral types.
     */
    namespace
    {

        /**************************************
         *                                    *
         *  UNSUPPORTED OPERAND COMBINATIONS  *
         *                                    *
         **************************************/

        static_assert(asmmath::SafeArithmetic<int8_t, uint8_t> == false);
        static_assert(asmmath::SafeArithmetic<int16_t, uint16_t> == false);
        static_assert(asmmath::SafeArithmetic<int32_t, uint32_t> == false);
        static_assert(asmmath::SafeArithmetic<int64_t, uint64_t> == false);

        static_assert(asmmath::SafeArithmetic<int8_t, uint16_t> == false);
        static_assert(asmmath::SafeArithmetic<int8_t, uint32_t> == false);
        static_assert(asmmath::SafeArithmetic<int8_t, uint64_t> == false);

        static_assert(asmmath::SafeArithmetic<int16_t, uint8_t> == false);
        static_assert(asmmath::SafeArithmetic<int16_t, uint32_t> == false);
        static_assert(asmmath::SafeArithmetic<int16_t, uint64_t> == false);

        static_assert(asmmath::SafeArithmetic<int32_t, uint8_t> == false);
        static_assert(asmmath::SafeArithmetic<int32_t, uint16_t> == false);
        static_assert(asmmath::SafeArithmetic<int32_t, uint64_t> == false);

        static_assert(asmmath::SafeArithmetic<int64_t, uint8_t> == false);
        static_assert(asmmath::SafeArithmetic<int64_t, uint16_t> == false);
        static_assert(asmmath::SafeArithmetic<int64_t, uint32_t> == false);
    } // namespace


    /**
     * @brief Verify that @ref asmmath::SafeType promotes integral types using
     *        `std::common_type_t`.
     */
    namespace
    {
        // Unsigned types
        static_assert(std::is_same_v<asmmath::SafeType<uint8_t, uint16_t>::type,
                                     int32_t>);
        static_assert(std::is_same_v<asmmath::SafeType<uint8_t, uint32_t>::type,
                                     uint32_t>);
        static_assert(std::is_same_v<asmmath::SafeType<uint8_t, uint64_t>::type,
                                     uint64_t>);
        static_assert(std::is_same_v<asmmath::SafeType<uint8_t, uint64_t>::type,
                                     uint64_t>);

        static_assert(std::is_same_v<
                      asmmath::SafeType<uint16_t, uint32_t>::type, uint32_t>);
        static_assert(std::is_same_v<
                      asmmath::SafeType<uint16_t, uint64_t>::type, uint64_t>);

        static_assert(std::is_same_v<
                      asmmath::SafeType<uint32_t, uint64_t>::type, uint64_t>);

        // Signed types
        static_assert(
            std::is_same_v<asmmath::SafeType<int8_t, int16_t>::type, int32_t>);
        static_assert(
            std::is_same_v<asmmath::SafeType<int8_t, int32_t>::type, int32_t>);
        static_assert(
            std::is_same_v<asmmath::SafeType<int8_t, int64_t>::type, int64_t>);
        static_assert(
            std::is_same_v<asmmath::SafeType<int8_t, int64_t>::type, int64_t>);

        static_assert(
            std::is_same_v<asmmath::SafeType<int16_t, int32_t>::type, int32_t>);
        static_assert(
            std::is_same_v<asmmath::SafeType<int16_t, int64_t>::type, int64_t>);

        static_assert(
            std::is_same_v<asmmath::SafeType<int32_t, int64_t>::type, int64_t>);
    } // namespace


    /**
     * @brief Verify that @ref asmmath::SafeType promotes the result to a
     *        floating-point type if either of the operand is a floating-point
     *        type.
     */
    namespace
    {
        // 32-bit floating-point types
        static_assert(
            std::is_same_v<asmmath::SafeType<float, uint8_t>::type, float>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, uint16_t>::type, float>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, uint32_t>::type, float>);

        static_assert(
            std::is_same_v<asmmath::SafeType<float, int8_t>::type, float>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, int16_t>::type, float>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, int32_t>::type, float>);

        static_assert(
            std::is_same_v<asmmath::SafeType<float, float>::type, float>);


        // 64-bit floating-point types
        static_assert(
            std::is_same_v<asmmath::SafeType<double, uint8_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, uint16_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, uint32_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, uint64_t>::type, double>);

        static_assert(
            std::is_same_v<asmmath::SafeType<double, int8_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, int16_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, int32_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<double, int64_t>::type, double>);
    } // namespace


    /**
     * @brief Verify that @ref asmmath::SafeType promotes the result to a
     *        64-bit floating-point type either of the operand is larger than a
     *        32-bit floating-point type.
     */
    namespace
    {

        static_assert(
            std::is_same_v<asmmath::SafeType<float, uint64_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, int64_t>::type, double>);
        static_assert(
            std::is_same_v<asmmath::SafeType<float, double>::type, double>);
    } // namespace

} // namespace
