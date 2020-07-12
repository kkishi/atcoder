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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
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
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

template <typename T, T Op(T, T), T Unit = T()>
class SegmentTree {
 public:
  SegmentTree(int size) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, Unit);
    l_.resize(two * 2 - 1, Unit);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = Op(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    return aggregate(begin, end, 0, (v_.size() + 1) / 2, 0);
  }
  void Update(int begin, int end, T v) {
    update(begin, end, 0, (v_.size() + 1) / 2, 0, v);
  }

 private:
  T aggregate(int begin, int end, int cbegin, int cend, int index) const {
    if (begin <= cbegin && cend <= end) {
      return v_[index] + l_[index];
    }
    if (cend <= begin || end <= cbegin) {
      return Unit;
    }
    int cmid = (cbegin + cend) / 2;
    return l_[index] +
        Op(aggregate(begin, end, cbegin, cmid, index * 2 + 1),
           aggregate(begin, end, cmid, cend, index * 2 + 2));
  }
  void update(int begin, int end, int cbegin, int cend, int index, T v) {
    if (begin <= cbegin && cend <= end) {
      l_[index] += v;
      return;
    }
    if (cend <= begin || end <= cbegin) {
      return;
    }
    int cmid = (cbegin + cend) / 2;
    update(begin, end, cbegin, cmid, index * 2 + 1, v);
    update(begin, end, cmid, cend, index * 2 + 2, v);
  }
  std::vector<T> v_;
  std::vector<T> l_;
};

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const {
    return X < m.X;
  }
};

Monster monster[200000];

ll Add(ll a, ll b) { return a + b; }

int main() {
  CIN(ll, N, D, A);
  REP(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  SegmentTree<ll, Add> tree(N);
  REP(i, N) tree.Set(i, monster[i].H);

  ll ans = 0;
  int mi = 0;
  while (mi < N) {
    int h = tree.Get(mi);
    if (h <= 0) {
      ++mi;
      continue;
    }
    Monster max_m = {monster[mi].X + D * 2, 0};
    int ub = upper_bound(monster, monster + N, max_m) - monster;
    ll cnt = (h + A - 1) / A;
    tree.Update(mi, ub, -cnt * A);
    ans += cnt;
  }
  COUT(ans);
}
