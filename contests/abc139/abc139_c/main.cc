#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  cin >> h;
  int ans = 0;
  int moved = 0;
  for (int i = 1; i < n; ++i) {
    if (h[i] <= h[i - 1]) {
      ++moved;
      chmax(ans, moved);
    } else {
      moved = 0;
    }
  }
  wt(ans);
}
