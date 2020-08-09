#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Construction {
  ll s, t, x;
  bool operator<(const Construction& c) const { return s < c.s; }
};

struct Person {
  ll d, index;
  bool operator<(const Person& p) const { return d < p.d; }
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
  vector<Person> p(q);
  rep(i, q) {
    cin >> p[i].d;
    p[i].index = i;
  }
  sort(all(p));

  multiset<ll> active;
  priority_queue<pair<ll, ll>> que;
  auto cit = c.begin();
  vector<ll> ans(q);
  for (const auto& pi : p) {
    dbg(pi.d, pi.index);
    while (cit != c.end() && cit->s <= pi.d) {
      dbg(cit->s, cit->t, cit->x);
      que.push({-cit->t, cit->x});
      active.insert(cit->x);
      ++cit;
    }
    while (!que.empty() && -que.top().first <= pi.d) {
      dbg(-que.top().first, que.top().second);
      active.erase(active.find(que.top().second));
      que.pop();
    }
    if (active.empty()) {
      ans[pi.index] = -1;
    } else {
      ans[pi.index] = *active.begin();
    }
  }
  rep(i, q) wt(ans[i]);
}
