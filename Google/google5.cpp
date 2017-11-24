/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.
[73, 74, 75, 71, 70, 76, 72] -> [1, 1, 3, 2, 1, nothing, nothing]
November 22, 2017  
*/
Solution ::
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> T={73, 74, 75, 71, 70, 76, 72};
    	vector<int> wait_time(T.size());

    	wait_time[wait_time.size()-1]=0;
    	for(int i=wait_time.size()-2; i>=0; i--){
        	if(T[i]<T[i+1]){
            		wait_time[i]=1;
        	}else{
            		if(wait_time[i+1]==0){
                		wait_time[i]=0;
            		}else{
                		wait_time[i]=wait_time[i+1]+1;
            		}
        	}
    	}
    	for(auto it=wait_time.begin();it!=wait_time.end();it++){
    	    cout<<*it<<" ";
    	}
    return 0;
}

