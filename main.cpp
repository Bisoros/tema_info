#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream in("aplicatii.in");

//declararea structurilor si variabilelor globale
struct data
{
    unsigned short zi, luna, an;
};

struct aplicatie
{
    char denumire[100];
    unsigned dimensiune;
    data data_lansare;
};

aplicatie aplicatii[100];
unsigned n = 0, i = 0;

//functia de afisare detaliata
void afisare_detalii(aplicatie x)
{
    cout << "Denumire: " << x.denumire << endl
    << "Dimensiune: " << x.dimensiune << endl
    << "Data lansare: " << x.data_lansare.zi << '.' << x.data_lansare.luna << '.' << x.data_lansare.an << endl;
}

//functia comparator pentru sortarea lexicografica
bool lexicografic(aplicatie a, aplicatie b)
{
    return strcmp(a.denumire, b.denumire) < 0;
}

//functie de comparare a doua date
bool comp_data(data x, data y)
{
    if (x.an == y.an)
    {
        if (x.luna == y.luna)
            return x.zi <= y.zi;
        else
            return x.luna < y.luna;
    }
    else
        return x.an < y.an;
}

int main()
{
    //1
    while (!in.eof())
    {
        in >> aplicatii[n].denumire >> aplicatii[n].dimensiune >> aplicatii[n].data_lansare.zi
        >> aplicatii[n].data_lansare.luna >> aplicatii[n].data_lansare.an;
        n++;
    }
    n--;

    //2
    cout << "Aplicatii: ";
    sort(aplicatii, aplicatii + n, lexicografic);
    for (i = 0; i < n; i++)
        cout << aplicatii[i].denumire << ' ';
    cout << endl;

    //3
    cout << endl <<"Aplicatii care incap pe un card SD de 1GB: ";
    for (i = 0; i < n; i++)
        if(aplicatii[i].dimensiune <= 1000)
            cout << aplicatii[i].denumire << ' ';
    cout << endl;

    //4
    cout << endl << "Aplicatii dezvoltate in API 24 sau mai nou: ";
    data x = {22, 8, 2016};
    for (i = 0; i < n; i++)
        if(comp_data(x, aplicatii[i].data_lansare))
            cout << aplicatii[i].denumire << ' ';
    cout << endl;

    //5
    cout << endl << "Aplicatia cu dimensiune maxima:" << endl;
    aplicatie aux = aplicatii[0];
    for (i = 1; i < n; i++)
        if (aplicatii[i].dimensiune > aux.dimensiune)
            aux = aplicatii[i];
    afisare_detalii(aux);
    cout << endl;

    //6
    cout << "Aplicatia cea mai recenta:" << endl;
    for (i = 0; i < n; i++)
        if (comp_data(aux.data_lansare, aplicatii[i].data_lansare))
            aux = aplicatii[i];
    afisare_detalii(aux);
    cout << endl;

    //7
    cout << "Vectorul fara aplicatia minima: " << endl;
    int min = 0;
    for (i = 1; i < n; i++)
        if (aplicatii[min].dimensiune > aplicatii[i].dimensiune)
            min = i;
    for (int i = min; i < n; ++i)
        aplicatii[i] = aplicatii[i + 1];
    n--;
    for (i = 0; i < n; i++)
            cout << aplicatii[i].denumire << ' ';
    cout << endl;

    //8
    cout << endl << "Aplicatia favorita: " << endl;
    strcpy(aplicatii[n].denumire, "Reddit");
    aplicatii[n].dimensiune = 50;
    x = {8, 12, 2017};
    aplicatii[n].data_lansare = x;
    n++;
    afisare_detalii(aplicatii[n-1]);

    return 0;
}
