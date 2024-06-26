#pragma once
#include"const.h"

#define EPS (1e-10)	//dung sai min
#define equals(a,b) (fabs (a-b)<EPS  ) //a==b if |a-b| < dung sai

class Segment;

class Point
{
public:
	double x, y;
	Point() :x(0), y(0) {}
	Point(double x, double y) :x(x), y(y) {}
	//add
	Point operator + (Point p);
	//minus
	Point operator - (Point p);
	//scaling
	Point operator*(double k);
	//copy
	Point operator=(Point& p);

	//norm & absolute
	double norm();
	double abs();
	//smaller
	bool operator < (const Point& p)const;
	//equal
	bool operator ==(const Point& p)const;
};

//hinh chieu
Point project(Segment& s, Point& p);
//phan xa
Point reflex(Segment& s, Point& p);


typedef Point Vector;

double norm(Vector a);
//absolute - the physical length
double abs(Vector a);
//dot product a.b=|a||b|cos(ab)
double dot(Vector a, Vector b);
//cross product |axb|=|a||b|sin(ab)
double cross(Vector a, Vector b);


//doan thang
class Segment
{
public:
	Point p1, p2;
	Segment() :p1(), p2() {}
	Segment(Point a, Point b) :p1(a), p2(b) {}
	Segment operator =(Segment& s);

};

typedef Segment Line;
//qhe giua 2 dg thang

//vuong
bool isOrthogonal(Vector a, Vector b);
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2);
bool isOrthogonal(Segment s1, Segment s2);

// song song
bool isParallel(Vector a, Vector b);
bool isParallel(Point a1, Point a2, Point b1, Point b2);
bool isParallel(Segment s1, Segment s2);



//circle
class Circle
{
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0) :c(c), r(r) {}
};


//da giac
typedef vector<Point> Poligon;
