#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
//1ore e 25
//Le tabelle particolari, non si usa l'indice, ma la key (di tutti i tipi)
//CIO CHIAMATO DA MAP
int main() {

    //Key: la key con cui viene associato la value
    //Value: il secondo parametro che viene associato al Key
    //map<key, value> nome della mappa

    int N, S;
    in>>N>>S;
    //mappa di interi entrambi
    map<int, int> v;

    for(int i = 0; i < N; i++) {
        int key, value;
        in>>key; //mi leggo la chiave ovvero il numero dell'auto (come auto1 etc)
        //v[key] = i + 1; questo mettere ed e possibile aggiornare la value
        //metodo per inserire nella mappa, .set in MAPPA DI JAVA (non so se computeIfAbsent)
        //se uso questa modalita se la chiave verra ripetuto rispetto a quella di sopra
        //perche puo essere usata cosi o
        //v.insert({key, i+1}); per inserire elementi LA PRIMA VOLTA E NON FA AGGIONAMENTI
        //auto res = v.insert({key, i+1}); e non lo inserisce e l'aggiornamento non lo fara per quella key del suo valore (senza v.insert({}));
        //res è una struct e controllando il secondo valore (booleano)
        //se è true -> utilizzato 1 volta e fa l'inserimento
        //se è false -> utilizzata piu volte
        //l'inserimento della mappa sara come lo faro io
        //la ricerca è veloce perche va a Key
        v[key] = i + 1;
    }

    //metodo dei sorpassi
    for(int i = 0; i < S; i++) {
        int num1, num2;
        in>>num1>>num2;
        v[num1]--;
        v[num2]++;
        //non ho bisogno di cercara
        //quindi per la key e incrementa la sua value
    }

    //capire chi ha vinto
    //ordimanento per il valore
    //x.first = chiave
    //x.second = valore
    for(auto x : v) {
        if(x.second == 1) {
            out<<x.first;
            break;
        }
    }
    return 0;
}
