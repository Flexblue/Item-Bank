#include<iostream>
#include<limits>
using namespace std;

class Solutions {
	private:
		int c1, c2;
		long long sum;
		long long min_sum, total_color;
		int *sequence;
	public:
		Solutions(): c1(0), c2(0), sum(0), 
			min_sum(numeric_limits<long long>::max()), sequence(NULL) {}
		void setup();
		void calculate(long long layer = 0);
		long long result() {return min_sum;}
};

int main(void) {
	int total_num;
	cin >> total_num;
	Solutions item[total_num];
	for(int i = 0 ; i < total_num ; ++i) {
		item[i].setup();
		item[i].calculate();
	}
	for(int i = 0 ; i < total_num ; ++i) {
		cout << item[i].result() << endl;
	}
	return 0;
}

void Solutions::setup() {
	cin >> total_color;
	sequence = new int [total_color];
	for(long long i = 0 ; i < total_color ; ++i) {cin >> sequence[i];} 
}

void Solutions::calculate(long long layer) {
	if(layer == total_color) {
		if(sum < min_sum) {min_sum = sum;}
		return ;
	}
	int temp_c1 = c1, temp_c2 = c2;
	if(c1 != sequence[layer])  {
		++sum; c1 = sequence[layer];
		calculate(layer+1);
		--sum; c1 = temp_c1;
	}
	else {
		calculate(layer+1);
	}
	
	if(c2 != sequence[layer]) {
		++sum; c2 = sequence[layer];
		calculate(layer+1);
		--sum; c2 = temp_c2;
	}
	else {
		calculate(layer+1);
	}
	
	return ;
}
