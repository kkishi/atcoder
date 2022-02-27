#include <bits/stdc++.h>

#include "atcoder.h"

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
  vector sum(N, int(0));
  rep(i, N) {
    int x = 0;
    string s = tostr(i);
    rep(mask, 1, 1 << L) {
      string S = s;
      bool ok = true;
      rep(j, L) if (hasbit(mask, j)) {
        if (S[j] == '0') {
          ok = false;
        } else {
          --S[j];
        }
      }
      if (ok) {
        int j = stoll(S);
        x += (even(popcount(mask)) ? -1 : 1) * sum[j];
      }
    }
    sum[i] = cnt[i] + x;
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
