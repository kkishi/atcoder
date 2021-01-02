#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(d, g);
  vector<int> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];
  int ans = big;
  rep(s, 1 << d) {
    int solved = 0;
    int score = 0;
    rep(i, d) if (hasbit(s, i)) {
      solved += p[i];
      score += p[i] * 100 * (i + 1) + c[i];
    }
    rrep(i, d) {
      if (score >= g) break;
      if (hasbit(s, i)) continue;
      int score_per_problem = 100 * (i + 1);
      int problems_to_solve =
          ((g - score) + score_per_problem - 1) / score_per_problem;
      int solve = min(problems_to_solve, p[i]);
      solved += solve;
      score += score_per_problem * solve;
      if (solve == p[i]) score += c[i];
    }
    chmin(ans, solved);
  }
  wt(ans);
}
