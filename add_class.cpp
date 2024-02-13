struct A
{
	A(int x,int y):x_(x),y_(y)
	{}
	get_x(){return this->x_;}
	get_y(){return this->y_;}
	private:
int x_;
int y_;
};
