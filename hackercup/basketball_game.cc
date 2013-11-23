#include <iostream>
#include <iomanip>
#include <queue>
#include <deque>
#include <string>
#include <iterator>
#include <cassert>

using namespace std;

struct Player {
  string name;
  int pct;
  int height;
  bool operator<(const Player &p) const {return pct != p.pct ? pct < p.pct : height < p.height;}
  bool operator>(const Player &p) const {return p < *this;}
};

void Solve(deque<Player> &players, int n, int m, int p) {
  deque<Player> t1on, t2on, t1off, t2off;
  sort(players.begin(), players.end(), greater<Player>());

  for (int i = 0; i < players.size(); ++i) {
    if (i % 2 == 0) t1off.push_back(players[i]);
    else t2off.push_back(players[i]);
  }

  for (int i = 0; i < p; ++i) {
    Player tmp = t1off.front();
    t1off.pop_front();
    t1on.push_back(tmp);
  }

  for (int i = 0; i < p; ++i) {
    Player tmp = t2off.front();
    t2off.pop_front();
    t2on.push_back(tmp);
  }

  for (int i = 0; i < m; ++i) {
    Player tmp = t1on.back();
    t1on.pop_back();
    t1off.push_back(tmp);
    tmp = t1off.front();
    t1off.pop_front();
    t1on.push_front(tmp);
  }

  for (int i = 0; i < m; ++i) {
    Player tmp = t2on.back();
    t2on.pop_back();
    t2off.push_back(tmp);
    tmp = t2off.front();
    t2off.pop_front();
    t2on.push_front(tmp);
  }

  copy(t2on.begin(), t2on.end(), back_inserter(t1on));
  sort(t1on.begin(), t1on.end(), [](Player a, Player b){return a.name < b.name;});
  for (auto &item : t1on) cout << item.name << " ";
}

int main() {
  int t, n, m, p;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m >> p;
    deque<Player> players;
    for (int j = 0; j < n; ++j) {
      Player player;
      cin >> player.name >> player.pct >> player.height;
      players.push_back(player);
    }
    cout << "Case #" << i + 1 << ": ";
    Solve(players, n, m, p);
    cout << endl;
  }
  return 0;
}
 
