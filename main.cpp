#include <iostream>
#include <conio.h>
#include <windows.h>

// meelanloeui
using namespace std;

#define H 32
#define W 64

char foodChar = char(240);
char shotChar = '*';
char emptyChar = ' ';
char shotMultyChar = '$';
char healtChar = char(3);
char boombChar = char(15);
char magicBoxChar = char(254);

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


int countShot = 1;
int healt = 5;

void fillFoodInGame(char world[][W])
{
    bool f= false;
    for(int i =0 ; i < H / 2; i++)
    {
        f = f ? false : true;

        for(int k = 0; k< W;k++)
        {
            if(f)
            {

                world[i][k] = foodChar;
            }
            else
            {
                world[i][k] = emptyChar;
            }
            f=!f;
        }

    }
}
void ChangePositionFoods(char world[][W],bool f)
{
    bool flag = f;
    for(int i = 0 ; i < H;i++)
    {
        for(int k=0; k< W;k++)
        {
            if(world[i][k] == foodChar)
            {
                if(flag && k != W-1)
                {

                    if(world[i][k+1] == shotChar)
                    {
                        int randInteger = rand() % 7;
                        if(3 == randInteger)
                        {
                            world[i][k+1] = shotMultyChar;
                        }
                        else if(2 == randInteger)
                        {
                            world[i][k+1] = healtChar;
                        }
                        else if(4 == randInteger)
                        {
                            world[i][k+1] = boombChar;
                        }else if(5 == randInteger)
                        {
                            world[i][k+1] = magicBoxChar;
                        }
                        else
                        {
                            world[i][k+1]= emptyChar;
                        }
                        world[i][k] = emptyChar;

                    }
                    else
                    {

                        world[i][k] = emptyChar;
                        world[i][k+1] = foodChar;

                    }
                    k++;
                }
                else
                {
                    if(world[i][k-1] == shotChar)
                    {
                        int randInteger = rand() % 7;
                        if(3 == randInteger)
                        {
                            world[i][k-1] = shotMultyChar;
                        }
                        else if(2 == randInteger)
                        {
                            world[i][k-1] = healtChar;
                        }
                        else if(4 == randInteger)
                        {
                            world[i][k-1] = boombChar;
                        }else if(5 == randInteger)
                        {
                            world[i][k-1] = magicBoxChar;
                        }
                        else
                        {
                            world[i][k-1]= emptyChar;
                        }
                        world[i][k] = emptyChar;

                    }
                    else
                    {
                        world[i][k-1] = foodChar;
                        world[i][k] = emptyChar;

                    }

                }

            }
        }
        flag = !flag;
    }
}

void CheckShotMultyChar(char world[][W])
{
    for(int i = H - 1; i > 0;i--)
    {
        for(int k = W; k > 0;k--)
        {

            if(world[i][k] == shotMultyChar)
            {
                if(world[i+1][k] != foodChar)
                {
                    if(world[i+1][k] == shotChar)
                    {
                        world[i+1][k] = emptyChar;
                        world[i][k] = emptyChar;
                        countShot++;
                    }else
                    {
                        world[i+1][k] = shotMultyChar;
                        world[i][k] = emptyChar;
                    }

                }

            }
        }

    }
}

void CheckHealtChar(char world[][W])
{
    for(int i = H - 1; i > 0;i--)
    {
        for(int k = W; k > 0;k--)
        {

            if(world[i][k] == healtChar)
            {
                if(world[i+1][k] != foodChar)
                {
                    if(world[i+1][k] == shotChar)
                    {
                        world[i+1][k] = emptyChar;
                        world[i][k] = emptyChar;
                        healt++;
                    }else
                    {
                        world[i+1][k] = healtChar;
                        world[i][k] = emptyChar;
                    }

                }

            }
        }

    }
}

void CheckBoombChar(char world[][W])
{
    for(int i = H - 1; i > 0;i--)
    {
        for(int k = W; k > 0;k--)
        {

            if(world[i][k] == boombChar)
            {
                if(i == 31)
                {
                    healt--;
                    world[i][k]= emptyChar;
                }
                else if(world[i+1][k] != foodChar)
                {
                    if(world[i+1][k] == shotChar)
                    {
                        world[i+1][k] = emptyChar;
                        world[i][k] = emptyChar;
                    }else
                    {
                        world[i+1][k] = boombChar;
                        world[i][k] = emptyChar;
                    }

                }

            }
        }

    }
}

void CheckMagicBoxChar(char world[][W])
{
    for(int i = H - 1; i > 0;i--)
    {
        for(int k = W; k > 0;k--)
        {

            if(world[i][k] == magicBoxChar)
            {
                if(i == 31)
                {
                    world[i][k]= emptyChar;
                }
                else if(world[i+1][k] != foodChar)
                {
                    if(world[i+1][k] == shotChar)
                    {
                        int randInteger = rand() % 7;
                        if(3 == randInteger)
                        {
                            world[i][k] = shotMultyChar;
                        }
                        else if(2 == randInteger)
                        {
                            world[i][k] = healtChar;
                        }
                        else if(4 == randInteger)
                        {
                            world[i][k] = boombChar;
                        }else if(5 == randInteger)
                        {
                            world[i][k] = magicBoxChar;
                        }
                        else
                        {
                            world[i][k]= emptyChar;
                        }
                        world[i+1][k] = emptyChar;

                    }else
                    {
                        world[i+1][k] = magicBoxChar;
                        world[i][k] = emptyChar;
                    }

                }

            }
        }

    }
}

CheckShotChar(char world[][W])
{
    for(int i =0 ; i < H; i++)
    {
        for(int k = 0; k< W;k++)
        {
            if(world[i][k]== shotChar)
            {

                if(i == 32)
                {
                    world[i][k]= emptyChar;
                }
                else if(world[i-1][k] == healtChar)
                {
                    world[i-1][k]= emptyChar;
                    world[i][k]= emptyChar;
                    healt++;
                }
                else if(world[i-1][k] == shotMultyChar)

                {
                    world[i-1][k]= emptyChar;
                    world[i][k]= emptyChar;
                    countShot++;

                }
                else if(world[i-1][k] == foodChar)
                {
                    int randInteger = rand() % 7;
                    if(3 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = shotMultyChar;
                    }
                    else if(2 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = healtChar;
                    }
                    else if (5 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = boombChar;

                    }else
                    {
                        world[i-1][k]= emptyChar;
                        world[i][k]= emptyChar;
                    }

                }else if(world[i-1][k] == magicBoxChar)
                {
                    int randInteger = rand() % 7;
                    if(3 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = shotMultyChar;
                    }
                    else if(2 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = healtChar;
                    }
                    else if (5 == randInteger)
                    {
                        world[i-1][k] = emptyChar;
                        world[i][k] = boombChar;

                    }else
                    {
                        world[i-1][k]= emptyChar;
                        world[i][k]= emptyChar;
                    }
                }
                else{
                    world[i-1][k]= shotChar;
                    world[i][k]= emptyChar;
                }

            }

        }
    }
}



void print(char world[][W],bool f)
{
    CheckShotMultyChar(world);
    CheckHealtChar(world);
    CheckBoombChar(world);
    CheckMagicBoxChar(world);
    ChangePositionFoods(world,f);
    CheckShotChar(world);
    for(int i =0 ; i < H; i++)
    {
        for(int k = 0; k< W;k++)
        {
            if(world[i][k] == shotChar)
            {
                SetConsoleTextAttribute(h,3);
            }
            else if(world[i][k] == healtChar)
            {
                SetConsoleTextAttribute(h,2);
            }else if(world[i][k] == boombChar)
            {
                SetConsoleTextAttribute(h,4);
            }else if(world[i][k] == shotMultyChar)
            {
                SetConsoleTextAttribute(h,9);
            }else if(world[i][k] == magicBoxChar)
            {
                SetConsoleTextAttribute(h,5);
            }
            else
            {
                SetConsoleTextAttribute(h,7);
            }
            cout << world[i][k];
        }
        cout<<endl;
    }

}

printHealt()
{

    SetConsoleTextAttribute(h,2);
    cout << char(9) << healtChar ;
    SetConsoleTextAttribute(h,7);
    cout << " : " << healt<< endl<<endl;
}

void printPosXPlayer(int &PosX)
{
    for(int i = 0; i < PosX;i++)
    {
        cout<< '-';
    }
    cout << "_/^\\_";
    for(int j = 0; j <  W - (PosX + 5);j++)
    {
        cout << '-';
    }
     cout << endl<<endl;
}

printGameOver()
{
        cout.clear();
    system("cls");
    for(int r = 0 ; r < W; r++)
    {
        cout << '#';
    }
    cout << endl;
    for(int f = 0 ; f < H - 6; f++)
    {
        cout << '#';
        if(f == H/2)
        {
            string tnkMSG =  "Thanks For Playing Game";
            int lenStr =  W - tnkMSG.size();
            for(int p = 0 ; p < lenStr / 2; p++)
            {
                cout<<' ';
            }

            cout << tnkMSG;
            for(int y = 0 ; y < (lenStr / 2) - 1; y++)
            {
                cout<<' ';
            }
            cout<< '#'<< endl;


            /////////////////////////////////

            cout << '#';
            string healtS = " ";
            healtS.push_back(healtChar);
            healtS+=(" : ");
            healtS+= to_string(healt);
            int lenHealtS = W - healtS.size();

            for(int q = 0 ; q < (lenHealtS / 2) - 2; q++)
            {
                cout<<' ';
            }
            cout << healtS;
            for(int y = 0 ; y < lenHealtS / 2; y++)
            {
                cout<<' ';
            }
        }

        else{

            for(int r = 0 ; r < W - 2; r++)
            {
                cout << ' ';
            }

        }

        cout<< '#';
        cout<<endl;

    }
    for(int a = 0 ; a < W; a++)
    {
        cout << '#';
    }

}

int main()
{
    char world[H][W] = {' '};
    char t;
    bool flag= false;
    int posXPlayer = (W / 2) - 2;


    fillFoodInGame(world);

    while(healt > 0)
    {

        if(_kbhit())
        {

            t = _getch();
            if(t == 'd')
            {
                if (!(posXPlayer > W - 4))
                    posXPlayer++;
            }
            if(t == 'a')
            {
                if(!(posXPlayer < 0))
                {
                    posXPlayer--;
                }
            }
            if(t == emptyChar)
            {
                for(int i =1; i<=countShot;i++ )
                {
                    if(world[H - 1 - i][posXPlayer + 2] == shotMultyChar)
                        {
                            countShot++;
                            world[H - 1 - i][posXPlayer + 2] = emptyChar;
                        }else
                        {
                            world[H - 1 - i][posXPlayer + 2] = shotChar;
                        }


                }
            }

            if(t == 'q')
            {
                break;
            }
        }

        cout.clear();
        flag = !flag;

        print(world,flag);

        printPosXPlayer(posXPlayer);
        printHealt();


        Sleep(300);


    }

    printGameOver();


    getchar();

    return 0;
}

