#include <iostream>
#include <string>
using namespace std;

//暗号化
string encryption(string text, int key){
    for(int i=0; i<text.size(); i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] += key;
            if(text[i] > 'Z')
                text[i] -= 26;
        }
        else if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] += key;
            if(text[i] > 'z')
                text[i] -= 26;
        }
    }
    return text;
}

//復号化
string decryption(string text, int key){
    for(int i=0; i<text.size(); i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] -= key;
              if(text[i] < 'A')
                 text[i] += 26;
        }
        else if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] -= key;
              if(text[i] < 'a')
                 text[i] += 26;
        }
    }
    return text;
}

int main(){
    string plaintext;   //平文
    string ciphertext;  //暗号文
    int k;  //コマンド
    int key;    //鍵
    while(true){
        cout << "" << endl;
        cout << "暗号作成の時は0を\n暗号解読の時は1を\n終了するときは2を入力:";
        cin >> k;

        if(k == 0){
            cout << "鍵を入力" << endl;
            cin >> key;
            cout << "文字列を入力" << endl;
            cin >> plaintext;
            ciphertext = encryption(plaintext, key);
            cout << "作成された暗号" << endl;
            cout << ciphertext << endl;
            continue;
        }
        else if(k == 1){
            cout << "鍵を入力" << endl;
            cin >> key;
            cout << "文字列を入力" << endl;
            cin >> ciphertext;
            plaintext = decryption(ciphertext, key);
            cout << "暗号の解読結果（平文）" << endl;
            cout << plaintext << endl;
            continue;
        }
        else if(k == 2) break;
        else continue;
    }
    return 0;
}