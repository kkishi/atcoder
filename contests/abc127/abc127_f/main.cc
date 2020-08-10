#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, q);
  multiset<ll> lo, hi;
  ll lo_sum = 0, hi_sum = 0;
  optional<ll> mid;
  ll bs = 0;
  while (q--) {
    rd(int, t);
    if (t == 1) {
      rd(ll, a, b);
      bs += b;
      if (!mid) {
        mid = a;
      } else if (a <= *mid) {
        lo.insert(a);
        lo_sum += *mid - a;
        while (lo.size() > hi.size()) {
          ll change = *mid - *lo.rbegin();

          hi.insert(*mid);
          hi_sum += change * hi.size();

          mid = *lo.rbegin();

          lo_sum -= change * lo.size();
          lo.erase(lo.find(*lo.rbegin()));
        }
      } else {
        hi.insert(a);
        hi_sum += a - *mid;
        while (lo.size() + 1 < hi.size()) {
          ll change = *hi.begin() - *mid;

          lo.insert(*mid);
          lo_sum += change * lo.size();

          mid = *hi.begin();

          hi_sum -= change * hi.size();
          hi.erase(hi.begin());
        }
      }
      dbg(lo.size(), hi.size());
      assert(lo.size() == hi.size() || lo.size() + 1 == hi.size());
      // dbg(*mid, lo_sum, hi_sum, lo.size(), hi.size());
    } else {
      wt(*mid, lo_sum + hi_sum + bs);
    }
  }
}
