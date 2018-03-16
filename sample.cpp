#include <iostream>
#include <vector>
#include <string>
using namespace std;

string f(vector<int> a) {
	int i = 1, count = 0;
	int start = 0, end = 0;
	string s;
	while(i <= a.size()) {
		cout << a[start] << ' ' << a[end] << endl;
		if(a[i] - a[i - 1] == 1) {
			end = i;
		}
		else {
			if(end - start >= 2) {
				s += to_string(a[start]) + "-" + to_string(a[end]);
			}
			else {
				for(int i = start; i <= end; i++) {
					if(s.length() != 0 && s[s.length() - 1] != ',')
						s =  s + "," + to_string(a[i]);
					else 
						s += to_string(a[i]);
				}
			}
			start = i;end = i;
		}
		i++;
		if(s.length() && s[s.length() - 1] != ',') 
			s += ",";
	}
	if(s[s.length() - 1] == ',')
		return s.substr(0, s.length() - 1);
	else 
		return s;
}

int main() {
	vector<int> a = {1, 2, 3, 4,5,6, 8 ,9};
	cout << f(a) << endl;
}
