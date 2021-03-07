#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  strings(s, t);
  V<int> cnt(10);
  rep(i, 1, 10) cnt[i] = k;
  V<int> tcnt(10);
  rep(i, 4) {
    --cnt[s[i] - '0'];
    ++tcnt[s[i] - '0'];
  }
  V<int> acnt(10);
  rep(i, 4) {
    --cnt[t[i] - '0'];
    ++acnt[t[i] - '0'];
  }
  double ans = 0;
  V<int> ten(6);
  ten[0] = 1;
  rep(i, 5) ten[i + 1] = ten[i] * 10;
  rep(i, 1, 10) rep(j, 1, 10) {
    V<int> c = cnt;
    if (c[i] == 0) continue;
    double p = c[i] / double(9 * k - 8);
    --c[i];
    if (c[j] == 0) continue;
    p *= c[j] / double(9 * k - 9);
    auto f = [&](vector<int> cnt, int x) {
      ++cnt[x];
      int ret = 0;
      rep(i, 1, 10) ret += i * ten[cnt[i]];
      return ret;
    };
    if (f(tcnt, i) > f(acnt, j)) ans += p;
  }
  wt(ans);
}
