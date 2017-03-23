#include <Helper.h>

Helper::Helper()
// Base library type
{
}

void Helper::setValues(int value1, int value2) {
  first = value1;
  second = value2;
}

int Helper::diff() {
  return second - first;
}

int Helper::invertDiff() {
  return first-second;
}
