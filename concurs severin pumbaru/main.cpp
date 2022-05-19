#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int x, y, a, z, s, ok1 = 1, x1 = 0, w = 1, bet = 0, credit, variabila = 0;
    char ok, c = '1';
    cout << "CREDIT = "; cin >> credit; cout << endl;
    srand(time(0));
    cout << "0 < BET <= credit" << endl;
    while (c == '1' && credit > 0)
    {
        variabila = 0;
        cout << "BET = "; cin >> bet;
        if (bet > credit) {
            cout << "NU POTI PARIA MAI MULT DECAT AI! " << credit;
            return 0;
        }
        if (bet < 0) {
            cout << "NU POTI PARIA SUME MAI MICI DE 0! " << credit;
            return 0;
        }
        x = 0;
        y = (rand() % 10) + 1;
        if (y == 1) { y = 11; variabila++; }
        cout << "PRIMUL JUCATOR" << endl;
        x = y;
        cout << y << " + ";
        z = (rand() % 10) + 1;
        if (x <= 10) z = 11;
        x = x + z;
        cout << z << " = " << x << endl;
        z = (rand() % 10) + 1;
        if (z == 1) z = 11;
        x1 = 0;
        s = (rand() % 10) + 1;
        if (x1 <= 10) s = 11;
        cout << "CASINO " << endl << z << " ? " << endl;
        x1 = s + z;
        w = 1;
        if (x < 21)cout << "HIT? YES(1) NO(2)" << endl;
        else if (x == 21) cout << endl << "BLACKJACK (" << x << ")";
        while (x < 21 && ok1 == 1)
        {
            cout << "HIT ";
            cin >> ok;
            if (ok == '1') {
                a = (rand() % 10) + 1;
                if (x <= 10) a = 11;
                cout << "AI PRIMIT " << a << " ";
                x = x + a;
                if (x == 21) cout << "AI SCORUL " << x << " BLACKJACK" << endl;
                else cout << "AI SCORUL " << x << endl;
            }
            else if (ok == '2') {
                cout << endl << "NICE (" << x << ")";
                ok1 = 0;
            }
            else cout << "HIT? YES(1) NO(2) " << "SCOR " << x << endl;
            if (x == 21) {
                cout << endl << "NICE (" << x << ")";
                ok1 == 0;
            }
        }
        ok1 = 1;
        if (x > 21) {
            cout << endl << "BUSTED (" << x << ")";
            w = 0;
        }
        cout << endl;
        if (w == 1) {
            cout << "CASINO " << endl << z << " " << s << " SCORE " << x1 << endl;
            while (x1 < x)
            {
                a = (rand() % 10) + 1;
                if (x1 <= 10) a = 11;
                x1 = x1 + a;
                cout << a << " " << x1 << endl;
            }
            if (x1 == x)            w = 2;
            if (x1 > x && x1 <= 21)  w = 0;
            if (x1 > x && x1 > 21)  w = 1;
            if (w == 2) cout << "EGALITATE " << endl;
            if (w == 0) cout << "CASINO A CASTIGAT " << bet << endl;
            if (w == 1) cout << "AI CASTIGAT " << bet << endl;
        }
        if (w == 2)  cout << "CREDIT = " << credit << endl;
        if (w == 0) {
            credit = credit - bet;
            cout << "CREDIT = " << credit << endl;
        }
        if (w == 1) {
            credit = credit + bet;
            cout << "CREDIT = " << credit << endl;
        }
        if(credit>0){cout<<"CONTINUE? YES(1) NO(2) ";
                     cin>>c;
                     if (c == '1') {
                        cout << " OK! ";
                        cout << endl;
                                  }
                     if(c=='2'){cout<<" CREDIT="<<credit;
                                return 0;}
                    }
        if (credit == 0) {
            cout << "AI PIERDUT TOTI BANII" << endl << "Ai vrea sa continui?" << endl;
            cout << "ADD CREDIT? YES(1) NO(2) "; cin >> c; cout << endl;
            if (c == '1') {
                cout << "Credit= ";
                cin >> credit;
                cout << endl;
            }
            else return 0;
        }

    }
    return 0;/// trebuie sa adaug variabila care numeroteaza de cate ori a fost asul 11 si cand scorul trece peste 21 sa scada 10 din scor si 1 din variabila if(variabila!=0 && scor>21) {scor=scor-10+carte; variabila--}
             /// ar fi calumea sa adaug un cnt care sa imi arate de cate ori am castigat/pierdut
}
