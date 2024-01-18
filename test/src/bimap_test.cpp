#include <gtest/gtest.h>
#include "bimap.hpp"

TEST(constructor, initializing)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    // EXPECT_EQ()
}

TEST(setValue, working)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    b.setValue("tite", 4);
    std::unordered_map<std::string, int> temp1 = {{"tite", 4}, {"tot", 2}};
    EXPECT_EQ(b.getMap(), temp1);
    std::unordered_map<int, std::string> temp2 = {{4, "tite"}, {2, "tot"}};
    EXPECT_EQ(b.getInverseMap(), temp2);

    b.setValue("tot", 5);
    temp1 = {{"tite", 4}, {"tot", 5}};
    temp2 = {{4, "tite"}, {5, "tot"}};
    EXPECT_EQ(b.getMap(), temp1);
    EXPECT_EQ(b.getInverseMap(), temp2);

    BiMap<int, int> b1 = {{1, 2}, {3, 4}};
    b1.setValue(1, 3);
    std::unordered_map<int, int> temp3 = {{1, 3}, {3, 4}};
    std::unordered_map<int, int> temp4 = {{3, 1}, {4, 3}};
    EXPECT_EQ(b1.getMap(), temp3);
    EXPECT_EQ(b1.getInverseMap(), temp4);
}

TEST(setValue, duplicate)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    EXPECT_THROW(b.setValue("tite", 2), std::runtime_error);
    EXPECT_THROW(b.setValue("tot", 1), std::runtime_error);
}

TEST(insert, working)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    b.insert("hello", 3);
    std::unordered_map<std::string, int> temp1 = {{"tite", 1}, {"tot", 2}, {"hello", 3}};
    std::unordered_map<int, std::string> temp2 = {{1, "tite"}, {2, "tot"}, {3, "hello"}};
    EXPECT_EQ(b.getMap(), temp1);
    EXPECT_EQ(b.getInverseMap(), temp2);
}

TEST(insert, duplicate)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}});
    EXPECT_THROW(b.insert("tite", 3), std::runtime_error);
    EXPECT_THROW(b.insert("hello", 1), std::runtime_error);
}

TEST(remove, working)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}, {"hello", 3}});
    b.remove("hello");
    std::unordered_map<std::string, int> temp1 = {{"tite", 1}, {"tot", 2}};
    std::unordered_map<int, std::string> temp2 = {{1, "tite"}, {2, "tot"}};
    EXPECT_EQ(b.getMap(), temp1);
    EXPECT_EQ(b.getInverseMap(), temp2);
}

TEST(remove, not_exist)
{
    BiMap<std::string, int> b({{"tite", 1}, {"tot", 2}, {"hello", 3}});
    b.remove("wassup");
    std::unordered_map<std::string, int> temp1 = {{"tite", 1}, {"tot", 2}, {"hello", 3}};
    std::unordered_map<int, std::string> temp2 = {{1, "tite"}, {2, "tot"}, {3, "hello"}};
    EXPECT_EQ(b.getMap(), temp1);
    EXPECT_EQ(b.getInverseMap(), temp2);
}