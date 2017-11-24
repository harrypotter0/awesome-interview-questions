/*
You have given height array of array. Generate the original array.

Input: [6,3,0,2,2,0,0]
Output : [1,4,7,3,2,6,5]

A[i] value in input array is the number of greater element on right side.
November 20, 2017
*/

/*
Here is the logic behind the question:
The given input has size 7 so you have to fill each position by picking one element from array [1,2,3,4,5,6,7]. Now the given height array of array is [6,3,0,2,2,0,0]. Here first height is 6 it means that 6 elements must be greater than the picking element. So we every time pick the (A[i]+1)th greatest element from the remaining array of [1,2,3,4,5,6,7].

For 1st position A[i] is 6. So pick 7th greatest element that is 1. Remaining array [2,3,4,5,6,7].
For 2nd position A[i] is 3. So pick 4th greatest element that is 4. remaining array [2,3,5,6,7].
For 3rd position A[i] is 0 so pick 1st greatest element that is 7. remaining array [2,3,5,6].
Similar process will run until we fill the all position.

If you use an array, it's O(n^2) time due to the remove operation that copies n/2 elements worst case average.
If you use a tree, (sorted map, red black tree etc) you can get away with O(n*lg(n)) time.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> generate(const vector<int> &in) {

	int s = in.size();
	vector<int> out(s+1);
	vector<int> inserted;

	for(int i = 1; i <= s; i++)
		inserted.push_back(i);

    int curRemain = s-1;
	for(int i = 1; i <= s; i++)
	{
	    int small = curRemain - in[i-1];
	    out[i]=inserted[small];
	    inserted.erase(inserted.begin()+small);
	    curRemain--;
	}
	out.erase(out.begin());
	return out;
}
int main(){
    vector <int> cool={6,3,0,2,2,0,0};
    vector<int> str_vec = generate(cool);
     for(auto it = str_vec.begin(); it != str_vec.end(); it++) {
         cout << *it << " ";
     }
    return 0;
}

