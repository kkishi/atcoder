#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  priority_queue<int> que;
  rep(i, n) {
    rd(int, a);
    que.push(a);
  }
  rep(i, m) {
    int a = que.top();
    que.pop();
    que.push(a / 2);
  }
  ll ans = 0;
  while (!que.empty()) {
    ans += que.top();
    que.pop();
  }
  wt(ans);
}
