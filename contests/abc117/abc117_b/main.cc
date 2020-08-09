#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  int s = accumulate(all(l), 0);
  rep(i, n) if (s - l[i] <= l[i]) {
    wt("No");
    return 0;
  }
  wt("Yes");
}
