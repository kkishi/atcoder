#include <bits/stdc++.h>

#include <atcoder/string>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s, t);
  string rgb = "RGB";
  int ans = 0;
  each(e, rgb) {
    string u = t;
    each(f, u) if (f != e) f = 'R' + 'G' + 'B' - e - f;
    rep(I, 2) {
      string us = u + '$' + s;
      int N = sz(us);
      auto sa = atcoder::suffix_array(us);
      V<int> rank(N);
      rep(i, N) rank[sa[i]] = i;
      auto la = atcoder::lcp_array(us, sa);
      int M = sz(la);
      V<int> lcp(M);
      lcp[rank[0]] = la[rank[0]];
      rep(i, rank[0] + 1, M) lcp[i] = min(lcp[i - 1], la[i]);
      lcp[rank[0] - 1] = la[rank[0] - 1];
      rrep(i, rank[0] - 1) lcp[i] = min(lcp[i + 1], la[i]);
      auto LCP = [&](int x) {
        if (x > rank[0]) {
          return lcp[x - 1];
        } else {
          return lcp[x];
        }
      };
      rep(i, n - I) if (LCP(rank[n * 2 - i]) >= i + 1)++ ans;
      swap(u, s);
    }
  }
  wt(ans);
}
