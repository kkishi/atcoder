#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int curr = h[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (h[i] > curr) {
      --h[i];
      if (h[i] > curr) {
        wt("No");
        return 0;
      }
    }
    curr = min(curr, h[i]);
  }
  wt("Yes");
}
