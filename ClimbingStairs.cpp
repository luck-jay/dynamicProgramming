/**
 *
 * 问题：
 *		有一个楼梯，总共有n个台阶。每一次，可以上一个台阶，也可以上两个台阶。
 *		问，爬上这样的一个楼梯，一共有多少不同的方法？
 * 分析：
 *	
 *	1. 爬上第n阶台阶需要先爬上第n-1台阶，或者先爬上n-2台阶
 *	2. 求n-1阶台阶有几种方法+n-2阶台阶有几种方法就等于总的方法数
 * */

# include <stdio.h>

#define MAX 100

int memo[MAX] = {0};

/**
 *
 * 使用递归的方法来实现这个问题
 * 并使用记忆化搜索的方法去节省时间
 * */

int climbStairs_d(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}

	if(memo[n] == 0)
		memo[n] = climbStairs_d(n - 1) + climbStairs_d(n - 2);

	return memo[n];
}

/**
 *
 * 使用动态规划的方法去实现
 * */

int climbStairs_s(int n)
{
	memo[0] = 1;
	memo[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	return memo[n];
}

int main()
{
		
	return 0;
}
