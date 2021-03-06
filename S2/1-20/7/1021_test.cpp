#include <iostream>
#include <deque>
#include <queue>

using namespace std;
deque<int> deq;
queue<int> q;

int main(){ 
    // FILE *stream = freopen("S2\\7\\input\\1021_input.txt", "r", stdin);
    FILE *stream = freopen("S2/7/input/1021_input.txt", "r", stdin);
    if(!stream) perror("freopen");
    
    deque<int>::iterator itr;
    
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i <= n; i++){
        deq.push_back(i);
    }
    
    for(int j=0; j < m; j++){
        int temp;
        cin >> temp;
        if(temp == deq.front()){
            deq.pop_front();
        } else {
            q.push(temp);
        }
    }
    int count = 0;
    while (!q.empty()) {
        int findNumber = q.front();
        int deqSize = deq.size();
        int index = 0;
        for(itr = deq.begin(); itr != deq.end(); itr++){
            if(*itr == findNumber){
                break;
            }
            index++;
        }
        if(index >= deqSize/2){
            int it = deqSize - index;
            for(int i=0; i < it; i++){
                deq.push_front(deq.back());
                deq.pop_back();
            }
            count += it;
        } else {
            for(int i=0; i < index; i++){
                deq.push_back(deq.front());
                deq.pop_front();
            }
            count += index;
        }
        deq.pop_front();
        q.pop();
    }
    
    cout << count << "\n";
    
    return 0;
}