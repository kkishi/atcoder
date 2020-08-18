#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  sort(all(a));
  sort(all(b));
  if (n % 2) {
    cout << (b[n / 2] - a[n / 2] + 1) << endl;
  } else {
    int am = a[n / 2 - 1] + a[n / 2];
    int bm = b[n / 2 - 1] + b[n / 2];
    cout << (bm - am + 1) << endl;
  }
}
