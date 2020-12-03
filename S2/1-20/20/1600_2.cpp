/*
������ �迭�� üũ �ȵǴ� ����... https://www.acmicpc.net/board/view/46431
�����迭 �湮üũ...? https://j3sung.tistory.com/466
���� 1600 https://www.acmicpc.net/problem/1600
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef struct Coord{
    Coord(int x, int y, int k, int moved): x(x), y(y), k(k), moved(moved) {}
    int x, y, k, moved;
}Coord;

int K, W, H;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
// �����ʺ��� �ð��������
int h_dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int h_dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool boundary(Coord cur){
    return cur.x >= 0 && cur.x < W && cur.y >= 0 && cur.y < H;
}

int main(){
    FILE *stream =freopen("S2\\1-20\\20\\input\\1600.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int map[202][202];
    int dp[202][202]; // x, y ������ �� �� �̵��Ͽ� �����ߴ��� ����
    queue<Coord> path;

    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));

    cin >> K;
    cin >> W >> H;

    for(int r = 0; r < H; r++){
        for(int c = 0; c < W; c++){
            cin >> map[r][c];
            dp[r][c] = 100;
        }
    }


    path.push(Coord(0, 0, K, 0));

    while(!path.empty()){
        Coord cur = path.front();
        path.pop();

        if(cur.x == H-1 && cur.y == W-1){
            cout << cur.moved;
            return 0;
        }

        if(cur.k > 0){
            for(int i = 0; i < 8; i++){
                Coord new_c = { cur.x + h_dx[i], cur.y + h_dy[i],
                                cur.k - 1, cur.moved + 1 };
                if(boundary(new_c)){
                    if(map[new_c.y][new_c.x] == 0 && new_c.k < dp[new_c.y][new_c.x] && new_c.k < K){
                           dp[new_c.y][new_c.x] = new_c.k;
                           path.push(new_c);
                       }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            Coord new_c = { cur.x + dx[i], cur.y + dy[i],
                            cur.k, cur.moved + 1 };
            if(boundary(new_c)){
                if(map[new_c.y][new_c.x] == 0 && new_c.k < dp[new_c.y][new_c.x]){
                    dp[new_c.y][new_c.x] = new_c.k;
                    path.push(new_c);
                }
            }

        }
    }

    cout << -1;

    return 0;
}