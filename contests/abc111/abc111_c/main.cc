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

int main() {
  in(int, n);
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<pair<int, int>>> counts(2);
  rep(i, 2) {
    map<int, int> m;
    for (int j = i; j < n; j += 2) m[v[j]]++;
    for (auto [k, v] : m) {
      counts[i].push_back({v, k});
    }
    sort(all(counts[i]), greater());
  }
  rep(i, 2) for (auto [k, v] : counts[i]) dbg(i, k, v);
  rep(i, 2) dbg(counts[i].size());
  // 1 2 3 1 1 1
  // 1 3 1
  // 2 1 1
  // 1 2 1 2 1 2
  // 2 1 2 1 2 1

  if (counts[0][0].second != counts[1][0].second) {
    out(n - (counts[0][0].first + counts[1][0].first));
  } else {
    vector<int> second(2);
    rep(i, 2) second[i] = counts[i].size() == 1 ? 0 : counts[i][1].first;
    rep(i, 2) dbg(second[i]);
    out(n -
        max(counts[0][0].first + second[1], counts[1][0].first + second[0]));
  }
}
