#include "../std_lib_facilities.h"

template <typename T>
struct S{
public:
	explicit S(T v) : val{v} {}; 
	T& get(); 
	const T& get() const;
	S& operator = (const T& new_val);
private: 
	T val;
};

template <typename T>
S<T>& S<T>::operator= (const T& new_val)
{
    val=new_val;
    return *this;
}

template <typename T>
const T& S<T>:: get() const
    {
        return val;
    }

template <typename T>
T& S<T>:: get() 
    {
        return val;
    }    

template<class T> istream& operator>>(istream& is, S<T>& value)
{
    T v;
    cin >> v;
    if (!is) return is;
  	value = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

//bonus
template <typename T>
ostream& operator<< (ostream& os, vector<T>& v)
{
    os<<"{";

    for(auto elem : v)
        os<<elem<<(elem==v[v.size()-1] ? "" : ", ");  
    os<<"}";

    return os;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v)
{
    char ch;
    is>>ch;
    if(ch!='{')
        is.unget();
    int val;
    while(is>>val)
    {
        v.push_back(val);
        is>>ch;
        if(ch!=',')
            break;
    }
    return is;
}

int main()
{
	S<int> si(314);
	S<char> sc('6');
	S<double> sd(3.14);
	S<string> sst("sztring");
    S<vector<int>> sv {vector<int>{1, 2, 3, 4, 5}};

	cout << "si= " << si.get() << '\n' ;
	cout << "sc= " << sc.get() << '\n' ;
	cout << "sst= " << sst.get() << '\n' ;
	cout << "sd= " << sd.get() << '\n' ;

	cout << "Írj be egy stringet: ";
	string ss;
	read_val(ss);
	cout << "A beolvasott string: "<< ss << endl << endl;

	cout << "Írj be egy intet: ";
	int ii;
	read_val(ii);
	cout << "A beolvasott int: " << ii << endl << endl;

	cout << "Írj be egy doublet: ";
	double dd;
	read_val(dd);
	cout << "A beolvasott double: " << dd << endl << endl;

	cout << "Írj be egy chart: ";
	char cc;
	read_val(cc);
	cout << "A beolvasott char: "<< cc << endl << endl;

	cout << "Írj be egy pár int értéket így: {val,val,val}" << endl << endl;
	vector<int> numbers;
	read_val(numbers);
	cout << "A beolvasott vector: " << numbers << endl << endl;


 
}