#include "../std_lib_facilities.h"
using namespace std;

template <typename T>
double sum(vector<T> v)
{
    double sum = 0;
    for (int i=0;i<v.size();i++)
    {
        sum = sum + v[i];
    }
    return sum;
}

int main()
{
    vector<double> vd;
    double d;
    ifstream ifs ("drill21_3.txt");
    while (ifs >> d)
    {
        vd.push_back(d);
    }
    vector<int> vi;
    for (vector<double>::iterator it = vd.begin(); it != vd.end(); it++)
    {
        vi.push_back(*it);
    }
    for (int i = 0; i < vd.size(); i++)
    {
        cout << vd[i] << " " << vi[i] << endl;
    }
    cout << "sum= " << sum(vd) << endl;
    cout << "difference= " << sum(vd) - sum(vi) << endl;
    reverse(vd.begin(), vd.end());
    for (int i = 0; i < vd.size(); i++)
    {
        cout << vd[i] << endl;
    }
    double mean = sum(vd) / vd.size();
    cout << "mean value= " << mean << endl;

    vector<double> vd2;

    for (vector<double>::iterator it = vd.begin(); it != vd.end(); it++)
    {
        if((*it)< mean)
        vd2.push_back(*it);
    }
    for (int i = 0; i < vd2.size(); i++)
    {
        cout << vd2[i] << endl;
    }
    sort(vd);
    for (int i = 0; i < vd.size(); i++)
    {
        cout << vd[i] << endl;
    }
    
}