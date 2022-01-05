// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 3e5 + 5;

int ch[N * 30][2], cnt[N * 30], tot;
int a[N];

void insert (int x) {
  int u = 0;
  for (int i = 29; i >= 0; --i) {
    int c = x >> i & 1;
    if (!ch[u][c]) ch[u][c] = ++tot;
    u = ch[u][c];
    ++cnt[u];
  }
}

int getMinDel (int x) {
  int u = 0, res = 0;
  for (int i = 29; i >= 0; --i) {
    int c = x >> i & 1;
    if (cnt[ch[u][c]]) {
      u = ch[u][c];
    } else {
      u = ch[u][c ^ 1];
      res ^= 1 << i;
    }
    --cnt[u];
  }
  return res;
}

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) scanf("%d", a + i);
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    insert(x);
  }
  FOR(i, 0, n) {
    printf("%d ", getMinDel(a[i]));
  }
  return 0;
}
