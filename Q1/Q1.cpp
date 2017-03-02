// Name: 吳明壎
// Date: March 2, 2017
// Last Update: March 3, 2017
// Problem statement: 找不同進位下的最小數回文

#include <iostream>
#include <string>

using namespace std;


string GetString(int dataFrom10, int toBase)
{
	if (dataFrom10 == 0)
		return "0";
	string ret;
	while (dataFrom10 != 0)
	{
		ret.insert(ret.begin(), static_cast<char>((dataFrom10 % toBase) + '0'));  //找不同的進位表示方式
		dataFrom10 /= toBase;
	}
	return ret;
}


bool GetResult(const string &str) //檢查是不是回文
{
	for (int i = 0; i < str.size() / 2; i++)
		if (str[i] != str[str.size() - 1 - i])
			return false;
	return true;
}


int FindResult(int data)
{
	int base[2] = { 0 };
	int range = 1000000;
	while (data <= range)
	{
		int ans = 0;
		for (int i = 2; i <= 10; i++)
		{
			if (GetResult(GetString(data, i)))
			{
				base[ans++] = i;
			}
			if (ans == 2)
			{
				cout << data << endl << base[0] << " " << GetString(data, base[0]) << endl << base[1] << " " << GetString(data, base[1]) << endl;
				return 1;
			}
		}
		++data;
	}
	return -1; // not found
}

int main()
{
	string find;
	string::size_type sz;

	cin >> find;
	while (find != "EOF") {
		int findint = stoi(find, &sz);
		int result = FindResult(findint);

		if (result == -1)
			cout << "No answer." << endl;

		cin >> find;
	}

	system("pause");
	return 0;
}