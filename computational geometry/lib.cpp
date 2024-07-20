#include "lib.h"

//1
// _________POINT
// 
//1. a) operators

Point Point::operator+(Point p){ return Point(x + p.x, y + p.y);}

Point Point::operator-(Point p){ return Point(x - p.x, y - p.y);}

Point Point::operator*(double k){ return Point(x * k, y * k);}

Point Point::operator/(double k){ return Point(x / k, y / k);}

Point Point::operator=(Point p)
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

double Point::norm(){ return x * x + y * y;}

double Point::abs(){ return sqrt(norm());}


//1. c) calculations in relationships

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
	return getDistancePL(p, s);
}

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
	Vector v1 = vec(b.p1, a.p1);
	Vector v2 = vec(b.p1, a.p2);
	Vector base = vec(b.p1, b.p2);
	Vector v = vec(a.p1, a.p2);
	double d1 = abs(cross(v1, base));
	double d2 = abs(cross(v2, base));
	Point r = (v * (d1 / (d1 + d2)));
	return a.p1 + r;
}






//2
// _________VECTOR
//
 
//2. a) recipes

Vector vec(Point& p1, Point& p2) { return Vector(p2 - p1); }

Vector vec(Segment& s) { return Vector(s.p2 - s.p1); }

double norm(Vector a){	return a.x * a.x + a.y * a.y;}

double abs(Vector a){ return sqrt(norm(a));}

double abs(Point& p1, Point& p2){ return abs(vec(p1, p2));}




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



Vector polar(double a, double r){ return Point(cos(r) * a, sin(r) * a);}

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




//4
// ______CIRCLE
//


//4. a) calculations in relationships

bool intersect(Circle& o, Line& l)
{
	if (getDistancePL(o.c, l) > o.r)return false;
	return true;
}

bool intersect(Circle& o1, Circle& o2)
{
	if (getDistance(o1.c, o2.c) > (o1.r + o2.r))return false;
	return true;
}

Segment getCrossPoints(Circle& o, Line& l)
{
	assert(intersect(o, l));
	Vector h = project(o.c, l);
	Vector vl = l.p2 - l.p1;
	double base = sqrt(o.r * o.r - norm(h - o.c));
	Vector e = (vl / abs(vl)) * base;
	Point p1 = h - e, p2 = h + e;
	Segment rs(p1, p2);
	return rs;
}
 
Segment getCrossPts(Circle& o1, Circle& o2)
{
	assert(intersect(o1, o2));
	double d = abs(o1.c - o2.c);
	double a = acos((o1.r * o1.r + d * d - o2.r * o2.r) / (2 * o1.r * d));
	double t = arg(o2.c - o1.c);//base rad
	return Segment(o1.c + polar(o1.r, t - a), o1.c + polar(o1.r, t + a));
}





//5
// ______POLIGON
//points arranged counter-clockwisely 


//5. a) calculations in relationships

int contains(Poligon& g, Point &p)
{
	int n = g.size();
	bool x = false;

	for (int i = 0; i < n; i++)
	{
		Point b = g[i] - p, a = g[(i + 1) % n] - p;
		double c = cross(a, b);
		if (abs(c) < EPS && dot(a, b) < EPS)return 1;
		if (a.y > b.y)swap(a, b);
		if (a.y < EPS && EPS<b.y && c>EPS)x = !x;
	}

	return (x ? 2 : 0);
}

int contains(Point& p, Poligon& g)
{
	//int n = g.size();
	//Vector base;
	//int pos, result;

	//for (int i = 0; i < n-1; i++)
	//{
	//	//base = g[i + 1] - g[i];
	//	pos = ccw(p, g[i], g[i + 1]);
	//	if (pos == ONLINE_FRONT)return ON;
	//	if(pos==)
	//}
	return 0;
}

double arg(Vector p){return atan2(p.y, p.x);}
