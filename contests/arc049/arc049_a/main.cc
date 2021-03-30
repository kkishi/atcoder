#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(a, b, c, d);
  rep(i, sz(s) + 1) {
    if (set<int>{a, b, c, d}.count(i)) cout << '"';
    if (i < sz(s)) cout << s[i];
  }
  cout << endl;
}
