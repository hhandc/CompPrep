#include <iostream>
#include <vector>

using namespace std;

int t, n, cyc = 1;

vector<int> student;
vector<int> check;
vector<int> cc;
vector<int> ans;

void can(int start, int next){
    check[next] = cyc;

    if(student[next] == start){
        cc[cyc] = 1;
        cyc++;
        return;
    }

    if(check[student[next]] == 0 || cc[check[student[next]]] == 0){
        can(start, student[next]);
    }

    return;
}

int main(){
    cin >> t;

    for(int i = 0;i<t;i++)
    {
        int cnt = 0;
        cin >> n;
        cyc = 1;
        student.clear();
        check.clear();
        cc.clear();
        student.resize(n + 1, 0);
        check.resize(n + 1, 0);
        cc.resize(n + 1, 0);

        for(int j = 1;j<=n;j++){
            cin >> student[j];
        }

        for(int j = 1;j<=n;j++){
            if(check[j] == 0 || cc[check[j]] == 0){
                can(j, j);
                cyc++;
            }
        }

        for(int j = 1;j<=n;j++)
        {
            if(check[j] == 0 || cc[check[j]] == 0){
                cnt++;
            }
        }

        ans.push_back(cnt);
    }

    for(int i = 0;i<t;i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}