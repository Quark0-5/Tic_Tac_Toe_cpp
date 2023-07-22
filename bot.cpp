#include <iostream>
#include <functional>
using namespace std;
struct tac
{
    int compare = 0;
    char show;
};
int main()
{
    tac data[3][3];
    int char_put = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            data[i][j].show = (char)char_put;
            char_put++;
        }
    }
    auto print = [&data]()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << data[i][j].show << ((j + 1) % 3 ? " | " : "");
            }
            cout << ((i + 1) % 3 ? "\n- - - - -\n" : "");
        }
    };
    auto matrix = [&data](char x, int y)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (data[i][j].show == x)
                {
                    data[i][j].compare = y;
                    if (y == 1)
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
    auto check = [&data](int input) -> bool
    {
        if (data[0][0].compare == input && data[0][1].compare == input && data[0][2].compare == input)
        {
            return true;
        }
        else if (data[0][0].compare == input && data[1][1].compare == input && data[2][2].compare == input)
        {
            return true;
        }
        else if (data[0][0].compare == input && data[1][0].compare == input && data[2][0].compare == input)
        {
            return true;
        }
        else if (data[0][1].compare == input && data[1][1].compare == input && data[2][1].compare == input)
        {
            return true;
        }
        else if (data[0][2].compare == input && data[1][2].compare == input && data[2][2].compare == input)
        {
            return true;
        }
        else if (data[0][2].compare == input && data[1][1].compare == input && data[2][0].compare == input)
        {
            return true;
        }
        else if (data[1][0].compare == input && data[1][1].compare == input && data[1][2].compare == input)
        {
            return true;
        }
        else if (data[2][0].compare == input && data[2][1].compare == input && data[2][2].compare == input)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    auto compute = [&](int input) -> char
    {
        int put = 0;
        if (data[0][0].compare == input && data[0][1].compare == input && data[0][2].compare == put)
        {
            return '3';
        }
        else if (data[0][0].compare == input && data[0][1].compare == put && data[0][2].compare == input)
        {
            return '2';
        }
        else if (data[0][0].compare == put && data[0][1].compare == input && data[0][2].compare == input)
        {
            return '1';
        }
        else if (data[0][0].compare == input && data[1][1].compare == input && data[2][2].compare == put)
        {
            return '9';
        }
        else if (data[0][0].compare == input && data[1][1].compare == put && data[2][2].compare == input)
        {
            return '5';
        }
        else if (data[0][0].compare == put && data[1][1].compare == input && data[2][2].compare == input)
        {
            return '1';
        }
        else if (data[0][0].compare == input && data[1][0].compare == input && data[2][0].compare == put)
        {
            return '7';
        }
        else if (data[0][0].compare == input && data[1][0].compare == put && data[2][0].compare == input)
        {
            return '4';
        }
        else if (data[0][0].compare == put && data[1][0].compare == input && data[2][0].compare == input)
        {
            return '1';
        }
        else if (data[0][1].compare == input && data[1][1].compare == input && data[2][1].compare == put)
        {
            return '8';
        }
        else if (data[0][1].compare == input && data[1][1].compare == put && data[2][1].compare == input)
        {
            return '5';
        }
        else if (data[0][1].compare == put && data[1][1].compare == input && data[2][1].compare == input)
        {
            return '2';
        }
        else if (data[0][2].compare == input && data[1][2].compare == input && data[2][2].compare == put)
        {
            return '9';
        }
        else if (data[0][2].compare == input && data[1][2].compare == put && data[2][2].compare == input)
        {
            return '6';
        }
        else if (data[0][2].compare == put && data[1][2].compare == input && data[2][2].compare == input)
        {
            return '3';
        }
        else if (data[0][2].compare == input && data[1][1].compare == input && data[2][0].compare == put)
        {
            return '7';
        }
        else if (data[0][2].compare == input && data[1][1].compare == put && data[2][0].compare == input)
        {
            return '5';
        }
        else if (data[0][2].compare == put && data[1][1].compare == input && data[2][0].compare == input)
        {
            return '3';
        }
        else if (data[1][0].compare == input && data[1][1].compare == input && data[1][2].compare == put)
        {
            return '6';
        }
        else if (data[1][0].compare == input && data[1][1].compare == put && data[1][2].compare == input)
        {
            return '5';
        }
        else if (data[1][0].compare == put && data[1][1].compare == input && data[1][2].compare == input)
        {
            return '4';
        }
        else if (data[2][0].compare == input && data[2][1].compare == input && data[2][2].compare == put)
        {
            return '9';
        }
        else if (data[2][0].compare == input && data[2][1].compare == put && data[2][2].compare == input)
        {
            return '8';
        }
        else if (data[2][0].compare == put && data[2][1].compare == input && data[2][2].compare == input)
        {
            return '7';
        }
        else if((data[0][1].compare==2 && data[1][2].compare==2) ||(data[0][1].compare==2 && data[1][0].compare==2) || (data[1][0].compare==2 && data[2][1].compare==2) ||(data[2][1].compare==2 && data[1][2].compare==2))
        {
            return '5';
        }
        else
        {
            return '0';
        }
    };
    auto computer = [&]()
    {
        char x = compute(1);
        char y = compute(2);
        if (x != '0')
            matrix(x, 1);
        else if (y != '0')
            matrix(y, 1);
        else
        {
            if (data[0][0].compare == 0)
                matrix('1', 1);
            else if (data[0][2].compare == 0)
                matrix('3', 1);
            else if (data[2][0].compare == 0)
                matrix('7', 1);
            else
                matrix('9', 1);
        }
    };
    bool bl = true;
    print();
    int count = 0;
    while (true)
    {
        if (bl)
        {
            cout << "\n......computer:......\n";
            computer();
            bl = false;
            cout << "\n";
            print();
            if (check(1))
            {
                cout << "\n.....Oops Computer Win.....\n...Next Time :)...";
                break;
            }
        }
        else
        {
            char x;
            cout << "\n\n......Your Turn......\nYou:";
            cin >> x;
            matrix(x, 2);
            bl = true;
            cout << "\n";
            print();
            if (check(2))
            {
                cout << ".....You Win.....\n";
                break;
            }
        }
        count++;
        if (count == 9)
        {
            cout << "\n......Draw......\n";
            break;
        }
    }
    return 0;
}
