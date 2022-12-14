#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int x)
{
    if (st.size() == 0) {
        st.push(x);
    }
    else {
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(a);
    }
}

void reverse_st(stack<int> &st) {
	if(st.size()>0) {
		int x = st.top();
		st.pop();
		reverse_st(st);
		insert_at_bottom(st,x);
	}
	return;
}

int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverse_st(st);
	while(!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}