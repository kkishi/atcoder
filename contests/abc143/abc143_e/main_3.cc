#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

const ll INF = 1LL << 60;

template <typename T>
void WarshalFloyd(vector<vector<T>>& v) {
  for (int k = 0; k < v.size(); ++k) {
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
      }
    }
  }
}

int main() {
  in(ll, n, m, l);

  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, m) {
    in(ll, a, b, c);
    if (c <= l) {
      --a, --b;
      dist[a][b] = dist[b][a] = c;
    }
  }
  WarshalFloyd(dist);

  vector<vector<ll>> dist2(n, vector<ll>(n, INF));
  rep(i, n) rep(j, n) if (dist[i][j] <= l) dist2[i][j] = 1;
  WarshalFloyd(dist2);

  in(int, q);
  rep(i, q) {
    in(int, s, t);
    --s, --t;
    ll d = dist2[s][t];
    if (d == INF) {
      out(-1);
    } else {
      out(d - 1);
    }
  }
}
