#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  strings(s);
  wt(Fix([&](auto dfs, int i, int sum) {
    if (i == sz(s)) return sum;
    int ret = 0;
    int d = 0;
    rep(j, i, sz(s)) {
      (d *= 10) += s[j] - '0';
      ret += dfs(j + 1, sum + d);
    }
    return ret;
  })(0, 0));
}
