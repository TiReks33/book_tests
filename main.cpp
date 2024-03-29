#include <iostream>

#include <queue>

#include <deque>

#include <stack>

#include <stdexcept>

#include <cstring>

//addition from VBox machine

template <typename X>

void swapargs (X &a, X &b)

{

	X temp;

	temp = a;

	a = b;

	b = temp;

	std::cout << "template func\n";

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



int division(int a, int b)

{

	try{

		if(!b){ throw b;/*return 0;*/}//std::runtime_error("Division by zero!");

	}

	catch(int i){

		throw std::runtime_error("Division by zero!");

	}

		return a/b;

}



class MyException

{

public:

	char str_what[80];

	MyException(){ *str_what = 0;}

	MyException(char const *s) {strcpy(str_what,s);}

};



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

st.pop();

std::cout << "\n" << st.top() << "\n";



/*int defront = dequ.front();

int deback = dequ.back();

std::cout << "\n front == "<< defront;

std::cout << "\n back" << deback;*/





std::cout << division(4,2);

std::cout << division(4,1);

//std::cout << division(4,0);



int aa=5;

int bb=0;



try{

if(!bb) throw MyException("Division by zero!!!");

else std::cout << aa/bb;

}



catch (MyException const & e){

	std::cout << e.str_what << "\n";

}





return 0;

}






