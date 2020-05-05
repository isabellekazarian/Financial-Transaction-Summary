/*
* Author: Isabelle Kazarian
* Program Title:  Financial Transaction Summary
* Program Description: This program reads data from three files
  to sort financial transaction information by category and ID.
* Date Created: 4/27/2017
* Date Last Modified: 5/5/2020
 */

/*
 * Data Abstraction:
    3 input file streams initialized
    Counters initialized for initial/total balance,
    number of missing transactions, number of transactions
    and number of categories.
    Arrays for transactions and categories initialized
    Variables initialized for data in input files

 * Input:
    Transaction data comes from transactions.txt
    Category data comes from categories.txt
    Initial balance comes from balance.dat

 * Process:
    Information is read from data files and stored in
    appropriate array or variable.
    Total balance updated to match initial balance
    Category descriptions stored with each Transaction
    Transactions sorted by ID

 * Output:
    Transaction data is outputted:
    if the amount was withdrawn, it is subtracted from the
    total balance. If deposited, added.
    If there is a missing transaction, it is noted.
    If there is a negative balance at any time, this is
    highlighted at the end of the output.

 * Assumptions:
    All transaction input is in identical formats
    There is a dollar sign before each trans. amount
    Deposit/withdrawal indicated by D or W
    There is no missing information
    No more than 100 transactions
    No more than 50 categories
 */

#include "prog25Functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

int main()
{
    ifstream in_file1, in_file2, in_file3;

    bool neg_bal = false;
    string temp;
    char tempc;
    double init_bal = 0;
    double tot_bal = 0;


    // Transaction variables
    Transaction t[100];
    int trans_id, prev_trans;
    char dw;
    double amt;
    int t_count = 0;

    // Category variables
    Category c[50];
    int cat_id;
    string desc;
    int c_count = 0;



    // --- Read/store transaction data --- //
    in_file1.open("transactions.dat");

    getline(in_file1, temp);
    while(in_file1 >> trans_id >> dw >> amt >> cat_id)
    {
        t[t_count].set_id(trans_id);
        t[t_count].set_dw(dw);
        t[t_count].set_amt(amt);
        t[t_count].set_cat(cat_id);

        t_count ++;
    }

    in_file1.close();



    // --- Read/store category data --- //
    in_file2.open("categories.txt");

    getline(in_file2, temp);
    while(in_file2 >> cat_id)
    {
        getline(in_file2, desc);
        c[c_count].set_id(cat_id);
        c[c_count].set_desc(desc);

        c_count++;
    }

    in_file2.close();


    // --- Read/store balance data --- //
    in_file3.open("balance.dat");
    in_file3 >> temp >> temp >> tempc >> init_bal;
    in_file3.close();

    tot_bal += init_bal;


    // --- Process data --- //
    // Set category descriptions for each transaction
    for(int i = 0; i < t_count; i++)
    {
        for(int j = 0; j < c_count; j++)
        {
            if(t[i].get_cat() == c[j].get_id())
               t[i].set_catdesc(c[j].get_desc());
        }
    }

    // Sort by transaction ID
    sortid(t, t_count);

    cout << setprecision(2) << fixed;

    // Header
    cout << setw(5) << left  << "ID"
         << setw(40)<< right << "Category"
         << setw(3) << right << "T"
         << setw(9) << right << "Amount"
         << setw(9) << right << "Balance" << endl << endl;


    // Data output
    for(int i=0; i < t_count; i++)
    {

        // Add/subtract balance for deposit/withdrawal
        if(t[i].get_dw() == 'D')
            tot_bal += t[i].get_amt();
        else
            tot_bal -= t[i].get_amt();

        // Check for negative balance
        if(tot_bal < 0)
            neg_bal = true;

        // Check for missing transactions
        if(t[i].get_id() != (prev_trans + 1) && i>0)
        {
            cout << "-" << setw(65) <<"*MISSING TRANSACTION*"  << endl;
        }

        cout << setw(5)  << left  << t[i].get_id()
             << setw(40) << right << t[i].get_catdesc()
             << setw(3)  << right << t[i].get_dw()
             << setw(9)  << right << t[i].get_amt()
             << setw(9)  << right << tot_bal << endl;

        // Set transaction # as previous transaction #
        prev_trans = t[i].get_id();
    }

    if(neg_bal == true)
        cout << endl << "***** WARNING: Negative Balance *****" << endl;

    return 0;
}
