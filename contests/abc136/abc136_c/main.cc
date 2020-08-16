#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> h(n);
  cin >> h;
  int curr = h[n - 1];
  bool ok = true;
  for (int i = n - 2; i >= 0; --i) {
    if (h[i] > curr) {
      --h[i];
      if (h[i] > curr) {
        ok = false;
      }
    }
    chmin(curr, h[i]);
  }
  wt(ok);
}
