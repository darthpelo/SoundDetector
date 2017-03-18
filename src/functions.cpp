int diff() {
  return micValue1-micValue0;
}

int invertDiff() {
  return micValue0-micValue1;
}

bool mayor(int value) {
  return diff() > value || invertDiff() > value;
}

bool equal(int value) {
  return diff() == value || invertDiff() == value;
}
