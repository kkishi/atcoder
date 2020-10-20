#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<string, int>> v(n);
  cin >> v;
  int sum = 0;
  for (auto [_, p] : v) sum += p;
  for (auto [s, p] : v)
    if (p * 2 > sum) {
      wt(s);
      return;
    }
  wt("atcoder");
}
