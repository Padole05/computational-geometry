#include "fileHandling.h"

//bool readPoint()
bool read1a(string fileName, vector<Segment>& Data)
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

bool write1a(string fileName, vector<int>& result)
{
	ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		cout << "error open close file\n";
		return false;
	}

	if (result.size() <= 0)return true;
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

bool read1b(string fn, vector<Segment>& datSeg, vector<Point>& datPt)
{
	ifstream fin;
	fin.open(fn);
	if (!fin.is_open()) { cout << "error open file1\n"; return false; }

	string line;
	string pos;

	getline(fin, line);
	istringstream ss(line);

	//push s to data
	datSeg.push_back(read1SegmentPerLine(ss));

	int q;
	getline(fin, line);
	q = stoi(line);
	for (int i = 0; i < q; i++)
	{
		getline(fin, line);
		istringstream ss(line);
		datPt.push_back(read1PointPerLine(ss));
	}
	fin.close();
	return true;
}

void write1PointPerLine(Point& p, ofstream& fout)
{
	fout << p.x << ' ' << p.y << endl;
}

bool write1b(string fn, vector<Point>& result)
{
	ofstream fout;
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "error open close file\n";
		return false;
	}

	if (result.size() <= 0)return true;
	for (int i = 0; i < result.size(); i++)
		write1PointPerLine(result[i], fout);
	return true;
}

bool read1c(string fn, vector<Segment>& datSeg, vector<Point>& datPt)
{
	ifstream fin;
	fin.open(fn);
	if (!fin.is_open()) { cout << "error open file1\n"; return false; }

	string line;
	string pos;

	getline(fin, line);
	istringstream ss(line);

	//push s to data
	datSeg.push_back(read1SegmentPerLine(ss));


	return true;
}

