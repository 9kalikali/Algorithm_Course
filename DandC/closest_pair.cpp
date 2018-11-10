#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Point{
public:
    double x, y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
};

const bool xorder(const Point& p, const Point& q)
{
    return p.x < q.x;
}
const bool yorder(const Point& p, const Point& q)
{
    return p.y < q.y;
}

class Solution{
public:
    double ClosestPair(vector<Point>& pointsX)
    {
        //sort points according to x-coordinate
        sort(pointsX.begin(), pointsX.end(), xorder);
        return closestpair(pointsX, 0, pointsX.size() -1);
    }
private:
    static double distance(Point& p, Point& q){
        return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y)*(p.y - q.y));
    }

    double closestpair(vector<Point>& px, int l, int r)
    {
        //if size <=3 do this following code
        if(r - l == 1)
            return distance(px[l], px[r]);
        if(r - l == 2){
            double d1 = distance(px[l], px[(r+l)/2]);
            double d2 = distance(px[(r+l)/2], px[r]);
            double d3 = distance(px[l], px[r]);
            return min(d1, min(d2, d3));
        }
        //if not do divide and conquer
        int mid = (l+r)/2;
        Point midPoint = px[mid];
        double delta1 = closestpair(px, l, mid);
        double delta2 = closestpair(px, mid+1, r);
        double delta = min(delta1, delta2);

        vector<Point> strip;
        for(int i = l; i <= r; i++)
        {
            if(abs(px[i].x - midPoint.x) < delta)
                strip.push_back(px[i]);
        }
        sort(strip.begin(), strip.end(), yorder);
        for(int i = 0; i < strip.size(); i++)
        {
            for(int j = i+1; j < strip.size() && abs(strip[i].y - strip[j].y) < delta; j++)
            {
                    double temp = distance(strip[i], strip[j]);
                    delta = temp < delta ? temp : delta;
            }
        }
        return delta;
    }
};

int main(){
    int count;
    double x, y;
    vector<Point> pointsX;
    Solution solution;
    cin >> count;
    while(pointsX.size() < count)
    {
        cin >> x >> y;
        Point p(x, y);
        pointsX.push_back(p);
    }
    double result = solution.ClosestPair(pointsX);
    cout << showpoint << fixed << setprecision(2) << result << endl;
    return 0;
}