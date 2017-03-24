#include <Helper.h>

Helper::Helper()
// Base library type
{
}

/*
  Store microphone samples data

  @param value1 the first sample value
  @param value2 the second sample value
*/
void Helper::setValues(int value1, int value2) {
  first = value1;
  second = value2;
}

/*
  Return the difference between the second sample and the first.

  @return the difference
*/
int Helper::diff() {
  return second - first;
}

/*
  Return the difference between the first sample and the second.

  @return the difference
*/
int Helper::invertDiff() {
  return first-second;
}
