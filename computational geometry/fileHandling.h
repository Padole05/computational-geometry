#pragma once
#include"lib.h"
bool read1a(string fileName, vector<Segment>& Data);
bool write1a(string fileName, vector<int>& result);
Segment read1SegmentPerLine(istringstream& ss);
Point read1PointPerLine(istringstream& ss);
bool read1b(string fn, vector <Segment>& datSeg, vector<Point>& datPt);
void write1PointPerLine(Point& p, ofstream& fout);
bool write1b(string fn, vector<Point>& result);
bool read1c(string fn, vector <Segment>& datSeg, vector<Point>& datPt);
bool write1c(string fileName, vector<double>& result);

