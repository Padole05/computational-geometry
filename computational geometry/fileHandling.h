#pragma once
#include"lib.h"
//q(l1), 1 seg/line (q lines)
bool read1(string fileName, vector<Segment>& Data);
//fout 1 int/line
bool write1(string fileName, vector<int>& result);
Segment read1SegmentPerLine(istringstream& ss);
Point read1PointPerLine(istringstream& ss);
//read n points in a line
bool readPointsLine(vector<Point>& datPt, int n, istringstream& ss);
//read q lines, n points/line
bool readLinesPoints(vector<Point>& datPt,int n, int q, ifstream& fin, string& line);
//1 seg(l1), q(l2), 1 pt/line (q lines)
bool read2(string fn, vector <Segment>& datSeg, vector<Point>& datPt);
void write1PointPerLine(Point& p, ofstream& fout);
//fout 1 pt/line
bool write2(string fn, vector<Point>& result);
//seg[i]=(pt[2i],pt[2i+1])
bool readSegsFromPoints(vector<Segment>& datSeg, vector<Point>& datPt, int start, int end);
//q(l1), 2 seg/line (q lines)
bool read4(string fn, vector <Segment>& datSeg, vector<Point>& datPt);
//fout 1 double/line
bool write4(string fileName, vector<double>& result);

