#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Point
{
public:
	Point(float px = 0, float py = 0)
	{
		x = px;
		y = py;
	};
	~Point() {};
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
	void setCordX(float px) {
		x = px;
	}
	void setCordY(float py) {
		y = py;
	}
	float getRadius()
	{
		return radius;
	}
	void pushPath(Point p) {
		result.push_back(p);
	}
	void printResult() {
		for (auto a : result)
		{
			printf("%5c%g%c%g%c", '{', a.getCordx(), ' ', a.getCordy(), '}');
		}
	}
private:
	double radius;
	vector <Point> result;
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

void moveMan(Manipulator* m1, Manipulator* m2, Point p1)
{
	class Vec vec1(p1.getCordx() - m1->getCordx(), p1.getCordy() - m1->getCordy());
	class Vec vec2(p1.getCordx() - m2->getCordx(), p1.getCordy() - m2->getCordy());

	if (vec2.getLen() > vec1.getLen())
	{
		m1->setCordX(p1.getCordx());
		m1->setCordY(p1.getCordy());
		m1->pushPath(p1);
	}
	else if (vec2.getLen() <= vec1.getLen())
	{
		m2->setCordX(p1.getCordx());
		m2->setCordY(p1.getCordy());
		m2->pushPath(p1);
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	Manipulator* m1 = new Manipulator(0, 0, 4);
	Manipulator* m2 = new Manipulator(2, 1, 3);

	vector <Point> arr = { {1,3},{2,1.41},{0.2, -7}, {-5,-1}, {0,9} };

	for (auto a : arr)
		moveMan(m1, m2, a);

	cout << "Первый манипулятор: ";
	m1->printResult();

	cout << "\nВторой манипулятор: ";
	m2->printResult();

	return 0;
}