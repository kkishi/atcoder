#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  int ans = 0;
  rep(i, sz(s) - 1) if (s[i] != s[i + 1])++ ans;
  wt(ans);
}
