
/*
[17478] https://www.acmicpc.net/problem/17478
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int N; 

void recur(int count){
    if(count >= N){
        for(int i = count; i > 0; i--) cout << "____";
        cout << "\"����Լ��� ������?\"\n";
        for(int i = count; i > 0; i--) cout << "____";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for(int i = count; i > 0; i--) cout << "____";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }

    for(int i = count; i > 0; i--) cout << "____";
    cout << "\"����Լ��� ������?\"\n";
    for(int i = count; i > 0; i--) cout << "____";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for(int i = count; i > 0; i--) cout << "____";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"; 
    for(int i = count; i > 0; i--) cout << "____";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    recur(count + 1);
    for(int i = count; i > 0; i--) cout << "____";
    cout << "��� �亯�Ͽ���.\n";
}

int main(){
    FILE *stream =freopen("S2\\12\\input\\17478.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> N; 
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

    recur(0);

    return 0;
}