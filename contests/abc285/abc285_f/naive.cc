#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  ints(q);
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(x);
      --x;
      rd(char, c);
      s[x] = c;
    } else {
      ints(l, r);
      --l;
      string t = s;
      sort(t);
      string u = s.substr(l, r - l);
      wt(t.find(u) != string::npos);
    }
  }
}
