#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  set<tuple<int, int, int>> s{{a, b, c}};
  int ans = 0;
  while (true) {
    if (!even(a) || !even(b) || !even(c)) break;
    ++ans;
    int A = (b + c) / 2, B = (c + a) / 2, C = (a + b) / 2;
    if (!s.insert({A, B, C}).second) {
      wt(-1);
      return;
    }
    a = A, b = B, c = C;
  }
  wt(ans);
}
