#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 *  Find the Kth largest number in an unsorted array
 *  Use the Floyd-Rivest method
 *  Change cin to scanf, it takes too much time...
 */

class Solution{

public:
    int selectKthLargest(vector<int>& array, int k){
        return find(array, 0, array.size() - 1, k - 1);
    }
private:
    int find(vector<int>& array, int l, int r, int k)
    {
        int i;
        while(l < r)
        {
            //magic number 600
            if(r - l > 600)
            {
                //remove the 0.5, ln and sqrt which original method had
                //but still get the right answer
                int n = r - l + 1;
                i = k - l + 1;
                int s = 2 * n / 3;
                int sd = (n * s * (n - s) / n) * sign(i - n / 2);
                int newL = max(l, k - i * s / n + sd);
                int newR = min(r, k + (n - i) * s / n + sd);
                find(array, newL, newR, k);
            }
            //partition
            int t = array[k];
            i = l;
            int j = r;
            swap(array[l], array[k]);

            if(array[r] < t)
                swap(array[r], array[l]);

            while (i < j)
            {
                swap(array[i],array[j]);
                i++;
                j--;

                while (array[i] > t)
                    i++;
                while (array[j] < t)
                    j--;
            }

            if (array[l] == t)
                swap (array[l], array[j]);      
            else
            {
                j++;
                swap (array[j],array[r]);
            }
            //adjust the l and r boundaries
            if (j <= k)
                l = j + 1;
            if (k <= j) 
                r = j - 1;
        }

        return array[k];
    }

    //to judge a number's sign
    int sign(const int& n)
    {
        return (n > 0 ? 1 : (n < 0 ? -1 : 0));
    }

};

int main(){
    Solution solution;
    int k, c, num;
    vector<int> input;
    cin >> c >> k;
    while(input.size() < c){
        //cin >> num;
        scanf("%d", &num);
        input.push_back(num);
    }
    int result = solution.selectKthLargest(input, k);
    cout << result << endl;
    // double sum=0.0f,n=1.0f;
    // for(int i =1; i <= 2097152; i++)
    // {
    //     sum+=1.0f/n;
    //     n++;
    //     cout << i << ":";
    //     printf("%f\n",sum);
    // }
    return 0;
}
