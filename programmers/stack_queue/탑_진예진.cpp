#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    
    for(int i = heights.size() - 1; i >= 0 ; i--){
        for(int j = 0; j < i; j++){
            if(heights[j] > heights[i])
            	answer[i] = j + 1;
        }
            
    }
    return answer;
}