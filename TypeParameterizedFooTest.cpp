//
// Created by bele on 12.02.19.
//

#ifndef GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEPARAMETERIZEDFOOTEST_H
#define GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEPARAMETERIZEDFOOTEST_H

#include <gtest/gtest.h>
#include <list>

template<typename T>
class TypeParameterizedFooTest : public ::testing::Test {
public:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    TypeParameterizedFooTest() {

    }

    virtual ~TypeParameterizedFooTest() {

    }

    typedef std::list<T> List;
    static T shared_;
    T value_;
};

TYPED_TEST_SUITE_P(TypeParameterizedFooTest);

TYPED_TEST_P(TypeParameterizedFooTest, TypeParameterizedDoesBlah) {
    TypeParam n = this->value_;
    // n += TestFixture::shared_;
    typename TestFixture::List values;
    values.push_back(n);
}

REGISTER_TYPED_TEST_SUITE_P(TypeParameterizedFooTest, TypeParameterizedDoesBlah);

typedef ::testing::Types<char, int, unsigned int> MyTypeParameterizedTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(MyTypeParameterizedTestSuite,
                               TypeParameterizedFooTest,
                               MyTypeParameterizedTypes);


#endif //GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEPARAMETERIZEDFOOTEST_H
