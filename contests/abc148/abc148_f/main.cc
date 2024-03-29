#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

int n, u, v;

void Main() {
  cin >> n >> u >> v;
  Graph edges(n);
  edges.Read();

  map<int, int> aoki;
  aoki[v - 1] = 0;
  queue<int> que;
  que.push(v - 1);

  while (!que.empty()) {
    int here = que.front();
    que.pop();
    // dbg(here, aoki[here]);
    for (int there : edges[here]) {
      if (aoki.count(there)) continue;
      aoki[there] = aoki[here] + 1;
      que.push(there);
    }
  }

  map<int, int> takahashi;
  takahashi[u - 1] = 0;
  que.push(u - 1);

  int maxi = -1;
  while (!que.empty()) {
    int here = que.front();
    que.pop();
    chmax(maxi, aoki[here]);
    // dbg(here, takahashi[here]);
    for (int there : edges[here]) {
      if (takahashi.count(there)) continue;
      if (aoki[there] <= takahashi[here] + 1) continue;
      takahashi[there] = takahashi[here] + 1;
      que.push(there);
      chmax(maxi, aoki[there]);
    }
  }
  dbg(maxi);
  if (maxi == -1) {
    if (aoki[u - 1] == 1) {
      wt(0);
    } else {
      wt(1);
    }
  } else {
    wt(maxi - 1);
  }
}
