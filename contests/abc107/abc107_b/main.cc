#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, h, w);
  vector<string> a(h);
  cin >> a;
  vector<bool> r(h), c(w);
  rep(i, h) rep(j, w) if (a[i][j] == '#') r[i] = c[j] = true;
  rep(i, h) if (r[i]) {
    rep(j, w) if (c[j]) cout << a[i][j];
    cout << endl;
  }
}
