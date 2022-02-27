#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int N = 1000000;
  V<int> cnt(N);
  each(e, a)++ cnt[e];
  int L = 6;
  // tostr(42) => "000042"
  auto tostr = [&](int x) {
    string s = to_string(x);
    return string(L - sz(s), '0') + s;
  };
  // 6-dimensional cumulative sum.
  vector sum = cnt;
  rep(i, L) {
    int t = Pow(10, i);
    rep(j, t) rep(k, N / (t * 10)) {
      int jk = j + k * (t * 10);
      rep(l, 9) sum[jk + (l + 1) * t] += sum[jk + l * t];
    }
  }
  int ans = 0;
  rep(i, N) {
    int j = N - 1 - i;
    int x = sum[j];

    // Subtract itself.
    string s = tostr(i);
    string S = tostr(j);
    bool ok = true;
    rep(i, L) if (s[i] > S[i]) ok = false;
    if (ok) --x;

    ans += x * cnt[i];
  }
  wt(ans / 2);
}
