/*
[���� 15686 ġŲ ���] https://www.acmicpc.net/problem/15686
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 987654321

using namespace std;


typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

int N, M;
int chicken_distance, local_distance;
int house_size, chicken_size;
int graph[MAX][MAX];
bool visited[13];
vector<Coord> house, chicken;


int get_distance(Coord a, Coord b){
        return abs(a.x - b.x) + abs(a.y - b.y);
}

void dfs(int idx, int selected){
    // M ���� ġŲ���� �� ������ ���
    if (selected == M){
        local_distance = 0;

        // ���� ���� ġŲ������ �Ÿ��� ����ؼ� �ּ� ġŲ�Ÿ� ���ϱ�
        for (int i = 0; i < house_size; i++){
            int dist = INF;
            for (int j = 0; j < chicken_size; j++){
                // �湮�� ���� �ִ� ġŲ����
                if (visited[j]){
                    dist = min(dist, get_distance(house[i], chicken[j]));
                }
            }
            local_distance += dist;
        }
        chicken_distance = min(chicken_distance, local_distance);
        return;
    }

    // �ε����� ġŲ�� ������ �Ѿ�� return
    if (idx == chicken_size) return;

    // ����ϴ� ���
    visited[idx] = true;
    dfs(idx + 1, selected + 1);
    
    // ��� ���ϴ� ���
    visited[idx] = false;
    dfs(idx + 1, selected);
}


int main(void){
    FILE *stream =freopen("S2\\16\\input\\15686.txt", "r", stdin);
    if(!stream) perror("freopen");

    scanf("%d %d", &N, &M);


    for(int i=0; i<N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &graph[i][j]);
            // 1�� �� 2�� ġŲ��
            if (graph[i][j] == 1) house.push_back(Coord(i, j));
            else if (graph[i][j] == 2) chicken.push_back(Coord(i, j));
        }
    }

    // �ʱ�ȭ
    chicken_distance = INF;
    chicken_size = chicken.size();
    house_size = house.size();


    dfs(0, 0);
    printf("%d\n", chicken_distance);

    return 0;
}