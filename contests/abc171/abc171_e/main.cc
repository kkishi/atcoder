#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll all = 0;
  rep(i, n) all ^= a[i];
  rep(i, n) {
    if (i) cout << " ";
    cout << (all ^ a[i]);
  }
  cout << endl;
}
