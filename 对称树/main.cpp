#include<iostream>
#include<string>
using namespace std;

int main() 
{
	string a;
	cin >> a;
	int l = a.size();//�ַ���a�ĳ���
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
        //rΪ�����꣬cΪ�����꣬r+c=i(i��0��ʼ����)
        int r, c;
        for (int i = 0; i < n + m - 1; ++i) {
            if (i % 2) {   //�����Խ��ߣ���ͷ�����Ϸ�ָ�����·���c--��r++
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