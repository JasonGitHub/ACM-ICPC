#include <iostream>

using namespace std;

bool FindStartAndSide(bool a[][20], int n, int &x, int &y, int &side) {
  bool f = false;
  side = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!f && a[i][j]) {
        x = i;
        y = j;
        f = true;
      }
      if (f && i == x && a[i][j]) side = max(j - y + 1, side);
    }
  }
  return f;
}

bool SquareDetector(bool a[][20], int n) {
  int x, y, side;
  if (!FindStartAndSide(a, n, x, y, side)) return false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= x && i < x + side && j >= y && j < y + side) {
        if (!a[i][j]) return false;
      } else {
        if (a[i][j]) return false;
      }
    }
  }
  return true;
}

int main() {
  int t, n;
  bool a[20][20];
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        char tmp;
        cin >> tmp;
        a[j][k] = tmp == '#' ? true : false;
      }
    }
    cout << "Case #" << i + 1 << ": ";
    if (SquareDetector(a, n)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
