#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(v, a, b, c);
  v %= a + b + c;
  if (v < a) {
    wt("F");
  } else if (v < a + b) {
    wt("M");
  } else {
    wt("T");
  }
}
