#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool is_digit(char c) {
    return 0 <= c - 48 && c - 48 < 10;
}

template <class T>
class stack
{
public:
    stack(int capa);//유저 입력 길이만큼의 stack 생성
    ~stack();
    bool is_empty();//원소수가 0이면 true || false 반환
    T& return_top();//스택의 최상위 원소 반환
    void make_postfix(string infix); //중위식을 후위식으로 변환하여 출력한다.
    void push(const T& item);//스택에 item을 push
    void pop();//top 원소를 삭제
    string token(string e);//e에서 토큰을 제거하여 반환함.
    int isp(string a);
    int icp(string a);//isp와 icp의 우선순위 반환

private:
    int top;
    int capacity;
    string infix;
    int infix_index = 0;
    string postfix;
    T* stack_arr;

};

int main()
{
    while (1)
    {
        string input;
        cin >> input;
        input = input + "#";//스택의 끝
        if (input == ".") break;
        else
        {
            int input_len = input.length();
            stack<int> s(input_len);
            s.make_postfix(input);
        }
    }
    return 0;
}

template <class T>
stack<T>::stack(int capa)
{
    stack_arr = new T[capa];//넉넉하게 생성해준다.
    capacity = capa;
    top = -1;
}

template<class T>
stack<T>::~stack()
{
    delete[] stack_arr;
}

template <class T>
int stack<T>::isp(string a)
{
    if ((a == "-") || a == "!") return 1;
    else if (a == "*" || a == "/" || a == "%") return 2;
    else if (a == "+" || a == "-") return 3;
    else if (a == "<" || a == "<=" || a == ">" || a == ">=") return 4;
    else if (a == "==" || a == "!=") return 5;
    else if (a == "&&") return 6;
    else if (a == "||") return 7;
    else if (a == "(") return 8;
}

template <class T>
int stack<T>::icp(string a)
{
    int temp;
    if (isp(a) == 8) temp = 0;//icp와 isp는 (만 다르다.
    else temp = isp(a);
    return temp;
}

template <class T>
void stack<T>::push(const T& item)//스택에 item을 push
{
    stack_arr[++top] = item;
}

template <class T>
void stack<T>::pop()
{
    top--;
}

template <class T>
T& stack<T>::return_top()
{
    return stack_arr[top];
}

template <class T>
bool stack<T>::is_empty()
{
    if (top == -1) return 1;
    else return 0;
}

template <class T>
string stack<T>::token(string e)
{
    char temp = e[infix_index];
    string token;
    if (is_digit(temp))//숫자인 경우 토큰 추출
    {
        int i;
        for (i = infix_index; is_digit(e[infix_index]) == 0; i++)
        {
            token += e[i];
        }
        infix_index = i;
    }
    else
    {
        int j;
        for (j = infix_index; is_digit(e[j]); j++)
        {
            token += e[j];
        }
        infix_index = j;
    }
    return token;
}


template <class T>
void stack<T>::make_postfix(string infix)//스택에 item을 push
{
    stack<T> stack;
    stack.push('#');
    for(string x=token(infix); x!="#"; x=token(infix))
    {
        if (is_digit(x)) cout << x;//숫자면 바로 출력하기.
        else if (x == ')')
        {
            for (; stack.top() != '('; stack.pop())//괄호가 닫힐 때 까지 출력하기.
            {
                cout<<stack.top();
            }
            stack.pop();
        }
    else
        {
            for (; isp(stack.top()) <= icp(x); stack.pop())
            {
                cout << stack.top();
            }
            stack.push(x);
        }
    }

    for (; !stack.is_empty();) cout << stack.top(); stack.pop();
    cout << endl;
}
