#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Missile {
    private:
        int total_num;
		int max_num;
        long long **rem; //二维数组记录递归结果，第一行按顺序记录导弹高度
                         //第二行记录拦截第奇数颗导弹时最多拦截的数量
                         //第三行记录拦截第偶数颗导弹时最多拦截的数量
		vector<long long> blocked;
		void block(int, int);
		void answer();
		void answer(int);
    public:
        Missile(): total_num(0), rem(NULL), max_num(INT_MAX) {}
        void setup(); //读入数据并存储
        void calculate();
        ~Missile();
};

int main() {
}

void Missile::setup() {
    cin >> total_num;
    rem = new long long*[3];
    for(int i = 0 ; i < 3 ; ++i) {
        rem[i] = new long long[total_num];
        if(i == 0) {
            for(int j = 0 ; j < total_num ; ++j) {
				cin >> rem[i][j];}
        }
        else {
            for(int j = 0 ; j < total_num ; ++j) {rem[i][j] = 0;}
        }
    }
}

Missile::~Missile() {
    for(int i = 0 ; i < 3 ; ++i) {delete[] rem[i];}
    delete[] rem;
}

void Missile::calculate() {
    int num = 0; //上一次拦截的导弹的下标
	for(int i = 0 ; i < total_num ; ++i) {
		blocked.push_back(i); block(i, 1);
	}
}

void Missile::block(int num, int cur) {
	if(num == total_num-1) {
		answer();
		blocked.pop_back(); return ;
	}
	if(cur == 1) {block(num, cur+1);}
	for(int cur_num = num+1; cur_num < total_num ; ++cur_num) {
		if(cur%2 == 0 && rem[0][cur_num] < rem[0][num]) {
			if(rem[2][cur_num] != -1) {
				blocked.push_back(cur_num); answer(cur_num);
				blocked.pop_back(); return ;
			}
			blocked.push_back(cur_num); block(cur_num, cur+1);
		}
		if(cur%2 != 0 && rem[0][cur_num] > total_num) {
			if(rem[1][cur_num] != -1) {
				blocked.push_back(cur_num); answer(cur_num);
				blocked.pop_back(); return ;
			}
			blocked.push_back(cur_num); block(cur_num, cur+1);
		}
	}
	blocked.pop_back(); return ;
}

void Missile::answer() {
	int rp = 0, p = 0;
	for(int i = 1; p < blocked.size() ; ++p, ++i) {
		while(rem[0][rp] != blocked[p]) {++rp;}
		if(i%2 == 0) {rem[2][rp] = blocked.size()-p-1;}
		else {rem[1][rp] = blocked.size()-p-1;}
	}
	if(blocked.size() < max_num) {max_num = blocked.size();}
}

void Missile::answer(int cur_num) {
	
	int temp = blocked.size()%2 == 0 ? rem[2][cur_num] : rem[1][cur_num];
	for(int i = 0 ; i < blocked.size() ; ++i) {
		//
	}
}
