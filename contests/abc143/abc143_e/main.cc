#include <bits/stdc++.h>

#include "atcoder.h"

struct State {
  int city;
  int remaining;
  int refueling;
  bool operator<(const State& dp) const {
    if (refueling != dp.refueling) {
      return refueling < dp.refueling;
    }
    return remaining > dp.remaining;
  }
  bool operator>(const State& dp) const { return dp < *this; }
};

int dist[301][301];
State seens[301][301];

void Main() {
  ints(n, m, l);

  rep(i, m) {
    ints(a, b, c);
    if (c <= l) {
      dist[a][b] = dist[b][a] = c;
    }
  }

  rep(i, n) {
    int city = i + 1;
    State init = {city, l, 0};

    State* seen = seens[city];
    seen[city] = init;

    low_priority_queue<State> que;
    que.push(init);

    while (!que.empty()) {
      State here = que.top();
      que.pop();
      if (seen[here.city] < here) continue;
      rep(j, n) {
        State there = here;
        there.city = j + 1;
        if (here.city == there.city) continue;
        int d = dist[here.city][there.city];
        if (d == 0) continue;
        there.remaining -= d;
        if (there.remaining < 0) {
          there.remaining = l - d;
          ++there.refueling;
        }
        State& s = seen[there.city];
        if (s.city == there.city && !(there < s)) continue;
        s = there;
        que.push(there);
      }
    }
  }
  ints(q);
  rep(i, q) {
    ints(s, t);
    State& st = seens[s][t];
    if (st.city == 0) {
      wt(-1);
    } else {
      wt(st.refueling);
    }
  }
}
