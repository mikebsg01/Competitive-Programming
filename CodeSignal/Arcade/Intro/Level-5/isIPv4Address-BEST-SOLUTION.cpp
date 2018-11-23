#include <bits/stdc++.h>
using namespace std;

bool isIPv4Address(std::string s) {
    regex r("[0-9]{1,3}(.[0-9]{1,3}){3}");
    if(!regex_match(s,r))return false;
    int a,b,c,d;
    sscanf(s.c_str(),"%d.%d.%d.%d", &a,&b,&c,&d);
    return a<256 && b<256 && c<256 && d<256;
}

int main() {
	cout	<< isIPv4Address("172.16.254.1") << endl
		<< isIPv4Address("172.316.254.1") << endl
		<< isIPv4Address(".254.255.0") << endl
		<< isIPv4Address("1.256.1.1") << endl;
	return 0;
}
