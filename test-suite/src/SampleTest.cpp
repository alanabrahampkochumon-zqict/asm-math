#include <gtest/gtest.h>


#include <Scalars.h>

#include "Utils.h"



TEST(SampleTest, OnePlusOneEqualsTwo)
{
	EXPECT_EQ(2, 1 + 1);
}

/**
 * @test Verify that add two numbers using @ref asmmath::add returns their sum.
 */
TEST(Add, ReturnsSumOfTwoNumbers)
{
	EXPECT_EQ(9, asmmath::_asm_scalar_add(5, 4));
}