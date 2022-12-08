#include <QCoreApplication>
#include "BallCollisionUnitTests/testBallUtils.h"
#include "BallCollisionUnitTests/testDrawingUtils.h"
#include "BallCollisionUnitTests/testVectorUtils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestBallUtils testBallUtils;
    TestDrawingUtils testDrawingUtils;
    TestVectorUtils testVectorUtils;

    QStringList args;
    args << "" << "-silent";
    QTest::qExec(&testBallUtils, args);
    QTest::qExec(&testDrawingUtils, args);
    QTest::qExec(&testVectorUtils, args);

    return 0;
}
