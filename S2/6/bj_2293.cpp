/*
2020-07-08 ������
[���� 2293 ���� 1] https://www.acmicpc.net/problem/2293
���� https://sihyungyou.github.io/baekjoon-2293/
*/

#include <stdio.h>

using namespace std;

int main(){
    FILE *stream = freopen("S2/6/input/2293_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N, K;
    int coins[101];
    int dp[10001] = {0,};

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        scanf("%d", &coins[i]);
    }

    dp[0] = 1;

    // i: ���� ���õ� ������ �ε���
    for(int i = 0; i < N; i++){
        // j: ���� ����ϴ� ��ġ�� ��
        for(int j = 1; j <= K; j++){
            // �������� ���ð������� ���� dp[i] ���� ���� ������ ������ ��ġ��ŭ �� �ε����� dp ���� �����ش�.
            if(j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
        }
    }

    printf("%d", dp[K]);

    return 0;
}