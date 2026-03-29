#include <gtest/gtest.h>


#include <Scalars.h>

#include "Utils.h"


template <typename T>
class ScalarAddition : public ::testing::Test
{
	asmmath::Scalar<T> _lhs;
	asmmath::Scalar<T> _rhs;
	asmmath::Scalar<T> _expectedSum;

	void SetUp() override
	{
		_lhs = 2348;
		_rhs = 1352;
		_expectedSum = 3700;
	}

};

/**
 * @brief Test fixture for @ref asmmath::Scalar initialization and implicit conversion to primitive, parameterized by @ref SupportedTypes.
 */
template <typename T>
class ScalarCoreTests : public ::testing::Test {};
TYPED_TEST_SUITE(ScalarCoreTests, SupportedTypes);



/** @test Verify that scalars can be initialized with different numeric types. */
TYPED_TEST(ScalarCoreTests, InitializesToCorrectValue)
{
	constexpr TypeParam initialValue = static_cast<TypeParam>(123.567891234);
	constexpr asmmath::Scalar<TypeParam> actual = TypeParam(initialValue);
	if constexpr (std::is_same_v<TypeParam, double>)
		EXPECT_DOUBLE_EQ(initialValue, actual);
	else if constexpr (std::is_floating_point_v<TypeParam>)
		EXPECT_FLOAT_EQ(initialValue, actual);
	else
		EXPECT_EQ(initialValue, actual);
}


/** @test Verify that scalar can be used as their primitive value_type. */
TYPED_TEST(ScalarCoreTests, ImplicitConversionToPrimitives)
{
	constexpr TypeParam initialValue = 123;
	constexpr asmmath::Scalar<TypeParam> s(initialValue);

	constexpr TypeParam primitive = s;

	if constexpr (std::is_same_v<TypeParam, double>)
		EXPECT_DOUBLE_EQ(initialValue, primitive);
	else if constexpr (std::is_floating_point_v<TypeParam>)
		EXPECT_FLOAT_EQ(initialValue, primitive);
	else
		EXPECT_EQ(initialValue, primitive);
}

/**
 * @test Verify that add two numbers using @ref asmmath::add returns their sum.
 */
//TEST(Add, ReturnsSumOfTwoNumbers)
//{
//	EXPECT_EQ(9, asmmath::_asm_scalar_add(5, 4));
//}
