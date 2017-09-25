/*
Problem : http://www.spoj.com/problems/ACODE/

Simple Dp problem...

But learnt about problems of taking string input with scanf()
using cin is preferred

*/


#include <bits/stdc++.h>
#define ss2(a,b) scanf("%d %d", &a, &b)
#define ss1(a) scanf("%d", &a)
#define loop(it,start,end,inc) for(int it=start;it<end;it+=inc)
#define pp(a) printf("%d ", a)

using namespace std;

int main(){
    string str;
    while(cin>>str && str!="0"){
        int n=str.length();
        int *dp=new int[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++) dp[i]=0;

        for(int i=2;i<=n;i++){
            if(str[i-2]-'0'==0) {
                dp[i]=dp[i-1];
                continue;
            }

            if(str[i-1]-'0'==0){
                dp[i]=dp[i-2];
                continue;
            }

            if( 10*(str[i-2]-'0') + (str[i-1]-'0')<=26  ) {
                dp[i]=dp[i-2]+dp[i-1];
                continue;
            }

            else dp[i]=dp[i-1];
        }
        cout<<dp[n]<<endl;

 }
}

