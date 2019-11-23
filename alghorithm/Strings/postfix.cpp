#include <bits/stdc++.h>
using namespace std;

int main()
{
 	string re, pfix , op=".*|";
    stack<char> rator;
	map<char,int> pred;
	pred['.'] = 2;
	pred['*'] = 1;
	pred['|'] = 0;
	pred['('] = -1;
	cin>>re;
	rator.push('(');
	re += ")";

    for(int i = 0; i< re.length(); ++i)
	{
		if(op.find( to_string(re[i]))!= string::npos)
		{
			while( !rator.empty() && pred[rator.top()] >= pred[re[i]])
			{
				pfix += to_string(rator.top());
				rator.pop();
			}
			rator.push(re[i]);
		}
		else if(re[i]=='(')
			rator.push('(');
		else if(re[i]==')')
		{
			while(!rator.empty() && rator.top()!='(')
			{
				pfix += to_string(rator.top());
				rator.pop();
			}
			rator.pop();
		}
		else
			pfix += to_string(re[i]);
	
	}
	cout<<pfix<<endl;
	return 0;
}    

