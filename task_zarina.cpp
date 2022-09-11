
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
string toString(T numb){
     std::ostringstream ss;
     ss << numb;
     return ss.str();
}

int incl(const string& path, double numb, int *i, int *j){
        string t, x = toString(numb);
	char ch;
	ifstream file;
	file.open(path, ios::in);

     if(file.is_open()) {
	if (file.peek() == std::ifstream::traits_type::eof())
		return -3; //file is empty
   	while(true){
		file.get(ch);
		if (file.eof()) break;
		t.append(1, ch);
	}
	if(t.find(x) >= 0 && t.find(x) != t.npos){
        	*i = t.find(x)+1;
		*j = t.find(x)+x.size();
		return 1; //included
	}
	return 0; //excluded
        file.close();
    } else
	return -1; //cannot open file
}
int main(){
    string path;
    double x;
    int i = 0, j = 0;
    cin >> x >> path;
    //path = "/Users/zarinayeleukina/Desktop/input.txt";
    cout << incl(path, x, &i, &j) <<", "<<i <<", " << j;
    return 0;
}
