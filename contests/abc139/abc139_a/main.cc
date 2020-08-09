#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s, t);
  int ans = 0;
  rep(i, 3) ans += s[i] == t[i];
  wt(ans);
}
