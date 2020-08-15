#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Construction {
  ll s, t, x;
  bool operator<(const Construction& c) const { return s < c.s; }
};

int main() {
  rd(ll, n, q);

  vector<Construction> c(n);
  rep(i, n) {
    cin >> c[i].s >> c[i].t >> c[i].x;
    c[i].s -= c[i].x;
    c[i].t -= c[i].x;
  }
  sort(all(c));

  vector<pair<ll, int>> p(q);
  rep(i, q) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(all(p));

  multiset<ll> active;
  low_priority_queue<pair<ll, ll>> que;
  auto cit = c.begin();
  vector<ll> ans(q);

  for (auto [d, index] : p) {
    while (cit != c.end() && cit->s <= d) {
      que.push({cit->t, cit->x});
      active.insert(cit->x);
      ++cit;
    }
    while (!que.empty() && que.top().first <= d) {
      active.erase(active.find(que.top().second));
      que.pop();
    }
    ans[index] = active.empty() ? -1 : *active.begin();
  }
  rep(i, q) wt(ans[i]);
}
