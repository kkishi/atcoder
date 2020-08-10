#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct State {
  int city;
  ll remaining;
  ll refueling;
  bool operator<(const State& dp) const {
    if (refueling != dp.refueling) {
      return refueling < dp.refueling;
    }
    return remaining > dp.remaining;
  }
  bool operator>(const State& dp) const { return dp < *this; }
};

int main() {
  rd(ll, n, m, l);

  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 0LL));
  rep(i, m) {
    rd(ll, a, b, c);
    if (c <= l) {
      dist[a][b] = dist[b][a] = c;
    }
  }

  vector<map<int, State>> seens(n + 1);
  rep(i, n) {
    int city = i + 1;
    State init = {city, l, 0};

    map<int, State>& seen = seens[city];
    seen[city] = init;

    priority_queue<State, vector<State>, greater<State>> que;
    que.push(init);

    while (!que.empty()) {
      State here = que.top();
      que.pop();
      if (seen[here.city] < here) continue;
      rep(j, n) {
        State there = here;
        there.city = j + 1;
        if (here.city == there.city) continue;
        ll d = dist[here.city][there.city];
        if (d == 0) continue;
        there.remaining -= d;
        if (there.remaining < 0) {
          there.remaining = l - d;
          ++there.refueling;
        }
        const auto p = seen.find(there.city);
        if (p != seen.end() && !(there < p->second)) continue;
        seen[there.city] = there;
        que.push(there);
      }
    }
  }
  rd(int, q);
  rep(i, q) {
    rd(int, s, t);
    const auto p = seens[s].find(t);
    if (p == seens[s].end()) {
      wt(-1);
    } else {
      wt(p->second.refueling);
    }
  }
}
