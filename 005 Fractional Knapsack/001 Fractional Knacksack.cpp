#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

bool compare(pii p1,pii p2){

    double v1 = (double)p1.ff/p1.ss;
    double v2 = (double)p2.ff/p2.ss;

    return v1>v2;
}

int main(){

int n;
cout<<"Number of Items : ";
cin>>n;

vii a(n); //container for value and weight

rep(ii,0,n){ //using rep for input
cout<<"Enter value for item "<<ii+1<<" : ";
cin>>a[ii].ff;
cout<<"Enter weight for item "<<ii+1<<" : ";
cin>>a[ii].ss;

}
int w; //w for total weight of how much weight that we can take
cout<<"Hey Mr. Thief, how much weight you wanna take : ";
cin>>w;

sort(a.begin(),a.end(),compare);

int ans=0;
rep(i,0,n){
if(w>=a[i].ss)
    {
        ans+=a[i].ff;
        w-=a[i].ss;
        continue;
    }
    double vw=(double)a[i].ff/a[i].ss; //realize of value per unit
    ans+=vw*w;
    w=0; //jokhon weight thakbena or weight 0 hoye jabe tokhon atake break kore dibo
    break;

}
cout<<"So Max Profit is"<<ans<<endl;
return 0;
}
