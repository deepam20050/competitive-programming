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

const int N = 1e5 + 5;

int arr[N];
map < int, int > who;
int p[N];
int vis[N];
int yes[N];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

int main () {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    who[arr[i]] = i;
    p[i] = i;
  }
  FOR(i, 1, n + 1) {
    int x = arr[i];
    if (who.count(a - x)) {
      p[find(who[a - x])] = find(i);
      vis[i] |= 1;
    }
    if (who.count(b - x)) {
      p[find(who[b - x])] = find(i);
      vis[i] |= 2;
    }
  }
  FOR(i, 1, n + 1) {
    yes[i] = 3;
  }
  FOR(i, 1, n + 1) {
    yes[find(i)] &= vis[i];
  }
  FOR(i, 1, n + 1) {
    if (yes[i] == 0) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  FOR(i, 1, n + 1) {
    printf("%d ", (yes[find(i)] & 1) == 0);
  }
  return 0;
}
