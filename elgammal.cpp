#include<iostream>
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
long int succ_exp(long int base,long int exp,long int N)
{
if (exp == 0)
return 1;
if (exp == 1)
return base % N;
long int t = succ_exp(base, exp / 2,N);
t = (t * t) % N;
if (exp % 2 == 0)
return t;
else
return ((base % N) * t) % N;
}
int main() {
cout<<"21BCE2717 "<<endl;
cout<<"-----------------"<<endl;
cout<<" "<<endl;
cout<<"Elgammal Cryptography "<<endl;
cout<<" "<<endl;


long int q,alpha,xa,M;
cout<<"Select a Prime Number: "<<endl;
cin>>q;
cout<<"Enter one primitive root: "<<endl;
cin>>alpha;
cout<<"Enter M value: "<<endl;
cin>>M;
cout<<" Choose private key [1 <x< (q-1)]: "<<endl;

cin>>xa;
long int ya=succ_exp(alpha,xa,q);
cout<<"Public key Ya is: "<<ya<<endl;


long int k;
cout<<"Choose random k value (1<k<q-1): "<<endl;
cin>>k;
long int K=succ_exp(ya,k,q);
cout<<"The value of K is: "<<K<<endl;
long int c1=succ_exp(alpha,k,q);
long int c2=((K*M)%q);
cout<<"M is encrypted as: ("<<c1<<","<<c2<<")"<<endl;
//Step3 Decryption
long int K_new=succ_exp(c1,xa,q);
cout<<"K value : "<<K_new<<endl;
long int M_new;
int ans=mul_inv_ext_eucl(q,K,0,1);
M_new=((c2*ans)%q);
cout<<"M value : "<<M_new<<endl;
if(M_new==M && K_new==K){
cout<<"ECC Successful! "<<endl;
}
else{
cout<<"ECC Failure! "<<endl;
}
return 0;
}
