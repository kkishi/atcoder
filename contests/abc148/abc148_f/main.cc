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

int n, u, v;



int main() {
  cin >> n >> u >> v;
  vector<vector<int>> edges(n);
  rep(i, n - 1) {
    in(int, a, b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

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
    maxi = max(maxi, aoki[here]);
    // dbg(here, takahashi[here]);
    for (int there : edges[here]) {
      if (takahashi.count(there)) continue;
      if (aoki[there] <= takahashi[here] + 1) continue;
      takahashi[there] = takahashi[here] + 1;
      que.push(there);
      maxi = max(maxi, aoki[there]);
    }
  }
  dbg(maxi);
  if (maxi == -1) {
    if (aoki[u - 1] == 1) {
      out(0);
    } else {
      out(1);
    }
  } else {
    out(maxi - 1);
  }
}
