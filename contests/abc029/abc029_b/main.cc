#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(12);
  cin >> s;
  int ans = 0;
  for (auto& si : s)
    if (count(all(si), 'r')) ++ans;
  wt(ans);
}
