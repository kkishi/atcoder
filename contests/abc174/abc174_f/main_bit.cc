#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

struct Q {
  int l, r, i, v;
};

void Main() {
  ints(n, q);
  V<int> c(n);
  cin >> c;
  V<Q> qs;
  rep(i, q) {
    ints(l, r);
    --l, --r;
    qs.pb({l, r, i, 0});
  }
  sort(qs, [](const Q& a, const Q& b) { return a.r < b.r; });
  V<int> seen(n, -1);
  int seen_cnt = 0;
  BIT<int> bit(n);
  auto qit = qs.begin();
  V<int> ans(q);
  rep(i, n) {
    int& s = seen[c[i] - 1];
    if (s == -1) {
      ++seen_cnt;
    } else {
      bit.Add(s, -1);
    }
    s = i;
    bit.Add(i, 1);
    while (qit != qs.end() && qit->r == i) {
      ans[qit->i] = seen_cnt - bit.Sum(qit->l - 1);
      ++qit;
    }
  }
  rep(i, q) wt(ans[i]);
}
