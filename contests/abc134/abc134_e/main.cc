#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> a(n);
  cin >> a;
  multiset<int, greater<int>> s;
  rep(i, n) {
    auto it = s.upper_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
    }
    s.insert(a[i]);
  }
  wt(s.size());
}
