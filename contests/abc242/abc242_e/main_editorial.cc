#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Solve() {
  ints(n);
  strings(s);
  int N = (n + 1) / 2;
  mint lt = 0;
  rep(i, N) lt = (s[i] - 'A') + lt * 26;
  mint eq = 0;
  {
    string head = s.substr(0, N);
    string tail = s.substr(0, n / 2);
    reverse(tail);
    if (head + tail <= s) eq = 1;
  }
  wt(lt + eq);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
