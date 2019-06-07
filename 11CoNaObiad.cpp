#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int searcher(int suma, int* kcal, int counter, int size, int final_kcal, int start){
    //int temp=0;
    for(int i=start; i<size ;++i){
        if(suma+kcal[i]==final_kcal){
            counter++;
            //temp=i+1;
        }
        else if (suma+kcal[i]<final_kcal){
            counter=searcher(suma+kcal[i], kcal, counter,size,final_kcal,i+1);
        }
    }
    return counter;
}



int main(){
    ios_base::sync_with_stdio(false);
    int l_progr, l_zestaw, calor, final_kcal;
    int counter;


    cin >> l_progr;
    for(int i=0;i<l_progr;++i){
        counter = 0;
        cin>>l_zestaw;
        int *kcal = new int[l_zestaw];

        for(int j=0; j<l_zestaw;++j){
            cin >> calor;
            kcal[j]=calor;
        }

        cin >> final_kcal;

        sort(kcal, kcal+l_zestaw, greater<int>());

        counter = searcher(0,kcal,counter,l_zestaw,final_kcal, 0);
        cout << counter << endl;
    }
    return 0;
}
