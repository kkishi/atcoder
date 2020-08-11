#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  rd(string, s);
  V<int> l(n), r(n);
  for (int i = 1; i < n; ++i) {
    l[i] = l[i - 1] + (s[i - 1] == 'W');
  }
  for (int i = n - 2; i >= 0; --i) {
    r[i] = r[i + 1] + (s[i + 1] == 'E');
  }
  int ans = n;
  rep(i, n) ans = min(ans, l[i] + r[i]);
  wt(ans);
}
