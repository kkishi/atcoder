#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string t;
  rep(i, n) {
    char c = s[i];
    string nt;
    each(d, t) if (d != c) nt += d;
    nt += c;
    swap(t, nt);
  }
  wt(t);
}
