#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  multiset<int, greater<int>> s;
  rep(i, n) s.insert(a[i]);
  rep(i, n) {
    s.erase(s.find(a[i]));
    wt(*s.begin());
    s.insert(a[i]);
  }
}
