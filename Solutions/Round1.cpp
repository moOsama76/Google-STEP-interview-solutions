#include <bits/stdc++.h>
using namespace std;

char mat[101][101];
int n, m;

int toInt(string s){
    int siz = s.size();
    int j = 0;
    bool isMince = 0;

    if(s[0] == '-'){
        j++;
        isMince = 1;
    }

    int store = 0;
    for(int i = j; i < s.size(); i++){
        store += (s[i] - '0') * pow(10, siz - i - 1);
    }

    if(isMince)
        return -store;
    else
        return store;
}

int main(){

    string s, num1, num2;
    string *sToAdd = &num1;
    char first, second;
    char *cToPick = &first;

    getline(cin, s);

    bool toComplete = 1;

    for(int i = 0; i < s.size(); i++){

        if(s[i] == 'o'){
            cout << "true";
            toComplete = 0;
            break;
        }

        if(s[i] >= '0' && s[i] <= '9' || s[i] == '-'){

            *(sToAdd) += s[i];

            if(s[i+1] == ' ')
                sToAdd = &num2;
        } else if(s[i] == '>' || s[i] == '<'){
            *(cToPick) = s[i];
            cToPick = &second;
        }

    }

    if(toComplete){

        if(first == '<' && second == '>' && toInt(num1) <= toInt(num2)){
            cout << "false";
        } else if (first == '>' && second == '<' && toInt(num1) >= toInt(num2)){
            cout << "false";
        } else {
            cout << "true";
        }
    }
}
