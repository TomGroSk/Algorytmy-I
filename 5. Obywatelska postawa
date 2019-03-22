#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct root {
    vector<root *>child;
    int val;
};


list <int> preorder(root tree, unsigned int min, int counter){
    list <int> lista;
    if(counter>3){
        lista.push_back(tree.val);
        counter=0;
    }
    if(tree.child.size()+1>=min && counter>=2){
        lista.push_back(tree.val);
        counter=0;
    }
    counter++;


    for(unsigned int i=0 ; i<tree.child.size() ; i++){
        //preorder(*tree.child[i], min, counter);
//        for(int j: preorder(*tree.child[i], min, counter)){
//            lista.push_back(j);
//        }
        lista.merge(preorder(*tree.child[i], min, counter));
    }

    return lista;
}

int main()
{
    ios_base::sync_with_stdio(false);
    list <int> lista;
    root *pom = new root;
    root *pom2;
    int l_cross, a, b;
    unsigned int min_path;

    cin >> l_cross >> min_path;

    //tworzenie tablicy wskaznikow
    root **tree = new root*[l_cross];

    //zerowanie
    for (int i =0 ; i<l_cross ; i++){
        tree[i]=nullptr;
    }

    //podstawianie pierwszego elementu, root
    pom->val = 1;
    tree[0] = pom;

    //wstawianie
    for (int i = 0; i < l_cross - 1; i++) {
        cin >> a >> b;
        //gdy ojciec nie istnieje
        if (tree[a-1] == nullptr) {
            pom = new root;
            pom2 = new root;
            pom->val = a;
            tree[a-1] = pom;
            //gdy dziecko nie istnieje
            if (tree[b-1] == nullptr) {
                pom2->val = b;
                tree[b-1] = pom2;
                tree[a-1]->child.push_back(pom2);
            }
            //gdy dziecko istnieje
            else {
                pom2 = tree[b-1];
                tree[a-1]->child.push_back(pom2);
            }
        }
        //gdy ojciec istnieje
        else {
            //gdy dziecko nie istnieje
            pom2 = new root;
            if (tree[b-1] == nullptr) {
                pom2->val = b;
                tree[b-1] = pom2;
                tree[a-1]->child.push_back(pom2);
            }
            //gdy dziecko istnieje
            else {
                pom2 = tree[b-1];
                tree[a-1]->child.push_back(pom2);
            }
        }
    }
    //wrzucenie na sztywno kamery na ratusz
    cout << 1;
    //preorder
    lista = preorder(*tree[0], min_path, 0);
    lista.sort();
    for(int i: lista){
        cout <<" "<< i;
    }

    return 0;
}
