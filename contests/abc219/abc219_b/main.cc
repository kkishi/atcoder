#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(3);
  string t;
  cin >> s >> t;
  string ans;
  each(e, t) ans += s[e - '1'];
  wt(ans);
}
