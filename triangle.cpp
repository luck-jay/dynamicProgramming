/**
 *			Triangle
 *
 * 给定一个三角形数字阵列，选择一条自顶向下的路径，使得沿途的所有数字之和最小。（每一步只能移动到相邻的格子中。）
 *
 * */

#include <iostream>
#define min(x, y) x < y ? x:y
#define max(x, y, z) x > y ? x : y > z ? x > y ? x:y : z

using namespace std;

//定义一个二维数组保存数据
int data[10][10] = {0};
//定义保存路径和最小值
int base_data[10] = {0};
//定义一个二维数组来保存计算出来的值，使用记忆搜索算法来优化递归算法
int temp[10][10] = {0};
int row = 0;
/**
 * 用动态规划的方式解决
 * */
int dif(int n){
	for(int i = 0; i < n; i++){
		base_data[i] = data[n - 1][i];
	}	
	for(int i = n-2; i >= 0; i--)
		for(int j = 0; j <= i; j++){
			int left = base_data[j] + data[i][j];
			int right = base_data[j + 1] + data[i][j];

			base_data[j] = left < right ? left:right;
	  }

	return base_data[0];
}
/**
 * 使用递归的方式求解
 * */

int fun(int x, int y){
	if(x == row -1)
		return data[x][y];

	if(temp[x][y] != 0)
		return temp[x][y];

	temp[x][y] = min(data[x][y] + fun(x + 1, y), data[x][y] + fun(x+1, y + 1));
	return temp[x][y];
}

int main(){
	cin >> row;

	for(int i = 0; i < row; i++){
		for(int j = 0; j <= i; j++){
			cin >> data[i][j];
		}
	}

	cout << fun(0, 0) << endl;
	return 0;
}
