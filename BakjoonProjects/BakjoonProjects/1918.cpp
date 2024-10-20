#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
자료 구조
스택
*/
string ans;
void changeStr(string str)
{
    stack<char> stChr;

    for (int i = 0; i < str.size(); ++i)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            ans.push_back(str[i]);
        else {
            if(str[i] == '(')
                stChr.push(str[i]);
            else if (str[i] == '*' || str[i] == '/')
            {
                while(!stChr.empty() && (stChr.top() == '*' || stChr.top() == '/'))
                {
                    ans.push_back(stChr.top());
                    stChr.pop();
                }
                stChr.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!stChr.empty() && stChr.top() != '(')
                {
                    ans.push_back(stChr.top());
                    stChr.pop();
                }
                stChr.push(str[i]);
            }
            else if (str[i] == ')') {
                while (!stChr.empty() && stChr.top() != '(') {
                    ans.push_back(stChr.top());
                    stChr.pop();
                }
                stChr.pop();
            }
        }
    }

    while (!stChr.empty()) {
        ans.push_back(stChr.top());
        stChr.pop();
    }
}
int main()
{
    string str;
    cin >> str;

    changeStr(str);

    cout << ans;
}