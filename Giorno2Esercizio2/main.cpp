#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
/*
 * serve per inventare dentro il programma, è come se fosse un classe di un profilo
 * il quale possiamo mettere i dati che vogliamo
 * tipo di dati inventato da me per il mio programma
 *
 * In questo caso auto e posizione per la struttura Auto
 * */
struct Auto {
    //Scomparto numero e pos
    int num, pos;
};
int cerca(vector<Auto>, int n);
bool cmp(Auto a1, Auto a2);
int main() {

    /*
     * Numero di macchine, Sorpassi totali
     * */
    int N, S;
    //Lettura da file (lo spazio è un separatore NO SPLIT STRINGA INUTILE PORCO DIO JAVA)
    in>>N>>S;

    //Vettore di tipo di Auto (tipo di Dato Auto)
    vector<Auto> v;
    //Dico al vettore la grandezza di N (numero di automobili)
    v.resize(N);

    //carichero la grigilia di partenza
    //Per accedere ai campi della struct il riferimento del vettore . il camp
    for(int i = 0; i < N; i++) {
        in>>v[i].num; //setto che numero di auto e per quell'Auto
        v[i].pos = i + 1; //setto la posizione per quell'Auto
    }

    //Gestire i sorpassi
    for(int i = 0; i < S; i++) {
        int num1, num2;
        in>>num1>>num2;
        int p = cerca(v, num1);
        //in v[p].pos
        //Macchina che sta sorpassando (da seconda a prima)
        v[p].pos--;
        p = cerca(v, num2);
        //macchina sorpassata (da prima posizion a seconda)
        v[p].pos++;
    }

    //sort in vettore che tiene un tipo base, perche non puo conosce il tipo Auto, perche non sa che criterio usare
    //quindi inventiamo una funzione che fa confronti tra auto
    //48:00 in rec
    //diciendogli che tipo di algoritmo che e customizzato
    sort(v.begin(), v.end(), cmp);

    //una volta ordinato (1:10)
    //mettiamo il coso nel file
    //essendo ordinato metteremo 0 e chiede il numero di quella macchian quindi mettiamo .num
    for(Auto x : v) {
        cout << x.num << " " << x.pos << endl;
    }
    out<<v[0].num;
    return 0;
}

//dobbiamo cercare dentro il vettore dove si trova la prima e seconda macchina aggiornando la posizione
//usiamo una funzione (vettore e numero auto da cercare)
int cerca(vector<Auto> v, int n) {
    //per ogni macchina presente nel vettore
    //vado a controllarmi se X.num == n
    for(int i = 0; i < v.size(); i++) {
        //se appena trovo un elemento del vettore in cui
        //nello scomparto num è uguale a N gli dico dove si trova
        //se non la trovo -1
        if(v[i].num == n) {
            return i;
        }
    }
    return -1;
}

bool cmp(Auto a1, Auto a2) {
    //quando deve confrontare due macchine dobbiamo confrontare
    //il campo pos, se la prima auto è minore della seconda auto
    //il sort ci ordinera il vettore per crescente per la posizione
    return a1.pos < a2.pos;
}

