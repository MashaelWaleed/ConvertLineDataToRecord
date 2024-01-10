
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct client {

	string AccountNumber = "";
	string PinCode = "";
	string name = "";
	string phone = "";
	double Balance = 0;

};

string readString() {
	string str;
	cout << "Line record is :" << endl;
	cin >> str;

	return str;
}
client fillInfoToClient(vector<string> v) {
	client c;

		c.AccountNumber = v[0];
		c.PinCode = v[1];
		c.name = v[2];
		c.phone = v[3];
		c.Balance = stod(v[4]);//cast double to string
	

	return c;
}
int findpos(string s, string delim) {
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, delim.length()) == delim)
			return i;

	}
	return-1;
}
void printClient(client cl) {
	cout<<"Account Number: " <<cl.AccountNumber << endl;
	cout << "Pin Code: " << cl.PinCode << endl;
	cout << "name: " << cl.name<< endl;
	cout << "Phone: " << cl.phone << endl;
	cout << "AccountBalance: " << cl.Balance << endl;
	
}

vector<string> splitString(string str, string delim = "#//#") {
	int index;
	vector<string>v;
	string sWord = "";
	while ((index = findpos(str, delim)) != -1) {
		sWord = str.substr(0, index);
		if (sWord != "") {
			v.push_back(sWord);
		}
		str = str.erase(0, index+delim.length());
	}
      //     t#//#www#//#qqq#//#rrr#//#9876
	if (str != "")
		v.push_back(str);

	
	return v;
}


//vector<string> splitString(string str,string delim="#//#") {
//
//	vector<string>v;
//	string sr ;
//	int l = delim.length();
//
//	for (int i = 0; i <= str.length() - 1; i++) {
//		if (str.substr(i).length() >= l && str.substr(i, l) == delim) {
//			i = i + l-1;
//			v.push_back(sr);
//			sr = "";
//
//		}
//		else
//			sr += str[i];
//	}
//	if(sr!="")
//	v.push_back(sr);
//
//	return v;
//}





int main() {
	string s = readString();
	vector<string> v = splitString(s);
	client c=fillInfoToClient(v);
	printClient(c);

	return 0;
}