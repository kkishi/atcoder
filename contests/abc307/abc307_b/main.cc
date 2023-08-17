#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  rep(i, n) rep(j, n) if (i != j) {
    string t = s[i] + s[j];
    string rt = t;
    reverse(rt);
    if (t == rt) return true;
  }
  return false;
}
