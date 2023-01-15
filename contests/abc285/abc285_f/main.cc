#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "atcoder.h"

struct S {
  bool sorted = true;
  array<int, 26> cnt = {};
  int left = -1;
  int right = -1;
};

S op(S l, S r) {
  if (l.left == -1) return r;
  if (r.left == -1) return l;
  assert(l.right == r.left);  // Important: ACL ensures this.
  S m;
  m.sorted = l.sorted && r.sorted;
  int lmax = -big, rmin = big;
  rep(i, 26) {
    m.cnt[i] = l.cnt[i] + r.cnt[i];
    if (l.cnt[i] > 0) chmax(lmax, i);
    if (r.cnt[i] > 0) chmin(rmin, i);
  }
  if (lmax > rmin) m.sorted = false;
  m.left = l.left;
  m.right = r.right;
  return m;
}

S e() { return S{}; }

void Main() {
  ints(n);
  strings(s);
  atcoder::segtree<S, op, e> t(n);
  rep(i, n) {
    S x;
    x.cnt[s[i] - 'a'] = 1;
    x.left = i;
    x.right = i + 1;
    t.set(i, x);
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
      ns.right = x + 1;
      t.set(x, ns);
    } else {
      ints(l, r);
      --l, --r;
      S a = t.prod(0, n);
      S b = t.prod(l, r + 1);
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
