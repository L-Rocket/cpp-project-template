#include "example.hpp"
#include "math/ops.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(SumTest, HandlesNestedDirectoryCase) {
    std::vector<int> nums = {4, 5, 6};
    EXPECT_EQ(sum(nums), 15);
}

TEST(MathOpsTest, HandlesNegativeMultiply) {
    EXPECT_EQ(multiply(-2, 5), -10);
}
