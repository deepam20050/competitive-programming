#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 5;
const int M = 1e6 + 2;

int a[N];
int divs[M];
set < int > st;
int n;
int nq;

struct FenwickTree {
  long long t[N];
  void update (int idx, int add) {
    while (idx <= n) {
      t[idx] += add;
      idx += idx & -idx;
    }
  }
  long long query (int idx) {
    long long sum = 0;
    while (idx > 0) {
      sum += t[idx];
      idx -= idx & -idx;
    }
    return sum;
  }
} tree1;

void precalc () {
  for (int i = 1; i < M; ++i) {
    for (int j = i; j < M; j += i) {
      ++divs[j];
    }
  }
}

int main () {
  precalc();
  scanf("%d %d", &n, &nq);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    tree1.update(i, a[i]);
    if (a[i] > 2) {
      st.insert(i);
    }
  }
  while (nq--) {
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1) {
      auto it = st.lower_bound(l);
      while (it != st.end() && *it <= r) {
        int y = *it;
        int x = a[y];
        a[y] = divs[x];
        tree1.update(y, a[y] - x);
        if (a[y] <= 2) st.erase(it++);
        else ++it;
      }
    } else {
      printf("%lld\n", tree1.query(r) - tree1.query(l - 1));
    }
  }
  return 0;
}
