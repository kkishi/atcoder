#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y);
  if (x > y) swap(x, y);
  if (y >= 2 + x) {
    wt("Alice");
  } else {
    wt("Brown");
  }
}
