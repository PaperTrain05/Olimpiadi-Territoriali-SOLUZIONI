#include <bits/stdc++.h> //Include le librerie stantard del C++

using namespace std;

int main() {
    vector<int> vett;

    vett.push_back(13); //se non si conosce le dimensione del vettore

    //Caricare come vettore statico invece cosi:
    vett.resize(10); //dice che dice di 10 elementi, resize alloca 10 elementi di memoria per gli elemeti da caricara
    //quindi caricamento con ciclo for
    for(int i = 0; i < 10; i++) {
        cin>>vett[i];
    }
    //se io voglio mettere piu di 10 elementi usando il resize posso usare pushback
    vett.push_back(123); //11 elemento inserito

    for(int i = 0; i < vett.size(); i++) { //Vettori dinamici
        cout<<vett[i]<<" "; //stampare il vettore senza sapere il size qiundi .size
    }
    //auto : calcola in automatico il tipo di vettore
    for(auto x : vett) { //per i vettori dimamici o anche for(int x : vett) la stessa cosa
        cout<<x<<" ";
    }
    //algoritmo di sorting
    sort(vett.begin(), vett.end()); //quindi come paramentro l'indirizzo di memoria del primo e poi il successivo all'ultimo, funziona con i vettori statici (vett[], vetto[] + dimensione)

    return 0;
}
