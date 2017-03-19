#ifndef HELPER_h  /* Include guard */
#define HELPER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Helper {
public:
  Helper();
  
  int diff(int first, int second);

  int invertDiff(int first, int second);

  // bool mayor(int value);
  //
  // bool equal(int value);
};

#endif // HELPER_H_
