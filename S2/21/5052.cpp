/*
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    FILE *stream =freopen("S2\\21\\input\\5052.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    bool exit_flag;
    vector<string> numbers;

    cin >> T;
    cin >> N;

    for(int t = 0; t < T; t++){
        numbers.clear();
        // ��ȣ �Է�
        for(int n = 0; n < N; n++){
            string temp;
            cin >> temp;
            numbers.push_back(temp);
        }

        exit_flag = false;

        for(int n = 0; n < N-1; n++){
            for(int i = 0; i < 10; i++){
                string *str1 = &numbers[n];
                string *str2 = &numbers[n+1];
                // str1�� str2�� prefix�� ���
                // str2�� str1�� prefix�� ��� => �ϰ����� ����.
                if(i >= str1->size() || i >= str2->size()){
                    cout << "NO\n";
                    exit_flag = true;
                }

                // �ٸ� ��쿣 ���� �ܾ�� �Ѿ
                if(str1[i] != str2[i]) break;
            }

            if(exit_flag) break;
        }

        if(!exit_flag) cout << "YES\n";
    }
    return 0;
}