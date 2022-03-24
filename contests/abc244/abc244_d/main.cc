#include <bits/stdc++.h>

#include "atcoder.h"
#include "inversion_number.h"

void Main() {
  V<char> s(3), t(3);
  cin >> s >> t;
  V<int> idx(3);
  rep(i, 3) rep(j, 3) if (s[i] == t[j]) idx[i] = j;
  wt(even(InversionNumber(idx)));
}
