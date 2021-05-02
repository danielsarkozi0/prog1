#include "../std_lib_facilities.h"
#include <map>
using namespace std;

void read(map<string, int>& m)
{
    pair<string, int> p;
    while (cin >> p.first >> p.second)
    {
        m.insert(m.begin(), p);
    }
}

void write(map<string, int>& m)
{
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}

int sum(map<string, int>& m)
{
    int sum = 0;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        sum = sum + (*it).second;
    }
    return sum;
}

void write2(map<int,string>& m)
{
    for (map<int,string>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}

int main()
{
    map<string,int> msi;
    vector<string> vec{ "q","w","e","r","t","z","u","i","o","p" };
    for (int i = 1; i != 11; i++)
    {
        msi.insert(msi.begin(), pair<string, int>(vec[i-1],i));
    }
    write(msi);
    msi.erase(msi.begin(), msi.end());

    read(msi);
    write(msi);
    cout << "sum= " << sum(msi) << endl;

    map<int,string> mis;

    for (map<string, int>::iterator it = msi.begin(); it != msi.end(); it++)
    {
        mis.insert(mis.begin(), pair<int,string>((*it).second, (*it).first));
    }
    write2(mis);
}