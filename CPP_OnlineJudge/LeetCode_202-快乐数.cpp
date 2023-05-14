
/*
	202. 快乐数 https://leetcode.cn/problems/happy-number/description/

	难度：简单

		编写一个算法来判断一个数 n 是不是快乐数。

		「快乐数」 定义为：

			对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
			然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
			如果这个过程 结果为 1，那么这个数就是快乐数。
		
		如果 n 是 快乐数 就返回 true ；不是，则返回 false 。


		示例 1：
			输入：n = 19
			输出：true
			解释：
			1*1 + 9*9 = 82
			8*8 + 2*2 = 68
			6*6 + 8*8 = 100
			1*1 + 0*0 + 0*0 = 1

		示例 2：
			输入：n = 2
			输出：false
 

		提示：
			1 <= n <= 231 - 1
*/
/*
    在十进位下，100以内的快乐数有（OEIS中的数列A00770） ：1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100。

    思路：
        创建容器 v
        创建容器 vRecord
        变量 num 存储 平方 后 相加 的结果

        容器v用来记录拆分出来的个位数
        容器vRecord用来记录每次 平方 后 相加 的结果

        每次循环都会去 容器vRecord 中找 是否有和 num 相同的数字，如果有，说明是死循环，不是快乐数
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> v;
        vector<int> vRecord;// 记录每次 平方 后 相加 的结果
        int num = 0;// 存储 平方 后 相加 的结果

        while (num != 1)
        {
            while (n >= 1)
            {
                v.push_back(n % 10);

                n /= 10;
            }

            for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
            {

                num += (*it) * (*it);
            }

            if (num == 1)
            {
                // 是 快乐数
                return true;
            }

            for (vector<int>::iterator it = vRecord.begin(); it != vRecord.end(); it++)
            {
                // 查找
                if ((*it) == num)
                {
                    // 不是 快乐数
                    return false;
                }
            }

            n = num;
            vRecord.push_back(num);
            num = 0;
            v.clear();
        }

        return false;// 无用的返回
    }
};

int main()
{
    Solution s;
    s.isHappy(3);

    return 0;
}