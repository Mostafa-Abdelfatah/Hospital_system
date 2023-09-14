#include <iostream>

using namespace std;
struct hospital_queue {
    string names[5];
    int status[5];
    int len = 0;

    void add_end(string name, int st) {
        if(len >= 5) {
            cout << "there are 5 patients\n";
            return;
        }
        else {
            names[len] = name;
            status[len] = st;
            len++;
            return;
        }
    }

    void add_front(string name, int st) {
        if(len >= 5) {
            cout << "there are 5 patients\n";
            return;
        }
        else {
            for(int i = len - 1; i >= 0; i--) {
                names[i + 1] = names[i];
                status[i + 1] = status[i];
            }
            names[0] = name;
            status[0] = st;
            len++;
            return;
        }
    }

    void remove_front() {
        if(len == 0) {
            cout << "no patients\n";
        }
        else {
            cout << "please go " << names[0] << " to the doctor\n";
            for (int i = 1; i < len; i++) {
                names[i - 1] = names[i];
                status[i - 1] = status[i];
            }
            len--;
        }
    }

    void print() {
        if (len == 0) {
            cout << "no patients\n";
        }
        else{
            for(int i = 0; i < len; i++) {
                cout << names[i] << " ";
                if(status[i])
                    cout << "urgent\n";
                else
                    cout << "regular\n";
            }
        }
    }
};

struct hospital_system {
    hospital_queue qu[20];
    void run() {
        cout << "Enter your choice:" << "\n";
        cout << "1) Add new patients" << "\n";
        cout << "2) Print all patients" << "\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit" << "\n";
        cout << "please enter the number of operation: ";
        int x;
        cin >> x;
        cout << "\n";
        if(x > 4 || x < 1) {
            cout << "please enter a valid number!\n";
            run();
        }
        if(x == 1) {
            cout << "please enter the number of specialization: ";
            int sp;
            cin >> sp;
            cout << "\nplease enter the statue: ";
            int st;
            cin >> st;
            cout << "\nplease enter the name :";
            string na;
            cin >> na;
            cout <<"\n";
            if(st) {
                qu[sp - 1].add_front(na, st);
            }
            else {
                qu[sp - 1].add_end(na, st);
            }
        }
        else if (x == 2) {
            for(int i = 0; i < 20; i++) {
                if(qu[i].len) {
                    cout << "the patients at department " << i + 1 << "\n";
                    qu[i].print();
                }
            }
        }
        else if (x == 3) {
            cout << "please enter the number of specialization: ";
            int sp;
            cin >> sp;
            cout << "\n";
            qu[sp - 1].remove_front();
        }
        else if (x == 4) {
            cout << "GoodBye\n";
        }
        run();
    }
};

int main() {

    hospital_system s;
    s.run();
    return 0;
}