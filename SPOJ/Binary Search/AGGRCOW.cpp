/*
http://www.spoj.com/problems/AGGRCOW/
For the problem at hand, let us define the following function:
F(x) = 1 if it is possible to arrange the cows in stalls such that the distance between any two cows is at least x
F(x) = 0 otherwise

Now it is easy to see that if F(x)=0, F(y)=0 for all y>x. Thus, the problem satisfies the monotonicity condition necessary for binary search. It is also easy to find two values of x which give F(x)=0 and 1 respectively. F(0)=1 trivially since the distance between any two cows is at least 0. Also, since we have at least two cows, the best we can do is push them towards the stalls at the end - so there is no way we can achieve better. Hence F(maxbarnpos-minbarnpos+1)=0.

Now, how do we check whether F(x)=1 for a general value of x? We can do this with a greedy algorithm: Keep placing cows at the leftmost possible stalls such that they are at least x distance away from the last placed cow. Assuming that the array pos containing positions of stalls has been sorted, here is the simple implementation:

    int F(int x)
    {
      //We can always place the first cow in the leftmost stall
      int cowsplaced=1,lastpos=pos[0];
      for(int i=1;i<N;i++)
      {
        if(pos[i]-lastpos>=x)
        {
          //We are at least x away from last placed cow
          //So we can place one here
          if(++cowsplaced==C)return 1;
          lastpos=pos[i];
        }
      }
      return 0;
    }



With this, the main part of the solution is simple as well:

    //First sort the barns so the precondition for F(x) is satisfied
    sort(pos,pos+N);
    //Invariant : F(start) is always 1, F(end) is always 0
    int start=0,end=pos[N-1]-pos[0]+1,mid;
    while(end-start>1)
    {
      mid=(end+start)>>1;
      (F(mid)?start:end)=mid;
    }
    return start;
*/


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

