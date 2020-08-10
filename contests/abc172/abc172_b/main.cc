#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int ans = 0;
  rd(string, a, b);
  rep(i, a.size()) if (a[i] != b[i])++ ans;
  wt(ans);
}
