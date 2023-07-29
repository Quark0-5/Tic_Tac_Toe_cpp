#include <iostream>
using namespace std;
struct tac
{
    int compare = 0;
    char show;
    char show_int;
};
int main()
{
    tac data[3][3];
    auto set = [&]()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                data[i][j].compare = 0;
            }
        }
    };

    auto strat = [&]()
    {
        int char_put = 49;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                data[i][j].show = (char)char_put;
                data[i][j].show_int = (char)char_put;
                char_put++;
            }
        }
    };
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
    auto matrix = [&data](char x, int y) -> void
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
        else if ((data[0][1].compare == 2 && data[1][2].compare == 2 && data[1][1].compare == 0) || (data[0][1].compare == 2 && data[1][0].compare == 2 && data[1][1].compare == 0) || (data[1][0].compare == 2 && data[2][1].compare == 2 && data[1][1].compare == 0) || (data[2][1].compare == 2 && data[1][2].compare == 2 && data[1][1].compare == 0))
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
    auto test = [&](char x)->bool
    {
        bool bool_test=false;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(data[i][j].show_int==x)
                {
                    if(data[i][j].compare!=0)
                    {
                        bool_test=true;
                    }
                }
            }
        }
        return bool_test;
    };
    auto computer_vs_human = [&]()
    {
        strat();
        set();
        bool bl = true;
        print();
        int count = 0;
        while (true)
        {
            if (bl)
            {
                count++;
                cout << "\n\ncomputer:......\n";
                computer();
                bl = false;
                cout << "\n";
                print();
                if (check(1))
                {
                    cout << "\n.....Oops Computer Win.....\n.....Next Time :).....";
                    break;
                }
            }
            else
            {
                char x;
                cout << "\n......Your Turn......\nYou:";
                cin >> x;
                if(test(x))
                {
                    cout << "The position is occupied!\nTry another position\n";
                    bl=false;
                    print();
                }
                else if(x<'1' || x>'9')
                {
                    cout << "Enter correct position!\n";
                    bl=false;
                    print();
                }
                else 
                {
                    count++;
                    matrix(x, 2);
                    bl=true;
                    cout << "\n";
                    print();
                    if(check(2))
                    {
                        cout << ".....You Win.....\n";
                        break;
                    }
                }
            }
            if (count == 9)
            {
                cout << "\n......Draw......\n";
                break;
            }
        }
    };
    auto human_vs_human = [&]()
    {
        strat();
        set();
        bool bl = true;
        print();
        int count = 0;
        while (true)
        {
            if (bl)
            {
                char x;
                cout << "\nEnter Player X:";
                cin >> x;
                if(test(x))
                {
                    cout << "The position is occupied!\nTry another position\n";
                    bl=true;
                    print();                    
                }
                else if(x<'1' || x>'9')
                {
                    cout << "Enter correct position!\n";
                    bl=true;
                    print();
                }                
                else
                {
                    count++;
                    matrix(x, 1);
                    bl = false;
                    cout << "\n";
                    print();
                    if(check(1))
                    {
                        cout << "\n.....Player X Win.....\n";
                        break;
                    }
                }
            }
            else
            {
                char x;
                cout << "\nEnter Player O:";
                cin >> x;
                if(test(x))
                {
                    cout << "The position is occupied!\nTry another position\n";
                    bl=false;
                    print();                    
                }
                else if(x<'1' || x>'9')
                {
                    cout << "Enter correct position!\n";
                    bl=false;
                    print();
                }     
                else
                {
                    count++;
                    matrix(x, 2);
                    bl = true;
                    cout << "\n";
                    print();
                    if(check(2))
                    {
                        cout << "\n.....Player O Win.....\n";
                        break;
                    }
                }
            }
            if (count == 9)
            {
                cout << "\n......Draw......\n";
                break;
            }
        }
    };
    cout << "........Tic Tac Toe........";
    while (true)
    {
        cout << "\nEnter 1 Computer vs Human!\nEnter 2 Human vs Human!\nEnter 0 EXIT!\n";
        cout << "ENTER:";
        int n;
        cin >> n;
        if (n == 1)
            computer_vs_human();
        else if (n == 2)
            human_vs_human();
        else
            return 0;
    }
    return 0;
}
