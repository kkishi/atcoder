#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<char> s(n);
  cin >> s;
  wt(count(all(s), 'Y') ? "Four" : "Three");
}
