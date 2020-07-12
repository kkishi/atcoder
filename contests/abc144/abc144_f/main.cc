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

double e[600];
double p[600];

int main() {
  in(int, n, m);
  vector<vector<int>> to(n);
  rep(i, m) {
    in(int, s, t);
    --s, --t;
    to[s].push_back(t);
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j : to[i]) {
      e[i] += (e[j] + 1) / to[i].size();
    }
    dbg(i, e[i]);
  }
  p[0] = 1;
  for (int i = 0; i < n; ++i) {
    dbg(i, p[i]);
    for (int j : to[i]) {
      p[j] += p[i] / to[i].size();
    }
  }
  double maxi = 0;
  for (int i = 0; i < n; ++i) {
    const vector<int>& t = to[i];
    if (t.size() <= 1) continue;
    double sum = 0;
    for (int j : t) sum += e[j];
    for (int j : t) {
      double diff = p[i] * (sum / t.size() - (sum - e[j]) / (t.size() - 1));
      maxi = max(maxi, diff);
    }
  }
  cout << setprecision(10) << fixed;
  out(e[0] - maxi);
}
