#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int Gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  assert(a != 0 && b != 0);
  return gcd(a, b);
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];

  SegmentTree<int, Gcd> t(N);
  REP(i, N) { t.Set(i, A[i]); }

  int ans = 0;
  REP(i, N) { ans = max(ans, Gcd(t.Aggregate(0, i), t.Aggregate(i + 1, N))); }
  cout << ans << endl;
}
