//
// Created by bele on 12.02.19.
//

#ifndef GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_VALUEPARAMETERIZEDFOOTEST_H
#define GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_VALUEPARAMETERIZEDFOOTEST_H

#include <gtest/gtest.h>

class ValueParameterizedFooTest : public ::testing::Test, public ::testing::WithParamInterface<int> {
public:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    ValueParameterizedFooTest() {

    }

    virtual ~ValueParameterizedFooTest() {

    }
};

TEST_P(ValueParameterizedFooTest, ValueParameterizedDoesBlah) {
    std::cout << "Example ValueParameterizedFooTest Test Param: " << std::to_string(GetParam()) << std::endl;
}

INSTANTIATE_TEST_SUITE_P(MyValueParameterizedTestSuite,
                         ValueParameterizedFooTest,
                         ::testing::Values(1, 2, 3));

#endif //GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_VALUEPARAMETERIZEDFOOTEST_H
