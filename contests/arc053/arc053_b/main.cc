#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  map<char, int> m;
  for (char c : s) m[c]++;
  int pairs = 0;
  for (auto [k, v] : m) pairs += v / 2;
  int rem = sz(s) - pairs * 2;
  if (rem == 0) {
    wt(sz(s));
  } else {
    wt(1 + (pairs / rem) * 2);
  }
}
