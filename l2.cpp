#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct atad{
    lli user;
    lli channel;
    int rank;
};

struct node{
    atad info;
    node *link;
};
void resize(lli *aux, int i){
    lli aux2[i*2];
    for(int j=0; j<i; j++){
        aux2[j]=aux[j];
    }
    aux = aux2;
}

class fila{
    int n = 0;

public:

    node *head=NULL, *tail, *a;
    void enfileirar(atad aux){
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
    void desenfileirar(lli aux){
        node *pointer, *b = NULL;
        pointer = head;
        if(pointer->info.user == aux){// garanto se a head = valor procurado
            a = pointer;
            pointer = pointer->link;
            head = pointer;
            n--;
            delete(a);
        }
        
        while(pointer != NULL && pointer->link != NULL){ // garanto seelem.meio == falor procurado
            if(pointer->link->info.user == aux){
                a = pointer->link;
                pointer->link = pointer->link->link;
                delete(a);
                n--;
            }
            pointer=pointer->link;
            b = pointer;
        }
        
         // se nao houver alteração na head ou meio da lista, confiro a tail
        pointer = tail;
        if(pointer != NULL && pointer->info.user == aux){
            a = tail;
            tail = b;
            delete(a);
            n--;
        }
    }
    /*void desim(lli user, lli *canal, int *k, bool ex) {
        node *pointer, *b = NULL;
        int v = 0;
        int j = 1;
        if(head == NULL){
            cout << 0 << endl;
            *k = v;
            return;
        }
        else{
            pointer = head;
            while(pointer != NULL){
                if(pointer->info.user == user){
                    if(pointer == tail){
                        tail = b;
                    }
                    if(ex == true){
                        if(v>j){
                            resize(canal, j);
                            j = j*2;
                        }
                        canal[v] = pointer->info.channel;
                        v++;
                    }
                    a = pointer;
                    pointer = pointer->link;
                    delete(a);
                    n--;
                }
                b = pointer;
                pointer = pointer->link;
            }
        }
        if(ex == true){
            *k = v;
        }
    }*/
    int num(){
        return n;
    }
};

struct table{
    fila a;
};

int posicao(lli num){
    return num%7793;
}
void sub2(lli user, lli channel,int rank, table *hashc){
    int pos = posicao(channel);

    if(hashc[pos].a.num()== 0){
        atad aux;
        aux.channel = channel;
        aux.rank = rank;
        aux.user = user;
        hashc[pos].a.enfileirar(aux); 
    }
    else{
        node *point = hashc[pos].a.head;
        while(point != NULL){
            if(point->info.channel == channel){
                if(point->info.user == user){
                    //cout << point->info.rank << endl;
                    point->info.rank = rank;
                    return;
                }
                else{
                    point = point->link;
                    continue;
                }
            }
            else{
                point = point->link;
            }
        }
        atad aux;
        aux.channel = channel;
        aux.rank = rank;
        aux.user = user;
        hashc[pos].a.enfileirar(aux);  
    }

}
void sub(lli user, lli channel,int rank, table *hashu){
    lli pos1 = posicao(user);

    if(hashu[pos1].a.num()== 0){
        atad aux;
        aux.channel = channel;
        aux.rank = rank;
        aux.user = user;
        hashu[pos1].a.enfileirar(aux);
        cout << rank << endl;
        return; 
    }
    else{
        bool e = false;
        node *point = hashu[pos1].a.head;
        while(point != NULL){
            if(point->info.user == user){
                if(point->info.channel == channel){
                    cout << point->info.rank << endl;
                    point->info.rank = rank;
                    e = true;
                    return;
                }
                else{
                    point = point->link;
                    continue;
                }
            }
            else{
                point = point->link;
            }
        }
        
        atad aux;
        aux.channel = channel;
        aux.rank = rank;
        aux.user = user;
        hashu[pos1].a.enfileirar(aux); 
        cout << rank <<endl;
        
        
    }
}

bool chn(table *hash, lli user){
    lli aux2 = posicao(user);
    node *pointer = hash[aux2].a.head;
    bool existe = false;
    while (pointer != NULL){
        if(pointer->info.user == user){
            cout << pointer->info.channel << " ";
            existe = true;
        }
        pointer = pointer->link;
    }
    if(existe == false){
        cout << '0' << endl;
        return false;
    } 
    return true;  
}

void usr(table *hash, lli channel){
    int i = 0;
    lli aux2 = posicao(channel);
    node *pointer = hash[aux2].a.head;
    while (pointer != NULL){
        if(pointer->info.channel == channel){
            i++;
        }
        pointer = pointer->link;
    }
    cout << i << endl;
}

void sco(table *hash, lli user, lli channel){
    lli aux1 = posicao(user);
    node *pointer = hash[aux1].a.head;
    while (pointer != NULL){
        if(pointer->info.user == user){
            if(pointer->info.channel == channel){
                cout << pointer->info.rank <<endl;
                return;
            }
            else{
                pointer = pointer->link;
            }
        }
        else{
            pointer = pointer->link;
        }
    }
    cout << '0' << endl;
    
}
void rmu(table *hashu, table *hashc, lli user){
    lli aux1 = posicao(user);
    node *aux;
    aux = hashu->a.head;
    while(aux != NULL){
        if(aux->info.user == user){
            lli aux2 = posicao(aux->info.channel);
            hashc[aux2].a.desenfileirar(user);
        }
        aux = aux->link;
    }
    hashu[aux1].a.desenfileirar(user);
    
}

int main(){

    string escolha;
    lli canal;
    lli usuario;
    int score;
    table usu[7793];
    table chan[7793];
    

    while (escolha != "END")
    {
        cin >> escolha;
        if(escolha == "END"){
            break;
        }
        if(escolha == "SUB"){
            cin >> usuario;
            cin >> canal;
            cin >> score;
            sub(usuario, canal, score, usu);
            sub2(usuario, canal, score, chan);
            //cout << usu[123].a.head->info.channel << endl;

        }
        if(escolha == "CHN"){
            cin >> usuario;
            if (chn(usu,usuario) == true){;
            cout << endl;
            }
        }
        if(escolha == "USR"){
            cin >> usuario;
            usr(chan, usuario);
        }
        if(escolha == "SCO"){
            cin >> usuario;
            cin >> canal;
            sco(usu, usuario, canal);

        }
        if(escolha == "RMU"){
            cin >> usuario;
            rmu(usu, chan, usuario);

        } 
    }
    
    
    return 0;
}