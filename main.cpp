#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("BDD.in");
unsigned int cod[100000];
double pret[100000];
int n, x;
char denumire[100][100], producator[100][100];
bool ok;

void Sterge() /// stergere
{
    int x, c = -1;
    cout << "Introduceti codul produsului pe care doriti sa-l stergeti: ";
    cin >> x;

    for (int i = 1; i <= n; i++)
        if (cod[i] == x)
            c = i;

    if (c == -1)
        cout << "Nu exista acest produs in baza de date!\n";
    else
    {
        for (int i = c; i <= n; i++)
        {
            cod[i] = cod[i + 1];
            cod[i]--;
            strcpy(denumire[i], denumire[i + 1]);
            strcpy(producator[i], producator[i + 1]);
            pret[i] = pret[i + 1];
        }
        n--;
    }
    for (int i = 1; i <= n; i++)
        cout << cod[i] << " " << denumire[i] << " " << pret[i] << " " << producator[i] << "\n";
    cout << "\n";
}

void C_cod() /// cautare dupa cod
{
    int x;

    cout << "Introduceti codul produsului: ";
    cin >> x;

    if (x <= n)
    {
        cout << "Exista un produs cu acest cod in baza de date!\n";
        cout << cod[x] << " " << denumire[x] << " " << pret[x] << " " << producator[x] << "\n";
    }
    else
        cout << "Codul nu exista in baza de date!\n";
    cout << "\n";
}

void C_pret() /// cautare dupa pret
{
    double x;
    int i;
    bool ok = 0;

    cout << "Introduceti pretul cautat: ";
    cin >> x;

    for (i = 1; i <= n; i++)
        if (pret[i] == x)
        {
            ok = 1;
            cout << cod[i] << " " << denumire[i] << " " << pret[i] << " " << producator[i] << "\n";
        }

    if (ok == 0)
        cout << "Nu exista un produs cu acest pret!\n";
    cout << "\n";
}

void C_den() /// cautare dupa denumire
{
    int i;
    bool ok = 0;
    char s[100], c[100];

    cout << "Introduceti numele produsului: ";
    cin >> s;

    for (int i = 0; i < strlen(s); i++)
        s[i] = tolower(s[i]);

    for (i = 1; i <= n; i++)
    {
        strcpy(c, denumire[i]);
        for (int j = 0; j < strlen(c); j++)
            c[j] = tolower(c[j]);
        if (strcmp(c, s) == 0)
        {
            ok = 1;
            cout << cod[i] << " " << denumire[i] << " " << pret[i] << " " << producator[i] << "\n";
        }
    }

    if (ok == 0)
        cout << "Nu exista acest produs!\n";
    cout << "\n";
}

void C_prod() /// cautare dupa producator
{
    bool ok = 0;
    char s[100], c[100];

    cout << "Introduceti numele producatorului: ";
    cin >> s;

    for (int i = 0; i < strlen(s); i++)
        s[i] = tolower(s[i]);

    for (int i = 1; i <= n; i++)
    {
        strcpy(c, producator[i]);
        for (int j = 0; j < strlen(c); j++)
            c[j] = tolower(c[j]);
        if (strcmp(c, s) == 0)
        {
            ok = 1;
            cout << cod[i] << " " << denumire[i] << " " << pret[i] << " " << producator[i] << "\n";
        }
    }

    if (ok == 0)
        cout << "Nu exista nici un produs de la acest producator!\n";
    cout << "\n";
}

void Afisare()
{
    int x;
    cout << "1. Afisare o inregistrare selectate\n";
    cout << "2. Afisarea intregii bazei de date\n";
    cout << "Optiune: ";
    cin >> x;
    cout << "\n";

    if (x == 1)
    {
        int c;
        cout << "Alegeti codul inregistrarii pe care doriti sa o afisati: ";
        cin >> c;
        if (c <= n)
            cout << cod[c] << " " << denumire[c] << " " << pret[c] << " " << producator[c] << "\n";
        else
            cout << "Nu exista aceasta inregistrare!\n";
    }
    else
        for (int i = 1; i <= n; i++)
            cout << cod[i] << " " << denumire[i] << " " << pret[i] << " " << producator[i] << "\n";
    cout << "\n";
}

int main()
{
    while (fin >> x)
    {
        n++;
        cod[n] = x; /// valori strict pozitive
        fin >> denumire[n];
        5 fin >> pret[n];
        fin >> producator[n];
    }
    while (ok == 0)
    {
        cout << "Alegeti o optiune!\n";
        cout << "1. Stergere din baza de date;\n";
        cout << "2. Cautati in functie de cod;\n";
        cout << "3. Cautati in functie de pret;\n";
        cout << "4. Cautati in functie de numele denumirea produsului;\n";
        cout << "5. Cautati in functie de numele producatorului;\n";
        cout << "6. Afisare.\n";
        cout << "7. Inchideti aplicatia;\n";
        cout << "Optiune: ";
        cin >> x;
        cout << "\n";

        if (x == 1)
            Sterge();
        else if (x == 2)
            C_cod();
        else if (x == 3)
            C_pret();
        else if (x == 4)
            C_den();
        else if (x == 5)
            C_prod();
        else if (x == 6)
            Afisare();
        else if (x == 7)
        {
            cout << "Inchidere...";
            break;
        }
        else
            cout << "Nu exista aceasta optiune!\n";
    }
    return 0;
}
