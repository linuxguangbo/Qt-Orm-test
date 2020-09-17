#pragma once

#include <QObject>
#include "Qdbc/Qdbc.h"
#include "Hellothread.h"
class QHello : public QObject
{
	Q_OBJECT

public:
	Hellothread th;
	Hellothread th2;
	QHello(QObject *parent);
	void selectone();
	void selectAll();

	void update();
	void update1();
	void remove();
	void insert();

	void transfer();
	~QHello();
};
