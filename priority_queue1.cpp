
/*Rearrange characters in a string such that no two adjacent are same

Given a string with repeated characters, task is rearrange characters in a string so that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Examples:

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible
*/

#include <bits/stdc++.h>
#define ss2(a,b) scanf("%d %d", &a, &b)
#define ss1(a) scanf("%d", &a)
#define loop(it,start,end,inc) for(int it=start;it<end;it+=inc)
#define pp(a) printf("%d ", a)
using namespace std;

class CompareBySecond
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second<n2.second;
    }
};

int main(){
	int T;
	int cnt[256];
	char str[100];
	ss1(T);
	while(T--){
		scanf("%s",str);
		loop(i,0,256,1) cnt[i]=0;

		int n=strlen(str);
		loop(i,0,n,1) cnt[str[i]]+=1;

		priority_queue<pair<int, int>, vector<pair<int,int> >, CompareBySecond> pq;
		loop(i,0,256,1) if(cnt[i]>0) pq.push(make_pair(i,cnt[i]));
		
		pair<int,int> curr;
		pair<int,int> last;

		vector<char> ans;

		while(1){
			curr=pq.top();
			pq.pop();

			if(curr.second<1) break; 

			ans.push_back(curr.first);

			pq.push(last);
			last.first=curr.first;
			last.second=curr.second-1;
		}

		if( ans.size()==n ) 
		loop(i,0,n,1) printf("%c", ans[i]);
		else printf("-1");

		printf("\n");
	}
}

