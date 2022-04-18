#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

struct DSU {
  int pr[N];
  int rank[N];
  int mx[N];
  void init (int n) {
    for (int i = 1; i <= n; ++i) {
      pr[i] = i;
      rank[i] = 0;
      mx[i] = i;
    }
  }
  int get (int a) {
    return (pr[a] == a) ? a : pr[a] = get(pr[a]);
  }
  bool same (int a, int b) {
    return get(a) == get(b);
  }
  int get_max (int a) {
    return mx[get(a)];
  }
  void join (int a, int b) {
    int A = get(a), B = get(b);
    if (rank[A] == rank[B]) {
      ++rank[A];
    }
    if (rank[A] < rank[B]) {
      swap(A, B);
    }
    pr[B] = A;
    mx[A] = max(mx[A], mx[B]);
  }
};

DSU dsu1;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  dsu1.init(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    dsu1.join(a, b);
  }
  int add = 0;
  int mx = dsu1.get_max(1);
  int lst = 1;
  for (int i = 1; i <= n; ++i) {
    if (i > mx) {
      lst = i;
      mx = dsu1.get_max(i);
      continue;
    }
    if (i <= mx && !dsu1.same(i, lst)) {
      ++add;
      dsu1.join(i, lst);
      mx = max(mx, dsu1.get_max(i));
    }
  }
  printf("%d\n", add);
  return 0;
}
