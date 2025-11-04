#include<bits/stdc++.h>
using namespace std;
  int add(int a,int b){
     int carry;
     while(b!=0){
        carry=a&b;
        a=a^b;
        b=carry<<1;
      }
      return a;
}
int subs(int a,int b){
       b=~b+1;
       int carry;
     while(b!=0){
        carry=a&b;
        a=a^b;
        b=carry<<1;
      }
      return a;
}
int mult(int p,int q){
    q=q-1;
    int ans=p;
  while(q--){
    ans=add(ans,p);
  }
  return ans;
}
int divs(int p,int q){
    int ans=0;
    while(p>=q){
        p=subs(p,q);
        ans++;
    }
    return ans;
 }
  int rem(int p,int q){
    int ans=0;
    while(p>=q){
        p=subs(p,q);
    }
    return p;
 }
  int main(){
   int x,y;
   cin>>x>>y;
   cout<<"Addition is "<<add(x,y)<<endl;
   cout<<"Substraction is "<<subs(x,y)<<endl;
    if(x>=y){
    cout<<"Multiplication is "<<mult(x,y)<<endl;
   }
   else cout<<mult(y,x)<<endl;

    if(x<0) x=x*(-1);
   if(y<0) y=y*(-1);
   if(x<0||y<0)cout<<"Quotient is "<<(-1)*divs(x,y)<<endl;
   else cout<<"Division is "<<divs(x,y)<<endl;
   cout<<"Remainder is "<<rem(x,y)<<endl;
  }