#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string t = "indeednow";
  sort(t);
  rep(n) {
    strings(s);
    sort(s);
    wt(s == t ? "YES" : "NO");
  }
}
