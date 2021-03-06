#include "stdafx.h"
#include "MainSceneButton.h"

MainSceneButton::MainSceneButton(QWidget *parent)
	: QPushButton(parent)
{
	connect(this, &QPushButton::clicked, this, [=]()
	{
		zoomPush();
		zoomPop();
	});
}

MainSceneButton::~MainSceneButton()
{
}

void MainSceneButton::setPicture(QString normalImg)
{
	QPixmap pix;
	this->normalImg = normalImg;
	pix.load(normalImg);
	pix = pix.scaled(pix.width() * 0.7, pix.height() * 0.7);
	this->setFixedSize(pix.width(), pix.height());
	this->setStyleSheet("QPushButton(border:0px)");
	this->setIcon(pix);
	this->setIconSize(QSize(pix.width(), pix.height()));
}
void MainSceneButton::zoomPush() {
	QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(200);
	animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
	animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
	animation->setEasingCurve(QEasingCurve::OutBounce);
	animation->start();
}
void MainSceneButton::zoomPop() {
	QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(200);
	animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
	animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
	animation->setEasingCurve(QEasingCurve::OutBounce);
	animation->start();
}

