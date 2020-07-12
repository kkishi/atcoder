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
  in(ll, n, k);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
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
  rep(i, n) {
    cout << a[i] << " ";
  }
  cout << endl;
}
