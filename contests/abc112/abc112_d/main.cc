#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  map<int, int> fs = Factorize(m);
  int ans = 1;
  Fix([&](auto dfs, map<int, int>::iterator it, int x) {
    if (it == fs.end()) {
      if (m / x >= n) chmax(ans, x);
      return;
    }
    rep(i, it->second + 1) {
      dfs(next(it), x);
      x *= it->first;
    }
  })(fs.begin(), 1);
  wt(ans);
}
