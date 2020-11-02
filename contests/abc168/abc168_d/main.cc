#include <bits/stdc++.h>

#include "atcoder.h"

int A[2 * 100000];
int B[2 * 100000];

void Main() {
  ints(N, M);

  vector<vector<int>> edges(N);
  rep(i, M) {
    ints(A, B);
    --A, --B;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }

  map<int, int> prev;
  prev[0] = -1;

  queue<int> que;
  que.push(0);

  while (!que.empty()) {
    int here = que.front();
    que.pop();

    for (int there : edges[here]) {
      if (prev.count(there) > 0) {
        continue;
      }
      prev[there] = here;
      que.push(there);
    }
  }

  bool ok = true;
  for (int i = 2; i < N; ++i) {
    if (prev.count(i) == 0) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
  for (int i = 1; i < N; ++i) {
    cout << prev[i] + 1 << endl;
  }
}
