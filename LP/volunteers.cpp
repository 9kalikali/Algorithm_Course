#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Simplex{
public:
    Simplex(vector<vector<double> >& matrix, vector<double>& c, vector<double>& b)
    {
        this->A = matrix;
        this->C = c;
        this->B = b;
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->ans = 0.0;
    }
    double do_simplex()
    {
        while(true)
        {
            for(p = 0; p < n; p++)
            {
                if(C[p] > 0) break;
            }
            if(p == n) return ans;
            double fz = 0x3f3f3f3f;
            for(int i = 0; i < m; i++)
            {
                if(A[i][p] > 0 && B[i]/A[i][p] < fz)
                {
                    fz = B[i]/A[i][p];
                    id = i;
                }
            }
            if(fz == 0x3f3f3f3f) return fz;
            pivot(id, p);
        }
    }
private:
    vector<vector<double> > A;
    vector<double> C, B;
    int n, m, p, id;
    double ans;
    void pivot(int id, int p)
    {
        A[id][p] = 1 / A[id][p];
        B[id] *= A[id][p];
        for(int i = 0; i < n; i++) 
        {
            //i != p
            if(i^p) A[id][i] *= A[id][p];
        }
        for(int i = 0; i < m; i++)
        {
            // i != id
            if((i^id) && A[i][p])
            {
                for(int j = 0; j < n; j++) if(j^p) A[i][j]-=A[i][p]*A[id][j];
                B[i]-=A[i][p]*B[id];
                A[i][p]*=-A[id][p];
            }
        }
        for(int i = 0; i<n; i++) if(i^p) C[i]-=C[p]*A[id][i];
        ans += C[p]*B[id];
        C[p] *= -A[id][p];
    }
};

int main()
{
    //N is n days; M is m kinds of volunteers
    int N, M;
    ios::sync_with_stdio(false);
    cin >> N >> M;
    //initial a N*M scale Matrix which value of elements have 0,1 
    vector<vector<double> > A(M, vector<double>(N, 0));
    //Ci
    vector<double> c(N, 0);
    //b
    vector<double> b;
    int s, f, cost;
    int i = 0;
    //该问题所得出的线性规划方程不是标准型，这里做一个转换（对调C和b）将其变为标准型
    while(cin >> s)
    {
        //b.push_back(s);
        c[i] = s;
        if(++i == N) break;
    }
    i = 0;
    //set A[s->f][i] = 1
    while(i < M)
    {
        cin >> s >> f >> cost;
        //c[i] = cost;
        b.push_back(cost);
        for(int j = s-1; j < f; j++)
        {
            A[i][j] = 1;
        }
        i++;
    }

    Simplex simplex(A, c, b);
    cout << simplex.do_simplex() << endl;
    return 0;
}

