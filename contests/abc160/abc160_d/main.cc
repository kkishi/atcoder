#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int dist[2 * 1000];

int abs(int x) { return x < 0 ? -x : x; }

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  --X, --Y;

  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < j; ++i) {
      dist[min(j - i, min(abs(X - i) + 1 + abs(Y - j),
                          abs(Y - i) + 1 + abs(X - j)))]++;
    }
  }
  for (int i = 1; i <= N - 1; ++i) {
    cout << dist[i] << endl;
  }
}
