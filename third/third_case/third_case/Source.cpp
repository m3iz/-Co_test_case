#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

bool endParse = false;

class Point
{
public:
	Point(float px = 0, float py = 0, float pz = 0)
	{
		x = px;
		y = py;
		z = pz;
	};
	float getCordx()
	{
		return x;
	}
	float getCordy()
	{
		return y;
	}
	float getCordz()
	{
		return z;
	}
protected:
	float x, y, z;
};

class Manipulator : public Point
{
public:
	Manipulator(float px, float py, float pz = 0)
	{
		x = px;
		y = py;
		z = pz;
	}
	void setCordX(float px)
	{
		x = px;
	}
	void setCordY(float py)
	{
		y = py;
	}
	void setCordZ(float pz)
	{
		z = pz;
	}
	void printCords()
	{
		printf("%f %f %f\n", x, y, z);
	}
};

vector <int> parseGcode(string str)
{
	vector <int> result;
	if (str[0] == 'X')
	{
		char a = NULL;
		int i = 1;
		int j = 0;
		char temp[5];
		while (i <= str.length())
		{
			if (endParse)break;
			if ('0' <= str[i] && str[i] <= '9' || (str[i] == '-' && !('0' <= str[i] && str[i] <= '9')))
			{
				temp[j] = str[i];
				j++;
			}
			else if (str[i] == ';')
			{
				if ((result.size() == 0 && str[i + 1] == 'Y') || (result.size() == 1 && str[i + 1] == 'Z') || (result.size() == 2))
				{
					temp[j] = '\0';
					result.push_back(atoi(temp));
					memset(temp, 0, 5);
					j = 0;
					i++;
				}
			}
			else endParse = true;
			i++;
		}
	}
	else
	{
		char a = NULL;
		int i = 0;
		int j = 0;
		char temp[5];
		while (i < str.length() + 1)
		{
			if (endParse)break;
			if ('0' <= str[i] && str[i] <= '9' || (str[i] == '-' && !('0' <= str[i] && str[i] <= '9')))
			{
				temp[j] = str[i];
				j++;
			}
			else if (str[i] == ' ' || str[i] == '\0')
			{
				temp[j] = '\0';
				result.push_back(atoi(temp));
				memset(temp, 0, 5);
				j = 0;
			}
			else endParse = true;
			i++;
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "RU");
	Manipulator* m1 = new Manipulator(0, 0);

	string gcode[] = { "10 20 0", "X10;Y20;Z30;", "X40;Y-20;Z20;", "X-10;Y-20;Z-10;" };

	for (auto a : gcode)
	{
		vector <int> res = parseGcode(a);
		if (endParse)
		{
			cout << "ERROR SCRIPT\n";
			return 1;
		}
		m1->setCordX(m1->getCordx() + res[0]);
		m1->setCordY(m1->getCordy() + res[1]);
		m1->setCordZ(m1->getCordz() + res[2]);
	}
	m1->printCords();

	return 0;
}
