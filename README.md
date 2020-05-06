# Financial Transaction Summarizer

## About
This program reads input data containing information regarding financial transactions. This information is sorted by transaction ID and categorized according to transaction type and whether it is a withdrawal or deposit. If the total balance drops below $0 at any time or if any transaction IDs are missing, the program will produce a warning.

## Prerequisites
Program can be run from either the command line or a C++-ready IDE such as CodeBlocks or Visual Studio.

## Getting started
To run, save the source files to computer. Run **main.cpp**.

## Using the program
The program will run using only input from the given files. These files may be modified to reflect different information, however, incorrect formatting may affect the program running successfully. See next section for more information.

## Assumptions
- All transaction input is in identical formats
- There is a dollar sign before each transaction amount
- Deposit/withdrawal indicated by D or W
- There is no information missing within a single transaction
- No more than 100 transactions
- No more than 50 categories
