#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  if (c == 0) {
    wt(a > b ? "Takahashi" : "Aoki");
  } else {
    wt(b > a ? "Aoki" : "Takahashi");
  }
}
