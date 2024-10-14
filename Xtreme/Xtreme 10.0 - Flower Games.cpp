#include<iostream>
using namespace std;
int main(void) {
	int n;
	cin>>n;
	int samples[n];
	for(int i = 0 ; i < n ; ++i) {
		cin>>samples[i];
	}
	for(int i = 0 ; i < n ; ++i) {
		char temp[samples[i]] = {0};
		int num = 1;
		for(int j = 0 ; j < samples[i]-1 ; ++j) {
			temp[num%(samples[i])] = 1;
			while(temp[num%samples[i]] == 1) {++num;}
			++num;
			while(temp[num%samples[i]] == 1) {++num;}
		}
		for(int j = 0 ; j < samples[i] ; ++j) {
			if(temp[j] == 0) {
				printf("%d\n", j+1);
				break;
			}
		}
	}
	return 0;
}
