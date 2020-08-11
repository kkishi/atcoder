#include <bits/stdc++.h>

#include "macros.h"
#include "setmin.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> memo(n + 1, -1);
  function<int(int)> rec = [&](int x) {
    if (x == 0) return 0;
    if (memo[x] == -1) {
      int mini = numeric_limits<int>::max();
      Setmin(mini, 1 + rec(x - 1));
      for (int i = 6; i <= x; i *= 6) {
        Setmin(mini, 1 + rec(x - i));
      }
      for (int i = 9; i <= x; i *= 9) {
        Setmin(mini, 1 + rec(x - i));
      }
      memo[x] = mini;
    }
    return memo[x];
  };
  wt(rec(n));
}
