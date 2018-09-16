#include "GUI.h"
#include "Window.h"
#include "Graph.h"
#include "fltk.h"
#include "Simple_window.h"

void put_shape0(int **data, int i, int j, int t);
void put_shape1(int **data, int i, int j);
void put_shape2(int **data, int i, int j, int t);
void put_shape3(int **data, int i, int j, int t);
void put_shape4(int **data, int i, int j, int t);
void clear_shape0(int **data, int i, int j, int t);
void clear_shape1(int **data, int i, int j);
void clear_shape2(int **data, int i, int j, int t);
void clear_shape3(int **data, int i, int j, int t);
void clear_shape4(int **data, int i, int j, int t);
bool check_shape1(int **data, int i, int j);
bool check_shape2(int **data, int i, int j, int t);
bool check_shape3(int **data, int i, int j, int t);
bool check_shape4(int **data, int i, int j, int t);
void put_all();
int condition[14] = { 0 };
vector<int **> all;

class shape0 : public Shape
{
private:
	Point s;
	Graph_lib::Rectangle *r1, *r2, *r3, *r4, *r5;
	int t;
public:
	shape0(Point ss, int tt);
	void draw_lines() const
	{
		r1->draw_lines();
		r2->draw();
		r3->draw();
		r4->draw();
		r5->draw();
	}
	void set_fill_color(Color col)
	{
		r1->set_fill_color(col);
		r2->set_fill_color(col);
		r3->set_fill_color(col);
		r4->set_fill_color(col);
		r5->set_fill_color(col);
	}
	void set_color(Color col)
	{
		r1->set_color(col);
		r2->set_color(col);
		r3->set_color(col);
		r4->set_color(col);
		r5->set_color(col);
	}
};

class shape1 : public Shape
{
private:
	Point s;
	Graph_lib::Rectangle *r1, *r2, *r3, *r4;
	int t;
public:
	shape1(Point ss, int tt);
	void draw_lines() const
	{
		r1->draw_lines();
		r2->draw();
		r3->draw();
		r4->draw();
	}
	void set_fill_color(Color col)
	{
		r1->set_fill_color(col);
		r2->set_fill_color(col);
		r3->set_fill_color(col);
		r4->set_fill_color(col);
	}
	void set_color(Color col)
	{
		r1->set_color(col);
		r2->set_color(col);
		r3->set_color(col);
		r4->set_color(col);
	}
};

class shape2 : public Shape
{
private:
	Point s;
	Graph_lib::Rectangle *r1, *r2, *r3, *r4, *r5;
	int t;
public:
	shape2(Point ss, int tt);
	void draw_lines() const
	{
		r1->draw_lines();
		r2->draw();
		r3->draw();
		r4->draw();
		r5->draw();
	}
	void set_fill_color(Color col)
	{
		r1->set_fill_color(col);
		r2->set_fill_color(col);
		r3->set_fill_color(col);
		r4->set_fill_color(col);
		r5->set_fill_color(col);
	}
	void set_color(Color col)
	{
		r1->set_color(col);
		r2->set_color(col);
		r3->set_color(col);
		r4->set_color(col);
		r5->set_color(col);
	}
};

class shape3 : public Shape
{
private:
	Point s;
	Graph_lib::Rectangle *r1, *r2, *r3, *r4, *r5;
	int t;
public:
	shape3(Point ss, int tt);
	void draw_lines() const
	{
		r1->draw_lines();
		r2->draw();
		r3->draw();
		r4->draw();
		r5->draw();
	}
	void set_fill_color(Color col)
	{
		r1->set_fill_color(col);
		r2->set_fill_color(col);
		r3->set_fill_color(col);
		r4->set_fill_color(col);
		r5->set_fill_color(col);
	}
	void set_color(Color col)
	{
		r1->set_color(col);
		r2->set_color(col);
		r3->set_color(col);
		r4->set_color(col);
		r5->set_color(col);
	}
};

class shape4 : public Shape
{
private:
	Point s;
	Graph_lib::Rectangle *r1, *r2, *r3, *r4, *r5, *r6;
	int t;
public:
	shape4(Point ss, int tt);
	void draw_lines() const
	{
		r1->draw_lines();
		r2->draw();
		r3->draw();
		r4->draw();
		r5->draw();
		r6->draw();
	}
	void set_fill_color(Color col)
	{
		r1->set_fill_color(col);
		r2->set_fill_color(col);
		r3->set_fill_color(col);
		r4->set_fill_color(col);
		r5->set_fill_color(col);
		r6->set_fill_color(col);
	}
	void set_color(Color col)
	{
		r1->set_color(col);
		r2->set_color(col);
		r3->set_color(col);
		r4->set_color(col);
		r5->set_color(col);
		r6->set_color(col);
	}
};

struct Lines_window : Window
{
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Button next_button;
	Button quit_button;
	shape0 s1;
	shape1 s2;
	shape2 s3;
	shape3 s4;
	shape4 s5;
	Graph_lib::Rectangle ***matrix;

	static void cb_next(Address, Address);
	void next();
	static void cb_quit(Address, Address);
	void quit();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	next_button(Point(x_max() - 150, 0), 70, 20, "Next", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
	s1(Point(100, 100),0),
	s2(Point (200, 125),0),
	s3(Point(300,75),0),
	s4(Point(150,200),0),
	s5(Point(250,200),0)
{
	matrix = new Graph_lib::Rectangle **[5];
	for (int i = 0; i < 5; ++i)
		matrix[i] = new Graph_lib::Rectangle *[5];
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			matrix[i][j] = new Graph_lib::Rectangle(Point(400 + 25 * i, 200 + 25 * j), 25, 25);
			matrix[i][j]->set_color(Color::black);
			attach(*matrix[i][j]);
		}
	}
	attach(next_button);
	attach(quit_button);
	s1.set_color(Color::black);
	s1.set_fill_color(Color::green);
	attach(s1);
	s2.set_color(Color::black);
	s2.set_fill_color(Color::red);
	attach(s2);
	s3.set_color(Color::black);
	s3.set_fill_color(Color::yellow);
	attach(s3);
	s4.set_color(Color::black);
	s4.set_fill_color(Color::magenta);
	attach(s4);
	s5.set_color(Color::black);
	s5.set_fill_color(Color::blue);
	attach(s5);
}

void Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

shape0::shape0(Point ss, int tt)
{
	t = tt;
	s = ss;
	switch (t)
	{
		case 0: 
		{
			r1 = new Graph_lib::Rectangle(s, 25, 25);
			r2 = new Graph_lib::Rectangle(Point(s.x, s.y + 25), 25, 25);
			r3 = new Graph_lib::Rectangle(Point(s.x, s.y + 50), 25, 25);
			r4 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 50), 25, 25);
			r5 = new Graph_lib::Rectangle(Point(s.x + 50, s.y + 50), 25, 25);
			break;
		}
		case 1:
		{
			r1 = new Graph_lib::Rectangle(s, 25, 25);
			r2 = new Graph_lib::Rectangle(Point(s.x-25, s.y), 25, 25);
			r3 = new Graph_lib::Rectangle(Point(s.x-50, s.y), 25, 25);
			r4 = new Graph_lib::Rectangle(Point(s.x-50, s.y+25), 25, 25);
			r5 = new Graph_lib::Rectangle(Point(s.x-50, s.y+50), 25, 25);
			break;
		}
		case 2:
		{
			r1 = new Graph_lib::Rectangle(s, 25, 25);
			r2 = new Graph_lib::Rectangle(Point(s.x, s.y - 25), 25, 25);
			r3 = new Graph_lib::Rectangle(Point(s.x, s.y - 50), 25, 25);
			r4 = new Graph_lib::Rectangle(Point(s.x - 25, s.y - 50), 25, 25);
			r5 = new Graph_lib::Rectangle(Point(s.x - 50, s.y - 50), 25, 25);
			break;
		}
		case 3:
		{
			r1 = new Graph_lib::Rectangle(s, 25, 25);
			r2 = new Graph_lib::Rectangle(Point(s.x+25, s.y), 25, 25);
			r3 = new Graph_lib::Rectangle(Point(s.x+50, s.y), 25, 25);
			r4 = new Graph_lib::Rectangle(Point(s.x+50, s.y-25), 25, 25);
			r5 = new Graph_lib::Rectangle(Point(s.x+50, s.y-50), 25, 25);
			break;
		}
		default:
			break;
		}
}

shape1::shape1(Point ss, int tt)
{
	s = ss;
	t = tt;
	r1 = new Graph_lib::Rectangle(s, 25, 25);
	r2 = new Graph_lib::Rectangle(Point(s.x+25, s.y), 25, 25);
	r3 = new Graph_lib::Rectangle(Point(s.x + 25, s.y+25), 25, 25);
	r4 = new Graph_lib::Rectangle(Point(s.x, s.y+25), 25, 25);
}

shape2::shape2(Point ss, int tt)
{
	s = ss;
	t = tt;
	r1 = new Graph_lib::Rectangle(s, 25, 25);
	r2 = new Graph_lib::Rectangle(Point(s.x, s.y+25), 25, 25);
	r3 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 25), 25, 25);
	r4 = new Graph_lib::Rectangle(Point(s.x+25, s.y + 50), 25, 25);
	r5 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 75), 25, 25);
}

shape3::shape3(Point ss, int tt)
{
	s = ss;
	t = tt;
	r1 = new Graph_lib::Rectangle(s, 25, 25);
	r2 = new Graph_lib::Rectangle(Point(s.x+25, s.y), 25, 25);
	r3 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 25), 25, 25);
	r4 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 50), 25, 25);
	r5 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 75), 25, 25);
}

shape4::shape4(Point ss, int tt)
{
	s = ss;
	t = tt;
	r1 = new Graph_lib::Rectangle(s, 25, 25);
	r2 = new Graph_lib::Rectangle(Point(s.x + 25, s.y), 25, 25);
	r3 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 25), 25, 25);
	r4 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 50), 25, 25);
	r5 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 75), 25, 25);
	r6 = new Graph_lib::Rectangle(Point(s.x + 25, s.y + 100), 25, 25);
}

void put_shape0(int **data, int i, int j, int t)
{
	switch (t)
	{
		case 0:
		{
			data[i][j] = 1;
			data[i+1][j] = 1;
			data[i+2][j] = 1;
			data[i+2][j+1] = 1;
			data[i+2][j+2] = 1;
			break;
		}
		case 1:
		{
			data[i][j] = 1;
			data[i][j-1] = 1;
			data[i][j-2] = 1;
			data[i+1][j-2] = 1;
			data[i+2][j-2] = 1;
			break;
		}
		case 2:
		{
			data[i][j] = 1;
			data[i-1][j] = 1;
			data[i-2][j] = 1;
			data[i-2][j-1] = 1;
			data[i-2][j-2] = 1;
			break;
		}
		case 3:
		{
			data[i][j] = 1;
			data[i][j+1] = 1;
			data[i][j+2] = 1;
			data[i-1][j+2] = 1;
			data[i-2][j+2] = 1;
			break;
		}
		default:
			break;
	}
}

void clear_shape0(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 0;
		data[i + 1][j] = 0;
		data[i + 2][j] = 0;
		data[i + 2][j + 1] = 0;
		data[i + 2][j + 2] = 0;
		break;
	}
	case 1:
	{
		data[i][j] = 0;
		data[i][j - 1] = 0;
		data[i][j - 2] = 0;
		data[i + 1][j - 2] = 0;
		data[i + 2][j - 2] = 0;
		break;
	}
	case 2:
	{
		data[i][j] = 0;
		data[i - 1][j] = 0;
		data[i - 2][j] = 0;
		data[i - 2][j - 1] = 0;
		data[i - 2][j - 2] = 0;
		break;
	}
	case 3:
	{
		data[i][j] = 0;
		data[i][j + 1] = 0;
		data[i][j + 2] = 0;
		data[i - 1][j + 2] = 0;
		data[i - 2][j + 2] = 0;
		break;
	}
	default:
		break;
	}
}

void put_shape1(int **data, int i, int j)
{
	data[i][j] = 2;
	data[i+1][j] = 2;
	data[i][j+1] = 2;
	data[i+1][j+1] = 2;
}

void clear_shape1(int **data, int i, int j)
{
	data[i][j] = 0;
	data[i + 1][j] = 0;
	data[i][j + 1] = 0;
	data[i + 1][j + 1] = 0;
}

void put_shape2(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 3;
		data[i + 1][j] = 3;
		data[i + 1][j+1] = 3;
		data[i + 2][j + 1] = 3;
		data[i + 3][j + 1] = 3;
		break;
	}
	case 1:
	{
		data[i][j] = 3;
		data[i][j - 1] = 3;
		data[i+1][j - 1] = 3;
		data[i + 1][j - 2] = 3;
		data[i + 1][j - 3] = 3;
		break;
	}
	case 2:
	{
		data[i][j] = 3;
		data[i - 1][j] = 3;
		data[i - 1][j-1] = 3;
		data[i - 2][j - 1] = 3;
		data[i - 3][j - 1] = 3;
		break;
	}
	case 3:
	{
		data[i][j] = 3;
		data[i][j + 1] = 3;
		data[i-1][j + 1] = 3;
		data[i - 1][j + 2] = 3;
		data[i - 1][j + 3] = 3;
		break;
	}
	default:
		break;
	}
}

void clear_shape2(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 0;
		data[i + 1][j] = 0;
		data[i + 1][j + 1] = 0;
		data[i + 2][j + 1] = 0;
		data[i + 3][j + 1] = 0;
		break;
	}
	case 1:
	{
		data[i][j] = 0;
		data[i][j - 1] = 0;
		data[i + 1][j - 1] = 0;
		data[i + 1][j - 2] = 0;
		data[i + 1][j - 3] = 0;
		break;
	}
	case 2:
	{
		data[i][j] = 0;
		data[i - 1][j] = 0;
		data[i - 1][j - 1] = 0;
		data[i - 2][j - 1] = 0;
		data[i - 3][j - 1] = 0;
		break;
	}
	case 3:
	{
		data[i][j] = 0;
		data[i][j + 1] = 0;
		data[i - 1][j + 1] = 0;
		data[i - 1][j + 2] = 0;
		data[i - 1][j + 3] = 0;
		break;
	}
	default:
		break;
	}
}

void put_shape3(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 4;
		data[i][j+1] = 4;
		data[i + 1][j + 1] = 4;
		data[i + 2][j + 1] = 4;
		data[i + 3][j + 1] = 4;
		break;
	}
	case 1:
	{
		data[i][j] = 4;
		data[i+1][j] = 4;
		data[i + 1][j - 1] = 4;
		data[i + 1][j - 2] = 4;
		data[i + 1][j - 3] = 4;
		break;
	}
	case 2:
	{
		data[i][j] = 4;
		data[i][j-1] = 4;
		data[i - 1][j - 1] = 4;
		data[i - 2][j - 1] = 4;
		data[i - 3][j - 1] = 4;
		break;
	}
	case 3:
	{
		data[i][j] = 4;
		data[i-1][j] = 4;
		data[i - 1][j + 1] = 4;
		data[i - 1][j + 2] = 4;
		data[i - 1][j + 3] = 4;
		break;
	}
	default:
		break;
	}
}

void clear_shape3(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 0;
		data[i][j + 1] = 0;
		data[i + 1][j + 1] = 0;
		data[i + 2][j + 1] = 0;
		data[i + 3][j + 1] = 0;
		break;
	}
	case 1:
	{
		data[i][j] = 0;
		data[i + 1][j] = 0;
		data[i + 1][j - 1] = 0;
		data[i + 1][j - 2] = 0;
		data[i + 1][j - 3] = 0;
		break;
	}
	case 2:
	{
		data[i][j] = 0;
		data[i][j - 1] = 0;
		data[i - 1][j - 1] = 0;
		data[i - 2][j - 1] = 0;
		data[i - 3][j - 1] = 0;
		break;
	}
	case 3:
	{
		data[i][j] = 0;
		data[i - 1][j] = 0;
		data[i - 1][j + 1] = 0;
		data[i - 1][j + 2] = 0;
		data[i - 1][j + 3] = 0;
		break;
	}
	default:
		break;
	}
}

void put_shape4(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 5;
		data[i][j + 1] = 5;
		data[i + 1][j + 1] = 5;
		data[i + 2][j + 1] = 5;
		data[i + 3][j + 1] = 5;
		data[i + 4][j + 1] = 5;
		break;
	}
	case 1:
	{
		data[i][j] = 5;
		data[i + 1][j] = 5;
		data[i + 1][j - 1] = 5;
		data[i + 1][j - 2] = 5;
		data[i + 1][j - 3] = 5;
		data[i + 1][j - 4] = 5;
		break;
	}
	case 2:
	{
		data[i][j] = 5;
		data[i][j - 1] = 5;
		data[i - 1][j - 1] = 5;
		data[i - 2][j - 1] = 5;
		data[i - 3][j - 1] = 5;
		data[i - 4][j - 1] = 5;
		break;
	}
	case 3:
	{
		data[i][j] = 5;
		data[i - 1][j] = 5;
		data[i - 1][j + 1] = 5;
		data[i - 1][j + 2] = 5;
		data[i - 1][j + 3] = 5;
		data[i - 1][j + 4] = 5;
		break;
	}
	default:
		break;
	}
}

void clear_shape4(int **data, int i, int j, int t)
{
	switch (t)
	{
	case 0:
	{
		data[i][j] = 0;
		data[i][j + 1] = 0;
		data[i + 1][j + 1] = 0;
		data[i + 2][j + 1] = 0;
		data[i + 3][j + 1] = 0;
		data[i + 4][j + 1] = 0;
		break;
	}
	case 1:
	{
		data[i][j] = 0;
		data[i + 1][j] = 0;
		data[i + 1][j - 1] = 0;
		data[i + 1][j - 2] = 0;
		data[i + 1][j - 3] = 0;
		data[i + 1][j - 4] = 0;
		break;
	}
	case 2:
	{
		data[i][j] = 0;
		data[i][j - 1] = 0;
		data[i - 1][j - 1] = 0;
		data[i - 2][j - 1] = 0;
		data[i - 3][j - 1] = 0;
		data[i - 4][j - 1] = 0;
		break;
	}
	case 3:
	{
		data[i][j] = 0;
		data[i - 1][j] = 0;
		data[i - 1][j + 1] = 0;
		data[i - 1][j + 2] = 0;
		data[i - 1][j + 3] = 0;
		data[i - 1][j + 4] = 0;
		break;
	}
	default:
		break;
	}
}

bool check_shape0(int **data, int i, int j, int t)
{
	bool flag = true;
	switch (t)
	{
		case 0:
		{
			if (i > 2 || j > 2)
			{
				flag = false;
				break;
			}
			else
			{
				if (data[i][j] != 0 ||
					data[i + 1][j] != 0 ||
					data[i + 2][j] != 0 ||
					data[i + 2][j + 1] != 0 ||
					data[i + 2][j + 2] != 0)
				{
					flag = false;
					break;
				}
			}
			break;
		}
		case 1:
		{
			if (i > 2 || j < 2)
			{
				flag = false;
				break;
			}
			else
			{
				if (data[i][j] != 0 ||
					data[i][j - 1] != 0 ||
					data[i][j - 2] != 0 ||
					data[i + 1][j - 2] != 0 ||
					data[i + 2][j - 2] != 0)
				{
					flag = false;
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (i < 2 || j < 2)
			{
				flag = false;
				break;
			}
			else
			{
				if (data[i][j] != 0 ||
					data[i - 1][j] != 0 ||
					data[i - 2][j] != 0 ||
					data[i - 2][j - 1] != 0 ||
					data[i - 2][j - 2] != 0)
				{
					flag = false;
					break;
				}
			}
			break;
		}
		case 3:
		{
			if (i < 2 || j > 2)
			{
				flag = false;
				break;
			}
			else
			{
				if (data[i][j] != 0 ||
					data[i][j + 1] != 0 ||
					data[i][j + 2] != 0 ||
					data[i - 1][j + 2] != 0 ||
					data[i - 2][j + 2] != 0)
				{
					flag = false;
					break;
				}
			}
			break;
		}
		default:
			break;
	}
	return flag;
}

bool check_shape1(int **data, int i, int j)
{
	bool flag = true;
	if (i > 3 || j > 3)
		flag = false;
	else
		if (data[i][j] != 0 ||
			data[i + 1][j] != 0 ||
			data[i][j + 1] != 0 ||
			data[i + 1][j + 1] != 0)
			flag = false;
	return flag;
}

bool check_shape2(int **data, int i, int j, int t)
{
	bool flag = true;
	switch (t)
	{
	case 0:
	{
		if (i > 1 || j > 3)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i + 1][j] != 0 ||
				data[i + 1][j + 1] != 0 ||
				data[i + 2][j + 1] != 0 ||
				data[i + 3][j + 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 1:
	{
		if (i > 3 || j < 3)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j - 1] != 0 ||
				data[i + 1][j - 1] != 0 ||
				data[i + 1][j - 2] != 0 ||
				data[i + 1][j - 3] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 2:
	{
		if (i < 3 || j < 1)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i - 1][j] != 0 ||
				data[i - 1][j - 1] != 0 ||
				data[i - 2][j - 1] != 0 ||
				data[i - 3][j - 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 3:
	{
		if (i < 1 || j > 1)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j + 1] != 0 ||
				data[i - 1][j + 1] != 0 ||
				data[i - 1][j + 2] != 0 ||
				data[i - 1][j + 3] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return flag;
}

bool check_shape3(int **data, int i, int j, int t)
{
	bool flag = true;
	switch (t)
	{
	case 0:
	{
		if (i > 1 || j > 3)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j + 1] != 0 ||
				data[i + 1][j + 1] != 0 ||
				data[i + 2][j + 1] != 0 ||
				data[i + 3][j + 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 1:
	{
		if (i > 3 || j < 3)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i + 1][j] != 0 ||
				data[i + 1][j - 1] != 0 ||
				data[i + 1][j - 2] != 0 ||
				data[i + 1][j - 3] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 2:
	{
		if (i < 3 || j < 1)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j - 1] != 0 ||
				data[i - 1][j - 1] != 0 ||
				data[i - 2][j - 1] != 0 ||
				data[i - 3][j - 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 3:
	{
		if (i < 1 || j > 1)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i - 1][j] != 0 ||
				data[i - 1][j + 1] != 0 ||
				data[i - 1][j + 2] != 0 ||
				data[i - 1][j + 3] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return flag;
}

bool check_shape4(int **data, int i, int j, int t)
{
	bool flag = true;
	switch (t)
	{
	case 0:
	{
		if (i > 0 || j > 3)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j + 1] != 0 ||
				data[i + 1][j + 1] != 0 ||
				data[i + 2][j + 1] != 0 ||
				data[i + 3][j + 1] != 0 ||
				data[i + 4][j + 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 1:
	{
		if (i > 3 || j < 4)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i + 1][j] != 0 ||
				data[i + 1][j - 1] != 0 ||
				data[i + 1][j - 2] != 0 ||
				data[i + 1][j - 3] != 0 ||
				data[i + 1][j - 4] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 2:
	{
		if (i < 4 || j < 1)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i][j - 1] != 0 ||
				data[i - 1][j - 1] != 0 ||
				data[i - 2][j - 1] != 0 ||
				data[i - 3][j - 1] != 0 ||
				data[i - 4][j - 1] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	case 3:
	{
		if (i < 1 || j > 0)
		{
			flag = false;
			break;
		}
		else
		{
			if (data[i][j] != 0 ||
				data[i - 1][j] != 0 ||
				data[i - 1][j + 1] != 0 ||
				data[i - 1][j + 2] != 0 ||
				data[i - 1][j + 3] != 0 ||
				data[i - 1][j + 4] != 0)
			{
				flag = false;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return flag;
}

void Lines_window::next()
{
	static int i;
	int **data;
	data = all[i];
	++i;
	if (i < all.size())
	{
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
			{
				switch (data[i][j])
				{
				case 1:
				{
					matrix[i][j]->set_fill_color(Color::green);
					break;
				}
				case 2:
				{
					matrix[i][j]->set_fill_color(Color::red);
					break;
				}
				case 3:
				{
					matrix[i][j]->set_fill_color(Color::yellow);
					break;
				}
				case 4:
				{
					matrix[i][j]->set_fill_color(Color::magenta);
					break;
				}
				case 5:
				{
					matrix[i][j]->set_fill_color(Color::blue);
					break;
				}
				default:
					break;
				}
			}
		redraw();
	}
	else
		cout << "all over!" << endl;
}

void put_all()
{
	int i0 = 0, j0 = 0, t0 = 0, i1 = 0, j1 = 0, i2 = 0, j2 = 0, t2 = 0, i3 = 0, j3 = 0, t3 = 0, i4 = 0, j4 = 0, t4 = 0;
	int **data;
	int **x;
	data = new int*[5];
	for (int i = 0; i < 5; ++i)
	{
		data[i] = new int[5];
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			data[i][j] = 0;
	}

	for (i0 = condition[0]; i0 < 5; ++i0)
		for (j0 = condition[1]; j0 < 5; ++j0)
			for (t0 = condition[2]; t0 < 4; ++t0)
			{
				if (check_shape0(data, i0, j0, t0))
				{
					put_shape0(data, i0, j0, t0);
					for (i1 = condition[3]; i1 < 5; ++i1)
						for (j1 = condition[4]; j1 < 5; ++j1)
						{
							if (check_shape1(data, i1, j1))
							{
								put_shape1(data, i1, j1);
								for (i2 = condition[5]; i2 < 5; ++i2)
									for (j2 = condition[6]; j2 < 5; ++j2)
										for (t2 = condition[7]; t2 < 4; ++t2)
										{
											if (check_shape2(data, i2, j2, t2))
											{
												put_shape2(data, i2, j2, t2);
												for (i3 = condition[8]; i3 < 5; ++i3)
													for (j3 = condition[9]; j3 < 5; ++j3)
														for (t3 = condition[10]; t3 < 4; ++t3)
														{
															if (check_shape3(data, i3, j3, t3))
															{
																put_shape3(data, i3, j3, t3);
																for (i4 = condition[11]; i4 < 5; ++i4)
																	for (j4 = condition[12]; j4 < 5; ++j4)
																		for (t4 = condition[13]; t4 < 4; ++t4)
																		{
																			if (check_shape4(data, i4, j4, t4))
																			{
																				put_shape4(data, i4, j4, t4);
																				x = new int*[5];
																				for (int i = 0; i < 5; ++i)
																					x[i] = new int[5];
																				for (int i = 0; i < 5; ++i)
																					for (int j = 0; j < 5; ++j)
																						x[i][j] = data[i][j];
																				all.push_back(x);
																				clear_shape4(data, i4, j4, t4);
																			}
																		}
																clear_shape3(data, i3, j3, t3);
															}
														}
												clear_shape2(data, i2, j2, t2);
											}
										}
								clear_shape1(data, i1, j1);
							}
						}
					clear_shape0(data, i0, j0, t0);
				}
			}
}

int main()
{
	put_all();
	try {
		Lines_window win(Point(100, 100), 800, 800, "lines");
		return gui_main();
	}
	catch (exception& e) {
		cerr << "exception:" << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
		return 2;
	}
	return 0;
}