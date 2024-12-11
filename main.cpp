#include <QCoreApplication>
#include "csocketclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CSocketClient client = new CSocketClient();
    client.connectToHost("127.0.0.1",1012);
    client.sendMessage("Enzo est trop fort");

    return a.exec();
}
