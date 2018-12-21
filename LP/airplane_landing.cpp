#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

#define eps (1e-10)
const int maxn =  1001;
double ans = 0;
int num[maxn],pos[maxn];
struct node{
    double a,b;
} nodes[maxn];

bool check(double len, int n)
{
    double x = nodes[pos[1]].a;
    for(int i = 2;i <= n;++i)
    {
        x += len;
        if(x > nodes[pos[i]].b)
            return 0;
        if(x < nodes[pos[i]].a)
            x = nodes[pos[i]].a;
    }
    return true;
}

string my_precision(double& num)
{
    regex reg("([1-9][0-9]*)\\.([0-9]{2}))|[0]\\.([0-9]{2}");
    string str_num = to_string(num);
    smatch r1;
    regex_match(str_num, r1, reg);
    return r1.str();
}

int main()
{
    int N, M;
    int count = 1;
    double s, t;
    ios::sync_with_stdio(false);
    do{
        cin >> s >> t;
        num[count] = count;
        nodes[count].a = s, nodes[count].b = t;
        count++;
    }while(cin.get() != '\n');
    count--;
    ans = 0;
    do{
        for(int i = 1;i <= count; ++i)
        {
            pos[num[i]] = i;
        }
        double l = 0,r = 24, mid;
        while(r - l > eps)
        {
            mid = (l + r) / 2.0;
            if(check(mid, count))
                l = mid;
            else{
                r = mid;
            }
                
        }
        ans = max(ans,r);
    }while(next_permutation(num + 1, num + 1 + count));
    //output

    double result = nodes[1].a;
    for(int i = 1; i <= count; i++)
    {
        if(i == 1)
        {
            cout << my_precision(result) << " ";
            continue;
        }
        if( result + ans <= nodes[i].a )
        {
            cout << fixed << setprecision(2) << my_precision(nodes[i].a) << " ";
            result = nodes[i].a;
            continue;
        }
        result += ans;
        if(i == count)
        {
            cout << fixed << setprecision(2) << my_precision(result);
            continue;
        }
        cout << fixed << setprecision(2) << my_precision(result) << " ";
    }

    return 0;
}