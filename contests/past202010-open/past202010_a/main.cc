#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> v(3);
  cin >> v;
  V<int> w = v;
  sort(w);
  rep(i, 3) if (v[i] == w[1]) wt(char('A' + i));
}
