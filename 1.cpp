#include <iostream>
#include <fstream>


using namespace std;



string convert(string res) {
    int size = res.size();

    if (size < 20) {
        for (; res.size() < 20;) {
            res += ' ';
        }
    }
    return res;
}

class HomeAccounting {

public:
   

    void recordExpense(int expense)
    {

        ofstream fout("expenses.txt", ios::app);
        if (fout.is_open())
        {
            fout << expense << endl;
            fout.close();
        }
        else
        {
            cout << "Unable to open file!"<<"\n";
        }
    }
    void recordIncome(int income)
    {
        ofstream fout("incomes.txt", ios::app);
        if (fout.is_open())
        {
            fout << income << endl;
            fout.close();
        }
        else
        {
            cout << "Unable to open file!"<<"\n";
        }
    }

    void calculateBalance()
    {
        int balance = 0;
       
        ifstream fin("incomes.txt");

        if (fin.is_open())
        {
            while (!fin.eof())
            {
                int token;
                fin >> token;
                balance += (int)token;
            }
            fin.close();
        }
        else
        {
            cout << "Unable to open file!"<<"\n";
        }

        ifstream fen("expenses.txt");
        if (fen.is_open())
        {
            while (!fen.eof())
            {
                
               int token;

                fen >> token;
                balance -= (int)token;
            }
            fen.close();
        }
        else
        {
            cout << "Unable to open file!"<<"\n";
        }
        cout << "balance"<<"\t";
        cout << balance<<"\n";
    }
    void percentmonth() {
        int exepenced,food,cloths,electronic,perevod;
    
        food = 20000 * 100 / 100000;
        cloths = 10000 * 100 / 100000;
        electronic = 40000 * 100 / 100000;
        perevod = 30000 * 100 / 100000;
        cout << "persent month" << "\n";
        cout << food  << "% food" << "\t";
        cout << cloths  << "% cloths " << "\t";
        cout << electronic  << "% electronic " << "\t";
        cout << perevod  << "% perevod " << "\n";
    }
    void percentall() {
        int exepenced, food, cloths, electronic, perevod;

        food = 200000 * 100 / 1000000;
        cloths = 100000 * 100 / 1000000;
        electronic = 400000 * 100 / 1000000;
        perevod = 300000 * 100 / 1000000;
        cout << "persent all" << "\n";
        cout << food << "% food " << "\t";
        cout << cloths  << "% cloths " << "\t";
        cout << electronic  << "% electronic" << "\t";
        cout << perevod  << "% perevod " << "\t";
    }
};
int main() {
    HomeAccounting* user1 = new HomeAccounting();
    user1->recordExpense(1000000);
    user1->recordIncome(1000000);
    user1->calculateBalance();
    user1->percentmonth();
    user1->percentall();
}
