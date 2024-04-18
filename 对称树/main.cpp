#include<iostream>
#include<string>
using namespace std;

int main() 
{
	string a;
	cin >> a;
	int l = a.size();//字符串a的长度
	int cc = 1;
	for (int i = 0; i < l; i++)
	{
		if (a[i] == a[i + 1]) 
		{
			cc++;
		}
		else 
		{
            cout << a[i] << cc;
		    cc = 1;
		}
	}
	return 0;
}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> vec;
        int m = mat.size(), n = mat[0].size();
        if (mat.empty())
            return vec;
        //r为纵坐标，c为横坐标，r+c=i(i从0开始计数)
        int r, c;
        for (int i = 0; i < n + m - 1; ++i) {
            if (i % 2) {   //奇数对角线，箭头从右上方指向左下方，c--，r++
                c = i < n - 1 ? i : n - 1;
                r = i - c;
                while (r < m && c >= 0) {
                    vec.push_back(mat[r++][c--]);
                }
            }
            else {
                r = i < m - 1 ? i : m - 1;
                c = i - r;
                while (c < n && r >= 0) {
                    vec.push_back(mat[r--][c++]);
                }
            }
        }
        return vec;
    }
};