# CSocketClient

Cette classe fournit un client socket TCP simple pour les applications Qt.

## Utilisation

Pour utiliser `CSocketClient`, incluez `csocketclient.h` dans votre projet. Voici un exemple simple :

```cpp
#include "csocketclient.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CSocketClient client;
    client.connectToHost("127.0.0.1", 1234);
    client.sendMessage("Hello, world!");

    return a.exec();
}
```

## Méthodes

### `CSocketClient(QObject *parent = nullptr)`

Constructeur de la classe. Crée un nouvel objet `CSocketClient`.

### `void connectToHost(const QString &host, int port)`

Se connecte à l'hôte spécifié sur le port donné.

*   `host`: L'adresse IP ou le nom d'hôte du serveur.
*   `port`: Le port sur lequel se connecter.

### `void sendMessage(const QString &message)`

Envoie un message au serveur. Le message n'est envoyé que si le socket est connecté.

*   `message`: Le message à envoyer.

## Slots

### `void onConnected()`

Ce slot est appelé lorsque le client est connecté au serveur.

### `void onReadyRead()`

Ce slot est appelé lorsque de nouvelles données sont disponibles à la lecture.

### `void onDisconnected()`

Ce slot est appelé lorsque le client est déconnecté du serveur.
