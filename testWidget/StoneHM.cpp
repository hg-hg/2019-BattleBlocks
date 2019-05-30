#include "stdafx.h"
#include "StoneHM.h"

StoneHM::StoneHM(QWidget *parent)
	: Stone(parent)
{
	setData();
	setImage();
}

void StoneHM::setData()
{
	TYPE = HM_STONE;
	HP = 5;
	DAMAGE = 0;
	MP = 5;
}

void StoneHM::setImage()
{
	//background = Qt::darkCyan;
	background = QPixmap("./Resources/stone_background.png");
	foreground = QPixmap(":/foreground/Resources/foreground/hm.png");
}
