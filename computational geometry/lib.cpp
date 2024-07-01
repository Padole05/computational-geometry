#include "lib.h"

//1
// _________POINT
// 
//1. a) operators

Point Point::operator+(Point &p){ return Point(x + p.x, y + p.y);}

Point Point::operator-(Point &p){ return Point(x - p.x, y - p.y);}

Point Point::operator*(double k){ return Point(x * k, y * k);}

Point Point::operator/(double k){ return Point(x / k, y / k);}

Point Point::operator=(Point& p)
{
	x = p.x;
	y = p.y;
	return *this;
}

bool Point::operator<(const Point& p) const
{
	return x != p.x ? x < p.x : y < p.y;
}

bool Point::operator==(const Point& p) const
{
	return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
}


//1. b) recipes

double Point::norm() { return x * x + y * y;}

double Point::abs() { return sqrt(norm());}


//1. c) calculations in relationships

Point project(Point& p, Segment& s)
{
	Vector base = s.p2 - s.p1, v = p - s.p1;
	double r = dot(v, base) / norm(base);
	Point b= (base * r);
	Point rs = s.p1 + b;//
	return rs;
}

Point reflect( Point& p, Segment& s)
{
	Point pp = (project(p,s) - p) * 2;
	return p + pp;
}

Point crossPoint(Segment& a, Segment& b)
{
	Vector v1 = get(b.p1, a.p1);
	Vector v2 = get(b.p1, a.p2);
	Vector base = get(b.p1, b.p2);
	Vector v = get(a.p1, a.p2);
	double d1 = abs(cross(v1, base));
	double d2 = abs(cross(v2, base));
	Point r = (v * (d1 / (d1 + d2)));
	return a.p1 + r;
}

double getDistance(Point& a, Point& b)
{
	Vector v = a - b;
	return abs(v);
}

double getDistancePS(Point& p, Segment& s)
{
	Vector a = s.p2 - s.p1, b = p - s.p1;
	if (dot(a, b) < 0.0)return abs(b);
	Vector c = s.p1 - s.p2, d = p - s.p2;
	if (dot(c, d))return abs(d);
	return getDistancePL(p,s);
}




//2
// _________VECTOR
//
 
//2. a) recipes
double norm(Vector &a){	return a.x * a.x + a.y * a.y;}

double abs(Vector &a){ return sqrt(norm(a));}

Vector get(Point& p1, Point& p2){ return Vector(p2-p1);}


//2. b) calculations in relationships

double dot(Vector& a, Vector& base){ return base.x * a.x + base.y * a.y;}

double cross(Vector &a, Vector& base){ return base.x * a.y - base.y * a.x;}

bool isOrthogonal(Point& a1, Point& a2, Point& b1, Point& b2)
{
	Vector a = a1 - a2;
	Vector b = b1 - b2;
	return isOrthogonal(a, b);
}

bool isParallel(Point& a1, Point& a2, Point& b1, Point& b2)
{
	Vector a = a1 - a2;
	Vector b = b1 - b2;
	return isParallel(a, b);
}

bool isOrthogonal(Vector& a, Vector& b){ return equals(dot(a, b), 0.0);}

bool isParallel(Vector &a, Vector &b){ return equals(cross(a, b), 0.0);}

int ccw(Point& p, Point& p1base, Point& p2base)
{
	Vector base = p2base - p1base;
	Vector a = p - p1base;
	if (cross(a, base) > EPS)return COUNTER_CLOCKWISE;
	if (cross(a, base) < -EPS)return CLOCKWISE;
	if (dot(a, base) < -EPS)return ONLINE_BACK;
	if (base.norm() < a.norm())return ONLINE_FRONT;
	return ON_SEGMENT;
}

int ccw(Point& p, Segment& base){ return ccw(p, base.p1, base.p2);}




//3
// _______SEGMENT
// 

//3. a) operators
Segment Segment::operator=(Segment& s)
{
	// TODO: insert return statement here
	this->p1 = s.p1;
	this->p2 = s.p2;
	return *this;
}


//3. b) calculations in relationships
bool isOrthogonal(Segment& s1, Segment& s2)
{
	Vector a = s1.p2 - s1.p1, b = s2.p2 - s2.p1;
	return equals(dot(a, b), 0.0);
}

bool isParallel(Segment& s1, Segment& s2)
{
	Vector a = s1.p2 - s1.p1, b = s2.p2 - s2.p1;
	return equals(cross(a, b), 0.0);
}

double getDistance(Segment& a, Segment& b)
{
	if (intersect(a, b))return 0;
	return min(min(getDistancePS(a.p1, b), getDistancePS(a.p2, b)), min(getDistancePS(b.p1, a), getDistancePS(b.p2, a)));
}

bool intersect(Point& p1, Point& p2, Point& p3, Point& p4)
{
	return (ccw(p3, p1, p2) * ccw(p4, p1, p2) <= 0 && ccw(p1, p3, p4) * ccw(p2, p3, p4) <= 0);
}

bool intersect(Segment& a, Segment& b){	return intersect(a.p1, a.p2, b.p1, b.p2);}

double getDistancePL(Point& p, Line& l)
{
	Vector a = l.p2 - l.p1, b = p - l.p1;
	return abs(cross(a, b) / abs(a));
}
