#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M  = matrix.begin()->size();
        if(N!=M){
            //矩阵不是N×N的
            return;
        }
        for(int layer = 0;layer<N/2;++layer)
        {
            for(int idx=layer;idx<N-1-layer;++idx)
            {
                //交换四个角
                int offset = idx - layer;
                int temp;
                temp = matrix[layer][layer+offset];
                matrix[layer][layer+offset] = matrix[N-1-layer-offset][layer];
                matrix[N-1-layer-offset][layer] = matrix[N-1-layer][N-1-layer-offset];
                matrix[N-1-layer][N-1-layer-offset]=matrix[layer+offset][N-1-layer];
                matrix[layer+offset][N-1-layer] = temp;
            }
        }
    }
};
