// A test file holding no TEST at all. The binary links gtest_main, which
// runs the zero tests it finds and reports "[  PASSED  ] 0 tests.", so the
// rag-lambda reaches green. googletest says "This test program does NOT link
// in any test case", and that line is the only sign a learner gets that a
// green light here was measured against nothing.
#include <gtest/gtest.h>

extern "C"
{
#include "hiker.h"
}

using namespace ::testing;
