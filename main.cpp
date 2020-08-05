#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n=3;
bool gameover=false;
void proverka(char pole[][n])
{
    int d=0;
    for (int i=0; i<n; i++)
    {
        for (int s=0; s<n-1; s++)
        {
            if (pole[i][s]==pole[i][s+1] && pole[i][s]!='_')
            {
                d++;
            }
        }
        if (d==n-1)
        {
            gameover=true;
            if (pole[i][0]=='x')
            {
                cout<<"Win x!";
            }
            else
                cout<<"Win o!";
        }
        d=0;
    }
    if (gameover==true)
    {
        return;
    }
    d=0;
    for (int i=0; i<n; i++)
    {
        for (int s=0; s<n-1; s++)
        {
            if (pole[s][i]==pole[s+1][i] && pole[s][i]!='_')
            {
                d++;
            }
        }
        if (d==n-1)
        {
            gameover=true;
            if (pole[0][i]=='x')
            {
                cout<<"Win x!";
            }
            else
                cout<<"Win o!";
        }
        d=0;
    }
    if (gameover==true)
    {
        return;
    }
    d=0;
    for (int i=0; i<n-1; i++)
    {
        if (pole[i][i]==pole[i+1][i+1] && pole[i][i]!='_')
        {
            d++;
        }
    }
    if (d==n-1)
    {
        gameover=true;
        if (pole[0][0]=='x')
        {
            cout<<"Win x!";
        }
        else
            cout<<"Win o!";
    }
    if (gameover==true)
    {
        return;
    }
    d=0;
    for (int i=n-1; i>0; i--)
    {
        if (pole[i][n-1-i]==pole[i-1][n-i] && pole[i][n-i-1]!='_')
        {
            d++;
        }
    }
    if (d==n-1)
    {
        gameover=true;
        if (pole[n-1][0]=='x')
        {
            cout<<"Win x!";
        }
        else
            cout<<"Win o!";
    }
}
pair <int, int> botturn(char pole[][n])
{
    int kletka,o=0;
    pair<int, int> p;
    while (pole[p.first][p.second]!='_' || o==0)
    {
        kletka=rand()%(n*n);
        p.first=kletka%n;
        p.second=kletka/n;
        o++;
    }
    return p;
}
int main()
{
    srand (time(NULL));
    int a,b,c,e=0,player1, player2;
    char pole[n][n];
    pair<int, int> g;
    a=1;
    for (int i=0; i<n; i++)
    {
        for (int s=0; s<n; s++)
        {
            pole[i][s]='_';
        }
    }
    cin>>player1;
    cin>>player2;
    system ("cls");
    for (int i=0; i<n; i++)
    {
        for (int s=0; s<n; s++)
        {
            cout<<pole[i][s]<<" ";
        }
        cout<<endl;
    }
    while (!gameover && e<n*n)
    {
        if (a==1)
        {
            if (player1==0)
            {
                cout<<"turn x:";
                cin>>b>>c;
                while (b<0 || c<0 || b>=n || c>=n || pole[b][c]!='_')
                {
                    cout<<"bad turn try again:";
                    cin>>b>>c;
                }
                pole[b][c]='x';
            }
            else
            {
                g=botturn(pole);
                pole[g.first][g.second]='x';
            }
            a++;
        }
        else
        {
            a=1;
            if (player2==0)
            {
                cout<<"turn o:";
                cin>>b>>c;
                while (b<0 || c<0 || b>=n || c>=n || pole[b][c]!='_')
                {
                    cout<<"bad turn try again:";
                    cin>>b>>c;
                }
                pole[b][c]='o';
            }
            else
            {
                g=botturn(pole);
                pole[g.first][g.second]='o';
            }
        }
        system ("cls");
        for (int i=0; i<n; i++)
        {
            for (int s=0; s<n; s++)
            {
                cout<<pole[i][s]<<" ";
            }
            cout<<endl;
        }
        e++;
        proverka(pole);
    }
    if (!gameover)
    {
        cout<<"draw";
    }
    else
        return 0;
}
