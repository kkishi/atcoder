#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(T);
  while (T--) {
    rd(ll, N, A, B, C, D);

    map<ll, ll> seen;
    seen[N] = 0;

    low_priority_queue<pair<ll, ll>> que;
    que.push({0, N});

    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      if (v == 0) {
        wt(c);
        break;
      }
      auto push = [&seen, &que](ll c, ll v) {
        if (v < 0) return;
        auto [it, ok] = seen.insert({v, c});
        if (ok || it->second > c) {
          it->second = c;
          que.push({c, v});
        }
      };
      if (v % 2 == 0) push(c + A, v / 2);
      if (v % 3 == 0) push(c + B, v / 3);
      if (v % 5 == 0) push(c + C, v / 5);
      for (ll d = -4; d <= 4; ++d) {
        ll nv = v + d;
        bool ok = false;
        ll mods[] = {2, 3, 5};
        for (ll m : mods) {
          if (v % m != 0 && nv % m == 0 && abs(d) < m) {
            ok = true;
          }
        }
        if (ok) push(c + D * abs(d), nv);
      }
      if (D * v > 0) {
        push(c + D * v, 0);
      }
    }
  }
}
