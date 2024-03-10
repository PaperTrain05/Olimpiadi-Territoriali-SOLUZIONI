#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

using namespace std;

int main() {

    int N; //numero di ricevimenti tresmessi dal coso
    /*
     * Numero:
     * Positivo: sale di tot numeri SE E LA PRIMA VOLTA sale di tot, parte da 5000
     * Negativo: scende dall'ultima posizione
     *
     * Esempio:
     * Al primo numero dopo N la prima stringa acquisita aggiunge ad esempio
     * +4 diventara 5004
     * -2 divetera 5004 - 2 = 5002
     * +10 diventera 5012 e cosi via
     * */
    in >> N;
    map<int, int> altitudes;
    int altitudineSTART = 5000;
    altitudes[altitudineSTART] = 1; // Aggiungiamo il campo base alla mappa

    for (int i = 0; i < N; ++i) {
        int change;
        in >> change;

        altitudineSTART += change; // Aggiorniamo l'altitudine

        // Incrementiamo il conteggio per questa altitudine
        altitudes[altitudineSTART]++;
    }
    // Troviamo l'altitudine più frequente
    int most_frequent_altitude = 5000;
    int max_count = 1;

    for (auto it = altitudes.begin(); it != altitudes.end(); ++it) {
        if (it -> second > max_count) {
            most_frequent_altitude = it -> first;
            max_count = it -> second;
        }
    }

    out << most_frequent_altitude << endl;

    in.close();
    out.close();
    return 0;
}
/*
 * 1:27 ora e 27 minuti circa
 * pair<int, int> coppia
 * se la usero nel programma
 * coppia = {5, 5} assegno un elemento alla coppia
 * coppia.first = 5 setto alla first e quindi modifico (la key)
 * coppia.second = 15 setto alla second e quindi modifico (la value)
 * è un oggetto struct predefinito (contenere qualunque cosa) che contiene due tipi
 * se dobbiamo ordinare un vettore di struct dobbiamo dire coem fare l'ordinamento perche non lo conosce
 * se dobbaimo fare con pair è in base al first
 * Quando dobbiamo ordinare un vettore di coppia senza usare i vettori
 * noi usando una mappa come un pair ecco
 * */
//pair<int, int> coppia;