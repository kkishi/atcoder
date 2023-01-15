/*
NOTE: This fails with the following input.
TODO: Understand why.

5
gpwwq
5
1_2_n
2_2_3
1_1_h
2_2_5
1_3_b
*/
#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

struct S {
  bool sorted = true;
  array<int, 26> cnt = {};
  int left = -1;
};

void Main() {
  ints(n);
  strings(s);
  SegmentTree<S> t(
      n,
      [](const S& l, const S& r) {
        if (l.left == -1) {
          assert(r.left != -1);
          return r;
        }
        if (r.left == -1) {
          assert(l.left != -1);
          return l;
        }
        S m;
        m.sorted = l.sorted && r.sorted;
        array<int, 26> L = l.cnt, R = r.cnt;
        if (l.left > r.left) swap(L, R);
        int lmax = -big, rmin = big;
        rep(i, 26) {
          if (L[i]) chmax(lmax, i);
          if (R[i]) chmin(rmin, i);
          m.cnt[i] = L[i] + R[i];
        }
        if (lmax > rmin) m.sorted = false;
        m.left = min(l.left, r.left);
        return m;
      },
      S{});
  rep(i, n) {
    S x;
    x.cnt[s[i] - 'a'] = 1;
    x.left = i;
    t.Set(i, x);
  }
  ints(q);
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(x);
      --x;
      rd(char, c);
      S ns;
      ns.cnt[c - 'a'] = 1;
      ns.left = x;
      t.Set(x, ns);
    } else {
      ints(l, r);
      --l, --r;
      S a = t.Aggregate(0, n);
      S b = t.Aggregate(l, r + 1);
      bool ok = b.sorted;
      int lo = big, hi = -big;
      rep(i, 26) if (b.cnt[i]) {
        chmin(lo, i);
        chmax(hi, i);
      }
      rep(c, lo + 1, hi) {
        if (b.cnt[c] != a.cnt[c]) ok = false;
      }
      wt(ok);
    }
  }
}
