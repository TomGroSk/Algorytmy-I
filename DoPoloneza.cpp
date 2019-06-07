#include <iostream>

using namespace std;

struct uczn{
    string kod;
    unsigned int metraz;
    int miesiac_uro;
    double srednia;
};


int main()
{
    ios_base::sync_with_stdio(false);
    int n,j, warunek_wyjsc1 , warunek_wyjsc2;
    char c1,c2,c3;
    uczn temp;

    cin >>n;
    cin >> c1 >> c2 >> c3;

    uczn *tab1 = new uczn[n];
    uczn *tab2 = new uczn[n];

    cin >> tab1[0].kod >> tab1[0].srednia >> tab1[0].metraz >> tab1[0].miesiac_uro >> tab2[0].kod
            >> tab2[0].srednia >> tab2[0].metraz >> tab2[0].miesiac_uro;

    for(int i=1;i<n;++i){
        cin >> tab1[i].kod >> tab1[i].srednia >> tab1[i].metraz >> tab1[i].miesiac_uro >> tab2[i].kod
                >> tab2[i].srednia >> tab2[i].metraz >> tab2[i].miesiac_uro;
        j=i;
        if(c1=='s'){
            warunek_wyjsc1=0;
            warunek_wyjsc2=0;
            while(j>0){

                if(warunek_wyjsc1==0 && tab1[j].srednia > tab1[j-1].srednia){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='m' && tab1[j].srednia == tab1[j-1].srednia && tab1[j].miesiac_uro > tab1[j-1].miesiac_uro){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='m' && tab1[j].srednia == tab1[j-1].srednia && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].metraz > tab1[j-1].metraz){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='d' && tab1[j].srednia == tab1[j-1].srednia && tab1[j].metraz > tab1[j-1].metraz){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='d' && tab1[j].srednia == tab1[j-1].srednia && tab1[j].metraz == tab1[j-1].metraz && tab1[j].miesiac_uro > tab1[j-1].miesiac_uro){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0){
                    warunek_wyjsc1++;
                }

                if(warunek_wyjsc2==0 && tab2[j].srednia > tab2[j-1].srednia){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='m' && tab2[j].srednia == tab2[j-1].srednia && tab2[j].miesiac_uro > tab2[j-1].miesiac_uro){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='m' && tab2[j].srednia == tab2[j-1].srednia && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].metraz > tab2[j-1].metraz){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='d' && tab2[j].srednia == tab2[j-1].srednia && tab2[j].metraz > tab2[j-1].metraz){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='d' && tab2[j].srednia == tab2[j-1].srednia && tab2[j].metraz == tab2[j-1].metraz && tab2[j].miesiac_uro > tab2[j-1].miesiac_uro){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 ){
                    warunek_wyjsc2++;
                }

                if(warunek_wyjsc1==1 && warunek_wyjsc2==1){
                    break;
                };

                --j;
            }
        }
        else if(c1=='d'){
            warunek_wyjsc1=0;
            warunek_wyjsc2=0;
            while(j>0){

                if(warunek_wyjsc1==0 && tab1[j].metraz > tab1[j-1].metraz){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='m' && tab1[j].metraz == tab1[j-1].metraz && tab1[j].miesiac_uro > tab1[j-1].miesiac_uro){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='m' && tab1[j].metraz == tab1[j-1].metraz && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].srednia > tab1[j-1].srednia){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='s' && tab1[j].metraz == tab1[j-1].metraz && tab1[j].srednia > tab1[j-1].srednia){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='s' && tab1[j].metraz == tab1[j-1].metraz && tab1[j].srednia == tab1[j-1].srednia && tab1[j].miesiac_uro > tab1[j-1].miesiac_uro){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0){
                    warunek_wyjsc1++;
                }


                if(warunek_wyjsc2==0 && tab2[j].metraz > tab2[j-1].metraz){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='m' && tab2[j].metraz == tab2[j-1].metraz && tab2[j].miesiac_uro > tab2[j-1].miesiac_uro){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='m' && tab2[j].metraz == tab2[j-1].metraz && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].srednia > tab2[j-1].srednia){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='s' && tab2[j].metraz == tab2[j-1].metraz && tab2[j].srednia > tab2[j-1].srednia){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='s' && tab2[j].metraz == tab2[j-1].metraz && tab2[j].srednia == tab2[j-1].srednia && tab2[j].miesiac_uro > tab2[j-1].miesiac_uro){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0){
                    warunek_wyjsc2++;
                }

                if(warunek_wyjsc1==1 && warunek_wyjsc2==1){
                    break;
                };

                --j;
            }
        }
        else{
            warunek_wyjsc1=0;
            warunek_wyjsc2=0;
            while(j>0){
                if(warunek_wyjsc1==0 && tab1[j].miesiac_uro > tab1[j-1].miesiac_uro){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='d' && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].metraz > tab1[j-1].metraz){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='d' && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].metraz == tab1[j-1].metraz && tab1[j].srednia > tab1[j-1].srednia){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='s' && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].srednia > tab1[j-1].srednia){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0 && c2=='s' && tab1[j].miesiac_uro == tab1[j-1].miesiac_uro && tab1[j].srednia == tab1[j-1].srednia && tab1[j].metraz > tab1[j-1].metraz){
                    temp = tab1[j];
                    tab1[j]=tab1[j-1];
                    tab1[j-1]=temp;
                }
                else if(warunek_wyjsc1==0){
                    warunek_wyjsc1++;
                }


                if(warunek_wyjsc2==0 && tab2[j].miesiac_uro > tab2[j-1].miesiac_uro){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='d' && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].metraz > tab2[j-1].metraz){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='d' && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].metraz == tab2[j-1].metraz && tab2[j].srednia > tab2[j-1].srednia){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='s' && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].srednia > tab2[j-1].srednia){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0 && c2=='s' && tab2[j].miesiac_uro == tab2[j-1].miesiac_uro && tab2[j].srednia == tab2[j-1].srednia && tab2[j].metraz > tab2[j-1].metraz){
                    temp = tab2[j];
                    tab2[j]=tab2[j-1];
                    tab2[j-1]=temp;
                }
                else if(warunek_wyjsc2==0){
                    warunek_wyjsc2++;
                }

                if(warunek_wyjsc1==1 && warunek_wyjsc2==1){
                    break;
                };

                --j;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout << tab1[i].kod << " " << tab2[i].kod << " ";
    }
    return 0;
}
