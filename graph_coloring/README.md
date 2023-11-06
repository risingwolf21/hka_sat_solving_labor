# Graph Coloring (Blatt 1 Aufgabe 1)

## Voraussetzung

C++ muss installiert sein. Alternativ kann der vorkonfigurierte `.devcontainer` verwendet werden. Für den Container wird Docker auf dem PC vorausgesetzt. Der Devcontainer stellt sicher, dass die C++ Version die gleiche wie bei uns ist.

### Dev Container

1. Installieren Sie Docker (z.B. Docker Desktop auf ihrem PC)
2. Installieren Sie die [Dev Container Erweiterung](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) in VSCode.
3. Öffnen Sie diesen Ordner ([graph_coloring/](./)) in dem Dev Container
    - Drücken Sie F1, dies öffnet die Command Palette
    - Geben Sie "`> Dev Containers: open folder in Container...`" ein, und führen Sie den Command aus.
    - Wählen Sie [graph_coloring/](./) im Explorer aus.
    - VSCode sollte nach einer gewissen Zeit den Editor aktualisieren und Sie befinden sich in einer laufenden Debian Umgebung mit C++ installiert.

## Programm bauen (optional)

Um das Programm neu zu bauen, muss zuerst in diesem Verzeichnis die [makefile](./makefile) mit `make all` ausgeführt werden.
Für die Ausführung ist dies nicht notwendig.

## Programm ausführen

Die auszuführende Datei liegt unter [./app/graph_coloring/](./app/graph_coloring/).

Navigieren Sie zuerst in diesen Ordner oder öffnen Sie das Terminal dort:

```sh
cd ./app/graph_coloring
```

[graph_coloring](./app/graph_coloring/graph_coloring) kann wie folgt ohne Parameter ausgeführt werden:

```sh
./graph_coloring
```

Wir haben die verschiedenen getesteten Eingaben unter [./app/graph_coloring/inputs/](./app/graph_coloring/inputs/) abgelegt. Ohne Parameter wird `small.txt` verwendet. Um eine andere Datei zu verwenden wird der Dateiname als erster Parameter übergeben:

```sh
./graph_coloring medium.txt
```
