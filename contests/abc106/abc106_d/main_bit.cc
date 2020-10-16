#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

using P = pair<int, int>;

struct Query {
  int i, l, r;
};

void Main() {
  ints(N, M, Q);

  V<P> trains;
  rep(i, M) {
    ints(L, R);
    trains.push_back({L - 1, R - 1});
  }
  sort(all(trains), [](const P& a, const P& b) { return a.second < b.second; });

  V<Query> queries;
  rep(i, Q) {
    ints(p, q);
    queries.push_back({i, p - 1, q - 1});
  }
  sort(all(queries), [](const Query& a, const Query& b) { return a.r < b.r; });

  V<int> ans(Q);
  BIT<int> bit(N);
  auto ti = trains.begin();
  auto qi = queries.begin();
  rep(r, N) {
    for (; ti != trains.end() && ti->second <= r; ++ti) {
      bit.Add(ti->first, 1);
    }
    for (; qi != queries.end() && qi->r <= r; ++qi) {
      ans[qi->i] = bit.Sum(qi->r) - bit.Sum(qi->l - 1);
    }
  }
  rep(i, Q) wt(ans[i]);
}
