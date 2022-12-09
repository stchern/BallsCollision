#include <QCoreApplication>
#include "BallCollisionUnitTests/testBallUtils.h"
#include "BallCollisionUnitTests/testDrawingUtils.h"
#include "BallCollisionUnitTests/testVectorUtils.h"
#include "BallCollisionUnitTests/testEntirePipline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestBallUtils testBallUtils;
    TestDrawingUtils testDrawingUtils;
    TestVectorUtils testVectorUtils;
    TestEntirePipeline testEntirePipeline;

    QStringList args;
    args << "" << "-silent";
    QTest::qExec(&testBallUtils, args);
    QTest::qExec(&testDrawingUtils, args);
    QTest::qExec(&testVectorUtils, args);
    QTest::qExec(&testEntirePipeline, args);

    return 0;
}
