//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
//#include <cctype>
#include <limits>

using namespace std;

class Cplans
{
private:
    int p;
    int p1k;
    int p1w;
    int Liczn;

protected:

    vector<vector<char> > plans;
    bool Sprawd(int Lic);
    vector<vector<char> > pole(int p1, int Liczn1);

    public:
    void Wpro();
    void Druk();

    Cplans();

    ~Cplans();

};

Cplans::Cplans() : p(0), p1k(0), p1w(0), Liczn(0)
{
    for (int i = 0; i <3; i++)
        plans.push_back(vector<char>());

    for (char i = '1'; i <= '3'; i++)
        plans[0].push_back(i);
    for (char i = '4'; i <= '6'; i++)
        plans[1].push_back(i);
    for (char i = '7'; i <= '9'; i++)
        plans[2].push_back(i);
}

void Cplans::Druk()
{
    for (int i1 = 0; i1 < 3; i1++) {
        for (int j1 = 0; j1 <3; j1++) {
            cout<< " " <<plans[i1][j1];
        } cout <<endl;
    }
}

void Cplans::Wpro()
{
    int i = 0;
    for (; i<9; i++) {
        int p = 0;
        int *wLicz = &i;
        cout<<"Ktore pole? ";
        cin>>p;

        if (cin.good()) {
            if (p<1 || p>9) {cerr<<"\nZle pole!\nKtore pole? ";
                cin>>p;
        }
            if ((plans[(p-1)/3][(p-1)%3] == 'X') ||
                    (plans[(p-1)/3][(p-1)%3] == 'O')) {
                cerr<<"\nZle pole!\b "; p = 0; i--;
            } else {
                cout<<endl<<endl;
                system("cls");
                int *pws = &p;

                plans = (pole(*pws, *wLicz));
            }
            if (Sprawd(*wLicz)) break;
    }
        if (!cin.good()) { cout<<"Zly numer!\n ";
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
        }
     }
}

vector<vector<char> > Cplans::pole(int p1, int Liczn1)
{
    p1k = (p1-1)/3;
    p1w = (p1-1)%3;

    plans[p1k][p1w] = ((Liczn1 % 2 == 0) ? 'X' : 'O');

    for (int i = 0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<" "<<plans[i][j];


        } cout<<endl;

    }
    return plans;
}

bool Cplans::Sprawd(int Lic)
{
    vector<char> vl, vs, vp, v1, v2, v3, v4, v5;

    for (int i = 0; i < 3; i++) vl.push_back(plans[i][0]);
    for (int i = 0; i < 3; i++) vs.push_back(plans[i][1]);
    for (int i = 0; i < 3; i++) vp.push_back(plans[i][2]);
    for (int i = 0; i < 3; i++) v1.push_back(plans[0][i]);
    for (int i = 0; i < 3; i++) v2.push_back(plans[1][i]);
    for (int i = 0; i < 3; i++) v3.push_back(plans[2][i]);
    for (int i = 0; i < 3; i++) v4.push_back(plans[i][i]);

    v5.push_back(plans[0][2]);
    v5.push_back(plans[1][1]);
    v5.push_back(plans[2][0]);

    char Zn = ((Lic % 2 == 0) ? 'X' : 'O');

    if ( count(vl.begin(), vl.end(), Zn) == 3 ||
         count(vs.begin(), vs.end(), Zn) == 3 ||
         count(vp.begin(), vp.end(), Zn) == 3 ||
         count(v1.begin(), v1.end(), Zn) == 3 ||
         count(v2.begin(), v2.end(), Zn) == 3 ||
         count(v3.begin(), v3.end(), Zn) == 3 ||
         count(v4.begin(), v4.end(), Zn) == 3 ||
         count(v5.begin(), v5.end(), Zn) == 3 )
    {
        cout << "\n"<<Zn<<" WYGRAL!\n"<<endl;
        return true;
    }
    else {return false; }

}

Cplans::~Cplans()
{

}

int main ( int argc, char **argv)
{
     Cplans v;
     v.Druk();
     v.Wpro();
     cout<<"Jeszcze raz? \n";
     char T;
     cin>>T;
     if (T == 't') { system("cls");
         main(argc, argv); }
     else {
         if (T != 't') system("cls");
         return 0;
     }

     return 0;

//}

//int main(int argc, char *argv[])
//{
 //   QCoreApplication a(argc, argv);

  //  return a.exec();
}
