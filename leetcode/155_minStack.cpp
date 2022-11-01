#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> he;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (he.empty())
        {
            he.push(val);
        }
        else if (he.top() < val)
        {
            he.push(he.top());
        }
        else
        {
            he.push(val);
        }
    }

    void pop()
    {
        st.pop();
        he.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return he.top();
    }
};

int main(int argc, char *argv[])
{
    int val = 0;
    MinStack *obj = new MinStack();
    obj->push(val);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << " " << param_4 << endl;
    return 0;
}
