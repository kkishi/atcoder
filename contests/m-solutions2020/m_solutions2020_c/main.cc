#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  vector<int> a(n);
  cin >> a;
  for (int i = k; i < n; ++i) {
    if (a[i] > a[i - k]) {
      wt("Yes");
    } else {
      wt("No");
    }
  }
}
