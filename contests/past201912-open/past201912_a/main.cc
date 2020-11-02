#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int x = 0;
  for (char c : s) {
    if (!isdigit(c)) {
      wt("error");
      return;
    }
    (x *= 10) += (c - '0') * 2;
  }
  wt(x);
}
