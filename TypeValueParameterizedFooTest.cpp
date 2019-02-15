//
// Created by bele on 12.02.19.
//

#ifndef GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEVALUEPARAMETERIZEDFOOTEST_H
#define GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEVALUEPARAMETERIZEDFOOTEST_H


#include <gtest/gtest.h>
#include <list>

template<typename A>
class TypeValueParameterizedFooTest : public ::testing::Test, ::testing::WithParamInterface<int> {
public:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    TypeValueParameterizedFooTest() {

    }

    virtual ~TypeValueParameterizedFooTest() {

    }

    typedef std::list<A> List;
    static A shared_;
    A value_;
};

TYPED_TEST_SUITE_P(TypeValueParameterizedFooTest);


TYPED_TEST_P(TypeValueParameterizedFooTest, TypeValueParameterizedDoesBlah) {
    TypeParam n = this->value_;
    // n += TestFixture::shared_;
    typename TestFixture::List values;
    values.push_back(n);
    std::cout << "Example TypeValueParameterizedFooTest Test Param: " << std::to_string(GetParam()) << std::endl;
}

REGISTER_TYPED_TEST_SUITE_P(TypeValueParameterizedFooTest, TypeValueParameterizedDoesBlah);

typedef ::testing::Types<char, int, unsigned int> MyTypeValueParameterizedTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(MyTypeValueParameterizedTestSuite,
                               TypeValueParameterizedFooTest,
                               MyTypeValueParameterizedTypes,
                               ::testing::Values(1, 2, 3));

#endif //GOOGLETESTTYPEVALUEPARAMETERIZEDTESTS_TYPEVALUEPARAMETERIZEDFOOTEST_H
