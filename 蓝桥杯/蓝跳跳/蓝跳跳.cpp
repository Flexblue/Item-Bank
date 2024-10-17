#include <iostream>
using namespace std;

class Item {
private:
    long long L; //总长度
    int p; //连续两步大于等于p就会摔倒
    int k; //每一步最多跳的长度
    long long** dp; //dp[i][j]表示跳到长度为i的位置，j表示上一步是否超过了p
public:
    Item(): L(0), p(0), k(0), dp(NULL) {} //构造函数
    void setup(); //初始化
    long long dfs(long long sum = 0, int flag = 0); //深搜
    ~Item() { //析构函数
        for (int i = 0; i <= L; i++) { delete[] dp[i]; }
        delete[] dp;
    }
};

int main() {
    Item item;
    item.setup();
    cout << item.dfs() << endl;
    return 0;
}

void Item::setup() {
    cin >> k >> p >> L;
    dp = new long long*[L + 1];
    for (int i = 0; i <= L; i++) { dp[i] = new long long[2]; dp[i][0] = dp[i][1] = 0 ; }
}

long long Item::dfs(long long sum, int flag) {
    if (sum == L) { return 1 ; }
    if (sum > L) { return 0 ; }
    if ( dp[sum][flag] ) { return dp[sum][flag] ; }
    for(int i = 1; i < p ; i++) {
        dp[sum][flag] += dfs(sum + i, 0);
    }
    if(flag == 0) {
        for(int i = p; i <= k; i++) {
            dp[sum][flag] += dfs(sum + i, 1);
        }
    }
    return dp[sum][flag];
}