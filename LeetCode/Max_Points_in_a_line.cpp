#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/* 
	Definition for a point
*/
struct Point {
	int x;
	int y;
	Point():x(0),y(0) {}
	Point (int a, int b):x(0), y(0) {}
};

int maxPoints(vector<Point> &points) {
	if (points.empty())
		return 0;
	if (points.size() <= 2) 
		return points.size();

	int numPoints = points.size();
	map<double, int> pmap;    //�洢б��-������Ӧֵ
	int numMaxPoints = 0;

	for (int i = 0; i != numPoints - 1; ++i) {
		int numSamePoints = 0, numVerPoints = 0;  //���ÿ����ֱ�������
		
		pmap.clear();
		
		for (int j = i + 1; j != numPoints; ++j) {
			if(points[i].x != points[j].x) {
				double slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
				if (pmap.find(slope) != pmap.end())
					++ pmap[slope];   //������ͬб��ֵ�ĵ����ۼ�
				else 
					pmap[slope] = 1;
			}
			else if (points[i].y == points[j].y) 
				numSamePoints ++;   //�غϵĵ�
			else
				numVerPoints ++;    //��ֱ�ĵ�

		}
		map<double, int>::iterator it = pmap.begin();
		for (; it != pmap.end(); ++ it) {
			if (it->second > numVerPoints)
				numVerPoints = it->second;
		}
		if (numVerPoints + numSamePoints > numMaxPoints) 
			numMaxPoints = numVerPoints + numSamePoints;
	}
	return numMaxPoints + 1;
}
// int main()
// {
// 	Point p;
// 	vector<Point> pp;
// 	p.x = 0, p.y = 0;
// 	pp.push_back(p);
// 	p.x = 0, p.y = 0;
// 	pp.push_back(p);
// 	p.x = 1, p.y = -1;
// 	pp.push_back(p);
// // 	p.x = 9, p.y = -25;
// // 	pp.push_back(p);
// 	cout << maxPoints(pp) << endl;
// 	return 0;
// }