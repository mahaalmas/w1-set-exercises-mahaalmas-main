#include "pch.h"
#include "CppUnitTest.h"
#include <regex>
#include "../task3/task3_functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittesttask3
{
	TEST_CLASS(unittesttask3)
	{
	public:
		
		TEST_METHOD(TestMethod_1)
		{

			std::string input = findCorners("../../task3/task3data-1.txt");
			Assert::IsFalse(input.empty());

			std::regex pattern("\\[(\\s*\\d+\\s*),(\\s*\\d+\\s*)\\]");
			std::smatch match;

			//First pair
			if (std::regex_search(input, match, pattern)) {
				std::cout << "Pair found: (" << match[1] << ", " << match[2] << ")" << std::endl;
				int topY = stoi(match[1]);
				int topX = stoi(match[2]);
				Assert::AreEqual(topY,1);
				Assert::AreEqual(topX,3);
				input = match.suffix().str();
			}
			else {
				Assert::IsTrue(false);
			}
			
			//Second pair
			if (std::regex_search(input, match, pattern)) {
				std::cout << "Pair found: (" << match[1] << ", " << match[2] << ")" << std::endl;
				int bottomY = stoi(match[1]);
				int bottomX = stoi(match[2]);
				Assert::AreEqual(bottomY, 2);
				Assert::AreEqual(bottomX, 6);
			}
			else {
				Assert::IsTrue(false);
			}

		}

		void checkTop(std::string fPath, int Y, int X)
		{
			std::string input = findCorners(fPath);
			Assert::IsFalse(input.empty());

			std::regex pattern("\"topLeft\"\\s*\\:\\s*\\[(\\s*\\d+\\s*),(\\s*\\d+\\s*)\\]");
			std::smatch match;

			//First pair
			if (std::regex_search(input, match, pattern)) {
				std::cout << "Pair found: (" << match[1] << ", " << match[2] << ")" << std::endl;
				int topY = stoi(match[1]);
				int topX = stoi(match[2]);
				Assert::AreEqual(topY, Y);
				Assert::AreEqual(topX, X);
				input = match.suffix().str();
			}
			else {
				Assert::IsTrue(false);
			}
		}
		void checkBottom(std::string fPath, int Y, int X)
		{
			std::string input = findCorners(fPath);
			Assert::IsFalse(input.empty());

			std::regex pattern("\"bottomRight\"\\s*\\:\\s*\\[(\\s*\\d+\\s*),(\\s*\\d+\\s*)\\]");
			std::smatch match;

			//First pair
			if (std::regex_search(input, match, pattern)) {
				std::cout << "Pair found: (" << match[1] << ", " << match[2] << ")" << std::endl;
				int bottomY = stoi(match[1]);
				int bottomX = stoi(match[2]);
				Assert::AreEqual(bottomY, Y);
				Assert::AreEqual(bottomX, X);
				input = match.suffix().str();
			}
			else {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(TestMethod_1_top)
		{
			checkTop("../../task3/task3data-1.txt", 1, 3);
		}
		TEST_METHOD(TestMethod_1_bottom)
		{
			checkBottom("../../task3/task3data-1.txt", 2, 6);
		}
		TEST_METHOD(TestMethod_2_top)
		{
			checkTop("../../task3/task3data-2.txt", 2, 1);
		}
		TEST_METHOD(TestMethod_2_bottom)
		{
			checkBottom("../../task3/task3data-2.txt", 5, 2);
		}
		TEST_METHOD(TestMethod_3_top)
		{
			checkTop("../../task3/task3data-3.txt", 0, 0);
		}
		TEST_METHOD(TestMethod_3_bottom)
		{
			checkBottom("../../task3/task3data-3.txt", 4, 2);
		}
		TEST_METHOD(TestMethod_4_top)
		{
			checkTop("../../task3/task3data-4.txt", 2, 15);
		}
		TEST_METHOD(TestMethod_4_bottom)
		{
			checkBottom("../../task3/task3data-4.txt", 4, 15);
		}
		TEST_METHOD(TestMethod_5_top)
		{
			checkTop("../../task3/task3data-5.txt", 0, 0);
		}
		TEST_METHOD(TestMethod_5_bottom)
		{
			checkBottom("../../task3/task3data-5.txt", 5, 4);
		}
		TEST_METHOD(TestMethod_6_top)
		{
			checkTop("../../task3/task3data-6.txt", 5, 5);
		}
		TEST_METHOD(TestMethod_6_bottom)
		{
			checkBottom("../../task3/task3data-6.txt", 5, 5);
		}

	};
}

/*
01



*/
