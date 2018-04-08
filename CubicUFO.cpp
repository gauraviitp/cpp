#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
const double PI = M_PI;

class Point{
public:
	double x = 0, y = 0, z = 0;
	Point() : x(0), y(0), z(0){}
	Point(double px, double py, double pz) : x(px), y(py), z(pz){}
};

double getThetaRadian(double area, double edge){
	const double error = 1e-12;
	double low = 0;
	double high = PI/4;
	while(low < high) {
		double mid = (low + high) / 2;
		double curArea = edge * cos(PI/4 - mid);
		if(abs(curArea - area) < error){
			return mid;
		}
		else if(curArea < area){
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return low;
}

void rotateSingle(Point& p1, Point& p2, Point& p3, double a, double area){
	double thetaRadian = getThetaRadian(area, sqrt(2));
	// calculate p1
	p1.x = a * cos(thetaRadian);
	p1.y = a * sin(thetaRadian);
	p1.z = 0;
	
	// calculate p2
	p2.x = -a * sin(thetaRadian);
	p2.y = a * cos(thetaRadian);
	p2.z = 0;
	
	// calculate p3
	p3.x = 0;
	p3.y = 0;
	p3.z = a;
}

void rotateDouble(Point& p1, Point& p2, Point& p3, double a, double area){
	const double sqrtTwo = sqrt(2);
	double thetaRadian = getThetaRadian(area, sqrt(3));
	p1.x = a / sqrtTwo;
	p1.y = a / sqrtTwo * cos(thetaRadian);
	p1.z = a / sqrtTwo * sin(thetaRadian);
	
	p2.x = -a / sqrtTwo;
	p2.y = a / sqrtTwo * cos(thetaRadian);
	p2.z = a / sqrtTwo * sin(thetaRadian);
	
	p3.x = 0;
	p3.y = a * sin(thetaRadian);
	p3.z = a * cos(thetaRadian);
}

void testRotateSingle();

int main(){
	//testRotateSingle();
	int t;
	cin >> t;
	const double a = 0.5;
	const double sqrtTwo = 1.414213; 
	cout.setf(ios::fixed);
	cout << setprecision(10);
	for(int caseno = 1; caseno <= t; ++caseno){
		double area;
		cin >> area;
		
		Point p1, p2, p3;
		if(area <= sqrtTwo){
			rotateSingle(p1, p2, p3, a, area);
		}
		else {
			rotateDouble(p1, p2, p3, a, area);
		}
		cout << "Case #" << caseno << ":" << "\n";
		// output p1
		cout << p1.x << " " << p1.y << " " << p1.z << "\n"; 
		// output p2
		cout << p2.x << " " << p2.y << " " << p2.z << "\n";
		// output p3
		cout << p3.x << " " << p3.y << " " << p3.z << "\n"; 
		
	}
}

bool areEqual(double a, double b){
	double error = 1e-2;
	if(abs(a-b) < error){
		return true;
	}
	return false;
}

void testRotateSingle(){
	Point p1, p2, p3;
	double a = 0.5;
	
	double area = 1.0;
	rotateSingle(p1, p2, p3, a, area);
	assert(areEqual(a, p1.x));
	assert(areEqual(0, p1.y));
	assert(areEqual(0, p1.z));
	assert(areEqual(0, p2.x));
	assert(areEqual(a, p2.y));
	assert(areEqual(0, p2.z));
	assert(areEqual(0, p3.x));
	assert(areEqual(0, p3.y));
	assert(areEqual(a, p3.z));
	
	area = 1.414213;
	rotateSingle(p1, p2, p3, a, area);
	assert(areEqual(a/sqrt(2), p1.x));
	assert(areEqual(a/sqrt(2), p1.y));
	assert(areEqual(0, p1.z));
	assert(areEqual(-a/sqrt(2), p2.x));
	assert(areEqual(a/sqrt(2), p2.y));
	assert(areEqual(0, p2.z));
	assert(areEqual(0, p3.x));
	assert(areEqual(0, p3.y));
	assert(areEqual(a, p3.z));
	
	cout << "Passed :)" << endl;
}
