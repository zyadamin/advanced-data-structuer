#include <iostream>
using namespace std;
class element
{
public:

  char  str[50];
  int group;
  int index;

element (){

for(int i=0;i<50;i++){

 str[i]='\0';

}


}

bool equal(element x,int k){
int base=2;

for(int i=0;i<k-1;i++){
base*=base;
}

if(k==0){base=1;}

for(int i=0;i<base;i++){
if(this->str[i]!=x.str[i]){
    return false;
}
}

return true;
}

};
class SuffixArray
{
element *arr;
int size;
public:

SuffixArray(char chars[]){

int size=0;
while(chars[size]!='\0'){
 size++;
}

arr = new element[size];
this->size=size;
for(int i=0;i<size;i++){
element temp;
int k=0;
for(int j=i;j<size;j++){
temp.str[k++]=chars[j];
}
temp.index=i;
this->arr[i]=temp;
}

}



void help(int k){
bool in =false;

for(int j=0;j<size-1;j++){

for(int i=0;i<size-1;i++){

compare(arr[i],arr[i+1],k);
}
}

arr[0].group=1;
for(int i=1;i<size;i++){

if(arr[i].equal(arr[i-1],k)){
arr[i].group=arr[i-1].group;
}
else{
arr[i].group=arr[i-1].group+1;
}
}

for(int i=0;i<size-1;i++){
if(arr[i].group==arr[i+1].group){
    in=true;
}
}
if(in){help(k+1);}
}




void ConstructUsingPrefixDoubling(){
help(0);

}


void Print(){

for(int i=0;i<size;i++){
 cout<<arr[i].index<<endl;


}
}

void compare(element &x,element &y, int k){
int base=2;
if(x.group==y.group||k==0){

for(int i=0;i<k-1;i++){
base*=base;
}

if(k==0){base=1;}

for(int i=k;i<base;i++){
if(x.str[i]>y.str[i]){
element temp=x;
x=y;
y=temp;
break;
}

}

}
}

};
int main()
{


SuffixArray x("ACGACTACGATAAC$");

x.ConstructUsingPrefixDoubling();
x.Print();

    return 0;
}
