// kClosetPoint.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>  
#include <functional>  
using namespace std;
class Point {
public:
	
	Point() :x(0), y(0) {}
	Point(int a,int b):x(a),y(b){}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	double getDistance() {
		return distance;
	}
	void setDistance(double distance) {
		this->distance = distance;

	}
	private:
	int x;
	int y;
	double distance;

	

};


class solution {
public:

	vector<Point> kCloset(vector<Point> points,Point origin,int k){
		int size = points.size();
		vector<Point> kPoint;

		for (int i =0;i<size;i++)
		{
			points[i].setDistance(getDistance(points[i], origin));
		}
		sort(points.begin(), points.end(), [](Point& point1, Point& point2)->bool { return point1.getDistance() < point2.getDistance(); });
	//	for (int i = 0; i < k; i++) {
	//		cout << points[i].getX() << ":" << points[i].getY() << "           " << points[i].getDistance() << endl;
	//	}

		vector<Point> result;
		result.assign(points.begin(), points.begin() + 6);
		return result;
			}

	double getDistance(Point a, Point b) {
		return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
	}
private:


};



int main()
{

	vector<Point> points;
	vector<int> aaa;

	for (int i = 0; i < 10; i++) {
	points.push_back(Point(i,i));
	}

	solution solution;
	points = solution.kCloset(points, Point(0, 0), 7);
	int size = points.size();
	for (int i = 0; i < size; i++) {
		cout << points[i].getDistance() << endl;
	}
    return 0;
}

