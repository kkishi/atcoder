#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;

using namespace std;

int A[2 * 100000];

ll choose2(ll n) { return n * (n - 1) / 2; }

int main() {
  int N;
  cin >> N;
  map<int, int> m;
  REP(i, N) {
    cin >> A[i];
    m[A[i]]++;
  }
  ll total = 0;
  for (const auto it : m) {
    total += choose2(it.second);
  }
  REP(i, N) {
    ll n = m[A[i]];
    cout << (total - choose2(n) + choose2(n - 1)) << endl;
  }
}
