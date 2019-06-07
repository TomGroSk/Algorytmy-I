#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct elem {
    vector<int>neigh;
    bool isGreen;
    bool isRed;
    int prevGreen;
    int prevRed;
    bool shouldGreen;
    bool shouldRed;
    bool firstGreen;
    bool firstRed;
    elem(){
        prevGreen = -1;
        prevGreen = -1;
        isGreen = false;
        isRed = false;
        shouldGreen = false;
        shouldRed = false;
        firstGreen = false;
        firstRed = false;
    }
};
struct struktbfs{
    int index;
    bool zielony;
    bool czerwony;
    struktbfs(){
        zielony=false;
        czerwony=false;
    }
};

void reverseQueue(queue<int>& kolejka)
{
    stack<int> stos;
    while (!kolejka.empty()) {
        stos.push(kolejka.front());
        kolejka.pop();
    }
    while (!stos.empty()) {
        kolejka.push(stos.top());
        stos.pop();
    }
}

void path(elem graph[], int start, int end){
    queue <int> kolejka;
    bool pom = false;
    kolejka.push(end);
    do{
        if(pom == true && (graph[end].isGreen==true && graph[end].isRed==true)){
            kolejka.push(graph[end].prevGreen);
            end = graph[end].prevGreen;
            pom = false;
        }
        if(pom == false){
            kolejka.push(graph[end].prevRed);
            end = graph[end].prevRed;
            pom = true;
        }
        else{
            kolejka.push(graph[end].prevGreen);
            end = graph[end].prevGreen;
            pom = false;
        }
    }while(graph[end].prevGreen!=start);


    kolejka.push(start);
    reverseQueue(kolejka);
    while (!kolejka.empty()) {
        cout << kolejka.front() << " ";
        kolejka.pop();
    }
    cout<<endl;
}



bool circle(elem graph[], int wierzcholek, char *table){
    table[wierzcholek] = 'P';
    for(unsigned int i=0;i<graph[wierzcholek].neigh.size();i++){
        if(table[graph[wierzcholek].neigh[i]]=='P'){
            return true;
        }
        if(table[graph[wierzcholek].neigh[i]]=='S' && circle(graph, graph[wierzcholek].neigh[i], table)){
            return true;
        }
    }
    table[wierzcholek] = 'E';
    return false;
}
bool cyclic(elem graph[], int all){
    char *table = new char [all];
    for(int i=0 ; i<all ; i++){
        table[i] = 'S';
    }
    for(int i=0 ; i<all ; i++){
        if(table[i] =='S' && circle(graph, i, table)){
            return true;
        }
    }
    return false;
}

bool BFS(elem graph[], int start, int all){
    if(graph[start].neigh.size()==0){
        cout<<"TAK"<<endl<<start<<endl;
        return true;
    }
    queue <struktbfs> kolejka;
    struktbfs pomo;
    struktbfs neighpom;
    int pom;

    pomo.index=start;
    pomo.zielony=true;
    pomo.czerwony=false;
    kolejka.push(pomo);

    graph[start].isGreen = true;
    graph[start].firstGreen = true;

    while(!kolejka.empty()){
        pomo = kolejka.front();
        kolejka.pop();
        for(unsigned int i=0; i<graph[pomo.index].neigh.size();i++){
            pom = graph[pomo.index].neigh[i];
            if(pomo.zielony==true && graph[pom].isRed==false){
                graph[pom].isRed=true;

                graph[pom].prevGreen=pomo.index;
                if(graph[pom].firstGreen==false && graph[pom].firstRed==false){
                    graph[pom].firstGreen=true;
                }

                neighpom.index=pom;
                neighpom.czerwony=true;
                neighpom.zielony=false;
                kolejka.push(neighpom);

            }
            else if(pomo.czerwony==true && graph[pom].isGreen==false){
                graph[pom].isGreen=true;


                graph[pom].prevRed=pomo.index;
                if(graph[pom].firstGreen==false && graph[pom].firstRed==false){
                    graph[pom].firstGreen=true;
                }


                if(graph[pom].neigh.size()==0){
                    cout << "TAK" << endl;
                    path(graph,start,pom);
                    return true;
                }

                neighpom.index=pom;
                neighpom.czerwony=false;
                neighpom.zielony=true;
                kolejka.push(neighpom);
            }
        }
    }
    if(cyclic(graph,all)==true){
        cout << "REMIS" << endl;
        return false;
    }
    else{
        cout << "NIE" << endl;
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tests, num_fields, num_paths,root, x, y;

    cin >> tests;
    for(int i=0; i<tests ; i++){

        cin>>num_fields>>num_paths>>root;

        //deklaracja tablicy
        elem *graph = new elem[num_fields];
        //pobieranie i tworzenie grafu
        for(int j=0;j<num_paths;j++){
            cin >> x >> y;
            graph[x].neigh.push_back(y);
        }
        for(int j=0;j<num_fields;j++){
            sort(graph[j].neigh.begin(), graph[j].neigh.end());
        }
        BFS(graph, root, num_fields);
        delete [] graph;
    }

    return 0;
}
