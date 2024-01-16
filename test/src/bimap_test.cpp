#include <gtest/gtest.h>
#include "bimap.hpp"

TEST(BiMap, constructor)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    // EXPECT_EQ()
}