#include <bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    int deep;
    node *right;
    node *left;
};

node* left(node *pointer){
    node *tmp = pointer->right;
    pointer->right = tmp->left;
    tmp->left = pointer;
    return tmp;
}
node* right(node *pointer) {
    node *tmp = pointer->left;
    pointer->left = tmp->right;
    tmp->right = pointer;
    return tmp;
}
node* minValuenode(node* a){  
    node* current = a;  
    while (current->left != NULL)  
        current = current->left;  

    return current;  
}
node* rotation(node *r, int value){
    if(r == NULL || r->value == value){
        return r;
    }
    else if(value > r->value){
        r->right = rotation(r->right, value);
        r = left(r);
        return r;
    }
    else if(value < r->value){
        r->left = rotation(r->left, value);
        r = right(r);
        return r;
    }
    else{
        return NULL;
    }
}
class tree{
    public:
    node *aux, *root = NULL, *pointer;

    node* del(node *root, int val){  
        if (root == NULL)  
            return root;  

        if ( val < root->value )  
            root->left = del(root->left, val);  

        else if( val > root->value )  
            root->right = del(root->right, val);  

        else
        {  
            if( (root->left == NULL) || (root->right == NULL) )  
            {  
                node *temp = root->left ?  root->left : root->right;  
                if (temp == NULL)  
                {  
                    temp = root;  
                    root = NULL;  
                }  
                else{
                *root = *temp;
                free(temp); 
                }
            }  
            else
            {   
                node* temp = minValuenode(root->right);  
                root->value = temp->value;  
                root->right = del(root->right, temp->value);  
            }  
        }  
    
        //if (root == NULL)  
        return root;  
    }

    int insert(int value){
        int deep = 0;
        aux = new node;
        aux->value = value;
        if(root == NULL){
            aux->left = NULL;
            aux->right = NULL;
            root = aux;
            return deep;
        }
        else{
            pointer = root;
            while(1){

                if(pointer->value == value){
                    return deep;
                }
                else if(value <= pointer->value){
                    if(pointer->left == NULL){
                        aux->right = NULL;
                        aux->left = NULL;
                        pointer->left = aux;
                        deep++;
                        return deep;
                    }
                    else{
                        pointer = pointer->left;
                        deep++;
                        continue;
                    }
                }
                else{
                    if(pointer->right == NULL){
                        aux->right = NULL;
                        aux->left = NULL;
                        pointer->right = aux;
                        deep++;
                        return deep;
                    }
                    else{
                        pointer = pointer->right;
                        deep++;
                        continue;
                    }
                }
            }
        }
    }
    int find2(int value, int *aux){
        node *aux2 = root;
        int i=0;
        if(root->value == value){
            return i;
        }
        else{
            while(1){
                if(value > aux2->value){
                    if(aux2->right != NULL){
                        if(aux2->right->value == value){
                            *aux = aux2->value;
                            return i;
                        }
                        else{
                            aux2 = aux2->right;
                            i++;
                            continue;
                        }
                    }
                    else{
                        *aux = i;
                        return -1;
                    }
                }
                else if(value < aux2->value){
                    if(aux2->left != NULL){
                        if(aux2->left->value == value){
                            *aux = aux2->value;
                            return i;
                        }
                        else{
                            aux2 = aux2->left;
                            i++;
                            continue;
                        }
                    }
                    else{
                        *aux = i;
                        return -1;
                    }
                }
            }
        }
    }
    int find(int value, int *a){
        int i = -1;
        pointer = root;
        while(1){
            i++;
            if(pointer->value == value){
                return i;
            }
            else if(value > pointer->value){
                if(pointer->right != NULL){
                    pointer = pointer->right;
                    continue;
                }
                else{
                    *a = i;
                    return -1;
                }
                
            }
            else if(value< pointer->value){
                if(pointer->left != NULL){
                    pointer = pointer->left;
                    continue;
                }
                else{
                    *a = i;
                    return -1;
                }
            }
        }
    }
};

int main(){
    string option;
    int val, aux, a;
    tree bst;

    while (option != "END"){
        cin >> option;

        if(option == "END"){
            break;
        }
        if(option == "FND"){
            a = 0;
            cin >> val;
            aux = bst.find(val, &a);
            if(aux != -1){
                bst.root = rotation(bst.root, val);
                cout << aux << endl;
            }
            else{

                cout << a+1 << endl;
            }
            a = 0;
        }
        if(option == "INS"){
            cin >> val;
            aux = bst.insert(val);
            bst.root = rotation(bst.root, val);
            cout << aux << endl;
        }
        if(option == "DEL"){
            cin >> val;
            a = 0;
            if(bst.root->value == val){
                bst.del(bst.root, val);
                cout << 0 << endl;
            }
            else{
                aux = bst.find2(val, &a);
                if(aux == -1){
                    cout << a+1 << endl;
                }
            
                else{
                    cout << aux+1 << endl;
                    bst.del(bst.root, val);
                    bst.root = rotation(bst.root, a);

                }
            }
            
        }
        if(option == "ROOT"){
            cout << bst.root->value << endl;
            if(bst.root->left != NULL) cout << "esquerda " << bst.root->left->value << endl;
            if(bst.root->right != NULL) cout << "direita " << bst.root->right->value << endl;
        }
    }

    return 0;
}