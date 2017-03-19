#include <Helper.h>

Helper::Helper()
// Base library type
{
}

int Helper::diff(int first, int second) {
  return second - first;
}

int Helper::invertDiff(int first, int second) {
  return first-second;
}

// int invertDiff() {
//   return micValue0-micValue1;
// }
//
// bool mayor(int value) {
//   return diff() > value || invertDiff() > value;
// }
//
// bool equal(int value) {
//   return diff() == value || invertDiff() == value;
// }
