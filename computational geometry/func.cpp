#include "func.h"

bool xuly1a(string fi, string fo)
{
	vector<Segment> data;
	vector<int>result;
	if (!read1a(fi, data))return false;

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


	if (!write1a(fo, result))return false;
	data.clear();
	result.clear();
	return true;
}

bool xuly1b(string fi, string fo)
{
	Point p;
	vector<Segment> datSeg;
	vector<Point> datPt;
	vector<Point> result;
	if (!read1b(fi, datSeg, datPt)) return false;
	for (int i = 0; i < datPt.size(); i++)
		result.push_back(project(datSeg[0], datPt[i]));
	if (!write1b(fo, result)) return false;
	result.clear();
	datPt.clear();
	return true;
}

