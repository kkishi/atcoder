#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> target(3);
  rep(i, 3) cin >> target[i];
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  vector<int> current(3);
  int ans = numeric_limits<int>::max();
  function<void(int, int)> dfs = [&](int depth, int used_mp) {
    if (depth == n) {
      rep(i, 3) {
        if (current[i] == 0) return;
        used_mp += abs(target[i] - current[i]);
      }
      ans = min(ans, used_mp);
      return;
    }
    rep(i, 4) {
      int mp = 0;
      if (i < 3) {
        if (current[i] != 0) {
          mp += 10;
        }
        current[i] += l[depth];
      }
      dfs(depth + 1, used_mp + mp);
      if (i < 3) {
        current[i] -= l[depth];
      }
    }
  };
  dfs(0, 0);
  wt(ans);
}
