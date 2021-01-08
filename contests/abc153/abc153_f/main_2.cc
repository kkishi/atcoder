#include <bits/stdc++.h>

#include "atcoder.h"

struct Monster {
  int X, H;
  bool operator<(const Monster& m) const { return X < m.X; }
};

Monster monster[200000];

int Add(int a, int b) { return a + b; }

void Main() {
  ints(N, D, A);
  rep(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  int ans = 0;
  queue<pair<int, int>> que;
  int damage_sum = 0;
  rep(i, N) {
    while (!que.empty() && que.front().first < monster[i].X) {
      damage_sum -= que.front().second;
      que.pop();
    }
    int remaining = monster[i].H - damage_sum;
    if (remaining > 0) {
      int cnt = div_ceil(remaining, A);
      ans += cnt;
      damage_sum += cnt * A;
      que.push({monster[i].X + 2 * D, cnt * A});
    }
  }
  wt(ans);
}
