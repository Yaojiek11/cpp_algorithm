#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
#define INF 100000000
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define rep(i, n) for(int (i)=1; (i)<=(n); (i)++)
typedef pair<int, int> P;
typedef long long ll;

int main(){

    string S;
    cin >> S;
    int cnt[27];

    for(int i=0; i<27; i++)
        cnt[i] = 0;

    for(int i=0; i < S.size(); i++){
        if(S[i] >= 'A' && S[i] <= 'Z'){
            cnt[S[i]-'A']++;
        }
    }

    for(int i=0; i<=26; i++){
        cout << char('A'+i) << " : " << cnt[i] << endl;
    }

    return 0;
}