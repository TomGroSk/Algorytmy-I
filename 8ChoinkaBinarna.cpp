#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct elem{
    int value;
    elem *left;
    elem *right;
    elem(){
        value=0;
        left=nullptr;
        right=nullptr;
    }
};
static int wc;

vector <int> postorder(elem *tab, vector <int> wiktor, int len){
    vector <int> left;
    vector <int> right;
    //postorder -> schodzimy na sam dol drzewka
    if(tab->left){
        left = postorder(tab->left,wiktor, len);
    }

    if(tab->right){
        right = postorder(tab->right,wiktor, len);
    }
    //sprawdzanie czy wartosc jest sama w sobie rowna dlugosci
    if(tab->value==len){
        wc++;
    }
    //jak mniejsza to wrzucamy do wiktora, jak 0 tzn ze albo nie warto albo root
    if(tab->value<len && tab->value!=0){
        wiktor.push_back(tab->value);
    }
    //sprawdzamy czy pojedynczo zsumowane nie daja dlugosci
    int sum;
    for(unsigned int i=0; i<left.size() ; i++){
        for(unsigned int j=0; j<right.size() ;j++){
            sum = left[i] + right[j];
            if(sum == len){
                wc++;
            }
        }
    }
    //do lewego dodajemy obecnego, jak mniejszy tzn ze sie przyda -> wrzucamy do wiktora
    for(unsigned int i=0; i<left.size() ; i++){
        left[i] += tab->value;
        if(left[i]==len){
            wc++;
        }
        if(left[i]<len){
            wiktor.push_back(left[i]);
        }
    }
    //to samo co wyzej tylko dla prawej strony drzewka
    for(unsigned int i=0; i<right.size() ; i++){
        right[i] += tab->value;
        if(right[i]==len){
            wc++;
        }
        if(right[i]<len){
            wiktor.push_back(right[i]);
        }
    }
    //przekazujemy wiktora wyzej
    return wiktor;
}

int main(){
    ios_base::sync_with_stdio(false);

    int tests, lengt, elements, value;
    elem **tab;
    elem *pom;

    cin>>tests;
    for(int i=0;i<tests;i++){
        cin >> elements >> lengt;

        vector <int> wiktor;
        wc = 0;
        tab = new elem*[elements+1];

        for(int j=1;j<elements+1; j++){
            cin>>value;
            pom = new elem;
            pom->value = value;
            tab[j] = pom;
            //tworzenie elementow i ich wartosci
        }
        for(int j=1;j<elements+1; j++){
            if(2*j+1 < elements+1){
                tab[j]->left = tab[2*j+1];
            }
            if(2*j+2 < elements+1){
                tab[j]->right = tab[2*j+2];
            }
            //przypisywanie lewego i prawego - ktore sa zawsze o 2*x miejsc dalej (2*x+1 - lewy | 2*x+2 - prawy)
        }

        pom = new elem;
        if(elements>=2){
            pom->left=tab[1];
            pom->right=tab[2];
        }
        else if(elements>=1){
            pom->left=tab[1];
        }
        tab[0]=pom; //tworzenie roota

        postorder(tab[0] ,wiktor, lengt);

        cout << wc << endl;
    }

    return 0;
}
