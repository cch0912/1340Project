# 1340Project
Suppose we are operating a very popular restaurant with many customers queuing outside waiting for seats. Our project is to introduce a program that allows customers to can reserve a vacant table or queue up for an occupied table before arriving the restaurant. 

First, the program will require users to enter a valid account. 
The restaurant’s account will be set in the program code. For example, we will set a variable called ‘user_name = “CCH restaurant” ’ and ‘PW = 12345’. Then, if staff login with the restaurant’s account, it will enter the ADMIN MODE.
On the other hand, customers have to register and create a customer’s account. They will login in to the system and enter the CUSTOMER MODE.

Login interface should look like this:
> ******************************************************************
> ********************Welcome to CCH restaurant!********************
> ******************************************************************

> Press L to login / Press R to create new account: L

> User name: CCH restaurant
> Password: 12345

> [Login success]


**The ADMIN MODE will be discussed first.**
> [Admin mode] Hello CCH Restaurant!
> *Main menu*
> - Input table information --------- A
> - Modify tables ------------------- B
> - Blacklist customers ------------- C
> - View complaints ------------------D
> - Exit ---------------------------- E

>  Option: A 

When we enter the ADMIN MODE, options will be provided. 
For option A, we can change the number of tables and the size of tables.
> [Option A] entered
> Please input the number of tables: 8 

We will then enter a for loop of 8 to input the size of tables.
> [Option A] entered

> Please input the number of tables: 8

> Input size of table 1: 2

> Input size of table 2: 2

> Input size of table 3: 2

> Input size of table 4: 4

> Input size of table 5: 4

> Input size of table 6: 4

> Input size of table 7: 6

> Input size of table 8: 6


> Press E to exit [Option A]: E

> Exiting [Option A]

> Back to Main menu

We will then be directed back to the main menu and enter option B.
> [Admin mode] Hello CCH restaurant!
> *Main menu*
> - Input table information --------- A
> - Modify tables ------------------- B
> - Blacklist customers ------------- C
> - View complaints ------------------D
> - Exit ---------------------------- E

>  Option: B 

For option B, we can see if the tables are being occupied or vacant.
> [Option B] entered
>
>           Size  Status    
> - Table 1  2      vacant    
> - Table 2  2      vacant    
> - Table 3  2      vacant    
> - Table 4  4      vacant    
> - Table 5  4      vacant    
> - Table 6  4      vacant    
> - Table 7  6      vacant      
> - Table 8  6      vacant      

> Press E to exit [Option B]: E

> Exiting [Option B]

> Back to Main menu

We will then be directed back to the main menu and enter option C.
> [Admin mode] Hello CCH restaurant!
> *Main menu*
> - Input table information --------- A
> - Modify tables ------------------- B
> - Blacklist customers ------------- C
> - View complaints ------------------D
> - Exit ---------------------------- E

>  Option: C

The restaurant can blacklist customers by entering their account names. Then, the customers will no longer be allowed to use this program to reserve table.
> [Option C] entered
> Blacklist user: chantaiman123

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

For option D, the restaurant can view the complaints made by customers.
> [Option D] entered
> Complaints are as follows:
table 2 has been occupied for a long time!

> Press E to exit: E

> Exit [Option D]

> Back to main menu

 
**Now, we will discuss the CUSTOMERS MODE. 
Supposedly, a customer has to create an account.**

> ******************************************************************
> ********************Welcome to CCH Restaurant!********************
> ******************************************************************

> Press L to login / Press R to create new account: R

> Please enter your user name: chowchunho123
> Please enter your password: 12345678

> Account created!

> Press L to login / Press R to create new account: L

> User name: chowchunho123
> Password: 12345678

> [Login success]

Then, since the user is not ‘CCH restaurant’, he or she will be in the customer mode.
> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Pre-occupy a table --------- C
> - Release a table ------------ D
> - Exit ----------------------- E
> - Complaint ------------------ F

>  Option: A

For option A, customers can see the dishes being served at the restaurant and decide whether they want to go to eat.
> [Option A] entered
> Today’s Dishes
> - Set A: Yeung Chow Fried Rice
> - Set B: Seafood Fried Rice with Curry Sauce
> - Set C: Ham Fried Rice with Tomato Sauce
> - Set D: Fried Noodle with Beef in Black Bean Sauce
> - Set E: Fried Rice Noodle with Beef in Soy
> - Set F: Fried Noodle with Mixed Vegetables
> - Set G: Baked Fish Fillet with Cream Sauce
> - Set H: Baked Pork Chop with Tomato Sauce
> - Set I: Baked Seafood with Cream Sauce

> Press E to exit: E

> [Exiting Option A]

> Back to main menu

We will then be directed back to the main menu and enter option B.

> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Pre-occupy a table --------- C
> - Release a table ------------ D
> - Exit ----------------------- E
> - Complaint ------------------ F

>  Option: B

For option B, customers can check the current table situation, whether the tables are occupied or vacant.
“Occupied” means that there are customers still eating at that table. 

> [Option B] entered
>
>           Size    Status    
> - Table 1  2      vacant    
> - Table 2  2      vacant    
> - Table 3  2      vacant    
> - Table 4  4      vacant    
> - Table 5  4      vacant    
> - Table 6  4      vacant    
> - Table 7  6      vacant      
> - Table 8  6      vacant      

> Press E to exit [Option B]: E

> Exiting [Option B]

> Back to Main menu

Now, if customers see that table 6 is currently vacant and they want to reserve table 6 before arriving the restaurant. He or she should enter option C and occupy that table.
> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Pre-occupy a table --------- C
> - Release a table ------------ D
> - Exit ----------------------- E
> - Complaint ------------------ F

>  Option: C
For option C, customers will input the number of people. The program will suggest a vacant table with minimal enough seats to the customer. If there is no vacant table, the program will tell the customer that there are no tables and ask them to come back later.

Example 1.1: 2 people, the program will suggest him to occupy a particular table, and see if they confirm their reservation.

> [Option C] entered
> Please enter the number of people: 2

> CCH restaurant suggests you to queue for table 3!

> Please indicate your choice (Yes/No): Yes

> You have successfully occupied table 3.

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

Example 1.2: 2 people, but they choose to not reserve the table.
> [Option C] entered
> Please enter the number of people: 2

> CCH restaurant suggests you to reserve table 3!

> Please indicate your choice (Yes/No): No

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

Example 2: All tables are occupied.
> [Option C] entered

> "Sorry there is no vacant table so far."

> "Please come back after a while."

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

We will then go back to the main menu and enter option D.
> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Pre-occupy a table --------- C
> - Release a table ------------ D
> - Exit ----------------------- E
> - Complaint ------------------ F

>  Option: D

For option D, if the customer wants to give up their table, they can do it.

Example 1: Giving up table 3. Then, the table will become vacant.
> [Option D] entered

> Please enter the table number to release:

> Are you sure you want to release table 3? (Yes/No): Yes

> Press E to exit: E

> Exiting [Option D]

> Back to main menu

Example 2: They decided to not give up the table.
> [Option D] entered
> Please enter the table number to release:

> Are you sure you want to release table 3? (Yes/No): No

> Press E to exit: E

> Exiting [Option D]

> Back to main menu


For option F, the customer can complaint or report situation, like notify the waiter for tables occupied for too long.
> [Option F] entered
> Please input your complaint:
table 2 has been occupied for a long time

> Thank you for your opinion. We will view your comment as soon as possible!

> Press E to exit: E

> Exiting [Option F]

> Back to main menu


