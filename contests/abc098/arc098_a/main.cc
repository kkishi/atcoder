#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  V<int> l(n), r(n);
  rep(i, n - 1) l[i + 1] = l[i] + (s[i] == 'W');
  rrep(i, n - 1) r[i] = r[i + 1] + (s[i + 1] == 'E');
  int ans = n;
  rep(i, n) chmin(ans, l[i] + r[i]);
  wt(ans);
}
