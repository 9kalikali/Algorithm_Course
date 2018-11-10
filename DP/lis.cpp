#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int longestIncSubseq(vector<int>& seq){
        return findLongest(seq);
    }
private:
    int findLongest(vector<int>& seq)
    {
        vector<int> subseq;

        for(auto &n : seq)
        {
            auto it = lower_bound(subseq.begin(), subseq.end(), n);
            if(it == subseq.end())
                subseq.push_back(n);
            else
                *it = n;
        }
        return subseq.size();
    }

};

int main()
{
    int T, N, num, result;
    vector<int> seq;
    Solution solution;
    //disable cin buffer
    ios::sync_with_stdio(false);
    cin >> T;
    while(T > 0)
    {
        cin >> N;
        while(N > 0)
        {
            cin >> num;
            seq.push_back(num);
            N--;
        }
        //do your algorithm
        result = solution.longestIncSubseq(seq);
        //algorithm done
        cout << result << endl;
        //clear seq
        vector <int>().swap(seq);
        T--;
    }
    return 0;
}