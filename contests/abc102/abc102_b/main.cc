#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> a(n);
  rep(i, n) cin >> a[i];
  wt(*max_element(all(a)) - *min_element(all(a)));
}
