#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

using namespace std;


int main() {

    map<int, int> gol;
    int N, num, ngol; //variabili per lettura del file

    //quante volte deve essere fatto il ciclo viene detto dal file la prima stringa, questo caso 7
    in >> N;

    //dovremmo caricare e nello stesso tempo valutare chi fare gia il max goal temporaneo, in certi instanti
    //numero maxGoal, goal fatto dal giocatore (capo cannoniere)
    int giocM, golM = 0;
    //La variabile max, va sempre inializzata al minimo

    //ciclo for per 7 volte determinato da 7 sopra
    for (int i = 0; i < N; i++) {
        in>> num >> ngol;
        //devo verificare se c'e il giacotore o meno, quindi devo usare gol.insert
        auto x = gol.insert({num, ngol});

        if(x.second == false) { //se l'inserimento è successivo o meno, false = se la chiave gia esiste quella chiave il giocatore, se true invece non e registrato e inserito
            //è la seconda o la terza vola che fa goal, significa che non devo aggiornare il valore ma devo sommarae il goal
            //con il letto e quello di pria
            gol[num] += ngol; //andremo a sommare += aggiorna il valore
        }

        if(golM < gol[num]) {
            //significa che gold[num] è il nuovo massimo
            golM = gol[num];
            giocM = num;
        }
    }

    cout<< giocM << " " << endl;
    out << giocM;
    return 0;
}
