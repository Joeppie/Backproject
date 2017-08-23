#include <vector>
#include <gtest/gtest.h> // googletest header file

#include "RunTestCases.h"
#include "../Context/Context.h"
#include "../Context/Operations/RemoveAllPointsOperation.h"
#include "../matrix.h"

//google test has examples here: https://github.com/google/googletest/blob/master/googletest/docs/Samples.md

/**
 * Tests whether the RemoveAllPointsOperation works as expected.
 */
TEST(RemoveAllPointsOperation,RemoveAllPointsOperation) {

    std::cout << "\ntesting RemoveAllPointsOperation " << std::endl;
    //Initialize the objects required to test
    Context context;
    RemoveAllPointsOperation operation;

    //Verify that operation cannot be run if there are no points.
    EXPECT_EQ(false, operation.IsPossible(context));
    context.addPoint(std::vector<double> {1,2,3});
    //Verify that operation can run when there are points.
    EXPECT_EQ(true, operation.IsPossible(context));

    //Verify the operations performs correctly.
    std::string result = operation.Perform(context);
    EXPECT_EQ("removed all points from context.",result);

    //The operation should now report that it is no longer possible.
    EXPECT_EQ(false, operation.IsPossible(context));
}

/**
 * Test that the 'set_width' of Image validates properly.
 */
TEST(Image,width__setter_validation) {

    std::cout << "\ntesting Image width__setter_validation" << std::endl;
    Image image;
    //should throw an exception.
    ASSERT_ANY_THROW(image.set_width(-5));
    //Should not throw an exception
    image.set_width(50);
}

/**
 * Test that multiply throws an exception when attempting to multiply matrices that cannot be multiplied.
 */
TEST(Matrix,multiplication_fails){
    std::cout << "\ntesting matrix multiplication " << std::endl;
    matrix m_2by2 = matrix {{1, 2},
                            {3, 4}};

    matrix m_3by3 = matrix {{1, 2, 3},
                            {3, 4, 5},
                            {6, 7, 8}};

    matrix result;
    ASSERT_ANY_THROW(result = multiply(m_2by2,m_3by3));
}

/**
 * A very obviously incorrect test/
 */
TEST(Broken,purposel_broken_test) {

    std::cout << "\ntesting purposely broken test" << std::endl;
    //Test something that should work, obviously.
    auto innocentLambda = []() { };
    ASSERT_ANY_THROW(innocentLambda);

}


