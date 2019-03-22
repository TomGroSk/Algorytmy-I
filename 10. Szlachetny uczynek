#include <iostream>
#include <vector>
using namespace std;

struct wiktor{
    vector <int> neigh;
};

int** way_to;
wiktor *graph;
int dfs(int curr_pack, int end, int max_pack, int curr_pkt){
    curr_pack++;
    if(curr_pack>=max_pack && curr_pkt!=end){
        return 0;
    }
    else if(curr_pack==max_pack && curr_pkt==end){
        return 1;
    }


    if(way_to[curr_pkt][curr_pack]==0){
        return 0;
    }
    else if(way_to[curr_pkt][curr_pack]==-123){
       way_to[curr_pkt][curr_pack]=0;
    }
    else if(way_to[curr_pkt][curr_pack]>0){
        return way_to[curr_pkt][curr_pack];
    }


    for(unsigned int i=0; i<graph[curr_pkt].neigh.size();i++){
        way_to[curr_pkt][curr_pack]+=dfs(curr_pack, end, max_pack, graph[curr_pkt].neigh[i]);
    }
    return way_to[curr_pkt][curr_pack];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int l_test, wierzch, route, last, pack, r1, r2;

    cin >> l_test;
    for(int i=0;i<l_test;++i){
        cin >> wierzch >> route >> last >> pack;

        graph = new wiktor[wierzch];
        way_to = new int *[wierzch];

        for(int j=0;j<wierzch;j++){
            way_to[j] = new int[pack+1];
            for(int g=0;g<pack;g++){
                way_to[j][g] = -123;
            }
        }

        for(int j=0;j<route;j++){
            cin >> r1 >> r2;
            graph[r1].neigh.push_back(r2);
        }

        dfs(-1, last, pack, 0);
        cout << way_to[0][0] << endl;
        delete [] graph;
    }
    return 0;
}
