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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

char s[N];

void solveTestCase () {
  int n, k; scanf("%d %d", &n, &k);  
  vector < bool > used(26);
  scanf("%s", s);
  FOR(i, 0, n) {
    int x = s[i] - 'a';
    for (; k && x && !used[x]; --x) {
      --k;
      used[x] = 1;
    }
    for (; used[x]; --x);
    printf("%c", x + 'a');
  }
  puts("");
}

int main () {
  int _tc; scanf("%d", &_tc);
  while (_tc--) {
    solveTestCase();
  }
  return 0;
}