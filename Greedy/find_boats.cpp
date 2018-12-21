#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution{
public:
    int Find_Boats(int& limit, vector<int>& p)
    {   
        int boats = 0;
        auto lt = p.begin();
        auto rt = p.end()-1;
        while(lt != rt)
        {
            if((*lt) == limit)
            {
                boats++;
                lt++;
            }else{
                if((*lt) + (*rt) <= limit)
                {
                    if((lt+1)==rt)
                    {
                        boats++;
                        break;
                    }
                    lt++;
                    rt--;
                    boats++;
                }else{
                    lt++;
                    boats++;
                }
            }
        }
        if(lt == rt) boats++;
        return boats;
    }
private:
};

int main()
{
    int n, limit, temp;
    vector<int> people_greater;
    //deque<int> people;
    Solution solution;
    //disable buffer
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> limit;
    while(n > 0)
    {
        cin >> temp;
        people_greater.push_back(temp);
        n--;
    }
    sort(people_greater.begin(), people_greater.end(), greater<int>());
    //people.assign(people_greater.begin(), people_greater.end());

    int result = solution.Find_Boats(limit, people_greater);
    cout << result << endl;
    return 0;
}