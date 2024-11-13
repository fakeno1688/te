#include<bits/stdc++.h>
using namespace std;
class array2{
private:
int *mem;//pointer to array
int size;
int length;
public:
array2(int s){
    size=s;
    length=0;
    mem=new int [s];
}
int get_length(){
    return length;
}
int get_size(){
    return size;
}
void fill(){
int num_of_elements;
cout<<"num_of_elements :";
    cin>>num_of_elements;
if(num_of_elements>size){
    cout<<"error: cannot fill array with more elements than its size \n";
    return;
}else{
for(int i=0;i<num_of_elements;i++){
length++;
cout<<i+1<<"-your element is ::";
    cin>>mem[i];
    cout<<"\n";
}
}
}
void display(){
for (int i=0;i<length;i++){
    cout<<"element num "<<i+1<<" ::"<<mem[i]<<"  \n";
}
}
int sreach(){
cout<<"please enter the key  ::";
int key;
cin>>key;
int start=0;
int end=length-1;
while(start<=end)
{
   int mid=(start+end)/2;
    if(mem[mid]==key){
        cout<<"element found at index :: "<<mem[mid]<<"\n";
        return mid;
    }
    else if(mem[mid]>=key){
end=mid-1;
}
else{
    start=mid+1;
}
}
return -1;
}
~array2(){
cout<<"program is end\n";
    delete [] mem;
}





};
int main(){
array2 x(10);
x.fill();
x.display();
cout <<x.sreach();




}