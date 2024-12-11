//Developpez par Enzo Bourkoua
//Le 10.12.2024
//Classe qui fonctionne de paire avec la classe CSocketServeur. Comme le nom l'indique C'EST UN SOCKET

#include <QTcpSocket>
#include <QObject>

class CSocketClient : public QObject {
    Q_OBJECT

public:
    CSocketClient(QObject *parent = nullptr);
    void connectToHost(const QString &host, int port);
    void sendMessage(const QString &message);

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();

private:
    QTcpSocket *socket;
};
