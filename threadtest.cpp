#include "threadtest.h"
#include <QDebug>
#include "lane.h"
ThreadTest::ThreadTest(QObject *parent)
{

}

ThreadTest::~ThreadTest()
{

}

void ThreadTest::run()
{
	for (size_t i = 0; i < 10; i++)
	{
		qDebug() << "threadid:" << QThread::currentThreadId();
		QList<Laneip*> lane;
		Qselect("select * from laneip where id = #{id}") < this->id > lane;
		qDebug() << QDBC_Id << Object_utils::toString(lane);
		QThread::sleep(1);
		//delete lane;
		Qclear();
	}
	
}
