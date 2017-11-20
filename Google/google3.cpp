/*
Given an array of sorted integers and find the closest value to the given number. Array may contain duplicate values and negative numbers.

Example : Array : 2,5,6,7,8,8,9
Target number : 5
Output : 5

Target number : 11
Output : 9

Target Number : 4
Output : 5
*/

int findClosestNumber(int[] data, int x, int start, int end) {
		if(x < data[start]) { 
			return data[start];
		} else if(x > data[end]) {
			return data[end];
		} else {
			if(start < end) {
				int mid = (start + end) /2;
				if(x > data[mid]) {
				
					return findClosestNumber(data, x, mid+1, end);
				} else {
					return findClosestNumber(data, x, start, mid);

				}
			} 
			return data[start];
		}
