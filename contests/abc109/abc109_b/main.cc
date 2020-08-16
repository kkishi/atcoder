#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<string> w(n);
  cin >> w;
  set<string> seen;
  bool ok = true;
  rep(i, n) {
    if (!seen.insert(w[i]).second) {
      ok = false;
      break;
    }
    if (i > 0 && w[i][0] != w[i - 1].back()) {
      ok = false;
      break;
    }
  }
  wt(ok);
}
