#include "fileHandling.h"


bool read1(string fileName, vector<Segment>& Data)
{
	int q = 0; //number of pairs to compare || num lines to read
	// Creation of ifstream class object to read the file
	ifstream fin;
	// by default open mode = ios::in mode
	fin.open(fileName);
	if (!fin.is_open()) { cout << "error open file1\n"; return false; }
	string line;

	//read q
	getline(fin, line);
	q = stoi(line);

	Segment s;
	string pos;

	for (int i = 0; i < q; i++)	//read q lines
	{
		getline(fin, line);
		istringstream ss(line);

		//read 2 segments' data

		//read s1.p1
		//x
		getline(ss, pos, ' ');
		s.p1.x = stod(pos);
		//y
		getline(ss, pos, ' ');
		s.p1.y = stod(pos);

		//read s1.p2
		//x
		getline(ss, pos, ' ');
		s.p2.x = stod(pos);
		//y
		getline(ss, pos, ' ');
		s.p2.y = stod(pos);

		//push s1 to data
		Data.push_back(s);

		//read s2.p1
		//x
		getline(ss, pos, ' ');
		s.p1.x = stod(pos);
		//y
		getline(ss, pos, ' ');
		s.p1.y = stod(pos);

		//read s2.p2
		//x
		getline(ss, pos, ' ');
		s.p2.x = stod(pos);
		//y
		getline(ss, pos);
		s.p2.y = stod(pos);

		//push s2 to data
		Data.push_back(s);

	}
	fin.close();
	return true;
}

bool write1(string fileName, vector<int>& result)
{
	ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		cout << "error open close file\n";
		return false;
	}

	for (int i = 0; i < result.size(); i++)
		fout << result[i] << endl;

	fout.close();
	return true;
}

Segment read1SegmentPerLine(istringstream& ss)
{
	Segment s;
	string pos;
	//read s.p1
	//x
	getline(ss, pos, ' ');
	s.p1.x = stod(pos);
	//y
	getline(ss, pos, ' ');
	s.p1.y = stod(pos);

	//read s.p2
	//x
	getline(ss, pos, ' ');
	s.p2.x = stod(pos);
	//y
	getline(ss, pos);
	s.p2.y = stod(pos);

	return s;
}

Point read1PointPerLine(istringstream& ss)
{
	Point p;
	string pos;
	//read x
	getline(ss, pos, ' ');
	p.x = stod(pos);
	//read y
	getline(ss, pos, ' ');
	p.y = stod(pos);
	return p;
}

bool readPointsLine(vector<Point>& datPt, int n, istringstream& ss)
{
	Point p;
	string pos;

	for (int i = 0; i < n; i++)
	{
		//read x
		getline(ss, pos, ' ');
		p.x = stod(pos);
		//read y
		getline(ss, pos, ' ');
		p.y = stod(pos);
		datPt.push_back(p);
	}
	return true;
}

bool readLinesPoints(vector<Point>& datPt,int n, int q, ifstream& fin, string& line)
{
	for (int i = 0; i < q; i++)
	{
		getline(fin, line);
		istringstream ss(line);
		readPointsLine(datPt, n, ss);
	}
	return true;
}


bool read2(string fn, vector<Segment>& datSeg, vector<Point>& datPt)
{
	ifstream fin;
	fin.open(fn);
	if (!fin.is_open()) { cout << "error open file1\n"; return false; }

	string line;

	getline(fin, line);
	istringstream ss(line);

	//read 1 line of segment, push s to data
	datSeg.push_back(read1SegmentPerLine(ss));

	int q;
	getline(fin, line);
	q = stoi(line);
	//read q lines, 1p/line
	readLinesPoints(datPt,1, q, fin, line);

	fin.close();
	return true;
}

void write1PointPerLine(Point& p, ofstream& fout)
{
	fout << p.x << ' ' << p.y << endl;
}

bool write2(string fn, vector<Point>& result)
{
	ofstream fout;
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "error open close file\n";
		return false;
	}

	if (result.size() <= 0)return false;
	for (int i = 0; i < result.size(); i++)
		write1PointPerLine(result[i], fout);
	fout.close();
	return true;
}

bool readSegsFromPoints(vector<Segment>& datSeg, vector<Point>& datPt, int start, int end)
{
	if (end<=start)return false;

	int i = start;
	while (i < end)
	{
		Segment s(datPt[i], datPt[i + 1]);
		datSeg.push_back(s);
		i += 2;
	}
	/*for (i = 0; i < datSeg.size(); i++)
		cout << datSeg[i].p1.x << ' ' << datSeg[i].p1.y <<' '<< datSeg[i].p2.x << ' ' << datSeg[i].p2.y << endl;*/

	return true;
}

bool read4(string fn, vector<Segment>& datSeg, vector<Point>& datPt)
{
	ifstream fin;
	fin.open(fn);
	if (!fin.is_open()) { cout << "error open file1\n"; return false; }

	string line;
	int q;
	getline(fin, line);
	q = stoi(line);

	readLinesPoints(datPt, 4, q, fin, line);//checked
	readSegsFromPoints(datSeg, datPt, 0, datPt.size() - 1);//checked
	fin.close();
	return false;
}

bool write4(string fileName, vector<double>& result)
{
	ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		cout << "error open close file\n";
		return false;
	}

	int n = result.size();
	for (int i = 0; i < n; i++)
		fout << result[i] << endl;

	fout.close();
	return true;
}



