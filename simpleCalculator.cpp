#include<iostream>
using namespace std;
float simpleCal(float n1,float n2,char opt){
    switch(opt){
        case '+':
        return n1+n2;
        break ;
        case '-':
        return n1-n2;
        break;
        case '/':
        return n1/n2;
        break;
        case '*':
        return n1*n2;
        break;
    }
}
int main(){
    cout<<"\n-----------SIMPLE CALCULATOR-----------\n";
    float n1,n2;
    char opt;
    cout<<"enter first number n1 =";
    cin>>n1;
    cout<<"enter second number n2 =";
    cin>>n2;
    cout<<"enter operator (+) or (-) or (/) or (*) = ";
    cin>>opt;
    simpleCal(n1,n2,opt);
    cout<<"output:"<<endl<<" "<<n1<<" "<<opt<<" "<<n2<<"= "<<simpleCal(n1,n2,opt);
    return 0;
}




