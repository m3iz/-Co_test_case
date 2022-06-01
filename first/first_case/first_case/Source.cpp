#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
	Point(float px = 0, float py = 0)
	{
		x = px;
		y = py;
	};
	float getCordx()
	{
		return x;
	}
	float getCordy()
	{
		return y;
	}
protected:
	float x, y;
};

class Manipulator : public Point
{
public:
	Manipulator(float px, float py, float rad)
	{
		x = px;
		y = py;
		radius = rad;
	}
	float getRadius()
	{
		return radius;
	}
private:
	float radius;
};

class Vec : public Point
{
public:
	Vec(float px, float py)
	{
		x = px;
		y = py;
		len = sqrt(pow(px, 2) + pow(py, 2));
	}
	float getLen()
	{
		return len;
	}

private:
	float len;
};

int main()
{
	//Âõîäíûå äàííûå
	Manipulator m1(15, 20, 10);
	Manipulator m2(20, 30, 5);
	Point p1(15, 23);

	//Ñîçäàåì âåêòîðà îò èíñòðóìåíòîâ äî òî÷êè
	Vec vec1(p1.getCordx() - m1.getCordx(), p1.getCordy() - m1.getCordy());
	Vec vec2(p1.getCordx() - m2.getCordx(), p1.getCordy() - m2.getCordy());

	//Ó÷èòûâàÿ ðàäóèñû ìàíèïóëÿòîðîâ, âûáèðàåì íàèëó÷èé ìàíèïóëÿòîð
	if (vec1.getLen() <= m1.getRadius() && vec1.getLen() <= vec2.getLen())cout << "First manipulator\n";
	else if (vec2.getLen() <= m2.getRadius() && vec2.getLen() <= vec1.getLen()) cout << "Second manipulator\n";
	else cout << "OUT OF RANGE\n";

	return 0;
}
