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

const int N = 1e5 + 5;
const int M = 26;

char str[N];
char suff[N];
stack < char > s;

int main () {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  suff[n] = str[n];
  for (int i = n - 1; i >= 1; --i) {
    suff[i] = min(suff[i + 1], str[i]);
  }
  int ptr = 1;
  FOR(i, 1, n + 1) {
    if (ptr > n) {
      printf("%c", s.top());
      s.pop();
    } else if (!s.empty() && s.top() <= suff[ptr]) {
      printf("%c", s.top());
      s.pop();
    } else {
      while (ptr <= n && str[ptr] != suff[ptr]) {
        s.em(str[ptr++]);
      }
      s.em(str[ptr++]);
      printf("%c", s.top());
      s.pop();
    }
  }
  return 0;
}