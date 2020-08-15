#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;
  rep(i, k) {
    vector<ll> na(n);
    rep(j, n) na[j] = 1;
    {
      low_priority_queue<ll> que;
      rep(j, n) {
        while (!que.empty() && que.top() < j) que.pop();
        na[j] += que.size();
        que.push(j + a[j]);
      }
    }
    {
      priority_queue<ll> que;
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
