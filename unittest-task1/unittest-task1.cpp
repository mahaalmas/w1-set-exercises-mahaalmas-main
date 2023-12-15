#include "pch.h"
#include "CppUnitTest.h"
#include "../task1/task1-functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittesttask1
{
	TEST_CLASS(UnitTestEngineMode)
	{
	public:
		
		// Electric space 1
		TEST_METHOD(TestEngineMode1_E1)
		{
			for (unsigned int s = 0; s <= 9; s++) {
				for (unsigned int b = 26; b <= 100; b++) {
					Assert::AreEqual(setEngineMode(s, b), 0);
				}
			}
		}
		// Electric space 2
		TEST_METHOD(TestEngineMode2_E2)
		{
			for (unsigned int s = 0; s <= 29; s++) {
				for (unsigned int b = 45; b <= 100; b++) {
					Assert::AreEqual(setEngineMode(s, b), 0);
				}
			}
		}
		// Petrol space 1
		TEST_METHOD(TestEngineMode1_P1)
		{
			for (unsigned int s = 0; s <= 100; s++) {
				for (unsigned int b = 0; b <= 25; b++) {
					Assert::AreEqual(setEngineMode(s, b), 1);
				}
			}
		}
		// Petrol space 2
		TEST_METHOD(TestEngineMode1_P2)
		{
			for (unsigned int s = 10; s <= 100; s++) {
				for (unsigned int b = 26; b <= 44; b++) {
					Assert::AreEqual(setEngineMode(s, b), 1);
				}
			}
		}
		// Petrol space 3
		TEST_METHOD(TestEngineMode1_P3)
		{
			for (unsigned int s = 30; s <= 100; s++) {
				for (unsigned int b = 45; b <= 100; b++) {
					Assert::AreEqual(setEngineMode(s, b), 1);
				}
			}
		}
	};
}
