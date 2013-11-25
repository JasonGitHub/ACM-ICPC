#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int k; 
double ps, pr, pi, pu, pw, pd, pl;
double p[101][101][1001];

double Solve(int w, int l, double s) {  // w: wins l: losses s: probability of sunny
  int ix = 1000 * s;
  if (w == k) return 1;
  if (l == k) return 0;
  if (p[w][l][ix] != -1) return p[w][l][ix];
  double up = s + pu >= 1 ? 1 : s + pu;
  double down = s - pd <= 0 ? 0 : s - pd;
  double ret = s * ps * pw * Solve(w + 1, l, up) +
               s * ps * (1 - pw) * Solve(w + 1, l, s) +
               s * (1 - ps) * pl * Solve(w, l + 1, down) +
               s * (1 - ps) * (1 - pl) * Solve(w, l + 1, s) +
               (1 - s) * pr * pw * Solve(w + 1, l, up) +
               (1 - s) * pr * (1 - pw) * Solve(w + 1, l, s) +
               (1 - s) * (1 - pr) * pl * Solve(w, l + 1, down) +
               (1 - s) * (1 - pr) * (1 - pl) * Solve(w, l + 1, s);
  p[w][l][ix] = ret;
  return ret;
}

void ClearP() {
  for (int i = 0; i < 101; ++i)
    for (int j = 0; j < 101; ++j)
      for (int k = 0; k < 1001; ++k)
        p[i][j][k] = -1;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    ClearP();
    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    cout << "Case #" << i + 1 << ": " << fixed << setprecision(6)
      << Solve(0, 0, pi) << endl;
  }
  return 0;
}
