#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(3);
  cin >> s;
  string ans;
  for (string si : s) ans += toupper(si[0]);
  wt(ans);
}
