// This solution is based on the editorial:
// https://atcoder.jp/contests/abc285/editorial/5514
#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<AddSegmentTree<int>> ts(26, AddSegmentTree<int>(n));
  rep(i, n) ts[s[i] - 'a'].Set(i, 1);
  ints(q);
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(x);
      --x;
      rd(char, c);
      ts[s[x] - 'a'].Set(x, 0);
      s[x] = c;
      ts[s[x] - 'a'].Set(x, 1);
    } else {
      ints(l, r);
      --l;
      V<int> all_cnt(26), cnt(26);
      rep(i, 26) {
        all_cnt[i] = ts[i].Aggregate(0, n);
        cnt[i] = ts[i].Aggregate(l, r);
      }
      int lo = big, hi = -big;
      rep(i, 26) if (cnt[i]) {
        chmin(lo, i);
        chmax(hi, i);
      }
      bool ans = true;
      rep(c, lo + 1, hi) {
        if (cnt[c] != all_cnt[c]) ans = false;
      }
      int pos = l;
      rep(i, lo, hi + 1) {
        if (ts[i].Aggregate(pos, pos + cnt[i]) != cnt[i]) ans = false;
        pos += cnt[i];
      }
      wt(ans);
    }
  }
}
