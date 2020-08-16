#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<string> s(n);
  cin >> s;
  rd(int, m);
  V<string> t(m);
  cin >> t;
  int ans = 0;
  rep(i, n) chmax(ans, count(all(s), s[i]) - count(all(t), s[i]));
  wt(ans);
}
