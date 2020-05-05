/*
* Author: Isabelle Kazarian
* Assignment Title:  Program 25
* Assignment Description: This program reads data from three files
  to sort financial transaction information by category and ID.
* Due Date: 4/27/2017
* Date Created: 4/27/2017
* Date Last Modified: 4/27/2017
 */


#ifndef PROG25FUNCTIONS_H_INCLUDED
#define PROG25FUNCTIONS_H_INCLUDED
#include <string>

using namespace std;



class Transaction
{
    private:

        int id;
        char dw;
        double amt;
        int category;
        string cat_desc;


    public:
        /*
        * description: Default constructor for transaction
        * return: none
        * precondition: none
        * postcondition: transaction exists
        */
        Transaction();

        /*
        * description: sets the transaction ID
        * return: none
        * precondition: transaction exists
        * postcondition: transaction ID is changed
        */
        void set_id(int);

        /*
        * description: sets the transaction withdrawal/deposit
        * return: none
        * precondition: transaction exists
        * postcondition: transaction withdrawal/deposit is changed
        */
        void set_dw(char);

        /*
        * description: sets the transaction amount
        * return: none
        * precondition: transaction exists
        * postcondition: transaction amount is changed
        */
        void set_amt(double);

        /*
        * description: sets the transaction category
        * return: none
        * precondition: transaction exists
        * postcondition: transaction category is changed
        */
        void set_cat(int);

        /*
        * description: sets the transaction category description
        * return: none
        * precondition: transaction exists
        * postcondition: transaction category description is changed
        */
        void set_catdesc(string);

        /*
        * description: gets transaction ID
        * return: integer
        * precondition: transaction exists
        * postcondition: transaction ID unchanged
        */
        int get_id();

        /*
        * description: gets transaction deposit/withdrawal
        * return: character
        * precondition: transaction exists
        * postcondition: transaction deposit/withdrawal unchanged
        */
        char get_dw();

        /*
        * description: gets transaction amount
        * return: integer
        * precondition: transaction exists
        * postcondition: transaction ammount unchanged
        */
        double get_amt();

        /*
        * description: gets transaction category#
        * return: integer
        * precondition: transaction exists
        * postcondition: transaction category# unchanged
        */
        int get_cat();

        /*
        * description: gets transaction category description
        * return: integer
        * precondition: transaction exists
        * postcondition: transaction category description unchanged
        */
        string get_catdesc();
};




class Category
{
    private:
        int id;
        string desc;


    public:
        /*
        * description: default constructor for category
        * return: none
        * precondition: none
        * postcondition: category exists
        */
        Category();

        /*
        * description: sets category ID
        * return: none
        * precondition: category exists
        * postcondition: category ID changed
        */
        void set_id(int);

        /*
        * description: sets category description
        * return: none
        * precondition: category exists
        * postcondition: category description changed
        */
        void set_desc(string);


        /*
        * description: gets category ID
        * return: integer
        * precondition: category exists
        * postcondition: category ID unchanged
        */
        int get_id();

        /*
        * description: gets category description
        * return: integer
        * precondition: category exists
        * postcondition: category description unchanged
        */
        string get_desc();
};


/*
* description: sorts transactions by ID#
* return: none
* precondition: array of transactions exists
* postcondition: transactions are swapped within array
*/
void sortid(Transaction a[], int n);



#endif // PROG25FUNCTIONS_H_INCLUDED
