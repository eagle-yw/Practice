#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/
bool isValid(std::string s)
{
	int nstrlength = int(s.length());
	if (nstrlength % 2 != 0 || nstrlength == 0) {
		return false;
	}
	std::stack<char> stackch;
	for (int i = 0; i< nstrlength; i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			stackch.push(s[i]);
		if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			if (stackch.empty()) return false;
			char chCom = stackch.top();
			stackch.pop();
			switch (int(s[i])) {
			case '}': {
				if (chCom != '{') return false;
				break;
			}
			case ']': {
				if (chCom != '[') return false;
				break;
			}
			case ')': {
				if (chCom != '(') return false;
				break;
			}
			default:
				return false;
				break;
			}
		}
	}
	if (!stackch.empty()) return false;
	return true;
}

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

*/
std::vector<int> Test(std::vector<int> &nums, int target) {
	//nums = [2,7,11,15], target = 9：nums = [3,2,4], target = 6nums = [3,3], target = 6
	//[0,1]
	std::vector<int> vResult;
	std::vector<int> vTrans;
	int nTotal1 = 0;

	for (int iter = 0; iter < nums.size(); iter++) {
		if (vTrans.size() != 0) {
			int nCurr = nums.at(iter);
			int nTotal2 = 0;
			for (int iterT = 0; iterT < vTrans.size(); iterT++) {
				int nTest = vTrans.at(iterT) + nCurr;
				if (nTest == target) {
					vResult.push_back(nTotal1);
					vResult.push_back(nTotal2);
				}
				nTotal2++;
			}
		}
		int ndifference = nums.at(iter);
		vTrans.push_back(ndifference);
		nTotal1++;
	}

	return vResult;
}

/*
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内
*/
int romanToInt(std::string s)
{
	//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
	int nstrlength = s.length();
	int nValue = 0;
	int nCurVal = 0;
	int nNexVal = 0;

	for (int i = 0; i < nstrlength; i++) {

		if (s[i] == 'I') nCurVal = 1;
		else if (s[i] == 'V') nCurVal = 5;
		else if (s[i] == 'X') nCurVal = 10;
		else if (s[i] == 'L') nCurVal = 50;
		else if (s[i] == 'C') nCurVal = 100;
		else if (s[i] == 'D') nCurVal = 500;
		else if (s[i] == 'M') nCurVal = 1000;

		if ((i + 1) != nstrlength) {
			if (s[i + 1] == 'I') nNexVal = 1;
			else if (s[i + 1] == 'V') nNexVal = 5;
			else if (s[i + 1] == 'X') nNexVal = 10;
			else if (s[i + 1] == 'L') nNexVal = 50;
			else if (s[i + 1] == 'C') nNexVal = 100;
			else if (s[i + 1] == 'D') nNexVal = 500;
			else if (s[i + 1] == 'M') nNexVal = 1000;
		}

		if ((i + 1) == nstrlength) {
			nValue += nCurVal;
		}
		else {
			if (nCurVal == nNexVal || nCurVal > nNexVal) {
				nValue += nCurVal;
			}
			else if (nCurVal < nNexVal) {
				nValue -= nCurVal;
			}
		}
	}

	return nValue;
}

/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
	std::string strResult = "";
	int nstrLength = strs.size();
	std::vector<char> vSameChar;
	std::vector<char> vSameChar2;
	if (nstrLength >= 2) {
		for (int j = 0; j < nstrLength; j++) {
			for (int i = 0; i < int(strs.at(j).length()); i++) {
				if (j == 0 && i == 0 && strs.at(j)[i] != strs.at(j + 1)[i]) {
					return "";
				}
				if ((vSameChar.size() != 0 && i < int(vSameChar.size()))) {
					if (strs.at(j)[i] == vSameChar.at(i)) {
						vSameChar2.push_back(strs.at(j)[i]);
					}
					else {
						break;
					}
				}
				else if (vSameChar.size() == 0) {
					if (strs.at(j)[i] == strs.at(j + 1)[i]) {
						vSameChar2.push_back(strs.at(j)[i]);
					}
					else {
						break;
					}
				}
			}
			if (vSameChar2.size() != 0) {
				vSameChar.swap(vSameChar2);
				vSameChar2.clear();
			}
			else {
				return "";
			}
		}
		for (int t = 0; t < int(vSameChar.size()); t++) {
			std::string strTrans(sizeof(vSameChar.at(t)), vSameChar.at(t));
			strResult += strTrans.c_str();
		}
	}
	else if (nstrLength > 0) {
		strResult = strs.at(0);
		return strResult;
	}
	return strResult;
}

/*给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。*/
int reverse(int x)
{
	int ans = 0;
	int temp = 0;
	int r = 0;

	if (x >= INT_MAX || x <= INT_MIN) return 0;
	if (x >= 0)
		while (x) {
			r = x % 10;
			if (INT_MAX / 10 < temp) return 0;
			temp = ans * 10;
			if (INT_MAX - r < temp) return 0;
			ans = temp + r;
			temp = ans;
			x /= 10;
		}
	else
		while (x) {
			r = x % 10;
			if (INT_MIN / 10 > temp) return 0;
			temp = ans * 10;
			if (INT_MIN - r > temp) return 0;
			ans = temp + r;
			x /= 10;
			temp = ans;
		}
	return ans;
}

/*给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。*/
bool isPalindrome(int x)
{
	long long ans = 0;
	long long temp = 0;
	long long r = 0;
	int nTrans = x;
	if (x == 0) return true;
	if (x < 0) return false;
	if (x > 0) {
		while (x) {
			r = x % 10;
			temp = ans * 10;
			ans = temp + r;
			temp = ans;
			x /= 10;
		}
	}
	if (ans == nTrans) return true;
	else return false;
}

int main(int argc, char* argv[])
{
	system("pause");
	return 0;
}