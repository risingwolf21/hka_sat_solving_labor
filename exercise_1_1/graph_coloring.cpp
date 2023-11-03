#include <iostream>
#include <fstream>
#include <vector>

#include "ipasir/ipasir.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <DIMACS-Graph-Datei>" << endl;
    return 1;
  }

  // Graphdatei einlesen
  ifstream input(argv[1]);
  if (!input.is_open())
  {
    cerr << "Fehler beim Öffnen der Datei \"" << argv[1] << "\"" << endl;
    return 1;
  }

  // Graphstruktur initialisieren
  int n = 0;                  // Anzahl der Knoten
  int m = 0;                  // Anzahl der Kanten
  vector<vector<int>> adj(n); // Adjazenzliste
  input >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    input >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // SAT-Solver initialisieren
  Ipasir solver;

  // Variablen erzeugen
  int x[n];
  for (int i = 0; i < n; i++)
  {
    x[i] = solver.newVar();
  }

  // Einschränkungen erzeugen
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      int v = adj[i][j];
      solver.addClause(x[i] != x[v]);
    }
  }

  // SAT-Problem lösen
  bool sat = solver.solve();
  if (!sat)
  {
    cerr << "Keine Lösung gefunden" << endl;
    return 1;
  }

  // Lösung ausgeben
  int num_colors = solver.nVars();
  for (int i = 0; i < n; i++)
  {
    cout << x[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}