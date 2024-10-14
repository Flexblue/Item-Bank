#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class ITEMS {
	private:
		int cur_sum, *solution, layer;
		int dogs, employers, *size, sum, **map;
		void answer();
	public:
		ITEMS(): dogs(0), employers(0), size(NULL), sum(INT_MAX), map(NULL), solution(NULL),
			cur_sum(0), layer(1) {}
		~ITEMS();
		void setup();
		int result() {return sum;}
		void calculate();
};

int main(void) {
	int total;
	cin >> total;
	ITEMS item[total];
	for(int i = 0 ; i < total ; ++i) {
		item[i].setup();
		item[i].calculate();
	}
	for(int i = 0 ; i < total ; ++i) {cout << item[i].result() << endl;}
	return 0;
}

void ITEMS::setup() {
	cin >> dogs >> employers;
	size = new int[dogs+1];
	for(int i = 0 ; i < dogs ; ++i) {cin >> size[i];}
	size[dogs] = -1;
	sort(size, size+dogs);
	map = new int*[dogs+1];
	for(int i = 1 ; i <= dogs ; ++i) {
		map[i] = new int[dogs];
		for(int j = 0 ; i+j <= dogs ; ++j) {
			map[i][j] = size[i+j-1]-size[i-1];
		}
	}
	solution = new int[employers+1];
}

ITEMS::~ITEMS() {
	delete[] size;
	for(int i = 0 ; i <= dogs ; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

void ITEMS::calculate() {
	if(layer == employers+1) {
		if(cur_sum == dogs) {answer();}
		--layer; return ;
	}
	for(int i  = 1 ; i <= dogs ; ++i) {
		cur_sum += i; solution[layer] = i; 
		++layer; calculate();
		cur_sum -= i;
	}
	--layer; 
}

void ITEMS::answer() {
	int temp = 0, j = 1;
	for(int i = 1 ; i <= employers ; ++i) {
		temp += map[j][solution[i]-1];
		j = j+solution[i];
	}
	if(temp < sum) sum = temp;
}
