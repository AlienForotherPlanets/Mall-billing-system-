// code by 19CP055
// 19CP057
// 19CP204
#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
using namespace std;
// structure for saving the detail of things
typedef struct
{
    char name[20];
    int quantity;
    float amount;
    float total;
} purchaselist;
class customer
{
    char name[30];
    char cust_id[10];
    char mobno[10];
    float billamt = 0;
    char address[40];
    purchaselist p[30];
    int n;

public:
    customer() {} // default constructor
    void setdata()
    {
        cout << "enter the customer details " << endl;
        cout << "enter the name  ";
        fflush(stdin);
        gets(name);
        cout << "enter the customer id ";
        cin >> cust_id;
        cout << "enter the mobile number ";
        int x = 1;
        while (x) // checking the mobile number is valid or not
        {
            cin >> mobno;
            try
            {
                if (strlen(mobno) != 10)
                    throw 1;
                if (1)
                {
                    for (int d = 0; d < 10; d++)
                    {
                        if (!(mobno[d] == '0' || mobno[d] == '1' || mobno[d] == '2' || mobno[d] == '3' || mobno[d] == '4' || mobno[d] == '5' || mobno[d] == '6' || mobno[d] == '7' || mobno[d] == '8' || mobno[d] == '9' || mobno[d] == '10'))
                            throw 2.32;
                    }
                }
                x = 0;
            }
            catch (...) // generic exception handler
            {
                cout << "mobile number is incorrect \nenter the mobile number correctly ";
            }
        }
        cout << "enter the address ";
        fflush(stdin);
        gets(address);
        cout << "---------------------" << endl;
    }

    void billing() // thing details and billing
    {
        cout << "bill section " << endl;
        cout << "how many things are there ";
        int i;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "name of thing = ";
            fflush(stdin);
            gets(p[i].name);
            cout << "quantity = ";
            cin >> p[i].quantity;
            cout << "amount of 1 piece ";
            cin >> p[i].amount;
        }
        // displaying things and their quantities
        cout << "things and quantities are ";
        cout << "name of thing\tquantity" << endl;
        for (i = 0; i < n; i++)
        {
            cout << "name of thing = " << p[i].name;
            cout << "\tquantity = " << p[i].quantity << endl;
        }
        int control = 1;
        while (control) // for add,remove thing or change the quantity
        {
            cout << "\n\nif you want to add thing enter 1;\nif you want to remove then enter 2;\nif you want to change quantity then enter 3;\notherwise enter 0" << endl;
            int x1;
            cin >> x1;
            switch (x1) // menu driven program
            {
            case 1:
            {
                cout << "name of thing = ";
                fflush(stdin);
                gets(p[n].name);
                cout << "quantity = ";
                cin >> p[n].quantity;
                cout << "amount of 1 piece ";
                cin >> p[n].amount;
                n++;
                break;
            }
            case 2:
            {
                cout << "name of thing = ";
                fflush(stdin);
                char thname[20];
                gets(thname);
                int i, m1 = -1;
                for (i = 0; i < n; i++)
                {
                    if (!strcmp(p[i].name, thname))
                        m1 = i;
                }
                if (m1 == -1)
                    cout << "no such thing in your list " << endl;
                else
                {
                    for (i = m1; i < n; i++)
                        p[i] = p[i + 1];
                }
                n--;
                break;
            }
            case 3:
            {
                cout << "name of thing = ";
                fflush(stdin);
                char thname2[20];
                gets(thname2);
                int i, m2 = -1;
                for (i = 0; i < n; i++)
                {
                    if (!strcmp(p[i].name, thname2))
                        m2 = i;
                }
                if (m2 == -1)
                    cout << "no such thing in your list " << endl;
                else
                {
                    cout << "enter new quantity ";
                    cin >> p[m2].quantity;
                }
                break;
            }
            case 0:
                control = 0;
            default:
                cout << "invalid input " << endl;
            }
        }
        // calculating total amount of bill
        for (i = 0; i < n; i++)
        {
            p[i].total = (p[i].quantity) * (p[i].amount);
            billamt += p[i].total;
        }
    }
    void display() // for display customer detail, things with amount and bill
    {
        cout << "----------------------------------------" << endl;
        cout << "final bill " << endl;
        cout << "customer details " << endl;
        cout << "name= " << name << endl;
        cout << "customer id= " << cust_id << endl;
        cout << "mobile number= " << mobno << endl;
        cout << "address= " << address << "\n\n";
        cout.width(15);
        cout << "name";
        cout.width(20);
        cout << "quantity";
        cout.width(10);
        cout << "amount";
        cout.width(10);
        cout << "total " << endl;
        int i;
        for (i = 0; i < n; i++) // formatted io
        {
            cout.width(15);
            cout << p[i].name;
            cout.width(20);
            cout << p[i].quantity;
            cout.width(10);
            cout << p[i].amount;
            cout.width(10);
            cout << p[i].total << endl;
        }
        cout << "\t\ttotal payable bill amount =" << billamt;
        cout << "\n-----------------------------------------" << endl;
    }
    bool checkid(const char *a) // for check customer id
    {
        if (!strcmp(cust_id, a))
            return 1;
        else
            return 0;
    }
};

int main()
{
    ofstream fout("billing", ios::app); // creating file
    fout.close();
    int control = 1;
    while (control) // infinite loop, it will end when user wants to end(enter greater than 3)
    {
        cout << "for enter the customer entry enter 1,\nfor search the detail of customer 2,\nfor display all the customer detail and bill enter 3,\nfor leaving the program enter 0\n";
        int i;
        cin >> i;
        if (i == 1) // adding the customer
        {
            ofstream fout("billing", ios::app); // opening file
            customer c;
            c.setdata();
            c.billing();
            c.display();
            fout.write((char *)&c, sizeof(customer));
            fout.close();
            getch();
            system("CLS");
        }
        else if (i == 2) // finding customer detail and bill
        {
            ifstream fin("billing");
            fin.seekg(0, ios_base::beg);
            customer cs;
            cout << "enter the customer number :";
            char csno[10];
            cin >> csno;
            int check;
            while (!fin.eof())
            {
                fin.read((char *)&cs, sizeof(customer));
                if (cs.checkid(csno))
                {
                    cs.display();
                    check = 0;
                    break;
                }
                else
                    check = 1;
            }
            if (check == 1) // message for no such customer having given id
            {
                cout << "no such customer having given id ";
            }
            fin.close();
        }
        else if (i == 3) // displaying all customer's details and bill details
        {
            ifstream fin1("billing");
            fin1.seekg(0, ios_base::beg);
            customer cs1;
            while (!fin1.eof())
            {
                fin1.read((char *)&cs1, sizeof(customer));
                if (!fin1.eof())
                    cs1.display();
            }
        }
        else if (i == 0) // to exit the menu and program
        {
            control = 0; // exiting program
        }
        else
            cout << "invalid input" << endl;
    }
    return 0;
}
