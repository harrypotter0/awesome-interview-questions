/*
Write code to find unmatched parentheses and return it in the below format:
((a) -> -10a1
(a)) -> 0a1-1
(((abc))((d))))) -> 000abc1100d111-1-1

November 18, 2017 in United States  
*/


//Solution::::
string a="(a))";
	cout<< a<<" -> ";
	stack<int> st;
	for(int i=0;i<a.length();i++){
		if(a[i]=='('){
			st.push(i);
		}else if(a[i]==')'){
			if(st.empty()){
				a.replace(i, 1, "-1");
			}else{
				a.replace(i, 1, "1");
				a.replace(st.top(), 1, "0");
				st.pop();
			}
		}

	}
	while(!st.empty()){
		a.replace(st.top(), 1, "-1");
		st.pop();
	}
	
	cout<<a<<endl;
