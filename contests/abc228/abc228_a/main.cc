#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s, t, x);
  bool ok = false;
  for (; s != t; s = (s + 1) % 24) {
    if (x == s) ok = true;
  }
  wt(ok);
}
