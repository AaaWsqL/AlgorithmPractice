/*
Given a string and text output the smallest window in the string which covers all the characters present in the text. Both the string and text contains small case letters.
If such window doesn`t exist or this task can not be done then print -1.

Input:
First line contains T , the number of test cases and each test contains 2 lines having a string each  and  ( n is the main string and x is the text )

Output:
Output the smallest window of the string containing all the characters of the text.

Constraints: 
1<=T<=100
1<=N,X<=1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo
*/

#include<bits/stdc++.h>
using namespace std;

void f(char* str, char* pat,int* ans){
	int has_found[256]={0};
	int to_find[256]={0};
	
	int minLen=10000;
	
	int n=strlen(str);
	int x=strlen(pat);
	for(int i =0;i<x;i++) to_find[pat[i]]+=1;
	
	//find the first minimum window that satisfies the condition
	int i=0,left=0,cnt=0;
	bool not_found=true;
	
	while(not_found && i<n){
		has_found[str[i]]+=1;
		
		if(has_found[str[i]]==to_find[str[i]]) cnt+=to_find[str[i]];
		if(cnt==x){
			//contracting from the left side 
			while(not_found){
				if( has_found[str[left]]-1>= to_find[str[left]]) {
				    has_found[str[left]]-=1; left++; 
				}
				else not_found=false;
			}
			ans[0]=left;
			ans[1]=i;
			minLen=i-left+1 ;
			
		}
		i++;
	}
	
	while(i<n){
		has_found[str[i]]+=1;
		if(str[i]==str[left]){
			bool not_minimized=true;
			while(not_minimized){
				if( has_found[str[left]]-1>= to_find[str[left]]) {
				    has_found[str[left]]-=1; 
				    left++;
				}
				else not_minimized=false;
			}
			
			if(i-left+1 < minLen) {
			    ans[0]=left;
			    ans[1]=i;
			    minLen=i-left+1 ;
			}
		}
		i++;
	}
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		char str[1000], pat[1000];
		scanf("%s", str);
		scanf("%s", pat);
		int ans[]={0,0};
		f(str,pat,ans);
		for(int i=ans[0];i<=ans[1];i++) printf("%c", str[i]);
		printf("\n");
	}
}