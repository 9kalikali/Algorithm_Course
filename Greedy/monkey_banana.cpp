#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    int pos;
    int cur_time, max_time = 0;
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int> > monkeys, bananas;
    
    do{
        cin >> pos;
        monkeys.push(pos);   
    }while((cin.get() != '\n'));

    do{
        cin >> pos;
        bananas.push(pos);   
    }while((cin.get() != '\n'));

    while(!monkeys.empty() && !bananas.empty())
    {
        cur_time = abs(monkeys.top()-bananas.top());
        max_time = max_time < cur_time ? cur_time : max_time;
        monkeys.pop();
        bananas.pop();
    }
    cout << max_time << endl;
    return 0;
}