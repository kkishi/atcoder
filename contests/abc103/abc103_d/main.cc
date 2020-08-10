#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

using P = pair<int, int>;

int main() {
  rd(int, n, m);
  vector<P> v;
  rep(i, m) {
    rd(int, a, b);
    v.push_back({b, a});
  }
  sort(all(v));
  int ans = 0;
  int last = 0;
  for (auto [b, a] : v) {
    if (a < last && last <= b) continue;
    ++ans;
    last = b;
  }
  wt(ans);
}
