#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  multiset<int, greater<int>> ms;
  rep(i, 1 << n) {
    rd(int, s);
    ms.insert(s);
  }
  vector<int> v;
  v.push_back(*ms.begin());
  ms.erase(ms.begin());
  rep(i, n) {
    int J = v.size();
    rep(j, J) {
      const auto it = ms.lower_bound(v[j] - 1);
      if (it == ms.end()) {
        wt("No");
        return 0;
      }
      v.push_back(*it);
      ms.erase(it);
    }
  }
  wt("Yes");
}
