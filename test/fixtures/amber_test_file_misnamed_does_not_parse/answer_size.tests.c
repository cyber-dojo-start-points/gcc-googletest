// A test file named .c, so the makefile hands it to the C compiler, where a
// gtest TEST cannot live and this file can never run as a test. Vanishing is
// what it must not do: every .c file here is compiled, so a file that is half
// written is seen even though it is not run.
#include "hiker.h"

int the_answer_is_two_digits_long(
{
    return answer() < 100;
}
