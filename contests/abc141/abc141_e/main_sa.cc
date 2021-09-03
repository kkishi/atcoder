#include <bits/stdc++.h>

#include <atcoder/string>

#include "atcoder.h"
#include "min_segment_tree.h"

void Main() {
  ints(n);
  strings(s);
  auto sa = atcoder::suffix_array(s);
  V<int> r(n);
  rep(i, n) r[sa[i]] = i;
  auto la = atcoder::lcp_array(s, sa);
  int m = sz(la);
  MinSegmentTree<int> t(m);
  rep(i, m) t.Set(i, la[i]);
  int ans = 0;
  auto lcp = [&](int i, int j) {
    i = r[i], j = r[j];
    if (i > j) swap(i, j);
    return t.Aggregate(i, j);
  };
  rep(i, n - 1) rep(j, i + 1, n) chmax(ans, min(lcp(i, j), j - i));
  wt(ans);
}
