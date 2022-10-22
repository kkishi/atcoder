#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int x = (10000 * b / a + 5) / 10;
  printf("%ld.%03ld", x / 1000, x % 1000);
}
