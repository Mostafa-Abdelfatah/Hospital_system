#include <iostream>

using namespace std;
string names[21][6];
int status[21][6];
int number_of_patient[21] {0};


void add_new_patient(int sp, string name, int st) {
    if(number_of_patient[sp] == 5) {
        cout << "Sorry they are 5 patients" << "\n";
        return;
    }
    else
    {
        number_of_patient[sp]++;
        names[sp][number_of_patient[sp]] = name;
        status[sp][number_of_patient[sp]] = st;
        return;
    }
}

void print_urgent(int i) {
    for(int j = number_of_patient[i]; j >= 1 ; j--)
    {
        if(status[i][j] == 1)
            cout << names[i][j] << " " << "urgent \n";
    }
}

void print_regular(int i) {
    for(int j = 1; j <= number_of_patient[i] ; j++)
    {
        if(status[i][j] == 0)
            cout << names[i][j] << " " << "regular \n";
    }
}

void print_all_patients() {
    for(int i = 1; i <= 20; i++)
    {
       if(number_of_patient[i] > 0)
       {
           cout << "there are " << number_of_patient[i] << " in specialization " << i << "\n";
           print_urgent(i);
           print_regular(i);
       }
    }
}

void get_patient(int sp) {
    if(number_of_patient[sp] == 0) {
        cout << "no patients you can rest\n";
        return;
    }
    for(int j = number_of_patient[sp]; j >= 1; j--) {
        if(status[sp][j] == 1) {
            cout << names[sp][j] << " please go with the doctor\n";
            for(int i = j; i < number_of_patient[sp]; i++) {
                names[sp][i] = names[sp][i + 1];
                status[sp][i] = status[sp][i + 1];
            }
            number_of_patient[sp]--;
            return;
        }
    }

    for(int j = 1; j <= number_of_patient[sp]; j++) {
        if(status[sp][j] == 0) {
            cout << names[sp][j] << " please go with the doctor\n";
            for(int i = j; i < number_of_patient[sp]; i++) {
                names[sp][i] = names[sp][i + 1];
                status[sp][i] = status[sp][i + 1];
            }
            number_of_patient[sp]--;
            return;
        }
    }
}


void hospital_go() {
    cout << "Enter your choice:" << "\n";
    cout << "1) Add new patients" << "\n";
    cout << "2) Print all patients" << "\n";
    cout << "3) Get next patient\n";
    cout << "4) Exit" << "\n";
    int op;
    cin >> op;
    if(op == 1) {
        cout << "Enter specialization, name, status: ";
        int sp, st;
        string name;
        cin >> sp >> name >> st;
        add_new_patient(sp, name, st);
        cout << "\n";
        hospital_go();
    }
    else if (op == 2) {
        print_all_patients();
        cout << "\n";
        hospital_go();
    }
    else if(op == 3) {
        cout << "Enter the specialization: ";
        int sp;
        cin >> sp;
        cout << "\n";
        get_patient(sp);
        cout << "\n";
        cout << "\n";
        hospital_go();
    }
    else
        return;
}

int main() {
    hospital_go();
    return 0;
}
