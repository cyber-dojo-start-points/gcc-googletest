// A learner who puts a test file in a sub-directory gets it compiled and
// run like any other. The counts in expected.json are what say so: two
// tests from two test suites rather than one.
#include <gtest/gtest.h>
#include <string>

extern "C"
{
#include "hiker.h"
}

using namespace ::testing;

TEST(AnswerSize, The_answer_is_two_digits_long)
{
    ASSERT_EQ(2u, std::to_string(answer()).size());
}
