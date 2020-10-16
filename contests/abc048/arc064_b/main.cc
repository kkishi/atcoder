#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int x = sz(s);
  if (s[0] == s.back()) {
    x -= 3;
  } else {
    x -= 2;
  }
  if (x & 1) {
    wt("First");
  } else {
    wt("Second");
  }
}
