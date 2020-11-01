#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  multiset<char> t;
  int ch = 0;
  rep(i, n - 1) {
    int rem = k - (ch + sz(t));
    if (s[i] == '_') ++rem;
    dbg(i, s, rem, t);
    optional<char> x;
    if (rem >= 2) {
      rrep(j, i + 1, n) {
        if (s[j] == '_') continue;
        if (!x || x > s[j]) x = s[j];
      }
    }
    optional<char> y;
    if (rem >= 1) {
      if (!t.empty()) {
        y = *t.begin();
      }
    }
    if (x) dbg(*x);
    if (y) dbg(*y);
    optional<char> z = x;
    if (y && (!z || z > y)) z = y;
    if (!z) continue;
    dbg(s[i], *z);
    if (s[i] == '_' || s[i] > z) {
      if (s[i] != '_') t.insert(s[i]);
      s[i] = *z;
      ++ch;
      if (y && y == z) {
        t.erase(t.find(*z));
      } else {
        assert(x && x == z);
        rrep(j, i + 1, n) if (s[j] == z) {
          s[j] = '_';
          break;
        }
      }
    }
  }
  rep(i, n) if (s[i] == '_') {
    assert(!t.empty());
    auto it = t.begin();
    s[i] = *it;
    t.erase(it);
  }
  wt(s);
}
