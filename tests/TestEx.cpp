#include "TestEx.h"

void TestEx::test1()
{
    QVERIFY(true);
}

void TestEx::test2()
{
    QCOMPARE(2 + 3, 5);
    QCOMPARE(0, 1);
}

QTEST_MAIN(TestEx)
