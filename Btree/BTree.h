#ifndef BTREE_H
#define BTREE_H

#include <iostream>
using namespace std;


template <class T,int n>
class BTree
{


struct node{

T* values;
int maxKeys;
int numberKeys;
node** childes;
bool leaf;
bool complete;

node(int max){
maxKeys=max;
numberKeys=0;
childes= new node*[maxKeys+1];
values= new T[maxKeys];

for(int i=0;i<maxKeys;i++){
    values[i]=-1;
}

for(int i=0;i<maxKeys+1;i++){
    childes[i]=nullptr;
}

this->leaf=true;
complete=false;
}


};


int order;

public:
node *root;
bool insert_second=false;

BTree(){
this->order=n;
root=nullptr;

}

void Insert(T value){

if(root==nullptr){
node *newNode= new  node(order-1);
root=newNode;
insert_helper(value,newNode);
}


else if(root->numberKeys==root->maxKeys&&insert_second){
int num=root->numberKeys+1;


T arr[num];
insert_plus(value,root,arr);

node* newNode= new node(order-1);
node* newNode3= new node(order-1);

insert_helper(arr[num/2],newNode);



for(int i=(num/2)+1;i<num;i++){

insert_helper(arr[i],newNode3);
}

for(int i=0;i<root->numberKeys;i++){
root->values[i]=-1;
}

root->numberKeys=0;

for(int i=0;i<num/2;i++){
insert_helper(arr[i],root);
}

newNode->childes[0]=root;
newNode->childes[1]=newNode3;
root=newNode;
root->leaf=false;
}

else{select(value,root);}
}

void insert_helper(T value , node * Node){

for(int i=0;i<Node->maxKeys;i++){

if(value>Node->values[i]&&Node->values[i]==-1){
Node->values[i]=value;
 break;
}

else if(value<Node->values[i]){
   for(int j=Node->maxKeys-1;j>=i;j--){
   if(Node->values[i]!=-1){
   Node-> values[j]=Node->values[j-1];
   }
   }

Node->values[i]=value;
break;
}

}

Node->numberKeys++;

if(root->numberKeys==root->maxKeys&&root->leaf){

 insert_second=true;

}
else{insert_second=false;}

}


void insert_plus(T value,node *Node,T arr[]){
bool in=true;
int k=0;
for(int i=0;i<Node->numberKeys+1;i++){

if(value<Node->values[k]&&in){
 arr[i]=value;
 in=false;
}
else{arr[i]=Node->values[k++];}

}

if(in){
arr[Node->numberKeys]=value;

}


}


void select(T value ,node * root){
if(root->leaf==true){
insert_helper(value,root);

}
else{
for(int i=0;i<root->numberKeys;i++){

if(value<root->values[i]){

if(root->childes[i]->numberKeys==root->childes[i]->maxKeys){
if(root->numberKeys==root->maxKeys){
int num=root->childes[i]->numberKeys+1;
T arr[num];
insert_plus(value,root->childes[i],arr);
insert_second=true;
Insert(arr[num/2]);
break;
}

else{
splite(root,root->childes[i],value,i);
break;
}
}

select(value,root->childes[i]);
break;
}

else if(value>root->values[i]&&i==root->numberKeys-1){
if(root->childes[i+1]->numberKeys==root->childes[i+1]->maxKeys){

splite(root,root->childes[i+1],value,i+1);
break;
}
 select(value,root->childes[i+1]);

    break;
}
}

}
}


void splite(node * root,node * myNode,T value ,int i){
int num=myNode->maxKeys+1;
T arr[num];

insert_plus(value,myNode,arr);

node * newNode= new node(order-1);

insert_helper(arr[num/2],root);

if(root->childes[i+1]!=0){
root->childes[i+2]=root->childes[i+1];
}
root->childes[i+1]=newNode;



for(int i=(num+1)/2;i<num;i++){
insert_helper(arr[i],newNode);
}
for(int i=0;i<myNode->numberKeys;i++){
myNode->values[i]=-1;
}

myNode->numberKeys=0;

for(int i=0;i<num/2;i++){
insert_helper(arr[i],myNode);
}


}


void print_helper(node * rootx){

 if(rootx==nullptr){return;}
if(rootx==root){
}
for(int i=0;i<rootx->numberKeys;i++){

cout<<rootx->values[i]<<" ";
}
cout<<endl;
int i=0;
for(int i=0;i<rootx->numberKeys+1;i++){
print_helper(rootx->childes[i]);
}

}


void Print(){
print_helper(root);

}


};

#endif // BTREE_H
