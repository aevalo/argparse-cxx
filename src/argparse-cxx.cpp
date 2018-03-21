#include "argparse-cxx.hpp"

namespace argparse_cxx {
  Argparse_cxx::Argparse_cxx()
   : number(6)
  {
  }

  int Argparse_cxx::get_number() const
  {
    return number;
  }
}