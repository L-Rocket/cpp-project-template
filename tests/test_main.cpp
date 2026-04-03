#include "example.hpp"
#include "math/ops.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(SumTest, HandlesSimpleSequence) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sum(nums), 6);
}

TEST(MathOpsTest, HandlesMultiply) {
    EXPECT_EQ(multiply(3, 4), 12);
}
