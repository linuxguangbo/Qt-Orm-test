#include "threadpooltest.h"
#include "Qdbc.h"
#include "lane.h"
#include <QDebug>
threadPoolTest::threadPoolTest(int id)
{
	this->id = id;
}

threadPoolTest::~threadPoolTest()
{

}

void threadPoolTest::run()
{
	qDebug() << "threadid:" << QThread::currentThreadId();
	Laneip* lane;
	Qselect("select * from laneip where id = #{id}") < this->id > lane;
	qDebug() << QDBC_Id << Object_utils::toString(lane);
	QThread::sleep(1);
	Qclear();
}
