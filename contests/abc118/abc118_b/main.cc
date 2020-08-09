#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  vector<int> food(m);
  rep(i, n) {
    rd(int, k);
    rep(j, k) {
      rd(int, a);
      food[a - 1]++;
    }
  }
  int ans = 0;
  rep(i, m) if (food[i] == n)++ ans;
  wt(ans);
}
