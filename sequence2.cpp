#include "sequence2.h"
#include <iostream>
using namespace CISP430_A2;


using std::cout;
using std::cin;

// note: we have only have to define the default parameter in the
// prototype in the class; not the implementation.
sequence::sequence(size_type entry)
{
  // allocate the user entered amount of variables in the array
  data = new value_type[entry];
  // and store the amount alloted in the "capacity" section
  capacity = entry;
  // at this point, the amount of the alloted capacity and the current index
  // will be zero, so we set those to zero.
  used = 0;
  current_index = 0;

  // the sequence has been constructed, and variables initialized.
}


