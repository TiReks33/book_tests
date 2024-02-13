struct A
{
	A(int x):x_(x)
	{}
	get_x(){return this->x_;}
	private:
int x_;
};
