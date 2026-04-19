/**
 * @file MathConceptsTests.cpp
 * @author Alan Abraham P Kochumon
 * @date Created on: April 19, 2026
 *
 * @brief Verify the mathematical concepts defined in MathConcepts.h constraints and promotes types as expected.
 *
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */


#include "MathConcepts.h"
#include <cstdint>


namespace
{
	/** @brief Verify that concepts support same signed integral and/or floating as operands. */
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

	}


	/** @brief Verify that the concept does not support opposite signed integral. */
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
	}

}
