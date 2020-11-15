#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  string t = "indeednow";
  sort(all(t));
  rep(n) {
    strings(s);
    sort(all(s));
    wt(s == t ? "YES" : "NO");
  }
}
