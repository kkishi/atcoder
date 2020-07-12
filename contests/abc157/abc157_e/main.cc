#include <bits/stdc++.h>

template <typename T, T Op(T, T), T Unit = T()>
    class SegmentTree {
 public:
  SegmentTree(int size) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, Unit);
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

 private:
  T aggregate(int begin, int end, int cbegin, int cend, int index) const {
    if (begin <= cbegin && cend <= end) {
      return v_[index];
    }
    if (cend <= begin || end <= cbegin) {
      return Unit;
    }
    int cmid = (cbegin + cend) / 2;
    return Op(aggregate(begin, end, cbegin, cmid, index * 2 + 1),
              aggregate(begin, end, cmid, cend, index * 2 + 2));
  }
  std::vector<T> v_;
};

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

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int Union(int a, int b) { return a | b; }

int main() {
  int N;
  cin >> N;
  SegmentTree<int, Union> tree(N);
  string S;
  cin >> S;
  REP(i, N) tree.Set(i, 1 << (S[i] - 'a'));
  REP(i, N) DBG(i, tree.Get(i));
  int Q;
  cin >> Q;
  REP(q, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      tree.Set(i - 1, 1 << (c - 'a'));
    } else {
      int l, r;
      cin >> l >> r;
      cout << __builtin_popcount(tree.Aggregate(l - 1, r)) << endl;
    }
  }
}
