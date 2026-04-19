#include "Utils.h"

#include <Scalars.h>
#include <gtest/gtest.h>

/**************************************
 *                                    *
 *            TEST SETUP              *
 *                                    *
 **************************************/

/**
 * @brief Test fixture for @ref asmmath::Scalar initialization and implicit
 *        conversion to primitive, parameterized by @ref SupportedTypes.
 */
template <typename T>
class ScalarCoreTests: public ::testing::Test
{};
TYPED_TEST_SUITE(ScalarCoreTests, SupportedTypes);


/**
 * @brief Test fixture for @ref asmmath::Scalar addition, parameterized by 
 *        @ref SupportedTypes.
 */
template <typename T>
class ScalarAddition: public ::testing::Test
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


/**
 * @brief Test fixture for @ref asmmath::Scalar subtraction, parameterized by
 *        @ref SupportedTypes.
 */
template <typename T>
class ScalarSubtraction: public ::testing::Test
{
protected:
    asmmath::Scalar<T> _lhs;
    asmmath::Scalar<T> _rhs;
    asmmath::Scalar<T> _expectedDifference;

    void SetUp() override
    {
        _lhs = T(31);
        _rhs = T(16);
        _expectedDifference = T(15);
    }
};
TYPED_TEST_SUITE(ScalarSubtraction, SupportedTypes);


/**
 * @brief Test fixture for @ref asmmath::Scalar multiplication, parameterized by
 *      @ref SupportedTypes.
 */
template <typename T>
class ScalarMultiplication: public ::testing::Test
{
protected:
    asmmath::Scalar<T> _lhs;
    asmmath::Scalar<T> _rhs;
    asmmath::Scalar<T> _expectedProduct;

    void SetUp() override
    {
        _lhs = T(3);
        _rhs = T(13);
        _expectedProduct = T(39);
    }
};
TYPED_TEST_SUITE(ScalarMultiplication, SupportedTypes);


/**
 * @brief Test fixture for @ref asmmath::Scalar division, parameterized by
 *        @ref SupportedTypes.
 */
template <typename T>
class ScalarDivision: public ::testing::Test
{
protected:
    asmmath::Scalar<T> _lhs;
    asmmath::Scalar<T> _rhs;
    asmmath::Scalar<T> _expectedQuotient;

    void SetUp() override
    {
        _lhs = T(12);
        _rhs = T(4);
        _expectedQuotient = T(3);
    }
};
TYPED_TEST_SUITE(ScalarDivision, SupportedTypes);



/**************************************
 *                                    *
 *             CORE TESTS             *
 *                                    *
 **************************************/

/** 
 * @test Verify that scalars can be initialized with different numeric types.
 */
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



/**************************************
 *                                    *
 *           ADDITION TESTS           *
 *                                    *
 **************************************/

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

/**
 * @test Verify that adding two scalars of different types return promoted type.
 */
TYPED_TEST(ScalarAddition, ReturnsPromotedType)
{
    const auto sum = this->_lhs + static_cast<double>(this->_rhs);

    static_assert(std::is_same_v<decltype(sum), const double>);
    EXPECT_DOUBLE_EQ(static_cast<double>(this->_expectedSum), sum);
}



/**************************************
 *                                    *
 *         SUBTRACTION TESTS          *
 *                                    *
 **************************************/

/**
 * @test Verify that subtracting two scalars return their difference.
 */
TYPED_TEST(ScalarSubtraction, ReturnsDifferenceOfTwoNumbers)
{
    const TypeParam difference = this->_lhs - this->_rhs;

    if constexpr (std::is_same_v<TypeParam, double>)
        EXPECT_DOUBLE_EQ(this->_expectedDifference, difference);
    else if constexpr (std::is_floating_point_v<TypeParam>)
        EXPECT_FLOAT_EQ(this->_expectedDifference, difference);
    else
        EXPECT_EQ(this->_expectedDifference, difference);
}


/**
 * @test Verify that subtracting two scalars of different types 
 *       return promoted type.
 */
TYPED_TEST(ScalarSubtraction, ReturnsPromotedType)
{
    const auto difference = this->_lhs - static_cast<double>(this->_rhs);

    static_assert(std::is_same_v<decltype(difference), const double>);
    EXPECT_DOUBLE_EQ(static_cast<double>(this->_expectedDifference),
                     difference);
}

/**************************************
 *                                    *
 *       MULTIPLICATION TESTS         *
 *                                    *
 **************************************/

/**
 * @test Verify that multiplying two scalars return their product.
 */
TYPED_TEST(ScalarMultiplication, ReturnsProductOfTwoNumbers)
{
    const TypeParam product = this->_lhs * this->_rhs;

    if constexpr (std::is_same_v<TypeParam, double>)
        EXPECT_DOUBLE_EQ(this->_expectedProduct, product);
    else if constexpr (std::is_floating_point_v<TypeParam>)
        EXPECT_FLOAT_EQ(this->_expectedProduct, product);
    else
        EXPECT_EQ(this->_expectedProduct, product);
}


/**
 * @test Verify that multiplying two scalars of different types return promoted
 * type.
 */
TYPED_TEST(ScalarMultiplication, ReturnsPromotedType)
{
    const auto product = this->_lhs * static_cast<double>(this->_rhs);

    static_assert(std::is_same_v<decltype(product), const double>);
    EXPECT_DOUBLE_EQ(static_cast<double>(this->_expectedProduct), product);
}


/** 
 * @test Verify that multiplying by a negative scalar flips 
 *       the sign of the result.
 */
TEST(ScalarMultiplication, TimesNegativeScalarFlipsSign)
{
    constexpr asmmath::Scalar scalarA = 5;
    constexpr asmmath::Scalar scalarB = -1;

    EXPECT_EQ(-5, scalarA * scalarB);
}


/**************************************
 *                                    *
 *          DIVISION TESTS            *
 *                                    *
 **************************************/

/**
 * @test Verify that dividing two scalars return their quotient.
 */
TYPED_TEST(ScalarDivision, ReturnsProductOfTwoNumbers)
{
    const TypeParam product = this->_lhs / this->_rhs;

    if constexpr (std::is_same_v<TypeParam, double>)
        EXPECT_DOUBLE_EQ(this->_expectedQuotient, product);
    else if constexpr (std::is_floating_point_v<TypeParam>)
        EXPECT_FLOAT_EQ(this->_expectedQuotient, product);
    else
        EXPECT_EQ(this->_expectedQuotient, product);
}


/**
 * @test Verify that dividing two scalars of different types 
 *       return promoted type.
 */
TYPED_TEST(ScalarDivision, ReturnsPromotedType)
{
    const auto product = this->_lhs / static_cast<double>(this->_rhs);

    static_assert(std::is_same_v<decltype(product), const double>);
    EXPECT_DOUBLE_EQ(static_cast<double>(this->_expectedQuotient), product);
}


/** 
 * @test Verify that dividing by a negative scalar flips the 
 *       sign of the result.
 */
TEST(ScalarDivision, TimesNegativeScalarFlipsSign)
{
    constexpr asmmath::Scalar scalarA = 5;
    constexpr asmmath::Scalar scalarB = -1;

    EXPECT_EQ(-5, scalarA / scalarB);
}