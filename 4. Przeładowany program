#include <iostream>
#include <string>
using namespace std;
template <class T>
struct root {
    T val;
    root *next;
};
template <class T>
class Stos {
public:
    root <T> *head;
    int counter;
    Stos() {
        head = nullptr;
        counter = 0;
    }
    ~Stos(){
        for(int i=0;i<counter;i++){
            pop();
        }
    }
    void push(T element) {
        root <T> *pom = new  root <T>;
        pom->val = element;
        pom->next = head;
        head = pom;
        counter++;
    }
    void pop() {
        if (!empty()) {
            root <T> *pom = head;
            head= head->next;
            delete pom;
            counter--;
        }
    }
    bool empty() {
        if (counter == 0)return true;
        else return false;
    }
    T newestVal() {
        return head->val;
    }
};
template <class T>
class Kolejka {
public:
    root <T> *head = new root <T>;
    root <T> *tail = new root <T>;
    int counter;
    Kolejka() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }
    ~Kolejka(){
        for(int i=0;i<counter;i++){
            pop();
        }
    }
    void push(T element) {
        root <T> *pom = new root <T>;
        pom->val = element;
        if(empty()){
            pom->next=nullptr;
            head = tail = pom;
        }
        else{
            tail->next=pom;
            tail=pom;
        }
        counter++;
    }
    void pop() {
        if(counter>0){
            root <T> *pom = head;
            head = head->next;
            delete pom;
            counter--;
        }
    }
    bool empty() {
        if (counter == 0)return true;
        else return false;
    }
    T currentVal() {
        return head->val;
    }
};
bool check(string rownanie) {

    //sprawdzanie nawiasow

    Stos <char> s;
    unsigned int i = 0;
    while (rownanie[i] != '\0') {
        if (rownanie[i] == '(' || rownanie[i] == '[' || rownanie[i] == '{') {
            s.push(rownanie[i]);
        }
        else if (!s.empty() && ((rownanie[i] == ')' && s.newestVal() == '(') || (rownanie[i] == ']' && s.newestVal() == '[') || (rownanie[i] == '}' && s.newestVal() == '{'))) {
            s.pop();
        }
        else if (!s.empty() && ((rownanie[i] == ')' && s.newestVal() != '(') || (rownanie[i] == ']' && s.newestVal() != '[') || (rownanie[i] == '}' && s.newestVal() != '{'))) {
            return false;
        }
        else if (s.empty() && (rownanie[i] == ')' || rownanie[i] == ']' || rownanie[i] == '}' || rownanie[i] == ' ')) {
            return false;
        }
        i++;
    }

    if (s.empty() == true) {
        return true;
    }
    else {
        return false;
    }
}
Kolejka <string> conversiONP(string rownanie){
    Kolejka <string> kolejka;
    Stos <string> stos;
    string pomo;
    for (unsigned int i = 0; i < rownanie.size(); i++) {
        if (isdigit(rownanie[i])) {
            pomo = rownanie[i];
            while (isdigit(rownanie[i + 1])) {
                pomo += rownanie[i + 1];
                i++;
            }
            kolejka.push(pomo);
        }
        else if (rownanie[i] == '(' || rownanie[i] == '[' || rownanie[i] == '{') {
            pomo = rownanie[i];
            stos.push(pomo);
        }
        else if (rownanie[i] == ')') {
            while (stos.newestVal() != "(") {
                pomo = stos.newestVal();
                kolejka.push(stos.newestVal());
                stos.pop();
            }
            stos.pop();
        }
        else if (rownanie[i] == ']') {
            while (stos.newestVal() != "[") {
                kolejka.push(stos.newestVal());
                stos.pop();
            }
            stos.pop();
        }
        else if (rownanie[i] == '}') {
            while (stos.newestVal() != "{") {
                kolejka.push(stos.newestVal());
                stos.pop();
            }
            stos.pop();
        }
        else if (rownanie[i] == '*' || rownanie[i] == '/') {
            pomo = rownanie[i];
            while (stos.empty() != true && (stos.newestVal() == "*" || stos.newestVal() == "/")) {
                kolejka.push(stos.newestVal());
                stos.pop();
            }
            stos.push(pomo);
        }
        else if (rownanie[i] == '+' || rownanie[i] == '-') {
            pomo = rownanie[i];
            while (stos.empty() != true && (stos.newestVal() == "*" || stos.newestVal() == "/" || stos.newestVal() == "+" || stos.newestVal() == "-")) {
                kolejka.push(stos.newestVal());
                stos.pop();
            }
            stos.push(pomo);
        }
    }
    while (!stos.empty()) {
        if (stos.newestVal() == "*" || stos.newestVal() == "/" || stos.newestVal() == "+" || stos.newestVal() == "-") {
            kolejka.push(stos.newestVal());
            stos.pop();
        }
    }
    stos.~Stos();
    return kolejka;
}

double countingONP(string rownanie) {
    Stos <double> stos;
    Kolejka <string> kolejka = conversiONP(rownanie);
    double a, b;

    while (!kolejka.empty() || (stos.counter > 1 && kolejka.counter > 1)) {
        if (isdigit(kolejka.currentVal()[0])) {
            stos.push(stol(kolejka.currentVal()));
            kolejka.pop();
        }
        else {
            b = stos.newestVal();
            stos.pop();
            a = stos.newestVal();
            stos.pop();
            if (kolejka.currentVal() == "+") {
                stos.push(a + b);
            }
            else if (kolejka.currentVal() == "-") {
                stos.push(a - b);
            }
            else if (kolejka.currentVal() == "/") {
                stos.push(a / b);
            }
            else if (kolejka.currentVal() == "*") {
                stos.push(a*b);
            }
            kolejka.pop();
        }
    }
    kolejka.~Kolejka();
    return stos.newestVal();
}
int main()
{

    ios_base::sync_with_stdio(false);

    string rownanie;
    int liczba_rownan;
    cin >> liczba_rownan;

    for (int i = 0; i < liczba_rownan; i++) {
        cin >> rownanie;
        if (check(rownanie) == true) {
            cout<<countingONP(rownanie)<<"\n";
        }
        else {
            cout << "BLAD\n";
        }
    }

    return 0;
}
