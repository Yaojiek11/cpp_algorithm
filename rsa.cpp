#include <iostream>
#include <limits>
#include <math.h>
#include <vector>
using namespace std;

//素数判定
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

//ユークリッドの互除法
int euclidean_gcd(int x, int y){
    //以下の性質を利用
    //gcd(x, y) == gcd(y, x mod y) (x >= b)
    //gcd(x, 0) = x

    if (x < y) return euclidean_gcd(y, x);  //x >= y に統一
    if (y > 0) {
        return euclidean_gcd(y, x % y);   //1つ目のケース
    } else {
        return x;  //終端条件
    }
}

//最小公倍数
int lcm(int x, int y)
{
   return x * y / euclidean_gcd(x, y);
}

//拡張ユークリッドの互除法
int extended_gcd(int a, int b){
    int x, y;
    int x1=1, y1=0, z1=a;
    int x2=0, y2=1, z2=b;
    int x3, y3, z3;

    while(z2 != 0){
        //(x3, y3, z3) <- (x1, y1, z1) - q*(x2, y2, z2)
        x3 = x1 - z1/z2 * x2;
        y3 = y1 - z1/z2 * y2;
        z3 = z1 - z1/z2 * z2;
        //(x1, y1, z1) <- (x2, y2, z2)
        x1 = x2;
        y1 = y2;
        z1 = z2;
        //(x2, y2, z2) <- (x3, y3, z3)
        x2 = x3;
        y2 = y3;
        z2 = z3;
    }

    //(x1, y1, z1) == (x, y, gcd(a, b))
    x = x1;
    y = y1;

    return x;
}

//暗号化
int encryption(int n, int phi_n, int M, int e){
    //公開指数eを求める
    //int e;
    //cin >> e;
    /*for(int i = 2; i<INF; i++){
        if(euclidean_gcd(i, phi_n) == 1){
            e = i;
            break;
        }
    }*/
    cout << "公開鍵は(e, n) = (" << e << ", " << n << ")" << endl;
    int C = 1;
    for(int i=0; i<e; i++){
        C *= M;
        C %= n;     //桁数オーバーフロー防止
    }
    return C;
}

//復号化
int decryption(int n, int phi_n, int C, int e){
    //秘密指数dを求める
    int d;
    d = extended_gcd(e, phi_n);
    int M = 1;
    for(int i=0; i<d; i++){
        M *= C;
        M %= n;
    }
    cout << "秘密指数は" << d << endl;
    cout << "秘密鍵は(d, n) = (" << d << ", " << n << ")" << endl;
    return M;
}

int main(){

    int k;  //コマンド
    int p, q;
    int n;
    int phi_n;  //phi_n=(p-1)(q-1)
    int M; //平文
    int C; //暗号文
    int e; //公開指数

    while(true){
        cout << "暗号化は0\n復号化は1\n終了は2を入力\n-> ";
        cin >> k;

        if(k == 0){
            cout << "平文を入力 : ";
            cin >> M;
            cout << endl;
            cout << "p, qを入力（互いに素）" << endl;;
            cout << "p : ";
            cin >> p;
            cout << "q:";
            cin >> q;

            n = p*q;
            phi_n = lcm((p-1), (q-1));

            if(IsPrime(p) && IsPrime(q)){
                //公開指数を決める
                cout << "公開指数:";
                cin >> e;
                cout << endl;
                //公開指数を自動生成
                /*for(int i = 2; i<INF; i++){
                    if(euclidean_gcd(i, phi_n) == 1){
                        e = i;
                        break;
                    }
                }*/
                C = encryption(n, phi_n, M, e);
                cout << "暗号文 : " << C << endl;
            }
            else cout << "素数を入力して下さい。" << endl;

            continue;
        }
        else if(k == 1){
            cout << "暗号文を入力 : ";
            cin >> C;
            cout << endl;
            cout << "p, qを入力（互いに素）" << endl;;
            cout << "p:";
            cin >> p;
            cout << "q:";
            cin >> q;

            if(IsPrime(p) && IsPrime(q)){
                n = p*q;
                phi_n = lcm((p-1), (q-1));
                //公開鍵を自動生成
                /*for(int i = 2; i<INF; i++){
                    if(euclidean_gcd(i, phi_n) == 1){
                        e = i;
                        break;
                    }
                }*/
                cout << "公開指数:";
                cin >> e;
                cout << endl;
                //cout << "e = " << e << endl;

                M = decryption(n, phi_n, C, e);
            }
            cout << "平文 : " << M << endl;
            continue;
        }
        else if(k == 2) break;
        else continue;
    }
    return 0;
}