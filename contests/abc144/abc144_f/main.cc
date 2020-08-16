#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

double e[600];
double p[600];

int main() {
  rd(int, n, m);
  VV<int> to(n);
  rep(i, m) {
    rd(int, s, t);
    --s, --t;
    to[s].push_back(t);
  }
  rrep(i, n) {
    for (int j : to[i]) {
      e[i] += (e[j] + 1) / to[i].size();
    }
  }
  p[0] = 1;
  rep(i, n) {
    for (int j : to[i]) {
      p[j] += p[i] / to[i].size();
    }
  }
  double maxi = 0;
  rep(i, n) {
    const vector<int>& t = to[i];
    if (t.size() <= 1) continue;
    double sum = 0;
    for (int j : t) sum += e[j];
    for (int j : t) {
      double diff = p[i] * (sum / t.size() - (sum - e[j]) / (t.size() - 1));
      chmax(maxi, diff);
    }
  }
  cout << setprecision(10) << fixed;
  wt(e[0] - maxi);
}
