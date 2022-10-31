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

char s[N];
int who[2][2];

int main () {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  lli odd = 0, even = 0;
  FOR(i, 1, n + 1) {
    ++who[s[i] - 'a'][i & 1];
    odd += who[s[i] - 'a'][i & 1];
    even += who[s[i] - 'a'][1 ^ (i & 1)];
  }
  printf("%lld %lld\n", even, odd);
  return 0;
}
