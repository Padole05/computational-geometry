#pragma once
#include"lib.h"
//always close files!


//1
// ___RECYCLE

//all trash but they worked so I'm not touching
Segment read1SegmentPerLine(istringstream& ss);
Point read1PointPerLine(istringstream& ss);
void write1PointPerLine(Point& p, ofstream& fout);


//1. a) read

//read n points in a line
bool readPointsLine(vector<Point>& datPt, int n, istringstream& ss);

//read q lines, n points/line
bool readLinesPoints(vector<Point>& datPt, int n, int q, ifstream& fin);

//seg[i]=(pt[2i],pt[2i+1])
bool readSegsFromPoints(vector<Segment>& datSeg, vector<Point>& datPt, int start, int end);

//read n circle(x,y,r) in a line
bool readCirclesLine(vector<Circle>& datC, int n, istringstream& ss);

//read n circle(x,y,r)/line, q lines
bool readLinesCircles(vector<Circle>& datC, int n, int q, ifstream& fin);

//read n poligons
bool readPoligons(Poligon& datPlg, int n, ifstream& fin);


//1. b) write

//fout<<x<<' '<<y
bool wP(Point& p, ofstream& fout);

//fout n points/line
bool writePoints(vector<Point>& result, int n, ofstream& fout);

//fout 1 pair<Point,Point>/line
bool writePair2Pts(vector<pair<Point, Point>>& result, ofstream& fout);

//fout 1 seg/line
//bool writeSeg(vector<Segment>& result);




//2
// ___EXAMPLEs


//2. a) read

//int q(l1), 1 seg/line (q lines)
bool read1(string fileName, vector<Segment>& Data);

//1 seg(l1), q(l2), 1 pt/line (q lines)
bool read2(string fn, vector <Segment>& datSeg, vector<Point>& datPt);

//int q(l1), 2 seg/line (q lines)
bool read4(string fn, vector <Segment>& datSeg, vector<Point>& datPt);

//1 point + 1 double(l1),int q(l2), 1 l/line (q lines)
bool read8(string fn, vector <Line>& datL, vector<Circle>& datC);

//Circle o1(l1), o2(l2)
bool read9(string fn, vector<Circle>& datC);

//Poligon[ int n(l1), 1 pt/line (n lines)], int q(line n+2), 1 pt/line (q lines)
bool read10(string fn, Poligon& datPlg, vector<Point>& datPt);


//2. b) write

//fout 1 int/line
bool write1(string fileName, vector<int>& result);

//fout 1 pt/line
bool write2(string fn, vector<Point>& result);

//fout 1 double/line
bool write4(string fileName, vector<double>& result);

//fout a pair<Point,Point>/line
bool write8(string fn, vector<Segment>& result);