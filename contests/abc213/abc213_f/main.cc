#include <bits/stdc++.h>

#include <atcoder/string>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  auto sa = atcoder::suffix_array(s);
  auto la = atcoder::lcp_array(s, sa);
  int N = sz(la);
  V<int> usum(N + 1), dsum(N + 1);
  rep(I, 2) {
    V<pair<int, int>> st = {{-1, -1}};
    V<int>& sum = (I == 0 ? usum : dsum);
    rep(i, N) {
      while (st.back().first >= la[i]) st.pop_back();
      int j = st.back().second;
      sum[i + 1] = la[i] * (i - j) + sum[j + 1];
      st.eb(la[i], i);
    }
    reverse(all(la));
  }
  reverse(all(dsum));
  map<int, int> m;
  rep(i, n) m[sa[i]] = i;
  rep(i, n) {
    int idx = m[i];
    wt(usum[idx] + dsum[idx] + (n - i));
  }
}
