#include <iostream>
using namespace std;
int mul_inv_ext_eucl(int r1,int r2,int t1,int t2){
int term1=r1;
int q=r1/r2;
int r=r1%r2;
int t=t1-(q*t2);
while(r!=0){
r1=r2;
r2=r;
q=r1/r2;
r=r1%r2;
t1=t2;
t2=t;
t=t1-(t2*q);
}
int ans=t2;
if(ans<0){
ans=ans+term1;
}
return ans;
}
int main() {
int P,a,b;
cout<<"21BCE2717 "<<endl;
cout<<"-----------------"<<endl;
cout<<" "<<endl;
cout<<"Point Doubling (2P) "<<endl;
cout<<" "<<endl;
cout << "Enter P value: " << endl;
cin >> P;
cout << "Enter a value: " << endl;
cin >> a;
cout << "Enter b value: " << endl;
cin >> b;
cout << "Enter x and y coordinates: " << endl;
int x1, y1;
cin >> x1 >> y1;
int num=((3*x1*x1)+a);
int den=2*y1;
int ans=mul_inv_ext_eucl(P,den,0,1);
if(den<0){
ans=P-((ans*num)%P);
}
else{
ans=(ans*num)%P;
}
int x3=((ans*ans)-x1-x1);
if(x3<0){
x3=P-((-1*x3)%P);
}
else{
x3=x3%P;
}
int y3=(ans*(x1-x3))-y1;
if(y3<0){
y3=P-((-1*y3)%P);
}
else{
y3=y3%P;
}
cout<<"The values of 2G are: "<<endl;
cout << "(" << x3 << "," << y3 << ")" << endl;
return 0;
}

