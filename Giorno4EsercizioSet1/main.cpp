#include <bits/stdc++.h>

using namespace std;


ifstream inputFile("input.txt");
ofstream outputFile("output.txt");

void solve(int M, string file[]) {
    set<string> virFile;
    multiset<string> virus;

    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < file[j].length() - M; i+=1) {
            string s = file[j].substr(i, M);
            virFile.insert(s);
        }
        for(auto a : virFile) {
            virus.insert(a);
        }
    }

    string vir;
    //qua ho troato il virus
    for(auto x : virus) {
        if(virus.count(x) == 4) {
            vir = x;
            break;
        }
    }

    //in che posizione si trova dentro le stringhe
    for(int i = 0; i < 4; i++) {
        outputFile<<file[i].find(vir)<< " ";
    }
    outputFile<<endl;
}


int main() {

    // numero di test case
    int T;
    inputFile>>T;

    //servira la soluzione dell'esericizio per T casi
    for(int t = 1; t <= T; t++) {
        outputFile<<"Case #"<<t<<": "<<endl;
        //ipotetici 4 file che contengon i virus
        string file[4];
        // la lunghezza del virus (string.lenght();
        int M;

        //servira per la lunghezza
        int num;

        for(int i = 0; i < 4; i++) {
            inputFile>>num;
        }
        inputFile>>M;

        //leggere le stringhe (il file)
        for(int i = 0; i < 4; i++) {
            inputFile>>file[i];
        }
        //lunghezza del virus e i 4 file
        solve(M, file);
    }
    return 0;
}
