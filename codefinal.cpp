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
void admin_optionD();
void add_blacklist(string user);

void customer_mode();
void customer_optionA();
void customer_optionB();
void customer_optionC();
int search_for_most_fit_table(tables *&head,int num_of_ppl);
void occupy_table(tables *&head,int vacant_table_num);
void rewrite_table_information(tables *&head);
void customer_optionD();
void customer_optionF();


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
    cout << "- Complaint ------------------ F" << endl;
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
    else if (option=="F") {
      customer_optionF();
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
  }
  cout << endl << "Press E to exit: ";
  cin >> exit;
  cout << "Back to main menu" << endl << endl;
  menu.close();
}

// (COMPLETE)
// print the table information in regular format
// similar to admin_optionB()
void customer_optionB() {
  ifstream fin;
  fin.open("table_information.txt");
  if (fin.fail()) {
    cout << "Failed to open table_information.txt" << endl;
  }
  string line,yes_or_no,exit;
  tables_head=NULL;
  while (getline(fin,line)) {
    int table_num,size;
    string status;
    table_num=line[0]-'0';
    size=line[2]-'0';
    status=line.substr(4,6);
    append_tables(tables_head,table_num,size,status);
  }
  fin.close();
  cout << "[Option B] entered" << endl << endl;
  print_table_information(tables_head);
  cout << "Press E to exit [Option B]: ";
  cin >> exit;
  cout << "Exiting [Option B]" << endl;
  cout << "Back to main menu" << endl << endl;
}

// (COMPLETE)
// this function suggest a vacant table with minimal seats
// if there is vacant table, return the table_num
// if all the tables are occupied, return -1
// occupy_table turns that status of that table from "vacant" to "occupy"
void customer_optionC() {
  int vacant_table_num,num_of_ppl;
  string choice,exit;
  cout << "[Option C] entered" << endl;
  cout << "Please enter the number of people: ";
  cin >> num_of_ppl;
  vacant_table_num=search_for_most_fit_table(tables_head,num_of_ppl);
  if (vacant_table_num>0) {
    cout << endl << "CCH restaurant suggests you to occupy table " << vacant_table_num << "!" << endl;
    cout << endl << "Please enter your choice (Yes/No): ";
    cin >> choice;
    cout << endl;
    if (choice=="Yes") {
      occupy_table(tables_head,vacant_table_num);
      print_table_information(tables_head);
      cout << "You have successfully occupied table " << vacant_table_num << "." << endl << endl;
    }
  }
  else {
    cout << endl;
    print_table_information(tables_head);
    cout << "Sorry there is no vacant table so far." << endl;
    cout << "Please come back after a while." << endl << endl;
  }
  cout << "Press E to exit: ";
  cin >> exit;
  cout << "Exiting [Option C]" << endl;
  cout << "Back to main menu" << endl << endl;
}

// (COMPLETE)
// search for table that the table size >= num_of_ppl
// if no table suits, return -1
int search_for_most_fit_table(tables *&head,int num_of_ppl) {
  tables *current=head;
  while (current!=NULL) {
    if (current->size>=num_of_ppl && current->status=="vacant") {
      return current->table_num;
    }
    current=current->next;
  }
  return -1;
}

// (COMPLETE)
// turns the status of that table from "vacant" to "occupy"
// update the table_information.txt
void occupy_table(tables *&head,int vacant_table_num) {
  int steps=vacant_table_num-1;
  tables *current=head;
  for (int k=0;k<steps;k+=1) {
    current=current->next;
  }
  current->status="occupy";
  rewrite_table_information(tables_head);
}

// (COMPLETE)
void rewrite_table_information(tables *&head) {
  ofstream fout;
  fout.open("table_information.txt");
  if (fout.fail()) {
    cout << "Failed to open table_information.txt" << endl;
  }
  tables *current=head;
  int table_num,size;
  string status;
  while (current!=NULL) {
    table_num=current->table_num;
    size=current->size;
    status=current->status;
    fout << table_num << " " << size << " " << status << endl;
    current=current->next;
  }
  fout.close();
}

// (COMPLETE)
// this function is to release the table occupied
void customer_optionD() {
  int table_to_be_release;
  string yes_or_no,exit;
  cout << "[Option D] entered" << endl;
  cout << "Please enter the table number to release: ";
  cin >> table_to_be_release;
  cout << "Are you sure to release table " << table_to_be_release << "? (Yes/No): ";
  cin >> yes_or_no;
  if (yes_or_no=="Yes") {
    release_table(tables_head,table_to_be_release);
  }
  cout << endl << "Press E to exit: ";
  cin >> exit;
  cout << "Exiting [Option D]" << endl;
  cout << "Back to main menu" << endl << endl;
}

// (COMPLETE)
// this function is for customer to complaint
void customer_optionF() {
  cout << "[Option F] entered" << endl;
  cout << "Please input your complaint: (Input 0 to stop)" << endl;
  string text,exit;
  ofstream fout;
  fout.open("complaint.txt",ios::app);
  while (getline(cin,text)) {
    if (text=="0") {
      break;
    }
    fout << text << endl;
  }
  fout.close();
  cout << "Thank you for your opinion! We will view your complaint as soon as possible." << endl;
  cout << endl << "Press E to exit: ";
  cin >> exit;
  cout << "Exiting [Option F]" << endl;
  cout << "Back to main menu" << endl << endl;
}


// ---------------[Admin mode]---------------

// (COMPLETE)
void admin_mode() {
  string option="";
  while (option!="E") {
    cout << "[Admin mode] Hello CCH Restaurant!" << endl;
    cout << "*main menu*" << endl;
    cout << "- Input table information ------ A" << endl;
    cout << "- Modify tables ---------------- B" << endl;
    cout << "- Blacklist customers ---------- C" << endl;
    cout << "- View complaints -------------- D" << endl;
    cout << "- Exit ------------------------- E" << endl;
    cout << "-> Option: ";
    cin >> option;
    cout << endl;
    if (option=="A") {
      admin_optionA();
    }
    else if (option=="B") {
      admin_optionB();
    }
    else if (option=="C") {
      admin_optionC();
    }
    else if (option=="D") {
      admin_optionD();
    }
  }
  cout << "Bye bye!" << endl;
}

// (COMPLETE)
// Open "table_information.txt", that erase the old infomration
// output the new table information to "table_information.txt"
void admin_optionA() {
  cout << "[Option A] entered" << endl;
  int num_of_tables;
  string status="vacant",exit;
  cout << "Please input the number of tables: ";
  cin >> num_of_tables;
  ofstream fout;
  fout.open("table_information.txt");
  if (fout.fail()) {
    cout << "Failed to open table_information.txt" << endl;
  }
  for (int n=1;n<=num_of_tables;n+=1) {
    int size;
    cout << "Input size of table " << n << ": ";
    cin >> size;
    fout << n << " " << size << " " << status << endl;
  }
  fout.close();
  cout << endl << "Press E to exit: ";
  cin >> exit;
  cout << "Exiting [Option A]" << endl;
  cout << "Back to main menu" << endl << endl;
}


// (COMPLETE)
// read in data from table_information.txt
// store data to struct called "tables"
// print the data in regular format
// if "release table", status of that table will turn from "occupied" to "vacant"
void admin_optionB() {
  ifstream fin;
  fin.open("table_information.txt");
  if (fin.fail()) {
    cout << "Failed to open table_information.txt" << endl;
  }
  string line,yes_or_no,exit;
  tables_head=NULL;
  while (getline(fin,line)) {
    int table_num,size;
    string status;
    table_num=line[0]-'0';
    size=line[2]-'0';
    status=line.substr(4,6);
    append_tables(tables_head,table_num,size,status);
  }
  fin.close();
  cout << "[Option B] entered" << endl << endl;
  print_table_information(tables_head);
  cout << "Release table? (Yes/No): ";
  cin >> yes_or_no;
  if (yes_or_no=="Yes") {
    int table_to_be_release;
    cout << "Please input table number: ";
    cin >> table_to_be_release;
    release_table(tables_head,table_to_be_release);
    cout << "Table " << table_to_be_release << " successfully released." << endl << endl;
    print_table_information(tables_head);
  }
  cout << "Press E to exit [Option B]: ";
  cin >> exit;
  cout << "Exit [Option B]" << endl;
  cout << "Back to main menu" << endl << endl;
}

// (COMPLETE)
// turn the status of that table from "occupied" to "vacant"
void release_table(tables *&head,int table_to_be_release) {
  int tranverse_times=table_to_be_release-1;
  tables *current=head;
  for (int j=0;j<tranverse_times;j+=1) {
    current=current->next;
  }
  current->status="vacant";
  rewrite_table_information(tables_head);
}

// (COMPLETE)
// build a linked list called "tables" in forward manner, with head only
void append_tables(tables *&head,int table_num,int size,string status) {
  tables *p=new tables;
  p->table_num=table_num;
  p->size=size;
  p->status=status;
  p->next=NULL;
  if (head==NULL) {
    head=p;
  }
  else {
    tables *current=head;
    while (current->next!=NULL) {
      current=current->next;
    }
    current->next=p;
  }
}

// (COMPLETE)
// print out the table information in regular format
void print_table_information(tables *&head) {

