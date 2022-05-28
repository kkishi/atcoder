#include <bits/stdc++.h>

#include "atcoder.h"

int naive(int n, int a, int b) {
  int ans = 0;
  rep(i, 1, n + 1) {
    if (i % a && i % b) ans += i;
  }
  return ans;
}

int solve(int n, int a, int b) {
  auto f = [&](int x) {
    int y = n / x;
    return x * y * (y + 1) / 2;
  };
  return f(1) - f(a) - f(b) + f(lcm(a, b));
}

void Main() {
  ints(n, a, b);
  wt(solve(n, a, b));
}
