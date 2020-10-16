#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;
  rep(i, k) {
    vector<int> na(n);
    rep(j, n) na[j] = 1;
    {
      low_priority_queue<int> que;
      rep(j, n) {
        while (!que.empty() && que.top() < j) que.pop();
        na[j] += que.size();
        que.push(j + a[j]);
      }
    }
    {
      priority_queue<int> que;
      rrep(j, n) {
        while (!que.empty() && que.top() > j) que.pop();
        na[j] += que.size();
        que.push(j - a[j]);
      }
    }
    if (na == a) break;
    swap(a, na);
  }
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}
