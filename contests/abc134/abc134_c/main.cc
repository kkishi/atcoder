#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  multiset<int, greater<int>> s;
  rep(i, n) s.insert(a[i]);
  rep(i, n) {
    s.erase(s.find(a[i]));
    wt(*s.begin());
    s.insert(a[i]);
  }
}
