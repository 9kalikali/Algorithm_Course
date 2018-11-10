#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Top k path
 * Using DP
 * */

class Solution{
public:
    void topKPath(vector<vector<int> >& grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        //init a 3d array with size m*n*k 
        //format like below
        // (0,0,...);(0,0,...);...
        // (0,0,...);(0,0,...);...
        // (0,0,...);(0,0,...);...
        vector<vector<vector<int> > > dp(rows, vector<vector<int> >(cols, vector<int>(k, 0)));
        //init the first k-array with grid[0][0]
        dp[0][0][0] = grid[0][0];
        //go!go!go!
        vector<int> result = kthScore(grid, dp, rows, cols, k);
        //long long paths = uniquePaths(rows, cols);
        //print result
        for(int i = 0; i < k; i++)
        {
            if(i == k -1)
                cout << result[i];
            else
                cout << result[i] << " ";
        }
        return;
    }
private:
    vector<int> kthScore(vector<vector<int> >& grid, vector<vector<vector<int> > >& dp, int rows, int cols, int k)
    {
        //pre-process dp rows
        for (int i = 1; i < rows; i++)
        {
                dp[i][0][0] = grid[i][0] + dp[i-1][0][0];
        }
        //pre-process dp cols
        for (int i = 1; i < cols; i++)
        {
                dp[0][i][0] = grid[0][i] + dp[0][i-1][0];
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {   
                vector<int> temp;
                for(int ks = 0; ks < k; ks++){
                    temp.push_back(dp[i-1][j][ks] + grid[i][j]);
                    temp.push_back(dp[i][j-1][ks] + grid[i][j]);
                }
                sort(temp.begin(), temp.end(), greater<int>());
                for(int ks = 0; ks < k; ks++)
                {
                        if(temp[ks] == grid[i][j]) break; 
                        dp[i][j][ks] = temp[ks];
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }

    long long uniquePaths(int m, int n)
    {
        int N = n + m - 2;
        int K = n - 1;
        double res = 1.0;
        for (int i = 1; i <= n - 1; ++i)
        {
            res = res * (N - K + i) / i;
        }
        return (long long)res;
    }
};

int main()
{
    int m, n, k;
    int temp;
    Solution solution;
    //disable cin buffer
    ios::sync_with_stdio(false);
    cin >> m >> n;
    cin >> k;
    
    //init m * n grid
    vector<vector<int> > grid(m, vector<int>(0));
    for(auto &row : grid)
    {
        int col = 0;
        while(col < n)
        {
            cin >> temp;
            row.push_back(temp);
            col++;
        }
    }

    //algo
    solution.topKPath(grid, k);
    //done
    return 0;
}