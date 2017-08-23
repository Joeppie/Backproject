//
// Created by Joep on 23-8-2017.
//

#include <vector>
#include "RunTestCases.h"
#include "../Context/Context.h"
#include <gtest/gtest.h> // googletest header file




//To be honest, I am disappointed by how hard gtest is to use https://github.com/google/googletest/blob/master/googletest/docs/Samples.md


const char *actualValTrue  = "hello gtest";
const char *actualValFalse = "hello world";
const char *expectVal      = "hello gtest";


TEST(Context,removeAllPoints) {
    std::cout << "Running add and remove points test on Context" << std::endl;
    Context context;
    context.addPoint(std::vector<double> {1,2,3});
    EXPECT_EQ(1u, context.listPoints().size());
    context.removeAllPoints();
    EXPECT_EQ(0u, context.listPoints().size());
}

/*

TEST(StrCompare, CStrEqual) {
EXPECT_STREQ(expectVal, actualValTrue);
}

TEST(StrCompare, CStrNotEqual) {
EXPECT_STREQ(expectVal, actualValFalse);
}*/
