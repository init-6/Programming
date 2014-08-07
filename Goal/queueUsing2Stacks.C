#include <iostream>
#include <stack>

using namespace std;

stack <int> in;
stack <int > out;

void enqueue(int val)
{
	in.push(val);
}

void dequeue()
{
	while(!in.empty())
	{
		out.push(in.top());
		in.pop();
	}
	cout << out.top() << endl;
	out.pop();
}
int main()
{
	

	int n;
	while(cin >> n && n)
	{
		enqueue(n);		
	}
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
