﻿#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

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

	for (int iter = 0; iter < int(nums.size()); iter++) {
		if (vTrans.size() != 0) {
			int nCurr = nums.at(iter);
			int nTotal2 = 0;
			for (int iterT = 0; iterT < int(vTrans.size()); iterT++) {
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

/*
求一个数组中的最小数
*/
int min(std::vector<int> InPut) {
	int nResurt = 0;
	int nTrans = InPut.at(0);
	for (int i = 0; i < int(InPut.size()); i++) {
		if (i + 1 <= int(InPut.size())) {
			if (InPut.at(i) < InPut.at(i + 1) && InPut.at(i) <= nTrans) {
				nTrans = InPut.at(i);
			}
			else if (InPut.at(i + 1) <= nTrans) {
				nTrans = InPut.at(i + 1);
			}
		}
	}
	nResurt = nTrans;
	return nResurt;
}

/************************************************************************/
/* 2021-5-31
*  Description: 判断输入是否为4的幂
*  Auto:Bing
/************************************************************************/
bool isPowerOfFour(int n) {

	if (n != 1 && (n % 4 != 0 || n < 4 ) ) {
		return false;
	}
	if (n == 1) {
		return true;
	}
	int nflag = 0;
	while (n >= 4 && n % 4 == 0)
	{
		n = n / 4;
		if (n == 1) {
			return true;
		}
	}
	return false;
}

/************************************************************************/
/* 2021-6-1
*  Description: 力扣1744 eg.candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
*  Auto:Bing
/************************************************************************/

std::vector<bool> canEat(std::vector<int>& candiesCount, std::vector<std::vector<int>>& queries) {
	std::vector<bool> vresult;
	int favoriteType = 0, favoriteDay = 0, dailyCap = 0;
	long nNeedMin, nCaneatMax, nCaneatMin, nNeedMax = 0;//candy 
	std::vector<long> Sum(int(candiesCount.size()));
	Sum[0] = candiesCount[0];
	for (int j = 1; j < int(candiesCount.size()); j++) {
		Sum[j] = Sum[j - 1] + candiesCount.at(j);
	}
	for (const auto &q : queries) {
		int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2]; 

		nNeedMin = (favoriteType == 0 ? 1 : Sum[favoriteType - 1] + 1);
		nCaneatMax = (long)(favoriteDay + 1) * dailyCap;
		nCaneatMin = favoriteDay + 1;
		nNeedMax = Sum[favoriteType];
		vresult.push_back(!(nCaneatMin > nNeedMax || nCaneatMax < nNeedMin));
	}
	return vresult;
}

/************************************************************************/
/* 2021-6-2
*  Description:力扣 523 eg. nums = [23,2,4,6,6], k = 7
*  Auto:Bing
/************************************************************************/
bool checkSubarraySum(std::vector<int>& nums, int k) {
	int nlength = nums.size();
	int nTemp, nRemainder = 0;
	if (nlength < 2) return false;
	std::unordered_map<int, int> unmap;
	unmap[0] = -1;
	for (int i = 0; i < nlength; i++) {
		nRemainder = (nRemainder + nums[i]) % k;//?
		if (unmap.count(nRemainder)) {
			nTemp = unmap[nRemainder];
			if (i - nTemp >= 2)
				return true;
		}
		else {
			unmap[nRemainder] = i;//?
		}
	}
	return false;
}

/*
选择排序 升序
*/
std::vector<int> selectionSort(std::vector<int> InPut) {
	int nTrans, nminIndex = 0;
	for (int i = 0; i < int(InPut.size()); i++) {
		nminIndex = i;
		for (int j = i + 1; j < int(InPut.size()); j++) {
			if (InPut.at(j) < InPut.at(nminIndex)) {
				nminIndex = j;
			}
		}
		nTrans = InPut.at(i);
		InPut.at(i) = InPut.at(nminIndex);
		InPut.at(nminIndex) = nTrans;	
	}
	return InPut;
}

/************************************************************************/
/* 2021-4-26
*  Description:冒泡排序 
*  Auto:Bing
/************************************************************************/
template<typename T>
void bubbleSort(std::vector<T> &Input) {
	for (int i = 0; i < int(Input.size() - 1); i++) {
		for (int j = 0; j < int(Input.size() - 1); j++) {
			if (Input.at(j) < Input.at(j + 1)) {
				std::swap(Input.at(j), Input.at(j + 1));
			}
		}
	}
}

/************************************************************************/
/* 2021-4-27
*  Description:QuickSort  use Recursion
*  Auto:Bing
/************************************************************************/
template<typename T>
void quickSort(std::vector<T> &Input, int nLeft, int nRight) {
	if (nLeft > nRight)
		return;
	int nBaseNumber = Input.at(nLeft);
	int nSentinelA = nLeft;
	int nSentinelB = nRight;
	while (nSentinelA != nSentinelB)
	{
		while (Input.at(nSentinelB) >= nBaseNumber && nSentinelA < nSentinelB)
			nSentinelB--;
		while (Input.at(nSentinelA) <= nBaseNumber && nSentinelA < nSentinelB)
			nSentinelA++;

		if (nSentinelA < nSentinelB) {
			//sentinels doesn't meet
			std::swap(Input.at(nSentinelA), Input.at(nSentinelB));	//exchange them site
		}
	}
	//when they meet
	std::swap(Input.at(nSentinelA), Input.at(nLeft));

	//and then do recursion
	quickSort(Input, nLeft, nSentinelA - 1);
	quickSort(Input, nSentinelA + 1, nRight);
	return;

}

/************************************************************************/
/* 2021-5-6
*  Description:Insertion Sort 
*  Auto:Bing
/************************************************************************/
template<typename T>
void InsertionSort(std::vector<T> &Input) {
	int i, j, nKey = 0;
	for (i = 1; i < int(Input.size()); i++){
		j = i - 1;
		nKey = Input.at(i);
		while (j >= 0 && Input.at(j) > nKey)
		{
			std::swap(Input.at(j), Input.at(j + 1));
			j--;
		}
		Input.at(j+1) = nKey;// insert
	}
}

/************************************************************************/
/* 2021-5-31
*  Description: shell sort
*  Auto:Bing
/************************************************************************/
template<typename T>
void ShellSort(std::vector<T> &Input) {
	int nflag = 1, nLength = Input.size();
	while (nflag < nLength /3)
	{
		nflag = nflag * 3 + 1;//?
	}
	while (nflag >= 1)
	{
		for (int i = nflag; i < nLength; i++)
		{
			for (int j = i; j >= nflag && Input.at(j) < Input.at(j - nflag); j -= nflag)//?
			{
				std::swap(Input.at(j), Input.at(j - nflag));
			}
		}
		nflag = nflag / 3;

	}
}

int main(int argc, char* argv[])
{
	std::vector<int> In = { 9,6,0,1,2,3,8,4,5 };
	//std::vector<int> Out = selectionSort(In);
	//bubbleSort(In);
	//quickSort(In, 0, int(In.size() - 1));
	//InsertionSort(In);
	ShellSort(In);
	for (int i = 0; i < int(In.size()); i++) {
		std::cout << In.at(i)<<std::endl;
	}
	//
	//bool nRet = isPowerOfFour(123);
	std::vector<int>candiesCount = { 23,2,4,6,6 };
	std::vector<std::vector<int>> queries ;
	queries.push_back({ 40, 1083, 86 });
	queries.push_back({ 43, 1054, 49 });
	queries.push_back({ 35, 669, 5 });
	queries.push_back({ 72, 822, 74 });
	queries.push_back({ 47, 933, 94 });

	//canEat(candiesCount, queries);
	bool nRet = checkSubarraySum(candiesCount, 7);
	std::cout<< "\r\n"<<nRet << std::endl;
	system("pause");
	return 0;
}