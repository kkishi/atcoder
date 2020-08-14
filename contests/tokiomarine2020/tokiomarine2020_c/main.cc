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
      priority_queue<ll, vector<ll>, greater<ll>> que;
      rep(j, n) {
        while (!que.empty() && que.top() < j) que.pop();
        na[j] += que.size();
        que.push(j + a[j]);
      }
    }
    {
      priority_queue<ll> que;
      for (ll j = n - 1; j >= 0; --j) {
        while (!que.empty() && que.top() > j) que.pop();
        na[j] += que.size();
        que.push(j - a[j]);
      }
    }
    bool changed = false;
    rep(j, n) if (na[j] != a[j]) changed = true;
    if (!changed) break;
    swap(a, na);
  }
  rep(i, n) { cout << a[i] << " "; }
  cout << endl;
}
