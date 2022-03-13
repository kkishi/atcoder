#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  set<int> s(all(a));
  for (int ai : a) {
    do {
      ai *= 2;
      s.erase(ai);
    } while (ai <= 1000000000);
  }
  wt(sz(s));
}
