#include<bits/stdc++.h>
using namespace std;
long long int aft=0,ear=0,cor=0;
long long int is_sqrt(long long int p)
{
   long long int n=p;
   double test;
   test=sqrt(n);
   long long int t;
   t=test;
   if(t==test) return 1;
   else
   return 0;


}

long long int after_sq(long long int p)
{
  long long int n=(long long int)sqrt(p);
  aft=(n+1)*(n+1);
  //cout<<aft<<endl;

   return aft;
}

long long int early_sq(long long int p)
{
   long long int n=(long long int)sqrt(p);
   ear=n*n;
   //cout<<ear<<endl;
   return ear;
}

long long int corner(long long int p)
{
     cor=(aft+ear+1)/2;
    //cout<<cor<<endl;
    return cor;
}

 long long int af_sqr_cor(long long int p)
{
if(p<aft && p>cor)return 1;
else
    return 0;
}

 long long int er_sqr_cor(long long int p)
{

   if(p<cor && p>ear)return 1;
   else
    return 0;
}

int main()
{
    long long int  c,col,row;
    long long int t;
    cin>>c;
    for(long long int i=1;i<=c;i++)
    {
        cin>>t;
        after_sq(t);
      early_sq(t);
      corner(t);
      long long int n,m;
      long long int x=0;
      n=af_sqr_cor(t);
      m=er_sqr_cor(t);


        if(t%2==1 && is_sqrt(t)==1)
        {
            col=1;
            row=(long long int)sqrt(t);
        }
        else if(t%2==0 && is_sqrt(t)==1)
        {
            col=(long long int)sqrt(t);
            row=1;
        }
        else if(cor==t)
        {
            col=row=(long long int)sqrt(aft);

        }
        else if(aft%2==1 && n==1)
        {
            row=(long long int)sqrt(aft);
            col=aft-t+1;
        }
        else if(aft%2==1 && m==1)
        {
            //cout<<"MOON"<<endl;
            row=(long long int)sqrt(aft)-(cor-t);
            col=sqrt(aft);

        }
        else if(aft%2==0 && m==1)
        {
            row=(long long int )sqrt(aft);
            col=t-ear;
        }
        else if(aft%2==0 && n==1)
        {
            row=aft-t+1;
            col=(long long int)sqrt(aft);
        }
        cout<<"Case "<<i<<": "<<col<<" "<<row<<endl;

    }
    return 0;

}
