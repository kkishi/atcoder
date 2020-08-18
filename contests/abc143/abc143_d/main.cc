#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  vector<int> l(n);
  cin >> l;
  sort(all(l));

  int ans = 0;
  for (int a = 0; a < n - 2; ++a) {
    for (int b = a + 1; b < n - 1; ++b) {
      vector<int>::iterator begin = l.begin() + b + 1;
      ans += upper_bound(begin, l.end(), l[a] + l[b] - 1) - begin;
    }
  }
  wt(ans);
}
