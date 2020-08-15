#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  cin >> h;
  int curr = h[n - 1];
  rrep(i, n - 1) {
    if (h[i] > curr) {
      --h[i];
      if (h[i] > curr) {
        wt("No");
        return 0;
      }
    }
    chmin(curr, h[i]);
  }
  wt("Yes");
}
