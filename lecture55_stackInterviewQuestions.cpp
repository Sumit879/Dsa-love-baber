#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str = "Abhishek";
    stack<char> s;

    for(int i=0; i<str.length(); ++i)
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout << "Answer is => " << ans << endl;
    return 0;
}

//did 8 eight questions in this lecture at code studio 
//refere YT channel for Question links