#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct tables {
  int table_num;
  int size;
  string status;
  tables *next;
};

tables *tables_head=NULL;

void login();
void add_customer(string account,string password);
bool search_customer(string account,string password);
bool in_blacklist(string account);

void admin_mode();
void admin_optionA();
void append_tables(tables *&head,int table_num,int size,string status);
void print_table_information(tables *&head);
void release_table(tables *&head,int table_to_be_release);
void admin_optionB();
void admin_optionC();
void add_blacklist(string user);

void customer_mode();
void customer_optionA();
void customer_optionB();
void customer_optionC();
int search_for_most_fit_table(tables *&head,int num_of_ppl);
void occupy_table(tables *&head,int vacant_table_num);
void rewrite_table_information(tables *&head);
void customer_optionD();


int main() {
  login();
}

// ---------------[Login interface]---------------

// the user can keep creating account until he press "L" to login, so a while loop is used
// for 'create account', the account information (i.e.account name and password), will be added into a linked list called 'customers'
// for 'login', if the account information is in the linked list 'users', login will be successful
void login() {
  string login_or_create,ac,pw;
  cout << "******************************************************************" << endl;
  cout << "********************Welcome to CCH restaurant!********************" << endl;
  cout << "******************************************************************" << endl << endl;
  cout << "Press L to login / Press R to create new account: ";
  cin >> login_or_create;
  cout << endl;
  while (login_or_create=="R") {
    cout << "Please enter your user name: ";
    cin >> ac;
    cout << "Please enter your password: ";
    cin >> pw;
    add_customer(ac,pw);
    cout << "Account created!" << endl << endl;
    cout << "Press L to login / Press R to create new account: ";
    cin >> login_or_create;
    cout << endl;
  }
  if (login_or_create=="L") {
    cout << "User name: ";
    cin >> ac;
    cout << "Password: ";
    cin >> pw;
    if (search_customer(ac,pw)==true) { // the user is customer
      if (in_blacklist(ac)==true) {
        cout << endl << "You are blacklisted." << endl;
        cout << "[Login failed]" << endl;
      }
      else {
        cout << "[Login success]" << endl << endl;
        customer_mode();
      }
    }
    else if (ac=="CCH_restaurant" && pw=="12345") { // the user is the restaurant owner
      cout << "[Login success]" << endl << endl;
      admin_mode();
    }
    else { // neither the above two cases
      cout << "[Login failed]" << endl;
    }
  }
}

// (COMPLETE)
// open "customers_account.txt"
// append the account information into txt
// close
void add_customer(string account,string password) {
  ofstream fout;
  fout.open("customers_account.txt",ios::app);
  if (fout.fail()) {
    cout << "Failed to open customers_account.txt" << endl;
  }
  fout << account << " " << password << endl;
  fout.close();
}

// (COMPLETE)
// read data from "customers_account.txt"
// store data to "customers" linked list
// search whether input is in the list, return true or false
bool search_customer(string account,string password) {
  ifstream fin;
  fin.open("customers_account.txt");
  if (fin.fail()) {
    cout << "Failed in opening customers_account.txt" << endl;
  }
  string line;
  while (getline(fin,line)) {
    int l=line.length(),pos=0;
    string ac_in_file="",pw_in_file="";
    while (line[pos]!=' ') {
      ac_in_file+=line[pos];
      pos+=1;
    }
    pos+=1;
    while (pos<l) {
      pw_in_file+=line[pos];
      pos+=1;
    }
    if (ac_in_file==account && pw_in_file==password) {
      return true;
    }
  }
  return false;
}

// (COMPLETE)
// if the user name is in blacklist, return true, and login fail
bool in_blacklist(string account) {
  ifstream fin;
  fin.open("blacklist.txt");
  if (fin.fail()) {
    cout << "Failed to open blacklist.txt" << endl;
  }
  string line;
  while (getline(fin,line)) {
    if (line==account) {
      return true;
    }
  }
  return false;
}

// ---------------[Customer mode]---------------

void customer_mode() {
  string option="";
  while (option!="E") {
    cout << "[Customer mode] Hello!" << endl;
    cout << "*main menu*" << endl;
    cout << "- Check today's menu --------- A" << endl;
    cout << "- Check tables occupation ---- B" << endl;
    cout << "- Pre-occupy a table --------- C" << endl;
    cout << "- Release a table ------------ D" << endl;
    cout << "- Exit ----------------------- E" << endl;
    cout << "-> Option: ";
    cin >> option;
    cout << endl;
    if (option=="A") {
      customer_optionA();
    }
    else if (option=="B") {
      customer_optionB();
    }
    else if (option=="C") {
      customer_optionC();
    }
    else if (option=="D") {
      customer_optionD();
    }
  }
  cout << "Byebye!" << endl;
}

// (COMPLETE)
// read in the today_menu.txt
// print out the content of the text file
void customer_optionA() {
  cout << "[Option A] entered]" << endl;
  cout << "Today's menu:" << endl;
  ifstream menu;
  menu.open("today_menu.txt");
  if (menu.fail()) {
    cout << "Failed to open menu." << endl;
  }
  string set,exit;
  while (getline(menu,set)) {
    cout << set << endl;
