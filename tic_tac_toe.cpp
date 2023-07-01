#include<iostream>
using namespace std;
struct tac
{
	int compare;
	char show;
};
int main()
{
	tac data[3][3];
	int put = 49;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			data[i][j].show = (char) put;
			put++;
		}
	}
	auto print = [&data]()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout << data[i][j].show << "   ";
			}
			cout << "\n\n";
		}
	};
	auto matrix = [&data](char x, int y)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(data[i][j].show == x)
				{
					data[i][j].compare = y;
					if(y==1)
					{
						data[i][j].show = 'X';
					}
					else
					{
						data[i][j].show = 'O';
					}
					break;
				}
			}
		}
	};
	auto check = [&data](int input)->bool
	{
		if(data[0][0].compare==input && data[0][1].compare==input && data[0][2].compare==input)
		{
			return true;
		}
		else if(data[0][0].compare==input && data[1][1].compare==input && data[2][2].compare==input)
		{
			return true;
		}
		else if(data[0][0].compare==input && data[1][0].compare==input && data[2][0].compare==input)
		{
			return true;
		}
		else if(data[0][1].compare==input && data[1][1].compare==input && data[2][1].compare==input)
		{
			return true;
		}
		else if(data[0][2].compare==input && data[1][2].compare==input && data[2][2].compare==input)
		{
			return true;
		}
		else if(data[0][2].compare==input && data[1][1].compare==input && data[2][0].compare==input)
		{
			return true;
		}
		else if(data[1][0].compare==input && data[1][1].compare==input && data[1][2].compare==input)
		{
			return true;
		}
		else if(data[2][0].compare==input && data[2][1].compare==input && data[2][2].compare==input)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
		
	bool bl = true;
	print();
	int count = 0;
	while(true)
	{
		if(bl)
		{
			char x;
			cout << "Enter Player X:";
			cin >> x;
			matrix(x, 1);
			bl = false;
			cout << "\n";
			print();
			if(check(1))
			{
				cout << ".....Player X Win.....\n";
				break;
			}
		}
		else
		{
			char x;
			cout << "Enter Player O:";
			cin >> x;
			matrix(x, 2);
			bl = true;
			cout << "\n";
			print();
			if(check(2))
			{
				cout << ".....Player O Win.....\n" ;
				break;
			}
		}
		count++;
		if(count == 9)
		{
			cout << "......Draw......" << "\n";
			break;
		}
	}
	return 0;
}
