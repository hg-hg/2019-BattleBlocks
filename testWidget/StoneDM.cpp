#include "stdafx.h"
#include "StoneDM.h"

StoneDM::StoneDM(QWidget *parent)
	: Stone(parent)
{
	setData();
	setImage();
}

void StoneDM::setData()
{
	TYPE = DM_STONE;
	HP = 0;
	DAMAGE = 5;
	MP = 5;
}

void StoneDM::setImage()
{
	//background = Qt::darkGreen;
	background = QPixmap(":/stone/Resources/stone/background.png");
	foreground = QPixmap(":/stone/Resources/stone/dm.png");
}
