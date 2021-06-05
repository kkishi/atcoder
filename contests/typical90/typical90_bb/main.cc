#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> papers;
  VV<int> authored_papers(n);
  rep(i, m) {
    ints(k);
    V<int> r(k);
    cin >> r;
    each(e, r) {
      --e;
      authored_papers[e].pb(i);
    }
    papers.eb(r);
  }
  V<int> ans(n, -1);
  queue<pair<int, int>> que;
  que.emplace(0, 0);
  V<bool> seen_person(n);
  seen_person[0] = true;
  V<bool> seen_paper(m);
  while (!que.empty()) {
    auto [person, number] = que.front();
    que.pop();
    ans[person] = number;
    each(paper_idx, authored_papers[person]) {
      if (seen_paper[paper_idx]) continue;
      seen_paper[paper_idx] = true;
      each(author, papers[paper_idx]) {
        if (seen_person[author]) continue;
        seen_person[author] = true;
        que.emplace(author, number + 1);
      }
    }
  }
  each(e, ans) wt(e);
}
