#include "func.h"

bool xuly1(string fi, string fo)
{
	vector<Segment> data;
	vector<int>result;
	if (!read1(fi, data))return false;

	int i = 0;
	while (i < data.size())
	{
		if (isOrthogonal(data[i], data[i + 1]))
			result.push_back(1);
		else
			if (isParallel(data[i], data[i + 1]))
				result.push_back(2);
			else
				result.push_back(0);
		i += 2;
	}

	if (!write1(fo, result))return false;
	
	data.clear();
	result.clear();
	return true;
}

bool xuly2(string fi, string fo)
{
	Point p;
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<Point> result;

	if (!read2(fi, datSeg, datPt)) return false;

	for (int i = 0; i < datPt.size(); i++)
		result.push_back(project(datPt[i], datSeg[0]));
	
	if (!write2(fo, result)) return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear();
	return true;
}

bool xuly3(string fi, string fo)
{
	Point p;
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<Point> result;

	if (!read2(fi, datSeg, datPt)) return false;

	for (int i = 0; i < datPt.size(); i++)
		result.push_back(reflect(datPt[i], datSeg[0]));

	if (!write2(fo, result)) return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear();
	return true;
}

bool xuly4(string fi, string fo)
{
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<double>result;

	if (!read4(fi, datSeg, datPt))return false;
	
	for (int i = 0; i < datSeg.size() - 1; i += 2)
		result.push_back(getDistance(datSeg[i], datSeg[i + 1]));
	
	if (!write4(fo, result))return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear();
	return true;
}

bool xuly5(string fi, string fo)
{
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<int>result;
	
	if (!read2(fi, datSeg, datPt))return false;
	
	for (int i = 0; i < datPt.size(); i++)
		result.push_back(ccw(datPt[i], datSeg[0]));
	
	if (!write1(fo, result))return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear();
	return true;
}

bool xuly6(string fi, string fo)
{
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<int>result;
	
	if (!read4(fi, datSeg, datPt))return false;
	
	for (int i = 0; i < datSeg.size() - 1; i += 2)
		result.push_back(intersect(datSeg[i], datSeg[i + 1]));
	
	if (!write1(fo, result))return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear();
	return true;
}

bool xuly7(string fi, string fo)
{
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<Point>result;
	
	if (!read4(fi, datSeg, datPt))return false;
	
	for (int i = 0; i < datSeg.size() - 1; i += 2)
		result.push_back(crossPoint(datSeg[i], datSeg[i + 1]));
	
	if (!write2(fo, result))return false;
	
	result.clear();
	datSeg.clear();
	datPt.clear(); 
	return true;
}

bool xuly8(string fi, string fo)
{
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<Point>result;
	double r;
}


