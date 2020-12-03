/*
*/
#include <stdio.h>
#include <iostream> 
#include <queue>
#include <stack>


using namespace std;

int N;

typedef struct Coord{
    Coord(int y, int x, int d, int n): y(y), x(x), d(d), n(n) {}
    int x, y, d, n;
}Coord;

bool boundary(Coord c){
    return c.x >= 0 && c.x < N && c.y >= 0 && c.y < N;
}


int main(){
    FILE *stream =freopen("S2\\20\\input\\17780.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int chess[13][13]; // ü���� �迭
    vector<vector<queue<int>>> location(13, vector<queue<int>>(13, queue<int>())); // ü���� �迭
    queue<Coord> pieces;
    int K;
    int r, c, d;
    int moved= 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int change_d[] = {1, 0, 3, 2};

    cin >> N >> K;

    for(r = 0; r < N; r++){
        // pieces.push_back(vector<queue<int>>);
        for(c = 0; c < N; c++){
            cin >> chess[r][c];
        }
    }

    for(int n = 0; n < K; n++){
        cin >> r >> c >> d;
        location[r][c].push(n);
        pieces.push(Coord(r, c, d, n));
    }


    while(moved <= 1001){
        Coord cur = pieces.front();
        pieces.pop();

        queue<int> *cur_pieces = &location[cur.y][cur.x];
        // ���� ������ ü������ �� �ٴڿ� �ִ��� Ȯ���ϴ� �ڵ� ¥����
        if(cur.n != cur_pieces->front()){
            pieces.push(cur);
            continue;
        }

        Coord new_c = {cur.y + dy[cur.d], cur.x + dx[cur.d], cur.d, cur.n};
        queue<int> *new_pieces = &location[new_c.y][new_c.x];

        // ��� => ü���� �ű�
        if(chess[new_c.y][new_c.x] == 0){
            while(!cur_pieces->empty()){
                new_pieces->push(cur_pieces->front());
                cur_pieces->pop();
            }
        }

        //������
        else if(chess[new_c.y][new_c.x] == 1){
            stack<int> temp;
            while(!cur_pieces->empty()){
                // �ݴ�� �ֱ����ؼ� �ϴ� ���ÿ� �׾���
                temp.push(cur_pieces->front());
                cur_pieces->pop();
            }

            while(!temp.empty()){
                new_pieces->push(temp.top());
                temp.pop();
            }
        }

        //�Ķ��� || ü���� ���
        else if(chess[new_c.y][new_c.x] == 2 || !boundary(new_c)){
            new_c.d = change_d[cur.d]; // ���⺯��
            new_c.x += dx[new_c.d];
            new_c.y += dy[new_c.d];

            // �̵��Ϸ��� ������ �Ķ����� �ƴϰ� ��� ���� ��츸 �̵�
            if(chess[new_c.y][new_c.x] != 2 && boundary(new_c)){
                queue<int> *new_pieces = &location[new_c.y][new_c.x];
                while(!cur_pieces->empty()){
                    new_pieces->push(cur_pieces->front());
                    cur_pieces->pop();
                }
            }
        }

        pieces.push(new_c);
        moved++;

        // 4���� ���̸� ����
        if(new_pieces->size() >= 4) break;
    }

    if(moved == 1001) printf("-1");
    else printf("%d", moved);

    return 0;
}