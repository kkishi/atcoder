#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int x = 0, y = 0;
  int q = 0;
  for (char c : s) {
    if (c == 'L') --x;
    if (c == 'R') ++x;
    if (c == 'U') ++y;
    if (c == 'D') --y;
    if (c == '?') ++q;
  }
  int dist = abs(x) + abs(y);
  ints(t);
  if (t == 1) {
    wt(dist + q);
  } else if (dist >= q) {
    wt(dist - q);
  } else {
    wt((q - dist) % 2);
  }
}
