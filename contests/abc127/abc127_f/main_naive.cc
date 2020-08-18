#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(q);
  vector<ll> as;
  ll bs = 0;
  while (q--) {
    ints(t);
    if (t == 1) {
      rd(ll, a, b);
      as.push_back(a);
      bs += b;
    } else {
      sort(all(as));
      ll mid = as[(as.size() - 1) / 2];
      ll sum = bs;
      for (ll a : as) sum += abs(mid - a);
      wt(mid, sum);
    }
  }
}
