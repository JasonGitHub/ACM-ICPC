// http://codeforces.com/contest/363/problem/A
#include <iostream>

using namespace std;

void PrintDigit(int d) {
  if (d < 5) cout << "O-|";
  else cout << "-O|";
  d %= 5;
  for (int i = 0; i < d; ++i) {
    cout << "O";
  }
  cout << "-";
  for (int i = 0; i < 4 - d; ++i) {
    cout << "O";
  }
  cout << endl;
}

void Soroban(int n) {
  while (true) {
    int d = n % 10;
    PrintDigit(d);
    n /= 10;
    if (!n) break;
  }
}  

int main() {
  int n;
  cin >> n;
  Soroban(n);
  return 0;
}
