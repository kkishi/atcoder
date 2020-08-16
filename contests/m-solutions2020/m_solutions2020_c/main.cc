#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  vector<int> a(n);
  cin >> a;
  for (int i = k; i < n; ++i) {
    wt(a[i] > a[i - k]);
  }
}
