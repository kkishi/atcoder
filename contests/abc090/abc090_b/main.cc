#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b);
  int ans = 0;
  for (int i = a; i <= b; ++i) {
    string s = to_string(i);
    bool ok = true;
    rep(j, s.size()) if (s[j] != s[s.size() - 1 - j]) ok = false;
    if (ok) ++ans;
  }
  wt(ans);
}
