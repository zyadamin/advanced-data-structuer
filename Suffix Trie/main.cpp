#include <iostream>

using namespace std;

struct listNode{
char value='\0';
listNode*next=nullptr;
};

class linkedList{



public:
int length=0;
listNode* start=nullptr;

void insert(char value){
listNode* newNode = new listNode();
newNode->value=value;

if(start==nullptr){
start=newNode;
}
else{
listNode* cur=start;

while(cur->next!=nullptr){
  cur=cur->next;

}

cur->next=newNode;

}

length++;
}

void print(){
listNode* cur=start;

while(cur!=nullptr){
cout<<cur->value<<" ";
    cur=cur->next;

}

}

int search(char x[]){
listNode* cur=start;
int count=0;

int size=0;
while(x[size]!='\0'){
 size++;
}

while(cur!=0&&count<size){
    if(cur->value==x[count]){count++;}
    else{break;}
     cur=cur->next;
}

if(count>0){return count;}
else{return 0;}
}

void delet(listNode* x){
listNode *cur=start;
while(cur->next!=nullptr){
  if(cur->next==x){
    cur->next=x->next;
       delete x;
          length--;

      break;

  }
  cur=cur->next;
}



}


};
struct trieNode{

linkedList object;
trieNode*childs[50];
int number;

trieNode(int number){
this->number=number;

for(int i=0;i<50;i++){
childs[i]=nullptr;
}

}

};

class suffixTrie{


public:
trieNode* root;

suffixTrie(char chars[]){
int size=0;
while(chars[size]!='\0'){
 size++;
}
root= new trieNode(-1);

for(int i=0;i<size;i++){
      char Ins[size];
      for(int t=0;t<size+1;t++){
        Ins[t]='\0';
      }
      int k=0;
    for(int j=i;j<size;j++){
     Ins[k++]=chars[j];
  }
insert(Ins,i);
}



}


void insert_hlper(char value[],int number,trieNode* root){

trieNode* newNode = new trieNode(number);

int i=0;
int found=0;
while(root->childs[i]!=nullptr){
found=root->childs[i]->object.search(value);
if(found>0){break;}
i++;
}

int size=0;
while(value[size]!='\0'){
 size++;
}

if(found==0){

for(int j=0;j<size;j++){
newNode->object.insert(value[j]);
}
root->childs[i]=newNode;

}

else{

if(root->childs[i]->object.length>found){
trieNode* second= new trieNode(root->childs[i]->number);

listNode* first=root->childs[i]->object.start;
 for(int i=0;i<found-1;i++){
  first=first->next;
 }

while(first->next!=nullptr){
second->object.insert(first->next->value);
root->childs[i]->object.delet(first->next);
}

int k=0;
while(root->childs[i]->childs[k]!=nullptr){
second->childs[k]=root->childs[i]->childs[k];
root->childs[i]->childs[k]=nullptr;
k++;
}

root->childs[i]->childs[0]=second;
root->childs[i]->number=-1;
}

char temp[size];
for(int j=0;j<size+1;j++){
temp[j]='\0';

}
int k=0;

for(int j=found;j<size;j++){
temp[k++]=value[j];
}

insert_hlper(temp,number,root->childs[i]);

}


}

void insert(char value[] ,int number){

insert_hlper(value,number,root);

}

void search_helper(trieNode* root,char x[]){

if(root==nullptr){return;}

int found=root->object.search(x);
int size=0;
while(x[size]!='\0'){
 size++;
}

if(this->root!=root){
if(found==0&&size!=0){
return;
}
}

char temp[size];
for(int i=0;i<size+1;i++){
  temp[i]='\0';
}

int k=0;
for(int i=found;i<size;i++){
temp[k++]=x[i];
 }
size=0;
while(temp[size]!='\0'){
 size++;
}

if(size==0&&root->number>=0){cout<<root->number<<endl;}


int j=0;
while(root->childs[j]!=nullptr){
search_helper(root->childs[j],temp);

j++;
}


}
void search(char x[]){
search_helper(root,x);
}


void print(trieNode* root){

if(root==nullptr){return;}

root->object.print();
cout<<root->number<<endl;
cout<<endl;
int j=0;
while(root->childs[j]!=nullptr){
print(root->childs[j]);

j++;
}

}



};
int main()
{

 //char  z[30]="bananabanaba";
 suffixTrie x("bananabanaba");


  x.search("ana");
  x.search("naba");
 // x.print(x.root);
    return 0;
}
