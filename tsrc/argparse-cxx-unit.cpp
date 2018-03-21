#include <limits.h>
#include "argparse-cxx.hpp"
#include "gtest/gtest.h"

namespace {
  TEST(ArgparseCxxUnitTest, GetNumber) {
    argparse_cxx::Argparse_cxx c;
    EXPECT_EQ(6, c.get_number());
  }
}