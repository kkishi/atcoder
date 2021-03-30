#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  string s;
  V<string> v;
  while (cin >> s) {
    v.pb(s == "Left" ? "<" : s == "Right" ? ">" : "A");
  }
  wt(v);
}
