#include <bits/stdc++.h>

#include "atcoder.h"

struct Construction {
  int s, t, x;
  bool operator<(const Construction& c) const { return s < c.s; }
};

void Main() {
  ints(n, q);

  vector<Construction> c(n);
  rep(i, n) {
    cin >> c[i].s >> c[i].t >> c[i].x;
    c[i].s -= c[i].x;
    c[i].t -= c[i].x;
  }
  sort(c);

  vector<pair<int, int>> p(q);
  rep(i, q) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p);

  multiset<int> active;
  low_priority_queue<pair<int, int>> que;
  auto cit = c.begin();
  vector<int> ans(q);

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
