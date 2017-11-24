/*
Given an array which is in ascending order till some point and then descending order till end. find peak element

*/#include <bits/stdc++.h>
using namespace std;
/*
Given an array which is in ascending order till some point and then descending order till end. find peak element

*/
int peak_value(vector<int>a, int start, int end){


    if (start==end)  return a[start];
    if(start>end) return 0;
    int mid=(start+end)/2;
    if(a[mid]<a[mid+1]){

       return peak_value(a,mid+1, end);

    }else if(a[mid]>a[mid+1]){
        if((mid-1)>=0){
            if(a[mid-1]>a[mid]){
                return peak_value(a, start, mid-1);
            }else{
                return a[mid];
            }
        }else{
            return a[mid];
        }

    }

}

int find_the_peak_value(vector<int> a){
    if(a.size()==0){
        return 0;
    }else{
        cout<<"calling first peak_value function"<<endl;
        return (peak_value(a, 0, a.size()-1) );
    }
}
int main(){
    static const int arr[] = {1,2,3,4,5,3,1}; 
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    cout<<find_the_peak_value(vec);
    return 0;
}

