#include <iostream>
#include <queue>
#include <deque>
#include <stack>

template <typename X>
void swapargs (X &a, X &b)
{
	X temp;
	temp = a;
	a = b;
	b = temp;
	printf("template func\n");
}

template<>
void swapargs<int> (int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "int specialize template func\n";
}

template<>
void swapargs<char> (char &a, char &b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "char specialize template func\n";
}

template <typename X,typename Y>
void swapargs (X &a, X &b,Y &c,Y &d)
{
	X temp_x;
	temp_x = a;
	a = b;
	b = temp_x;

	Y temp_y;
	temp_y = c;
		c = d;
		d = temp_y;
	std::cout << "2x overload template func\n";
}

template <>
void swapargs (int &a, int &b,char &c,char &d)
{
	int temp_x;
	temp_x = a;
	a = b;
	b = temp_x;

	char temp_y;
	temp_y = c;
		c = d;
		d = temp_y;
	std::cout << "2x overload template func (int and char specialize)\n";
}

template<typename X,size_t size>
class queue
{
public:
queue()
     //:
     {stock=exit=0;}
	void qput(X i);
	X qget();
	size_t qsize();
private:
	X q[size];
	size_t stock,exit;
};

template<typename X,size_t size>
void queue<X,size>::qput(X i)
{
	if(stock==size)
	{
		std::cout << "queue is full\n";
		return;
	}
	stock++;
	q[stock]=i;
}

template<typename X,size_t size>
X queue<X,size>::qget()
{
	if(stock==exit)
	{
		std::cout << "\nqueue is empty.\n";
		return 0;
	}
	exit++;
	return q[exit];
}

template<typename X,size_t size>
size_t queue<X,size>::qsize()
{
	return size;
}

int main(int argc, char * argv[])
{
char a = 'a';
char b = 'b';
swapargs(a,b);
int x = 1;
int y = 2;
swapargs(x,y);
swapargs(a,b,x,y);
swapargs(x,y,a,b);
queue<int,5> q;
for(size_t i=0;i!=q.qsize()+1;++i)
	q.qput(i);
for(size_t i=0;i!=q.qsize()+1;++i)
	std::cout << q.qget();
printf("\n\n\n");
std::queue<int>qu;
qu.push(2);
qu.push(3);
qu.push(35);
qu.push(104);
qu.push(356356356);
qu.pop();
qu.pop();

int front = qu.front();
int back = qu.back();
std::cout << "\n front == "<< front;
std::cout << "\n back" << back;
std::cout << "\n" << qu.front();
std::cout << "\n"  << qu.back();

std::deque<int>dequ;
dequ.push_back(89);
dequ.push_back(104);
dequ.push_back(476);
dequ.push_front(575);
std::cout << "\ndeque " << dequ.front();
std::cout << "\ndeque " << dequ.back() << std::endl;
//dequ.clear();

std::stack<int> st;
st.push(35);
st.push(3464);
st.push(675849);
st.pop();

printf("\n%d",st.top());

/*int defront = dequ.front();
int deback = dequ.back();
std::cout << "\n front == "<< defront;
std::cout << "\n back" << deback;*/

	std::cout << "123\n";
}
