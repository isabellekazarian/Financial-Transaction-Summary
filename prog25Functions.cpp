/*
* Author: Isabelle Kazarian
* Assignment Title:  Program 25
* Assignment Description: This program reads data from three files
  to sort financial transaction information by category and ID.
* Due Date: 4/27/2017
* Date Created: 4/27/2017
* Date Last Modified: 4/27/2017
 */


#include "prog25Functions.h"



// TRANSACTION FUNCTIONS
Transaction::Transaction()
{
    id = 0;
    dw = 'D';
    amt = 0;
    category = 0;
    cat_desc = "No description";
}

void Transaction::set_id(int i)
{
    id = i;
}


void Transaction::set_dw(char c)
{
    dw = c;
}


void Transaction::set_amt(double a)
{
    amt = a;
}


void Transaction::set_cat(int c)
{
    category = c;
}

void Transaction::set_catdesc(string c)
{
    cat_desc = c;
}

int Transaction::get_id()
{
    return id;
}

char Transaction::get_dw()
{
    return dw;
}

double Transaction::get_amt()
{
    return amt;
}

int Transaction::get_cat()
{
    return category;
}

string Transaction::get_catdesc()
{
    return cat_desc;
}



// CATEGORY FUNCTIONS
Category::Category()
{
    id = 0;
    desc = "No description";
}

void Category::set_id(int i)
{
    id = i;
}

void Category::set_desc(string d)
{
    desc = d;
}

int Category::get_id()
{
    return id;
}

string Category::get_desc()
{
    return desc;
}


// SORT FUNCTION
void sortid(Transaction a[], int n)
{
    for(int i = 0;  i < n-1;  i++){
        for (int j = 0;  j < n-1-i;  j++){
            if(a[j].get_id() > a[j+1].get_id())
                swap(a[j], a[j+1]);
        }
    }
}
