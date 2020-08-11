#include <bits/stdc++.h>
using namespace std;

bool st_en_mat[100][100];

int main(){

    string s;
    cin >> s;

    vector < pair <int, int> > st_end;

    for(int st = 0; st < s.size(); st++){
        deque <char> subString;
        deque <char> tempSubString;

        for(int en = st; en < s.size(); en++){
            subString.push_back(s[en]);
            tempSubString.push_back(s[en]);
            reverse(tempSubString.begin(), tempSubString.end());

            if(subString == tempSubString){
                if(st_end.size() == st+1){
                    st_end.pop_back();
                }
                pair <int, int> temp_st_en;
                temp_st_en.first = st;
                temp_st_en.second = en;
                st_end.push_back(temp_st_en);

            }

            reverse(tempSubString.begin(), tempSubString.end());

        }

    }

    for(int i = 0; i < st_end.size(); i++){
        st_en_mat[st_end[i].first][st_end[i].second] = 1;
    }

    int beg = 0;
    int cnt = 0;

    for(int i = beg; i < s.size(); i = beg){
        for(int j = s.size()-1; j >= 0; j--){
            if(st_en_mat[i][j]){
                beg = j+1;
                cnt++;
                break;
            }
        }
    }

    cout << cnt-1;

}
