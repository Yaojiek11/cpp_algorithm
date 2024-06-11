#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
const long long int INF=1000000000000000000;

//dp[i番目の必殺技について][必殺技の組み合わせ2^15=32768]
//A[i]:二進数表記で破壊できるオーブを明記(ex. 1001の場合、1番目と4番目を破壊可能)
ll int N, M, E[201], K[201], O[201][15], A[201]={}, dp[201][32768]={};
int main(){
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        cin >> E[i] >> K[i];
        for(int j=0; j<K[i]; j++){
            cin >> O[i][j];
            A[i]+=(1<<(O[i][j]-1));
        }
    }

    //dp配列初期化
    for(int i=0; i<=M; i++){
        for(int j=0; j<(1<<N); j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0]=0;

    for(int i=1; i<=M; i++){
        for(int j=0; j<(1<<N); j++){
            dp[i][j|A[i]] = min(dp[i][j|A[i]], dp[i-1][j] + E[i]);
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }

    if(dp[M][(1<<N)-1]==INF){
        cout << "Dead" << endl;
    }else{
        cout << "Alive" << endl << dp[M][(1<<N)-1] << endl;
    }

    return 0;
}