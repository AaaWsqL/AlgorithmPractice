#include <bits/stdc++.h>
#define ss2(a,b) scanf("%d %d", &a, &b)
#define ss1(a) scanf("%d", &a)
#define loop(it,start,end,inc) for(int it=start;it<end;it+=inc)
#define pp(a) printf("%d ", a)

using namespace std;

int F(int x,int c,int* a,int n){
    // We must always place the first cow in the first stall
    int cnt=1,last=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last>=x){
            cnt+=1;
            last=a[i];
        }
    }

    if (cnt>=c) return 1;
    return 0;
}

int main()
{
 int T;
 ss1(T);
 while(T--){
    int n,c;
    ss2(n,c);
    int *a=new int[n];
    for(int i=0;i<n;i++) ss1(a[i]);
    sort(a,a+n);
    int lo=0;
    int hi=a[n-1]-a[0]+1;
    // Invariant: F(lo)=1 and F(hi)=0
    while(lo<hi-1){ // don't fully understand why lo< hi-1 instead of lo<hi
        int mid=lo + (hi-lo)/2;
        if(F(mid,c,a,n)) lo=mid;
        else hi=mid; 
    }  
    cout<<lo<<endl;
 }
}

