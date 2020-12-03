/*
[���� 1068] https://www.acmicpc.net/problem/11055
Ʋ�� ���̽� https://www.acmicpc.net/board/view/59793
https://www.acmicpc.net/board/view/51552
*/
#include <stdio.h>
#include <iostream> 
#include <map>
#include <queue>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\23\\input\\1068.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, temp, remove, answer = 0;
    multimap<int, int> tree;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        tree.insert(pair<int, int>(temp, i));
    }

    cin >> remove;

    queue<int> q;
    q.push(-1);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        auto found = tree.find(parent);

        // ������尡 ������� ��� ����ó�� ����� ��. ��ĳ��
        if(found == tree.end()) answer++; // Ű ã�Ҵµ� ������ ����
        else if(found->first == remove) continue; // ����� ���� �н�
        else{ // �������ϴ� ��尡 �ƴϸ�
            // ���� �θ��� �ڽ��� ��� ť�� ����
            for(found; found->first == parent; found++){
                if(found->second == remove) continue;
                q.push(found->second);
            }
        }
    }

    cout << answer;
    return 0;
}