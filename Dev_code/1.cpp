#include <bits/stdc++.h>
using namespace std;

bool judge(int k){
	for(int i=2;i<=sqrt(k);i++){
		if(k%i==0)
		return false;
	}
	return true;
}
int main() {
	    
	int cnt=0; 
	for(int i=2;;i++){
		if(judge(i))
		cnt++;
		if(cnt==2025){
			cout<<i<<endl;
			break;
		}
	}
	return 0;    
}
