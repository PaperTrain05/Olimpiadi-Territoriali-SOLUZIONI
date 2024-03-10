#include <bits/stdc++.h>
using namespace std;

//STRUTTURE DINAMICHE, usiamo il SET dobbiamo maneggiare i dati MA NON POSSIAMO MODIFICARLI (ad esempio fare la somma dentro come potremmo farlo nelle mappe o vettori)

//prende un set di interi V, per ogni dato dentro V stampa il valore
void stampa(set<int> v) {
    for(auto val : v) {
        cout<<val<< " ";
    }
}

void stampa(unordered_set<int> y) {
    for(auto val : y) {
        cout<<val<< " ";
    }
}

void stampa(multiset<int> z) {
    for(auto val : z) {
        cout<<val<< " ";
    }
}
int main() {
    //il set non puo contenere dello stesso valore, differenti (1 e 1 non possono essere ripetuti)
    //gia ordinato in modo cronologico (dal piu grande al piu piccolo)
    //come se fosse una lista ordinata
    //set<int> x;
    //set.insert(34); etc (10, 2)
    //sara 2-10-34

    //x.count(val); -> se restituisce 0 non è presente nella sequenza se restituisce 1 ci sara nella sequenza
    //è una struttura di tempi ricerca sono veloci perche è gia ordinato
    //3 tipi di set: multiset (consente valori ripetuti),

    set<int> x;
    x.insert(24);
    x.insert(1);
    x.insert(34);
    x.insert(20);
    x.insert(24);

    stampa(x);
    //ci compare una volta sola il 24 non 2, ed è gia ordinato (l'insert fara in automatico un'algoritmo di ordinamento gia integrato dentro la funzione)

    //verifica o meno la presenza di 21, restituisce 0 in questo caso perche non c'e
    cout<<x.count(21);

    //verifica o meno la presenza di 21, restituisce 1 in questo caso perche c'e
    cout<<x.count(24);

    // sara un set MA NON ORDINATO IN MODO CRESCENTE.
    // mantiene un ordinamento che ho dato, se sono duplicati sono prende l'ultimo inserito
    unordered_set<int> y;
    y.insert(24);
    y.insert(1);
    y.insert(34);
    y.insert(20);
    y.insert(24);

    stampa(y);

    //la ricerca sara un po complicata perche deve mantenere le chiavi duplicate, è ORDINATA
    multiset<int> z;
    z.insert(24);
    z.insert(1);
    z.insert(34);
    z.insert(20);
    z.insert(24);

    //voglio cancellare il numero 34
    //1-> devo sapere dove si trova, non fa per valore ma per posizione
    //per scorrere un set dobbiamo fare un for per scorrerlo
    //cio è un puntatore di memoria
    //metodo tradizionale, qui dobbiamo lavorare con i puntatori (partono dal primo elemnto begin() fino all'ultimo con end()) l'end prende la posizone dopo quando finisce il Set
    //se dobbiamo fare il for dobbiamo fare cosi: LAVORA CON INDIRIZZO QUESTO FOR
    for(auto i = z.begin(); i != z.end(); i++) {
        cout<<(*i)<<endl; //si prende il valore = il * viene usato per vedere il valore dentro l'indirizzo di memoria i è un puntatore
    }
    //2 -> togliamo il numero per valore
    z.erase(20);

    //cancella il set azzera il set
    z.clear();


    stampa(z);

    //restistuisce la quantita di volte è stato ripetuto il 24 in questo caso
    cout<<z.count(24)<<endl;

    return 0;
}
