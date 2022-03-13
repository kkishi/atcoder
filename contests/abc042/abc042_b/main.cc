#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<string> s(n);
  cin >> s;
  sort(all(s));
  wt(accumulate(s));
}
