//Developpez par Enzo Bourkoua
//Le 10.12.2024
//Classe qui fonctionne de paire avec la classe CSocketServeur. Comme le nom l'indique C'EST UN SOCKET

#include "csocketclient.h"
#include <QDebug>

CSocketClient::CSocketClient(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &CSocketClient::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &CSocketClient::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &CSocketClient::onDisconnected);
}

void CSocketClient::connectToHost(const QString &host, int port) {
    socket->connectToHost(host, port);
}

void CSocketClient::sendMessage(const QString &message) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
    }
}

void CSocketClient::onConnected() {
    qDebug() << "Client connected";
}

void CSocketClient::onReadyRead() {
    qDebug() << "Client received:" << socket->readAll();
}

void CSocketClient::onDisconnected() {
    qDebug() << "Client disconnected";
}
