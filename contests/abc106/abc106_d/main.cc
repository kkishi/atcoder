#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, M, Q);
  vector<int> l(N + 2), r(N + 2);
  vector<vector<int>> train(N + 1);
  while (M--) {
    ints(L, R);
    ++l[L];
    ++r[R];
    train[L].push_back(R);
  }
  vector<int> ls(N + 2), rs(N + 2);
  rep(i, N) {
    ls[i + 1] = ls[i] + l[i + 1];
    rs[i + 1] = rs[i] + r[i + 1];
  }

  vector<vector<int>> outside(N + 1, vector<int>(N + 1));
  low_priority_queue<int> que;
  for (int i = 1; i <= N; ++i) {
    for (int t : train[i - 1]) {
      que.push(t);
    }
    while (!que.empty() && que.top() <= i) {
      que.pop();
    }
    low_priority_queue<int> que2 = que;
    for (int j = i; j <= N; ++j) {
      while (!que2.empty() && que2.top() <= j) {
        que2.pop();
      }
      outside[i][j] = que2.size();
    }
  }
  while (Q--) {
    ints(p, q);
    wt(rs[q] - ls[p - 1] + outside[p][q]);
  }
}
