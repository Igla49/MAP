#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Elev {
private:
    string nume;
    vector<int> note;

public:
    Elev(string n) : nume(n) {}

    void adaugaNota(int nota) {
        note.push_back(nota);
    }

    float medie() const {
        if (note.empty()) return 0;
        float suma = 0;
        for (int n : note)
            suma += n;
        return suma / note.size();
    }

    void afisare() const {
        cout << "Nume: " << nume << " | Note: ";
        for (int n : note)
            cout << n << " ";
        cout << "| Medie: " << medie() << endl;
    }
};

int main() {
    vector<Elev> elevi;
    int opt;

    do {
        cout << "\n=== MENIU ===\n";
        cout << "1. Adauga elev\n";
        cout << "2. Adauga nota\n";
        cout << "3. Afiseaza elevi\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> opt;

        switch (opt) {
        case 1: {
            string nume;
            cout << "Nume elev: ";
            cin.ignore();
            getline(cin, nume);
            elevi.emplace_back(nume);
            cout << "Elev adaugat.\n";
            break;
        }

        case 2: {
            int index, nota;
            cout << "Index elev (0 - " << elevi.size() - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= elevi.size()) {
                cout << "Index invalid.\n";
                break;
            }

            cout << "Nota: ";
            cin >> nota;
            elevi[index].adaugaNota(nota);
            cout << "Nota adaugata.\n";
            break;
        }

        case 3:
            for (int i = 0; i < elevi.size(); i++) {
                cout << i << ". ";
                elevi[i].afisare();
            }
            break;

        case 0:
            cout << "La revedere!\n";
            break;

        default:
            cout << "Optiune invalida.\n";
        }

    } while (opt != 0);

    return 0;
}
