#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  int ans = 0;
  rep(i, 1, n + 1) {
    string s = to_string(i);
    int sum = 0;
    for (char c : s) sum += c - '0';
    if (a <= sum && sum <= b) ans += i;
  }
  wt(ans);
}
