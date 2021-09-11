#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> p(26);
  cin >> p;
  string s;
  each(e, p) s += 'a' + e - 1;
  wt(s);
}
