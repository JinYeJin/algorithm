/*
https://www.acmicpc.net/problem/10282
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;


int hacked[100001]; // 탐색 여부 및 값을 저장하는 배열.

int t;
int n, d, c;
int a, b, s;
int main() {
    FILE *stream = freopen("S2/7/input/10282_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    cin >> t;
    while(t--){
        vector<pair<int, int>> list[100001]; // 연결리스트
        queue<pair<int, int>> q; // bfs를 위한 큐
        memset(hacked, -1, sizeof(hacked)); // 초기화를 진행
        cin >> n >> d >> c; // 컴퓨터 의존성 감염된 컴퓨터
        
        for(int i=0; i < d; i++){
            cin >> a >> b >> s; // a가 b를 의존 s초 후에 감염
            list[b].push_back(make_pair(a, s));
            list[a].push_back(make_pair(b, s));

        }
        
        q.push(make_pair(c, 0)); // 시작점이므로 큐에 넣어준다.
        hacked[c] = 0;
        while(!q.empty()){
            int x = q.front().first; // 이동하려는 곳,
            q.pop();
            for(int i=0; i < list[x].size(); i++){
                int next = list[x][i].first;
                int value = list[x][i].second;
                if(hacked[next] == -1 || hacked[next] > value){
                    q.push(make_pair(next, value));
                    hacked[next] = value;
                }
            }
        }
        
        int cnt = 0;
        int sum = 0;
        for(int i=1; i < n+1; i++){
            if(hacked[i] != -1) {
                sum+=hacked[i];
                cnt++;
            }
        }
        cout << cnt << " " << sum << "\n";
    }
    
    
    return 0;
}