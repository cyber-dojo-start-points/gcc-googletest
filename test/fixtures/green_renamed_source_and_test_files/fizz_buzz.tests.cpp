#include <gtest/gtest.h>

extern "C"
{
#include "fizz_buzz.h"
}

using namespace ::testing;

TEST(FizzBuzz, Life_the_universe_and_everything)
{
    ASSERT_EQ(42, fizz_buzz());
}
