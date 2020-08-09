#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> p(n);
  int d = 0;
  rep(i, n) {
    cin >> p[i];
    if (i + 1 != p[i]) ++d;
  }
  wt(d <= 2 ? "YES" : "NO");
}
