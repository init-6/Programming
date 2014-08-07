#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

const int highwaySpeedLimit = 65;
const int streetSpeedLimit = 30;

class Road
{      double dist;
	public:
	        Road(double d)
		{
		dist = d;
		}
		int getDistance();
		double getTime();
		virtual ~Road() { cout << "In base class dest" << endl; }

};


int Road::getDistance()
{
	return dist;
}


class Highway : public Road
{

	public:
		Highway();
	  	~Highway() { cout << "Killing Highway" << endl;}
};


class Street : public Road
{

	public : 
		Street();
		~Street() { cout << "Killing street" << endl; }
};


int main()
{
	string s;
	int totDist=0;
	double totTime =0.0;
	while(getline(cin,s))
	{
		stringstream ss;
		size_t pos1 = s.find(",");
		string roadName = s.substr(0,pos1);
		cout << roadName << endl;
		char roadType; double dist;
		string rType = s.substr(pos1+1,1);
		string rDist = s.substr(pos1+3);
		ss << rType; ss >> roadType;
		ss << rDist; ss >> dist;
		
		Road *rd;
		if(roadType == 'H')
		{
			rd = new Highway(roadname,roadDist,highwaySpeedLimit);
		}
		else
		{
			rd = new Street(roadName,roadType,streetSpeedLimit);
		}

		totDist += rd->getDistance();
		totTime += rd->getTime();
		delete rd;
	}
}
