#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  each(e, s) reverse(e);
  sort(s);
  each(e, s) reverse(e);
  each(e, s) wt(e);
}
