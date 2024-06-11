#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define INF 1e9+7

ll int N, E, dp1[3001][10001]={}, dp2[3001][10001]={};
pair<ll int, ll int> AC[3001];

int main(){
    cin >> N >> E;
    for(int i=1; i<=N; i++)
        cin >> AC[i].first >> AC[i].second;

    //AとCをAについて小さい順に並び替える。
    sort(AC+1,AC+N+1);

    for(int i=1; i<=N; i++){
        for(int j=0; j<=E; j++){
            //i番目のボタンを押す(このあともボタンを押す)
            if(j >= AC[i].second){
                dp1[i][j] = max(dp1[i][j], dp1[i-1][j-AC[i].second]+AC[i].first);
            }

            //押さない
            dp1[i][j] = max(dp1[i][j], dp1[i-1][j]);

            //i番目のボタンを押す(このあとはボタンを押さない)
            if(j <= AC[i].second){
                dp2[i][j] = max(dp2[i][j], dp1[i-1][j-AC[i].second] + 10*AC[i].first);
            }

            //dp2に遷移したあとはボタンを押さない
            dp2[i][j] = max(dp2[i][j], dp2[i][j-1]);
        }
    }
    cout << dp2[N][E] << endl;

    return 0;
}