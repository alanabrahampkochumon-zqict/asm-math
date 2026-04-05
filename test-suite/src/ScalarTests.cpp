#include <gtest/gtest.h>


#include <Scalars.h>

#include "Utils.h"



/**
 * @brief Test fixture for @ref asmmath::Scalar initialization and implicit conversion to primitive, parameterized by @ref SupportedTypes.
 */
template <typename T>
class ScalarCoreTests : public ::testing::Test {};
TYPED_TEST_SUITE(ScalarCoreTests, SupportedTypes);


/**
 * @brief Test fixture for @ref asmmath::Scalar addition, parameterized by @ref SupportedTypes.
 */
template <typename T>
class ScalarAddition : public ::testing::Test
{
protected:
	asmmath::Scalar<T> _lhs;
	asmmath::Scalar<T> _rhs;
	asmmath::Scalar<T> _expectedSum;

	void SetUp() override
	{
		_lhs = T(31);
		_rhs = T(16);
		_expectedSum = T(47);
	}
};
TYPED_TEST_SUITE(ScalarAddition, SupportedTypes);



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
 * @test Verify that adding two scalars return their sum.
 */
TYPED_TEST(ScalarAddition, ReturnsSumOfTwoNumbers)
{
	const TypeParam sum = this->_lhs + this->_rhs;

	if constexpr (std::is_same_v<TypeParam, double>)
		EXPECT_DOUBLE_EQ(this->_expectedSum, sum);
	else if constexpr (std::is_floating_point_v<TypeParam>)
		EXPECT_FLOAT_EQ(this->_expectedSum, sum);
	else
		EXPECT_EQ(this->_expectedSum, sum);
}
