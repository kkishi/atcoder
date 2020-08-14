#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, d, g);
  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];
  ll ans = numeric_limits<ll>::max();
  for (int s = 0; s < (1 << d); ++s) {
    ll solved = 0;
    ll score = 0;
    rep(i, d) if ((s >> i) & 1) {
      solved += p[i];
      score += p[i] * 100 * (i + 1) + c[i];
    }
    for (int i = d - 1; i >= 0 && score < g; --i) {
      if ((s >> i) & 1) continue;
      ll score_per_problem = 100 * (i + 1);
      ll problems_to_solve =
          ((g - score) + score_per_problem - 1) / score_per_problem;
      ll solve = min(problems_to_solve, p[i]);
      solved += solve;
      score += score_per_problem * solve;
      if (solve == p[i]) score += c[i];
    }
    chmin(ans, solved);
  }
  wt(ans);
}
