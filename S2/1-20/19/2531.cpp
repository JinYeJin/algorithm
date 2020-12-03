/*
*/
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\19\\input\\2531.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, D, K, C;
    vector<int> sushi;
    int temp, num_sushi, max_kinds = 0;
    bool exist_C = false;
    map<int, int> check;
    vector<int>::iterator s_p, e_p;

    // N �ʹ��� ����, D �ʹ��� ���� ��, K �������� �Դ� �ʹ� ��, C ����
    cin >> N >> D >> K >> C;

    for(int i = 0; i < N; i++){
        cin >> temp;
        sushi.push_back(temp);
    }

    // ���� ������ �ʱ�ȭ
    s_p = sushi.begin();
    check.insert({sushi[1], 1});

    // ó�� K�� �ʱ�ȭ
    for(int i = 1; i < K; i++){
        // check �ȿ� ������,
        if(check.find(sushi[i]) != check.end())
            check[i]++;
        else check.insert({sushi[i], 1});
    }

    // ������ ������ �ʱ�ȭ
    e_p = sushi.end();

    // K �� ����
    for(int i = K; i < N; i++){
        max_kinds = max_kinds < check.size() ? max_kinds : check.size();

        // ���ӵ� �ʹ� �ȿ� C�� ����
        if(check.find(C) == check.end()){
            // �� ���̳� ���� C�� ������, ������ ���� �ϳ� �þ��.
            ++e_p;
            if(s_p != sushi.begin()){
                --s_p;
                if(*s_p == C) max_kinds++;
                ++s_p; // ������ ���ΰ� ����
            }
            else if(*e_p == C) max_kinds++;
            ++s_p; // ���� ���
        }// C�� �ϳ��� ������ C�� �ִٰ� ǥ��
        else exist_C = true;

        // check �ȿ� �̹� �ִ� ���Ҷ��, value ����
        if(check.find(*e_p) != check.end()){
            check[*e_p]++;
        }
        else{ // ���� ���̶�� ���� �߰��� ��
            check.insert({*e_p, 1});
        }
    }
    cout << max_kinds;
    return 0;
}