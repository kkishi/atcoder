#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<ll> a(n);
  cin >> a;
  ll all = 0;
  rep(i, n) all ^= a[i];
  rep(i, n) {
    if (i) cout << " ";
    cout << (all ^ a[i]);
  }
  cout << endl;
}
