#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\16\\input\\2504.txt", "r", stdin);
    if(!stream) perror("freopen");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    int multiply = 1;
    bool break_flag = false;

    string input;
    stack<char> bracket;
    map<char, char> pair = {{'(', ')'}, {'[', ']'}};

    cin >> input;

    int i = 1;
    bracket.push(input[0]);

    for(int i = 0; i < input.size(); i++){
        break_flag = true;
        while(!bracket.empty()){
            char cur = bracket.top();
            
            // ������ top�̶� ���� input ���ؼ� ������
            if(pair[cur] == input[i]){
                bracket.pop();
                // ���� �� pop�� ������ ������ )�� 2
                if(input[i] == ')'){
                    
                }
                else if(input[i] == ']'){

                }
            }
            // �ٸ��� ���ÿ� �ְ� ����
            else if(input[i] == '(' || input[i] == '['){
                bracket.push(input[i]);
            }
            else{
                break_flag = true;
                break;
            }
        }
        if(break_flag) break;
        answer += multiply;
        bracket.push(input[i]);
    }
    if(!bracket.empty()) cout << answer;
    return 0;
}