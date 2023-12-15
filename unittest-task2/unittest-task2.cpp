#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>
#include "../task2/task2-functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittesttask2
{
	TEST_CLASS(unittest_task2)
	{
	public:
		
		TEST_METHOD(readDataPoints_test_size)
		{
			int N;
			vector<Point> points1 = readDataPoints("../../task2/task2data-1.txt");
			N = (int)points1.size();
			Assert::AreEqual(N, 4);
			vector<Point> points2 = readDataPoints("../../task2/task2data-2.txt");
			N = (int)points2.size();
			Assert::AreEqual(N, 3); 
		}
		TEST_METHOD(readDataPoints_test_vals)
		{
			int N;
			/*
			{
				0  0
				0  10
				20 10
				20 0
			}
			*/
			vector<Point> xp;
			xp.push_back({ 0,0 });
			xp.push_back({ 0,10 });
			xp.push_back({ 20,10 });
			xp.push_back({ 20,0 });
			vector<Point> points = readDataPoints("../../task2/task2data-1.txt");
			N = (int)points.size();
			Assert::AreNotEqual(N, 0);
			for (unsigned int n = 0; n < points.size(); n++) {
				Assert::AreEqual(xp[n].x, points[n].x);
				Assert::AreEqual(xp[n].y, points[n].y);
			}
			/*
			{
				0  0
				5  20
				10 0
			}
			*/
			xp.clear();
			xp.push_back({ 0,0 });
			xp.push_back({ 5,20 });
			xp.push_back({ 10,0 });
			points = readDataPoints("../../task2/task2data-2.txt");
			//Check number of points read
			N = (int)points.size();
			Assert::AreNotEqual(N, 0);
			for (unsigned int n = 0; n < points.size(); n++) {
				Assert::AreEqual(xp[n].x, points[n].x);
				Assert::AreEqual(xp[n].y, points[n].y);
			}
		}
		TEST_METHOD(areaOfPolygon_test)
		{
			vector<Point> xp;
			xp.push_back({ 0,0 });
			xp.push_back({ 0,10 });
			xp.push_back({ 20,10 });
			xp.push_back({ 20,0 });
			Assert::AreEqual(areaOfPolygon(xp), 200.0);
			xp.clear();
			xp.push_back({ 0,0 });
			xp.push_back({ 5,20 });
			xp.push_back({ 10,0 });
			Assert::AreEqual(areaOfPolygon(xp), 100.0);
		}

		TEST_METHOD(circumferenceOfPolygon_test)
		{
			vector<Point> xp;
			xp.push_back({ 0,0 });
			xp.push_back({ 0,10 });
			xp.push_back({ 20,10 });
			xp.push_back({ 20,0 });
			Assert::IsTrue((abs(circumferenceOfPolygon(xp) - 60.0) < 0.1));
			xp.clear();
			xp.push_back({ 0,0 });
			xp.push_back({ 5,20 });
			xp.push_back({ 10,0 });
			Assert::IsTrue((abs(circumferenceOfPolygon(xp) - 51.2) < 0.1));
		}


	};
}
