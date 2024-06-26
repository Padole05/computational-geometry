#include "lib.h"

Point project(Segment& s, Point& p)
{
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / norm(base);
	Point rs = s.p1 + base * r;
	return rs;
}

Point reflex(Segment& s, Point& p)
{
	return p + (project(s, p) - p) * 2;
}

double norm(Vector a)
{
	return a.x * a.x + a.y * a.y;
}

double abs(Vector a)
{
	return sqrt(norm(a));
}

double dot(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
	return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(Vector a, Vector b)
{
	return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2)
{
	return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2)
{
	return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Vector a, Vector b)
{
	return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2)
{
	return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2)
{
	return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Point Point::operator+(Point p)
{
	return Point(x + p.x, y + p.y);
}


Point Point::operator-(Point p)
{
	return Point(x - p.x, y - p.y);
}

Point Point::operator*(double k)
{
	return Point(x * k, y * k);
}


Point Point::operator=(Point& p)
{
	// TODO: insert return statement here
	x = p.x;
	y = p.y;
	return *this;
}






double Point::norm() { return x * x + y * y; }

double Point::abs() { return sqrt(norm()); }

bool Point::operator<(const Point& p) const
{
	return x != p.x ? x < p.x : y < p.y;
}

bool Point::operator==(const Point& p) const
{
	return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
}

Segment Segment::operator=(Segment& s)
{
	// TODO: insert return statement here
	this->p1 = s.p1;
	this->p2 = s.p2;
	return *this;
}

