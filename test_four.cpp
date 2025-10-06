#include <gtest/gtest.h>
#include "Four.h"

TEST(FourTest, DefaultConstructor) {
    Four num;
    EXPECT_TRUE(num.isEmpty());
    EXPECT_EQ(num.toString(), "0");
}

TEST(FourTest, SizeValueConstructor) {
    Four num(3, 2);
    EXPECT_EQ(num.toString(), "222");
    EXPECT_EQ(num.size(), 3);
}

TEST(FourTest, InitializerListConstructor) {
    Four num{1, 2, 3};
    EXPECT_EQ(num.toString(), "123");
}

TEST(FourTest, StringConstructor) {
    Four num("321");
    EXPECT_EQ(num.toString(), "321");
}

TEST(FourTest, StringConstructorInvalid) {
    EXPECT_THROW(Four num("456"), std::invalid_argument);
}

TEST(FourTest, CopyConstructor) {
    Four num1("123");
    Four num2(num1);
    EXPECT_EQ(num2.toString(), "123");
}

TEST(FourTest, MoveConstructor) {
    Four num1("123");
    Four num2(std::move(num1));
    EXPECT_EQ(num2.toString(), "123");
    EXPECT_TRUE(num1.isEmpty());
}

TEST(FourTest, Addition) {
    Four num1("12");
    Four num2("3");
    Four result = num1.add(num2);
    EXPECT_EQ(result.toString(), "21");
}

TEST(FourTest, AdditionWithCarry) {
    Four num1("3");
    Four num2("3");
    Four result = num1.add(num2);
    EXPECT_EQ(result.toString(), "12");
}

TEST(FourTest, Subtraction) {
    Four num1("21");
    Four num2("3");
    Four result = num1.subtract(num2);
    EXPECT_EQ(result.toString(), "12");
}

TEST(FourTest, SubtractionInvalid) {
    Four num1("3");
    Four num2("12");
    EXPECT_THROW(num1.subtract(num2), std::invalid_argument);
}

TEST(FourTest, Comparison) {
    Four num1("12");
    Four num2("3");
    Four num3("12");
    
    EXPECT_TRUE(num1.equals(num3));
    EXPECT_FALSE(num1.equals(num2));
    EXPECT_TRUE(num2.lessThan(num1));
    EXPECT_TRUE(num1.greaterThan(num2));
}

TEST(FourTest, RemoveLeadingZeros) {
    Four num{0, 0, 1, 2};
    EXPECT_EQ(num.toString(), "12");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}