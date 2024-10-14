#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Missile {
private:
    int max_num;
    int total_num; //导弹的数目
    long long **height; //二维数组，第一行记录导弹高度，第二行和第三行记录递归结果（第二行为奇，第三行为偶）
    //
    vector<long long> log; //记录拦截的导弹高度数据
    void block(int); //递归主体，参数为当前拦截的导弹的下标
    void answer(int);
    void answer();
public:
    Missile(): total_num(0), height(NULL), max_num(INT_MAX) {}
    void setup();
    void calculate();
    int result() {return max_num;}
    ~Missile() {delete[] height;}
};

int main(void) {
    Missile item;
    item.setup();
    item.calculate();
    cout << item.result() << endl;
    return 0;
}

void Missile::setup() {
    cin >> total_num;
    height = new long long *[3];
    height[0] = new long long [total_num];
    for(int i = 0 ; i < total_num ; ++i) {cin >> height[0][i];}
    height[1] = new long long [total_num];
    height[2] = new long long [total_num];
    for(int i = 0 ; i < total_num ; ++i) {height[1][i] = -1;}
    for(int i = 0 ; i < total_num ; ++i) {height[2][i] = -1;}
}

void Missile::calculate() {
    int sub = 0; //当前拦截的导弹下标
    for(; sub < total_num ; ++sub) {
        block(sub);
    }
}

void Missile::block(int sub) {
    log.push_back(height[0][sub]);
    if(sub == total_num-1) {answer(); log.pop_back(); return ;}
    if(height[1][sub] != -1 || height[2][sub] != -1) {
        answer(sub); log.pop_back(); return;
    }
    int last = sub;
    if(log.size()%2 != 0) {
        for(; sub < total_num ; ++sub) {
            if(height[0][last] > height[0][sub]) { block(sub);}
        }
    }
    else {
        for(; sub < total_num ; ++sub) {
            if(height[0][last] < height[0][sub]) { block(sub);}
        }
    }
    log.pop_back(); return;
}

void Missile::answer() {

}

void Missile::answer(int sub) {
    int temp = log.size()%2 == 0 ? height[1][sub] : height[2][sub];
    for(int i = 0 ; i < log.size() ; ++i) {
        if(i%2 == 0) {height[1][sub] = log.size()+temp-i-1;}
        else {height[2][sub] = log.size()+temp-i-1;}
    }
    if (max_num < log.size() + temp) { max_num = log.size() + temp; }
}