#include <bits/stdc++.h>

using namespace std;

int prec(char c)
{
	if (c == '$')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

float PerformOperation(char operation, float operand1, float operand2)
{
	switch(operation){
		case '+':
		return operand1 +operand2;
		case '-':
		return operand1 - operand2;
		case '*':
		return operand1 * operand2;
		case '/':
		return operand1 / operand2;
		case '$':
	return pow(operand1,operand2);
		default:
		return 0;

	}
}

string convert(string s)
{

	stack<char> st;
	// stack<string> op;
	string result=" ";

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		string temp ="";  

			while(isdigit(s[i]) || s[i]=='.'){	
				temp+= s[i];
				i++;
			}
		
			result += " " + temp ;
			
		// 	if(c == '(')
        //     st.push('(');
 
    
        // else if(c == ')') {
        //     while(st.top() != ')')
        //     {
        //         result += " " + st.top();
        //         st.pop();
        //     }
        //     st.pop();
        // }
		
			while(!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				result = result + " " + st.top() ;
				st.pop();
			}
			st.push(s[i]);
		
	}

	while (!st.empty())
	{
		result += " " + st.top();
		st.pop();
	}

	return result;
}

float EvaluatePostfix(string expression)
{
	stack<float> S;

	for(int i = 0;i< expression.length();i++) {

		if(expression[i] == ' ') continue; 

		else if(IsOperator(expression[i])) {
			float operand2 = S.top(); S.pop();
			float operand1 = S.top(); S.pop();
			float result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			 
			string operand = ""; 
			while(i<expression.length() &&( IsNumericDigit(expression[i]) || expression[i]=='.')) {
				
				operand += expression[i]; 
				i++; 
			}

			float f_value = stof(operand);
			
			S.push(f_value);
		}
	}
	
	return S.top();
}



int main(int argc, char** argv)
{
	string s;
	// cin>>s; 
	s = argv[1];
	
	string res = convert(s);

	// cout << res<<endl;
	cout<<EvaluatePostfix(res);
	
	return 0;
}

