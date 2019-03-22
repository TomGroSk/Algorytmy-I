#include <iostream>
using namespace std;

struct root {
    int val;
    string name;
    root *next;
    root *prev;
};
struct Change {
    int x;
    int y;
};

class Flag {
public:
    bool flag;
    void setFlagFalse(){
        flag = false;
    }
    void setFlagTrue(){
        flag = true;
    }
    bool getFlag() const{
        return flag;
    }
};

struct sumy {
    int suma;
    sumy *prev;
    sumy *next;
};
class Sumy {
public:
    int counter;
    sumy *head;
    sumy *tail;
    sumy *current;

    Sumy() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        counter = 0;
    }

    ~Sumy() {
        sumy *pom = new sumy;
        for (int i = 0; i<counter; ++i) {
            pom = head;
            head = head->next;
            delete pom;
        }
    }
    void push_back(int element) {
        if (counter == 0) {
            sumy *pom = new sumy;
            pom->suma = element;
            head = tail = current = pom;
            pom->next = nullptr;
            pom->prev = nullptr;
            counter++;
        }
        else {
            sumy *pom = new sumy;
            pom->suma = element;
            tail->next = pom;
            pom->prev = tail;
            tail = pom;
            head->prev = tail;
            tail->next = head;
            counter++;
        }
    }
    void erase(int element) {
        sumy *pom = new sumy;
        pom = head;
        while (pom->suma != element) {
            pom = pom->next;
        }
        if (pom == head) {
            pom = head;
            tail->next = pom->next;
            pom->next->prev = tail;
            head = pom->next;
        }
        else if (pom == tail) {
            pom = tail;
            head->prev = pom->prev;
            pom->prev->next = head;
            tail = pom->prev;
        }
        else {
            pom->prev->next = pom->next;
            pom->next->prev = pom->prev;
        }
        delete pom;
        counter--;
    }
    bool empty() {
        if (counter == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void show() {
        sumy *pom = head;
        for (int i = 0; i<counter; ++i) {
            cout << pom->suma << endl;
            pom = pom->next;
        }
    }
    bool search(int element) {
        sumy *pom = new sumy;
        pom = head;
        for (int i = 0; i<counter; i++) {
            if (pom->suma == element) {
                return true;
            }
            pom = pom->next;
        }
        return false;
    }
};


class Lista {
public:
    int counter;
    root *head;
    root *tail;
    root *current;

    Lista() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        counter = 0;
    }

    ~Lista() {
        root *pom = new root;
        for (int i = 0; i<counter; ++i) {
            pom = head;
            head = head->next;
            delete pom;
        }
    }

    void push_back(int element, string name) {
        if (counter == 0) {
            root *pom = new root;
            pom->val = element;
            pom->name = name;
            head = tail = current = pom;
            pom->next = nullptr;
            pom->prev = nullptr;
            counter++;
        }
        else {
            root *pom = new root;
            pom->val = element;
            pom->name = name;
            tail->next = pom;
            pom->prev = tail;
            tail = pom;
            head->prev = tail;
            tail->next = head;
            counter++;
        }
    }
    void eraseCurr() {
        root *pom = new root;
        pom = current;
        if (pom == head) {
            tail->next = head->next;
            head->next->prev = tail;
            head = current = head->next;
            delete pom;
            counter--;
        }
        else if (pom == tail) {
            head->prev = tail->prev;
            tail->prev->next = head;
            tail = tail->prev;
            current = head;
            delete pom;
            counter--;
        }
        else {
            pom->prev->next = pom->next;
            pom->next->prev = pom->prev;
            current = pom->next;
            delete pom;
            counter--;
        }

    }
    void move(int step, int n) {
        if (empty() == true) { return; }
        else {
            if (step%n>0) {
                for (int i = 0; i<step%n; ++i) {
                    current = current->next;
                }
            }
            else if (step%n == 0) {
                return;
            }
            else {
                for (int i = step%n; i<0; ++i) {
                    current = current->prev;
                }
            }
        }
    }
    bool empty() {
        if (head->next == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
};
struct root2 {
    Lista *val;
    root2 *next;
    root2 *prev;
};

class PriorList {
public:
    int counter;
    root2 *head;
    root2 *tail;
    root2 *current;

    PriorList() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        counter = 0;
    }

    ~PriorList() {
        root2 *pom = new root2;
        for (int i = 0; i<counter; ++i) {
            pom = head;
            head = head->next;
            delete pom;
        }
    }

    void pushList(Lista *l) {
        if (counter == 0) {
            root2 *pom = new root2;
            pom->val = l;
            head = tail = current = pom;
            head->next = tail->next = nullptr;
            head->prev = tail->prev = nullptr;
            counter++;
        }
        else {
            root2 *pom = new root2;
            pom->val = l;
            tail->next = pom;
            pom->prev = tail;
            tail = pom;
            head->prev = tail;
            tail->next = head;
            counter++;
        }

    }

    bool empty() {
        if (counter == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void move(int step) {
        if (empty() == true) { return; }
        else {
            if (step%counter>0) {
                for (int i = 0; i<step%counter; ++i) {
                    current = current->next;

                }
            }
            else if (step%counter == 0) {
                return;
            }
            else {
                for (int i = step%counter; i<0; ++i) {
                    current = current->prev;

                }
            }
        }
    }
    int sum(bool flag, int suma, Change change[], PriorList *priorlist, int i, int l_zmian, Flag f) {
        int wynik;
        if(flag == true){
            root2 *pom = new root2;
            pom = head;
            wynik=0;
            for(int i = 0; i<counter; i++){
                if (pom->val->counter>0) {
                    wynik += pom->val->current->val;
                    pom = pom->next;
                }
                else {
                    pom->val->~Lista();
                }
            }
        }
        else{
            wynik=suma;
            if(i!=l_zmian && !priorlist->empty()){
                priorlist->move(change[i].x);
                wynik -= priorlist->current->val->current->val;
                priorlist->current->val->move(change[i].y, priorlist->current->val->counter);
            }
            else{
                wynik -= priorlist->current->val->current->val;
            }
            wynik += priorlist->current->val->current->val;
            f.setFlagTrue();
        }
        return wynik;
    }
    string show_name() {
        string name = "";
        root2 *pom = new root2;
        pom = head;
        for (int i = 0; i<counter; i++) {
            if (pom->val->counter>0) {
                name += pom->val->current->name;
                pom = pom->next;
            }
            else {
                pom->val->~Lista();
            }
        }
        return name;
    }
    void eraseList(PriorList *l) {
        int temp = counter;
        root2 *pom = new root2;
        pom = l->head;
        for (int i = 0; i<temp; i++) {
            if (pom->val->counter == 1 && counter>1) {
                if (pom->val == l->head->val) {
                    if (current == l->head) {
                        current = head->next;
                    }
                    tail->next = head->next;
                    head->next->prev = tail;
                    head = head->next;
                    pom->val->~Lista();
                    counter--;
                }
                else if (pom->val == l->tail->val) {
                    if (current == l->tail) {
                        current = head;
                    }
                    head->prev = tail->prev;
                    tail->prev->next = head;
                    tail = tail->prev;
                    pom->val->~Lista();
                    counter--;
                }
                else {
                    if (current == pom) {
                        current = pom->next;
                    }
                    pom->next->prev = pom->prev;
                    pom->prev->next = pom->next;
                    pom->val->~Lista();
                    counter--;
                }
            }
            else if (pom->val->counter == 1 && counter == 1) {
                l->~PriorList();
                counter = 0;
                break;
            }
            else {
                pom->val->eraseCurr();
            }
            pom = pom->next;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    int liczba_stempli, liczba_wynikowa, liczba_dyskow, l_kontrolne, nr_kontrolny, l_zmian, x,
        y, suma = 0, i;
    string name;
    Flag f;
    f.setFlagTrue();
    Sumy s;
    PriorList *priorlist = new PriorList();
    Lista *l;

    cin >> liczba_dyskow;

    for (i = 0; i <liczba_dyskow; ++i) {
        l = new Lista();
        cin >> liczba_stempli;
        for (int j = 0; j<liczba_stempli; j++) {
            cin >> name >> liczba_wynikowa;
            l->push_back(liczba_wynikowa, name);
        }
        priorlist->pushList(l);

    }

    cin >> l_kontrolne;

    for (i = 0; i<l_kontrolne; ++i) {
        cin >> nr_kontrolny;
        s.push_back(nr_kontrolny);
    }

    cin >> l_zmian;
    Change *change = new Change[l_zmian];
    for (i = 0; i < l_zmian; i++) {
        cin >> x >> y;
        change[i].x = x;
        change[i].y = y;
    }

    suma = priorlist->sum(f.flag,suma,change,priorlist,i,l_zmian, f);
    for (i = 0; i<l_zmian+1; ++i) {
        while (s.search(suma) != false) {
            cout << suma << " " << priorlist->show_name() << endl;
            priorlist->eraseList(priorlist);
            s.erase(suma);
            f.setFlagTrue();
            suma = priorlist->sum(f.flag,suma,change,priorlist,i,l_zmian,f);
        }
        f.setFlagFalse();
        suma = priorlist->sum(f.flag,suma,change,priorlist,i,l_zmian,f);
        if(priorlist->empty() == true){
            return 0;
        }
    }
    return 0;
}
