#include <iostream>
using namespace std;
struct Strykt{
    string nazwa_auta;
    unsigned long long int przebieg;
};
int main()
{
    ios_base::sync_with_stdio(false);
    Strykt temp[3];
    int j, g;
    long double p, n;
    unsigned long long int przestawiak, wynik, d;
    string nazwa_samochodu;

    cin>>n;

    for(int i =0;i<3;++i){
        getline(cin, nazwa_samochodu);
        getline(cin, nazwa_samochodu);
        cin>>p>>d;
        wynik = p*1000/(3.141593*d*2.54*0.01);
        temp[i].przebieg = wynik;
        temp[i].nazwa_auta = nazwa_samochodu;
    }

    for (int i=1;i<3;++i){
        przestawiak = temp[i].przebieg;
        nazwa_samochodu = temp[i].nazwa_auta;
        j = i-1;
        while (j >= 0 && temp[j].przebieg > przestawiak){
            temp[j+1].przebieg = temp[j].przebieg;
            temp[j+1].nazwa_auta = temp[j].nazwa_auta;
            j = j-1;
        }
        temp[j+1].przebieg = przestawiak;
        temp[j+1].nazwa_auta = nazwa_samochodu;
    }

    if(temp[0].przebieg==temp[1].przebieg || temp[1].przebieg==temp[2].przebieg){
        for(int i=0;i<2;++i){
            if(temp[0].nazwa_auta>temp[1].nazwa_auta && temp[0].przebieg==temp[1].przebieg){
                przestawiak = temp[1].przebieg;
                nazwa_samochodu = temp[1].nazwa_auta;
                temp[1].przebieg = temp[0].przebieg;
                temp[1].nazwa_auta = temp[0].nazwa_auta;
                temp[0].przebieg = przestawiak;
                temp[0].nazwa_auta = nazwa_samochodu;
            }
            if(temp[1].nazwa_auta>temp[2].nazwa_auta && temp[1].przebieg==temp[2].przebieg){
                przestawiak = temp[2].przebieg;
                nazwa_samochodu = temp[2].nazwa_auta;
                temp[2].przebieg = temp[1].przebieg;
                temp[2].nazwa_auta = temp[1].nazwa_auta;
                temp[1].przebieg = przestawiak;
                temp[1].nazwa_auta = nazwa_samochodu;
            }
        }
    }

    for(int i=3;i<n;++i){
        getline(cin, nazwa_samochodu);
        getline(cin, nazwa_samochodu);
        cin>>p>>d;
        wynik = p*1000/(3.141593*d*2.54*0.01);
        for(j=0;j<3;++j){
            if((temp[j].przebieg == wynik && temp[j].nazwa_auta.compare(nazwa_samochodu)>0) || (temp[j].przebieg > wynik)){
                g=2;
                for(int k=0;k<2-j;k++){
                    temp[g].przebieg = temp[g-1].przebieg;
                    temp[g].nazwa_auta = temp[g-1].nazwa_auta;
                    g--;
                }
                temp[j].przebieg = wynik;
                temp[j].nazwa_auta = nazwa_samochodu;
                break;
            }
        }
    }


    cout << temp[0].nazwa_auta << endl << temp[0].przebieg << endl;
    cout << temp[1].nazwa_auta << endl << temp[1].przebieg << endl;
    cout << temp[2].nazwa_auta << endl << temp[2].przebieg << endl;
    return 0;
}
