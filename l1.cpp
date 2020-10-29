#include<bits/stdc++.h>

using namespace std;

struct node{
    string info;
    node *link;
};

class fila{
    node *head=NULL, *tail, *a;
    int n = 0;
public:
    void enfileirar(string aux){
        a = new node;
        a-> info = aux;
        a -> link = NULL;
        if(head == NULL){
            head = a;
            tail = a;
            //cout << head->info << endl;                         
        }    
        else{
            tail->link = a;
            tail = a;
            //cout << tail-> info<<endl;
        }
        n++;
        //cout << n << endl;
    }

    bool desenfileirar(){
        if(head == NULL){
            cout << "NULL" << endl;
            return true;
        }
        a = head;
        head = head-> link;
        delete(a);
        n-=1;
        return false;
    }

    void show(){
        
        cout << head->info << endl;
    }  
    int num(){
        return n;
    } 
};

class stak{
    node *ptr,*top = NULL,*a;
    int pos = 0;
public:
    void push(string x){
    ptr = new node;
    ptr -> info = x;
    ptr -> link = NULL;
    if(top == NULL){
        top = ptr;                         
    }    
    else{
        ptr -> link = top;
        top = ptr;
    }
    pos++;
}
    bool pop();
    string show();
    int num();
    void pan();
};

/*void fila::enfileirar(string aux){
    a = new node;
    a-> info = aux;
    a -> link = NULL;
    if (head == NULL){
        head = a;
    }
    tail = a;
    n++;
}*/

/*bool fila::desenfileirar{
    if(head == NULL){
        cout << "NULL" << endl;
        return true;
    }
    a = head;
    head = head-> link;
    delete(a);
    n-=1;
    return false;
}*/

/*void fila::show(){
    cout << head->info << endl;
}*/

/*void fila::num(){
    cout << n << endl;
}*/

/*void stak::push(string x){
    ptr = new node;
    ptr -> info = x;
    ptr -> link = NULL;
    if(top == NULL){
        top = ptr;                         
    }    
    else{
        ptr -> link = top;
        top = ptr;
    }
    pos++;
}*/

bool stak::pop(){
    if(top == NULL)
    {
        cout << "NULL" << endl;
        return true;
    }
    a = top;
    top = top -> link;
    delete(a);
    pos -= 1;
    return false;  
    
}

string stak::show(){
    return top-> info;
}
int stak::num(){
    return pos;
}
void stak::pan(){
    while(pos != 0)
    {
        a = top;
        top = top -> link;
        delete(a);
        pos -= 1;
    }
    top = NULL;
}

void transfere(stak *history, fila *save){
    string aux;
    aux = history->show();
    save->enfileirar(aux);
}

int main(){

    string option;
    string aux;

    stak history;
    fila save;

    while (option != "END")
    {
        cin >> option;

        if (option ==  "END"){
            break;
        }
        else if(option == "OPN"){
            string url;
            cin >> url;
            history.push(url);
            int aux = history.num();
            cout << aux <<endl;
            
        }
        else if(option == "CUR"){
            aux = history.show();
            cout << aux << endl;
        }
        else if(option == "BCK"){
            history.pop();
            int aux = history.num();
            if (aux == 0){
                cout << "NULL" << endl;
            }
            else{
                string aaux=history.show();
                cout<< aaux << endl;
            }

        }
        else if(option == "PAN"){
            int aux = history.num();
            cout << aux << endl;
            history.pan();
        }
        else if(option == "SAV"){
            transfere(&history, &save);
            int aux = save.num();
            cout << aux << endl;
            //save.show();
        }
        else if(option == "REA"){
            save.show();
            save.desenfileirar();
        }
    }
    
    return 0;
}