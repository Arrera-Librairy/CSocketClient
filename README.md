## CArreraClient

`CArreraClient` est un client WebSocket simple pour les applications Qt basé sur `QWebSocket`.

### Où regarder le code

- Interface: [carreraclient.h](carreraclient.h#L1)
- Implémentation: [carreraclient.cpp](carreraclient.cpp#L1)

## Utilisation

Incluez l'en-tête et créez un objet `CArreraClient`. Passez un nom d'application/logiciel optionnel au constructeur.

Exemple minimal:

```cpp
#include "carreraclient.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CArreraClient client("MonApp");
    client.connectToServeur("ws://127.0.0.1:1234");
    client.sendMessage("Hello, world!");

    return a.exec();
}
```

> Remarque: `CArreraClient` utilise WebSocket. Passez une URL WebSocket (`ws://` ou `wss://`) à `connectToServeur()`.

## API principale

- `CArreraClient(const QString &pnameSoft = "", QObject *parent = nullptr)` : constructeur. `pnameSoft` est envoyé automatiquement au serveur après connexion.
- `~CArreraClient()` : destructeur ferme la connexion si elle est active.
- `void connectToServeur(const QString &url)` : ouvre une connexion WebSocket vers l'URL fournie.
- `void disconnectFromServer()` : ferme la connexion.
- `bool sendMessage(const QString &message)` : envoie un message texte. Retourne `false` si le client n'est pas connecté.
- `bool isServerConnected() const` : indique si la connexion est établie.

## Signaux

- `void messageReceived(const QString &message)` : émis quand un message texte est reçu.
- `void connectionEstablished()` : émis après la connexion réussie.
- `void connectionClosed()` : émis après la déconnexion.
- `void errorOccurred(const QString &errorString)` : émis lorsqu'une erreur se produit.

## Comportements importants

- Lors de la connexion (`onConnected()`), le client envoie automatiquement le message `namesoft <pnameSoft>\n` si un nom a été fourni.
- À la réception d'un message texte, le signal `messageReceived()` est émis. Si le message reçu n'est pas la chaîne `"Message Received"` et n'est pas vide, le client répond automatiquement par `"Message Received"`.
- `sendMessage()` renvoie `false` si `isServerConnected()` est `false`.

## Exemple d'utilisation avec connexions Qt

```cpp
CArreraClient *client = new CArreraClient("MonApp", parent);
connect(client, &CArreraClient::connectionEstablished, [](){ /* connecté */ });
connect(client, &CArreraClient::messageReceived, [](const QString &msg){ /* traiter msg */ });
connect(client, &CArreraClient::connectionClosed, [](){ /* déconnecté */ });
connect(client, &CArreraClient::errorOccurred, [](const QString &err){ /* gérer erreur */ });

client->connectToServeur("ws://example.com:1234");
client->sendMessage("Payload JSON...");
```

## Notes

- Le nom des fichiers source dans ce dépôt est `carreraclient.h` et `carreraclient.cpp`.
- Cette documentation reflète l'implémentation actuelle. Si vous souhaitez renommer la classe ou les fichiers pour une meilleure cohérence (par exemple `WebSocketClient`), dites-le moi et je peux proposer un refactoring.
