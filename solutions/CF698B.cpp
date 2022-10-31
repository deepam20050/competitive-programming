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

const int N = 2e5 + 5;

int p[N], siz[N];
int yeet[N];
int n;

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (siz[x] < siz[y]) {
    swap(x, y);
  }
  siz[x] += siz[y];
  p[y] = x;
}

int main () {
  scanf("%d", &n);
  int root = -1;
  FOR(i, 1, n + 1) {
    scanf("%d", yeet + i);
    p[i] = i;
    siz[i] = 1;
    if (i == yeet[i]) {
      root = i;
    }
  }
  int ans = 0;
  FOR(i, 1, n + 1) {
    if (find(i) != find(yeet[i])) {
      join(i, yeet[i]);
    } else if (i != yeet[i]) {
      if (root == -1) {
        yeet[i] = i;
        root = i;
        ++ans;
      } else {
        yeet[i] = root;
        ++ans;
        join(i, root);
      }
    }
  }
  FOR(i, 1, n + 1) {
    if (i == yeet[i] && i != root) {
      join(yeet[i], root);
      ++ans;
      yeet[i] = root;
    }
  }
  FOR(i, 1, n + 1) {
    if (find(i) != find(root)) {
      yeet[i] = root;
      ++ans;
      join(i, root);
    }
  }
  printf("%d\n", ans);
  FOR(i, 1, n + 1) {
    printf("%d%c", yeet[i], " \n"[i == n - 1]);
  }
  return 0;
}
