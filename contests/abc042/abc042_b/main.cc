#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l);
  V<string> s(n);
  cin >> s;
  sort(s);
  wt(accumulate(s));
}
