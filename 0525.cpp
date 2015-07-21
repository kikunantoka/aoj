//include
//------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const int MAX_R = 10 + 1;
const int MAX_C = 10000 + 1;

int senbei[MAX_C][MAX_R] = {};
int r,c;

vector<int> xx;
vector<int> yy;


int count() {
  int res = 0;
  REP(i,r) {
    REP(j,c) {
      if(senbei[j][i] == 1) res++;
    }
  }
  return res;
}

void upset_x(int y) {
  REP(x,c) {
    senbei[x][y] = -senbei[x][y];
  }
}

void upset_y(int x) {
  REP(y,r) {
    senbei[x][y] = -senbei[x][y];
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int ans = 0;

  while(cin >> r >> c && r && c) {
    ans = 0;
    int tmp = 0;
    yy.clear();
    xx.clear();
    REP(i,r) yy.push_back(i);
    REP(i,c) xx.push_back(i);
    REP(i,r) {
      REP(j,c) {
        cin >> tmp;
        if(tmp == 0) senbei[j][i] = -1;
        else senbei[j][i] = tmp;
      }
    }
    ans = count();
    do {
      REP(i,r) {
        do {
          REP(j,r) {
            upset_y(xx[j]);
            ans = max(ans,count());
          }
        } while( next_permutation(xx.begin(), xx.end()) );
        upset_x(yy[i]);
        ans = max(ans, count());
      }
    } while( next_permutation(yy.begin(), yy.end()) );
    cout << ans << endl;
  }

  return 0;
}
