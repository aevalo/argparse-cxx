#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_ARGPARSE_CXX
    #define ARGPARSE_CXX_PUBLIC __declspec(dllexport)
  #else
    #define ARGPARSE_CXX_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_ARGPARSE_CXX
      #define ARGPARSE_CXX_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define ARGPARSE_CXX_PUBLIC
  #endif
#endif

namespace argparse_cxx {
  class ARGPARSE_CXX_PUBLIC Argparse_cxx {
    public:
      Argparse_cxx();
      int get_number() const;
    private:
      int number;
  };
}