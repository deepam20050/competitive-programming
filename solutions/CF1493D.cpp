#include "bits/stdc++.h"

using namespace std;

const int M = 2e5 + 5;
const int MOD = 1e9 + 7;

map < int, int > a[M];
vector < int > cnt[M];
int sp[M];
int ans = 1;
int n, nq;

void precalc () {
  memset(sp, -1, sizeof sp);
  for (int i = 2; i < M; i += 2) sp[i] = 2;
  for (int i = 3; i < M; i += 2) {
    if (sp[i] == -1) {
      sp[i] = i;
      for (int j = i; 1ll * j * i < M; j += 2) {
        if (sp[j * i] == -1) {
          sp[j * i] = i;
        }
      }
    }
  }
}

void push (int prime, int x) {
  if (cnt[prime].size() < x) 
    cnt[prime].emplace_back(0);
  --x;
  ++cnt[prime][x];
  if (cnt[prime][x] == n) {
    ans = 1ll * ans * prime % MOD;
  }
}

void update (int pos, int x) {
  while (x > 1) {
    push(sp[x], ++a[pos][sp[x]]);
    x /= sp[x];
  }
}

int main () {
  precalc();
  scanf("%d %d", &n, &nq);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    update(i, x);
  }
  while (nq--) {
    int i, x;
    scanf("%d %d", &i, &x);
    update(i, x);
    printf("%d\n", ans);
  }
  return 0;
}
