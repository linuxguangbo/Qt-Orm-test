#include "Test.h"

#include <QMetaMethod>
#include <QDebug>
#include <QDateTime>
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include "lane.h"
QHello::QHello(QObject *parent)
	: QObject(parent)
{
	bool s = QgetDabaseConnect();
	this->update1();
	this->selectAll();
	this->selectone();

	//this->remove();
	//this->insert();
}

void QHello::selectone()
{
	Laneip *lane;
	QString sql = "SELECT * FROM laneip WHERE id = #{lid}";
	Qselect(sql) < 3 > lane;
	if (lane == NULL) {
		qDebug() << "error";
		return;
	}
	
	Laneip pp;
	Object_utils::copy(&pp, lane);
	qDebug() << QDBC_Id << Object_utils::toString(&pp);

	Laneip *lane1;
	Qselect(sql) < 3 > lane1;
	if (lane1 == NULL) {
		qDebug() << "error";
		return;
	}
}

void QHello::selectAll()
{
	
	/*qDebug() << "-------test property-----------";
	Laneip newObj;
	newObj.setProperty("id", 1);
	newObj.setProperty("ip","12345");
	qDebug() << newObj.property("ip").toString();
	qDebug() << "--------end----------";*/


	qDebug() << "QHello::selectAl start";
	QList<Laneip*> lanelist;
	QString sql = "SELECT * FROM laneip";
	Qselect(sql) > lanelist;
	qDebug() << QDBC_Id << Object_utils::toString(lanelist);

	//Qclear();
}


void QHello::update()
{
	qDebug() << "update start :";
	Laneip lane;
	lane.ip = "192.168.1.100";
	lane.id = 3;
	lane.port = 100;
	lane.updatetime = QDateTime::currentDateTime();
	lane.url_url = "https://github.com/linuxguangbo/";
	QString sql = "UPDATE laneip SET ip=#{ip},updatetime=#{updatetime},url=#{url_url} WHERE id=#{id} and `port` = #{port}";
	int count;
	Qupdate(sql) < &lane > count;
	//qDebug() << "QHello::update" << count;

}

void QHello::update1()
{
	QString sql = "UPDATE laneip SET updatetime='${updatetime}' WHERE id=${id}";
	int count;
	Qupdate(sql) < QDateTime::currentDateTime() < 2 > count ;
	qDebug() << "update1:" << count;
}

void QHello::remove()
{
	//Laneip lane = Laneip();
	//lane["id"] = 2;
	//lane["port"] = 5010;
	//int count;
	//Qdelete("DELETE FROM laneip  WHERE id=#{id} and `port` = #{port}") < lane > count;
	//qDebug() << "remove:" << count;
	/*QString sql = "delete from axisstandard   WHERE AxisType = ?";
	int rows;
	Qdelete << sql << 1001 >> rows;
	qDebug() << "rows" << rows;*/
}

void QHello::insert()
{
	Laneip lane;
	lane.ip = "192.168.1.112";
	lane.port = 1144;
	lane.url_url = "www.google.com";
	lane.entryno = 2;
	lane.Status = 1;
	lane.description = "ÍøÂçÕý³£";
	QString sql = "INSERT INTO laneip (ip,port,url,entryno,etype,description) "
		" VALUES(#{ip},#{port},#{url_url},#{entryno},#{etype},#{description})";
	int count;
	Qinsert(sql) < &lane > count;
	qDebug() << "insert:" << count;
}

void QHello::transfer()
{
	/*Qtransactional();
	Laneip lane = Laneip();
	lane["ip"] = "192.168.1.103";
	lane["id"] = 2;
	QString sql = "UPDATE laneip SET ip=#{ip} WHERE id=#{id}";
	int count;
	Qupdate("UPDATE laneip SET1 ip=#{ip} WHERE id=#{id}") < lane > count;
	lane["ip"] = "192.168.1.104";
	lane["id"] = 2;


	Qupdate(sql) < lane > count;
	qDebug() << "update:" << count;*/
}

QHello::~QHello()
{
}
