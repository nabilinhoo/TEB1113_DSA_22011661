// NAME : NABIL NAQIB BIN SAHRUL RIZAL
// ID : 22011661
// GROUP : G1

#include <bits/stdc++.h>
using namespace std;

vector<int> diagonalOrder(const vector<vector<int>>& mat) {
    vector<int> res;
    
    int n = mat.size();
    int m = mat[0].size();
    
    for(int line = 1; line <= (n + m - 1); line++) {
        
        int startCol = max(0, line - n);
      
        int count = min({line, (m - startCol), n});
        
        for(int j = 0; j < count; j++) {
            
            int row = min(n, line) - j - 1;
            int col = startCol + j;
            res.push_back(mat[row][col]);
        }
    }
    
    return res;
}

int main() {

    vector<vector<int>> mat = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 },
        { 17, 18, 19, 20 }
    };
    vector<int> res = diagonalOrder(mat);
    for (auto val: res) cout << val << " ";
    cout << endl;
    
    return 0;
}
