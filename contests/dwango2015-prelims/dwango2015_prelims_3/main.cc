#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);

  auto comb = [](int a, int b) {
    double ret = 0;
    rep(i, b) ret += log(a - i) - log(b - i);
    return ret;
  };
  V<double> pow3(n + 1);
  rep(i, 1, n + 1) pow3[i] = pow3[i - 1] + log(3);
  auto prob = [&](int a, int b, int c) {
    return exp(comb(a + b + c, a + b) + comb(a + b, b) - pow3[a + b + c]);
  };

  vector win(n + 1, vector(n + 1, vector(n + 1, int(0))));
  rep(r, n + 1) rep(p, n + 1 - r) rep(s, n + 1 - r - p) {
    V<pair<int, int>> v{{r, 0}, {p, 1}, {s, 2}};
    sort(v);
    V<int> cnt(3), kind(3);
    rep(i, 3) tie(cnt[i], kind[i]) = v[i];
    int& w = win[r][p][s];
    auto winner = [&](int i, int j) {
      if (cnt[i] == cnt[j] && (kind[i] + 1) % 3 == kind[j]) {
        return cnt[j];
      }
      return cnt[i];
    };
    if (cnt[0] > 0) {
      if (cnt[0] == cnt[1] && cnt[1] == cnt[2]) {
        w = r + p + s;
      } else {
        w = winner(0, 1);
      }
    } else if (cnt[1] > 0) {
      w = winner(1, 2);
    } else {
      w = cnt[2];
    }
  }

  V<double> dp(n + 1);
  rep(i, 2, n + 1) {
    dp[i] = 1;
    double sp = 0;
    rep(r, i + 1) rep(p, i + 1 - r) {
      int s = i - (r + p);
      int w = win[r][p][s];
      if (w == (r + p + s)) {
        sp += prob(r, p, s);
      } else {
        dp[i] += prob(r, p, s) * dp[w];
      }
    }
    dp[i] /= 1 - sp;
  }
  wt(dp[n]);
}
