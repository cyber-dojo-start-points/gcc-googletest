#include <gtest/gtest.h>
#include <string>

extern "C"
{
#include "hiker.h"
}

using namespace ::testing;

TEST(AnswerSize, The_answer_is_two_digits_long)
{
    ASSERT_EQ(2u, std::to_string(answer(.size());
}
