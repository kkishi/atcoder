#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  V<int> c = atcoder::convolution(a, b);
  rep(i, sz(c)) {
    if (i) cout << " ";
    cout << c[i];
  }
  cout << endl;
}
