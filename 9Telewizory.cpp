#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    int num_try, num_programs, first_min, sec_min, cost, start , end;
    deque <int> pom;
    int maks_odl;
    bool was_changed;
    deque <int>::iterator g;
    deque <int>::iterator pom_it;



    cin >> num_try;

    for(int i=0; i<num_try ; ++i){
        cost = 0;

        cin>>num_programs >> first_min >> sec_min;

        int * started = new int [num_programs];
        int * ended = new int [num_programs];

        if(sec_min>0){
            maks_odl = first_min/sec_min;
        }
        else{
            maks_odl = 1000000;
        }

        for(int j=0 ; j<num_programs ; ++j){
            cin>>start>>end;
            cost += (first_min+sec_min*(end-start));
            started[j]=start;
            ended[j]=end;
        }

        sort(started, started + num_programs);
        sort(ended, ended + num_programs);


        for(int j = 0 ; j<num_programs ; ++j){
            pom.push_back(ended[j]);
            was_changed=false;

            //czyszczenie z tych ktore juz sa nie potrzebne - wychodza poza maksymalna odleglosc
            while(started[j] - pom[0] > maks_odl){
                pom.erase(pom.begin());
            }
            //szukanie najodpowiedniejszego
            for(g = pom.begin(); g!=pom.end() ; ++g){
                if(started[j] - *g > 0 ){
                    pom_it = g;
                    was_changed=true;
                }
                else{
                    if(was_changed==true){
                        cost -= (first_min - (started[j] - *pom_it) * sec_min);
                        pom.erase(pom_it);
                    }
                    break;
                }
            }
        }
        //odpowiedz i czyszczenie pomocniczego vectora
        cout << cost << endl;
        pom.clear();
    }
    return 0;
}
