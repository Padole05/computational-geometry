//I prioritise object than base because object is still the object but scale defines that object varies
#pragma once
#include"const.h"

#define EPS (1e-10)	//dung sai min
#define equals(a,b) (fabs(a-b)<EPS) //a==b if |a-b| < dung sai

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

class Segment;

//1
// _________POINT
// 
class Point
{
public:
	double x, y;
	//constructors
	Point() :x(0), y(0) {}
	Point(double x, double y) :x(x), y(y) {}

	//1. a) operators
	//add
	Point operator + (Point&p);
	//minus
	Point operator - (Point&p);
	//scaling
	Point operator*(double k);
	Point operator/(double k);
	//copy
	Point operator=(Point& p);
	//smaller
	bool operator < (const Point& p)const;
	//equal
	bool operator ==(const Point& p)const;

	//1. b) recipes
	//norm = x^2 + y^2
	double norm();
	//absolute = |x^2 + y^2|
	double abs();
};

//1. c) calculations in relationships
//check square vector a vs b
bool isOrthogonal(Point& a1, Point& a2, Point& b1, Point& b2);
//check parallel vector a(a1->a2) vs b(b1->b2)
bool isParallel(Point& a1, Point& a2, Point& b1, Point& b2);
//projection of Point p to Segment s; 
// s.p1+base^2.(p1,p)/(|base|^2)
Point project(Point& p, Segment& s);
//reflection of Point p to Segment s;
//  2(p,project)
Point reflect(Point& p, Segment& s);
//distance from 2 points; 
// |a,b|
double getDistance(Point& a, Point& b);
//distance from Point p to Segment s;
//  |project|
double getDistancePS(Point& p, Segment& s);




//2
// _________VECTOR
typedef Point Vector;
//2. a) recipes
//norm = x^2 + y^2
double norm(Vector&a);
//absolute - the physical length
double abs(Vector &a);

//2. b) calculations in relationships
//dot product a.b=|a||b|cos(ab)
double dot(Vector& a, Vector& base);
//cross product |axb|=|a||b|sin(ab)
double cross(Vector& a, Vector& base);
//check square vector a vs b
bool isOrthogonal(Vector& a, Vector& b);
//check parallel vector a vs b
bool isParallel(Vector& a, Vector& b);
//clock-direction of (p1base,p) to (p1base,p2base)  
int ccw(Point& p, Point& p1base, Point& p2base);
//clock-direction of (base.p1,p) to (base.p1,base.p2)
int ccw(Point& p, Segment &base);


//3
// _______SEGMENT
// 
class Segment
{
public:
	Point p1, p2;
	//constructors
	Segment() :p1(), p2() {}
	Segment(Point a, Point b) :p1(a), p2(b) {}

	//3. a) operators
	Segment operator =(Segment& s);
};

//3. b) calculations in relationships
//check square s1 vs s2
bool isOrthogonal(Segment& s1, Segment& s2);
//check s1 parallel s2
bool isParallel(Segment& s1, Segment& s2);
//distance between 2 segments
double getDistance(Segment& a, Segment& b);
//check if seg(p1,p2) cut seg(p3,p4)
bool intersect(Point& p1, Point& p2, Point& p3, Point& p4);
//check if 2 segments cut each other
bool intersect(Segment& a, Segment& b);

typedef Segment Line;
//distance from Point p to Line l
double getDistancePL( Point& p, Line& l);



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
