﻿#include "stdafx.h"
#include "PVE.h"
#include "CharacterManager.h"
#include "ConfirmBox.h"
#include <QTimer>
#include "Account.h"

PVE::PVE(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//Account * account = Account::getInstance();
	ui.stackedWidget->setCurrentWidget(ui.playing);
	//ui.toast->setCurrentWidget(ui.escapePage);
	connect(ui.gameBoard, SIGNAL(sendPlayerDead(QString)), this, SLOT(playerDead(QString)));
	ui.gameBoard->setData(CharacterManager::getInstance()->getCharacter("THE BIG DEMON"));
	ui.gameBoard->setLocalGame(true);
}

PVE::~PVE()
{
	qDebug();
}

void PVE::confirm()
{
	//ui.toast->setCurrentWidget(ui.continuePage);
}

void PVE::escape()
{
	auto c = new ConfirmBox(this);
	c->setText("Are you sure?");
	if (c->exec() == 1) emit mainScene();
}

void PVE::continueGame()
{
	ui.gameBoard->restart();
	ui.stackedWidget->setCurrentWidget(ui.playing);
	//ui.toast->setCurrentWidget(ui.escapePage);
}

void PVE::quitGame()
{
	emit mainScene();
}

void PVE::playerDead(QString playerAccount)
{
	ui.stackedWidget->setCurrentWidget(ui.gameOver);
	if (playerAccount == ui.gameBoard->enemyAccount) {
		const auto moviePath = ":/skin/Resources/skin/" + Account::getInstance()->getSelectedCharacter()->skin;
		const auto movie = new QMovie(this);
		movie->setFileName(moviePath);
		ui.movie->setMovie(movie);
		movie->start();
		ui.loser->setVisible(false);
		ui.movie->setVisible(true);
	}
	else {
		ui.loser->setPixmap(QPixmap(":/word/Resources/word/newBee.png"));
		ui.loser->setVisible(true);
		ui.movie->setVisible(false);
	}
	QTimer::singleShot(500, this, [=]() {
		//change display movie time 500ms
		confirm();
	});
	
}
