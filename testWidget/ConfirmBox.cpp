#include "stdafx.h"
#include "ConfirmBox.h"

ConfirmBox::ConfirmBox(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

ConfirmBox::~ConfirmBox()
{
}

void ConfirmBox::setText(const QString text)
{
	ui.label->setText(text);
}

void ConfirmBox::mousePressEvent(QMouseEvent * e)
{
	last = e->globalPos();
}

void ConfirmBox::mouseMoveEvent(QMouseEvent * e)
{
	const auto dx = e->globalX() - last.x();
	const auto dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}

void ConfirmBox::mouseReleaseEvent(QMouseEvent * e)
{
	const auto dx = e->globalX() - last.x();
	const auto dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}
