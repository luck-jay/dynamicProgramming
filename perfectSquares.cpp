/**
 *				Perfect Squares
 *
 * 给出一个正整数n， 寻找最少的完全平方数，使他们的和为n
 * 完全平方数：1， 4， 9， 16……
 * */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
//定义一个数组用于记忆搜索或动态规划时使用
vector<int> memo;

/**
 * 判断这个数是否是一个完全平方数
 * return:返回一个布尔值，如果是返回true
 * */
int flag(int num){
	float x = pow(num, 0.5) * 10;
	if((int)x % 10 == 0)
		return true;
	else
		return false;
}
/**
 * 使用递归的方式解决问题
 * return: 返回可以拆分成的完全平方数，最少是多少
 * */
int fun(int n ){
	int count = 1, base = 1000;
	//如果n是一个完全平方数，那就直接返回1
	if(flag(n))
		return 1;

	if(memo[n] != -1)
		return memo[n];

	while(count * count < n){
		base = min(base,1 + fun(n - count * count));
		count++;
	}

	memo[n] = base;

	return base;
}
/**
 *
 * 使用动态规划的方式解决问题
 * */

int funAction(int n){
	for(int i = 1; i <=n; i++){
		if(flag(i)){//如果是一个完全平方数，则直接赋值为1
			memo[i] = 1;
			continue;
		}
		int count = 1;

		while(count * count < i){
			memo[i] = min(memo[i],1 + memo[i - count*count]);
			count++;
		}
	}
	return memo[n];
}

int main(){
	int n;//正整数n
	cin >> n;
	//使用记忆化搜索时初始化	
	//memo = vector<int>(n+1, -1);
	//使用动态规划时的初始化
	memo = vector<int>(n + 1, 1000);

	cout << funAction(n) << endl;

	return 0;
}
