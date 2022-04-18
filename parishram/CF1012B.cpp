#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int MAX = 4e5 + 5;

int p[MAX], siz[MAX];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  siz[x] += siz[y];
  p[y] = x;
}

int main () {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  FOR(i, 1, MAX) {
    p[i] = i;
    siz[i] = 1;
  }
  while (nq--) {
    int a, b;
    scanf("%d %d", &a, &b);
    join(a, b + n);
  }
  int ans = 0;
  FOR(i, 1, n + m + 1) {
    if (find(i) == i) {
      ++ans;
    }
  }
  printf("%d\n", ans - 1);
  return 0;
}
