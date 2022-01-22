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
using arr = array < int, 3 >;

const int N = 105;

double dp[N][N][N];
int r, s, p;

double f (int rr, int ss, int pp) {
  if(!((rr ^ r) | (ss ^ s) | (pp ^ p))){
      return 1.0;
  }
  if(rr > r || ss > s || pp > p){
      return 0.0;
  }
  if (dp[rr][ss][pp] == dp[rr][ss][pp]) {
    return dp[rr][ss][pp];
  }
  double a = f(rr , ss + 1 , pp);
  double b = f(rr + 1 , ss , pp);
  double c = f(rr , ss , pp + 1);
  double x = 1.0 * (rr * (ss + 1)) / (rr * (ss + 1) + rr * pp + (ss + 1) * pp);
  double y = 1.0 * ((rr + 1) * pp) / ((rr + 1) * ss + (rr + 1) * pp + ss * pp);
  double z = 1.0 * (ss * (pp + 1)) / (rr * ss + rr * (pp + 1) + (pp + 1) * ss);
  if(rr == 0){
      x = 0;
  }
  if(pp == 0){
      y = 0;
  }
  if(ss == 0){
      z = 0;
  }
  return dp[rr][ss][pp] = a * x + b * y + c * z;
}

int main () {
  scanf("%d %d %d", &r, &s, &p);
  double ansr = 0, anss = 0, ansp = 0;
  memset(dp, -1, sizeof dp);
  FOR(i, 1, r + 1) ansr += f(i, 0, 0);
  FOR(i, 1, s + 1) anss += f(0, i, 0);
  FOR(i, 1, p + 1) ansp += f(0, 0, i);
  printf("%.9lf %.9lf %.9lf\n", ansr, anss, ansp);
  return 0;
}
