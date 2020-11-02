#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(s, c);
  if (c <= s * 2) {
    wt(c / 2);
  } else {
    wt(s + (c - s * 2) / 4);
  }
}
