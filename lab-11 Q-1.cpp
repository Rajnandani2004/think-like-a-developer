#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};


int getheight(struct node* p){
    if(p==NULL)
    return 0;
    return p->height;
}


struct node* createnode(int x){
    node* p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    return p;
}


int max(int a, int b){
return (a>b)?a:b;
}


int balencefector(struct node *p){
    if(p==NULL){
    return 0;
    }
    return getheight(p->left)-getheight(p->right);
}


struct node* rightrotat(struct node* n){
struct node* x=n->left;
struct node* t2=x->right;
x->right=n;
n->left=t2;
x->height=max(getheight(x->left),getheight(x->right))+1;
n->height=max(getheight(n->left),getheight(n->right))+1;
return x;
}


struct node* leftrotat(struct node* n){
    struct node* x=n->right;
    struct node* t1=x->left;
    x->left=n;
    n->right=t1;
    x->height=max(getheight(x->left),getheight(x->right))+1;
    n->height=max(getheight(n->left),getheight(n->right))+1;
return n;
}


struct node* insert(struct node* n, int x)
{
    if(n==NULL)
    return NULL;
    if(x<n->data)
    n->left=insert(n->left,x);
    else if(x>n->data)
    n->right=insert(n->right,x);
    n->height=1+max(getheight(n->left),getheight(n->right));
    int bf=balencefector(n);
    //ll
    if(bf>1 && x<n->left->data)
    return rightrotat(n);
    //rr
    if(bf<-1 && x>n->right->data)
    return leftrotat(n);
    //lr
    if(bf>1 && x>n->left->data){
    n->left=leftrotat(n->left);
    return rightrotat(n);}
    //rl
    if(bf<-1 && x<n->right->data){
    n->right=rightrotat(n->right);
    return leftrotat(n);
    }
    return n;
}


void inorder(struct node* n){
    if(n!=NULL)
    {
        inorder(n->left);
        cout<< n->data<<" ";
        inorder(n->right);
    }
}


int main(){
    struct node* r=NULL;
    r=insert(r,3);
    r=insert(r,8);
    r=insert(r,5);
    r=insert(r,2);
    r=insert(r,10);
    inorder(r);
    return 0;
}
