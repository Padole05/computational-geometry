//I prioritise object over bases
// because objects r consistent,
// while bases/scales define them vary

#pragma once
#include"const.h"

#define EPS (1e-10)	//dung sai min
#define equals(a,b) (fabs(a-b)<EPS) //a==b if |a-b| < dung sai

//clock-directions, human POV

//v(L)_base(R)
static const int COUNTER_CLOCKWISE = 1;
//base(L)_v(R)
static const int CLOCKWISE = -1;
//v=-k*base (k>0)
static const int ONLINE_BACK = 2;
//0<=v<=base
static const int ONLINE_FRONT = -2;
//base<v
static const int ON_SEGMENT = 0;


//status point vs shape
typedef enum Contains{OUT,ON,IN};


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
	Point operator + (Point p);
	//minus
	Point operator - (Point p);
	//scaling
	Point operator*(double k);
	Point operator/(double k);
	//copy
	Point operator=(Point p);
	//smaller
	bool operator < (const Point& p)const;
	//equal
	bool operator ==(const Point& p)const;


	//1. b) recipes

	//norm = x^2 + y^2
	double norm();
	//absolute |xy| = (x^2 + y^2)^(-2)
	double abs();
};


//1. c) calculations in relationships

//distance from 2 points; 
// =|a,b|
double getDistance(Point& a, Point& b);

//distance from Point p to Segment s;
//  =|p->projection|
double getDistancePS(Point& p, Segment& s);

//projection of Point p to Segment s; 
// =s.p1+base^2.(p1,p)/(|base|^2)
Point project(Point& p, Segment& s);

//reflection of Point p to Segment s;
//  =2(p,project)
Point reflect(Point& p, Segment& s);

//point p = a cut b
//(a1p/pa2)=(a1h1/a2h2) -> p
//h1=a1 proj b, h2=a2 proj b
Point crossPoint(Segment& a, Segment& b);





//2
// _________VECTOR
typedef Point Vector;


//2. a) recipes

//norm = x^2 + y^2
double norm(Vector a);

//absolute - the physical length
double abs(Vector a);

//absolute - the physical length
double abs(Point& p1, Point& p2);

//get vector(p1,p2)
Vector vec(Point& p1, Point& p2);
Vector vec(Segment& s);


//2. b) calculations in relationships

//dot product a.b=|a||b|cos(ab)
double dot(Vector& a, Vector& base);

//cross product |axb|=|a||b|sin(ab)
// =height*|base|
double cross(Vector& a, Vector& base);

//check square vector a vs b
//true (dot==0)
bool isOrthogonal(Point& a1, Point& a2, Point& b1, Point& b2);

//check parallel vector a(a1->a2) vs b(b1->b2)
//true (cross==0)
bool isParallel(Point& a1, Point& a2, Point& b1, Point& b2);

//check square vector a vs b
//true (dot==0)
bool isOrthogonal(Vector& a, Vector& b);

//check parallel vector a vs b
//true (cross==0)
bool isParallel(Vector& a, Vector& b);

//clock-direction of (p1base,p) to (p1base,p2base)
//COUNTER_CLOCKWISE        1;
//CLOCKWISE		-1;
//ONLINE_BACK		 2;
//ONLINE_FRONT		-2;
//ON_SEGMENT		 0;
int ccw(Point& p, Point& p1base, Point& p2base);

//clock-direction of (base.p1,p) to (base.p1,base.p2)
//COUNTER_CLOCKWISE        1;
//CLOCKWISE		-1;
//ONLINE_BACK		 2;
//ONLINE_FRONT		-2;
//ON_SEGMENT		 0;
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

//(cos(r)*a, sin(r)*a)
Vector polar(double a, double r);

//check square s1 vs s2
//true (dot==0)
bool isOrthogonal(Segment& s1, Segment& s2);

//check s1 parallel s2
//true (cross==0)
bool isParallel(Segment& s1, Segment& s2);

//distance between 2 segments
//	return min(min(getDistancePS(a.p1, b), getDistancePS(a.p2, b)), min(getDistancePS(b.p1, a), getDistancePS(b.p2, a)));
double getDistance(Segment& a, Segment& b);

//check if seg(p1,p2) cut seg(p3,p4)
//	return (ccw(p3, p1, p2) * ccw(p4, p1, p2) <= 0 && ccw(p1, p3, p4) * ccw(p2, p3, p4) <= 0);
bool intersect(Point& p1, Point& p2, Point& p3, Point& p4);

//check if 2 segments cut each other
//	return (ccw(p3, p1, p2) * ccw(p4, p1, p2) <= 0 && ccw(p1, p3, p4) * ccw(p2, p3, p4) <= 0);
bool intersect(Segment& a, Segment& b);




typedef Segment Line;

//distance from Point p to Line l
// =abs(p,proj)
double getDistancePL( Point& p, Line& l);





//4
// ______CIRCLE
//
class Circle
{
public:
	Point c;
	double r;
	//constructors
	Circle() :c(), r(0) {}
	Circle(Point c,double r):c(c),r(r){}

};


//4. a) calculations in relationships

//check if Line cut Circle
bool intersect(Circle& o, Line& l);

//check if Circle1 cut Circle2
bool intersect(Circle& o1, Circle& o2);

//get seg(p1,p2) = circle cut line
//p2=CH+base, p1=CH-base
//|base|^2=r^2-CH^2, base=line*|base|
//H=project C->line
Segment getCrossPoints(Circle& o, Line& l);

//get seg(p1,p2) = circle1 cut circle2
//baseRad=<O,O1,O2>
//a=<O2,O1,p2>
//p2=O1+r1*cos(baseRad+a)
//p1=O1+r1*cos(baseRad-a)
Segment getCrossPts(Circle& o1, Circle& o2);





//5
// ______POLIGON
//points arranged counter-clockwisely 
typedef vector<Point> Poligon;


//5. a) calculations in relationships

//check if poligon contains point
//IN	2
//ON	1
//OUT	0
int contains(Poligon& g, Point &p);

//check if poligon contains point
//IN	2
//ON	1
//OUT	0
int contains(Point& p, Poligon& g);




//angles

//radian of angle xOp
double arg(Vector p);