/**
 *
 * 实现斐波那契数列
 *
 * f(0) = 1, f(1) = 1, f(n) = f(n-1) + f(n - 2)
 * 使用记忆化搜索的方法来加快计算的速度
 * 使用动态规划的方式节省程序空间
 * */

#include <stdio.h>

#define MAX 100

int memo[MAX] = {0};

/**
 *
 * 通过递归来计算斐波那契数列
 * 使用了记以化搜索的方法
 * */
int fib_d(int n)
{
	if(n == 1)
	{
		return 1;
	}
	if(n == 0)
	{
		return 1;
	}
	if(memo[n] == 0)
		memo[n] = fib_d(n - 1) + fib_d(n-2);

	return memo[n];
}
/**
 *
 * 通过动态规划的方法实现斐波那契数列
 * */

int fib_g(int n)
{
	memo[0] = 1;
	memo[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	return memo[n];
}

/**
 *
 * 调用生成斐波那契数列的函数
 * */
int main()
{
	int n = 10;
	
	for(int i = 0; i < n; i++)
	{
		printf("%d,", fib_g(i));
	}
	printf("\n");
}
