#include<iostream>
using namespace std;

class Items {
	private:
		long N;
		long A;
		long B;
		long long sum;
	public:
		Items(): N(0), A(0), B(0), sum(0) {}
		void setup() {cin>>N>>A>>B;}
		long long* show_val() {long long a[4] = {N, A, B, sum}; return a;}
		void calculate_sum();
};

long max_yue(long, long);

int main(void) {
	long total_num;
	cin>>total_num;
	Items item[total_num];
	for(long i = 0 ; i < total_num ; ++i) {
		item[i].setup();
		item[i].calculate_sum();
	}
	for(long i = 0 ; i < total_num ; ++i) {
		printf("%lld\n", (item[i].show_val())[3]);
	}
	return 0;
}

void Items::calculate_sum() {
	for(long i = A ; i <= B ; ++i) {
		if(max_yue(i, N) == 1) {sum += i;}
	}
}

long max_yue(long m, long n) {
	long temp;
	if(n > m) {
		temp = m; m = n; n = temp;
	}
	while(1) {
		temp = m%n;
		if(temp == 0) {return n;}
		else {
			m = n; n = temp;
		}
	}
}
