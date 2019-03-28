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
> - Input table size --------- A
> - Modify tables ------------ B
> - Report situation --------- C
> - Blacklist customers ------ D

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
> - Input table size --------- A
> - Modify tables  ----------- B
> - Report situation --------- C
> - Blacklist customers ------ D

>  Option: B 

For option B, we can see if the tables are being occupied, reserved or vacant. The heading and the function will be explained later.
> [Option B] entered
> -                Status     Dining time     Reserved time     Queue

> - Table 1 [2]    vacant       --:--:--          --:--           0

> - Table 2 [2]    vacant       --:--:--          --:--           0

> - Table 3 [2]    vacant       --:--:--          --:--           0

> - Table 4 [4]    vacant       --:--:--          --:--           0

> - Table 5 [4]    vacant       --:--:--          --:--           0

> - Table 6 [4]    vacant       --:--:--          --:--           0

> - Table 7 [6]    vacant       --:--:--          --:--           0

> - Table 8 [6]    vacant       --:--:--          --:--           0

> Press E to exit [Option B]: E

> Exiting [Option B]

> Back to Main menu

We will then be directed back to the main menu and enter option C.
> [Admin mode] Hello CCH restaurant!
> *Main menu*
> - Input table size --------- A
> - Modify tables ------------ B
> - Report situation --------- C
> - Blacklist customers ------ D

>  Option: C

For option C, we can release a table, notify waiters for tables that have been occupied for too long, report emergencies, etc

We will then be directed back to the main menu and enter option D.
> [Admin mode] Main menu
> - Input table size --------- A
> - Modify tables ------------ B
> - Report situation --------- C
> - Blacklist customers ------ D

>  Option: D

The restaurant can blacklist customers by entering their account names. Then, the customers will no longer be allowed to use this program to reserve table.
> [Option D] entered
> Blacklist user: chantaiman123

> Press E to exit: E

> Exiting [Option D]

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

>  Option: A

For option A, customers can see the dishes being served at the restaurant and decide whether they want to go to eat.
> [Option A] entered
> Today’s Dishes
> Set A: Yeung Chow Fried Rice
> Set B: Seafood Fried Rice with Curry Sauce
> Set C: Ham Fried Rice with Tomato Sauce
> Set D: Fried Noodle with Beef in Black Bean Sauce
> Set E: Fried Rice Noodle with Beef in Soy
> Set F: Fried Noodle with Mixed Vegetables
> Set G: Baked Fish Fillet with Cream Sauce
> Set H: Baked Pork Chop with Tomato Sauce
> Set I: Baked Seafood with Cream Sauce

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

>  Option: B

For option B, customers can check the current table situation, whether the tables are occupied, reserved or vacant.
“Occupied” means that there are customers still eating at that table. The “Dining time” shows how long the customers have been staying at that table.
“Reserved” means that the table was vacant but a customer has ‘pre-occupied’ the table. He or she will be given 10 minutes before arriving the restaurant. If the reserved time counts to 0, the reserevd table will be released for other customers.
“Queue” shows how many customers are queuing for that table. If we take the following as an example, when customers at Table 5 finished their meal, table 5 will be released. Since there is already a customer queuing for table 5, it will be reserved for that particular customer and the reserved time will start to count down.
> [Option B] entered
>                Status     Dining time     Reserved time     Queue
> Table 1 [2]  occupied       00:23:13          --:--           2
> Table 2 [2]  occupied       00:46:23          --:--           1
> Table 3 [2]  occupied       01:12:13          --:--           1
> Table 4 [4]  reserved       --:--:--          08:56           0
> Table 5 [4]  occupied       02:03:45          --:--           1
> Table 6 [4]    vacant       --:--:--          --:--           0
> Table 7 [6]  occupied       00:35:24          --:--           1
> Table 8 [6]  occupied       00:04:59          --:--           1

> Press E to exit [Option B]: E

> Exiting [Option B]

> Back to Main menu

Now, if customers see that table 6 is currently vacant and they want to reserve or 'pre-occupy' table 6 before arriving the restaurant. He or she should enter option C and occupy that table.
> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Occupy a table ------------- C
> - Release a table ------------ D

>  Option: C
For option C, customers will input the number of people. The program will suggest a vacant table with minimal enough seats to the customer. If there is no vacant table, the program will suggest the customer to queue for a table.
Example 1.1: 2 people, the program will suggest him to queue for table 3 as the current dining time is the longest, it should be vacant sooner than the ohter tables.
> [Option C] entered
> Please enter the number of people: 2

> CCH restaurant suggests you to queue for table 3!

> Please indicate your choice (Yes/No): Yes

> You are queuing for table 3 at the 2nd position.

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

Example 1.2:
> [Option C] entered
> Please enter the number of people: 2

> CCH restaurant suggests you to queue for table 3!

> Please indicate your choice (Yes/No): No

> Press E to exit: E

> Exiting [Option C]

> Back to main menu

Example 2: 4 people, the program suggests the customer to pre-occupy table 6 since it is vacant.
> [Option C] entered
> Please enter the number of people: 4

> CCH restaurant suggests you to pre-occupy table 6!

> Please indicate your choice (Yes/No): Yes

> Table 6 has been reserved for you for 10 minutes.

> Press E to exit: E

> Exiting [Option C]

> Back to main menu
If there are 6 people, the program will suggest him to queue for table 7 according to the above logic.

We will then go back to the main menu and enter option D.
> [Customer mode] Hello chowchunho123!
> *Main menu*
> - Check today’s dishes ------- A
> - Check tables occupation ---- B
> - Occupy a table ------------- C
> - Release a table ------------ D

>  Option: D

For option D, if the customer has been waiting too long and want to give up waiting, he can release the table or quit the queue.

Example 1: Giving up the queue for table 3. Then, the queue number in [option B] will be reduced by 1.
> [Option D] entered
> You are now queuing for table 3 in the 2nd position.

> Are you sure you want to release table 3? (Yes/No): Yes

> Press E to exit: E

> Exiting [Option D]

> Back to main menu

Example 2: Pre-occupied table 6 and table 6 is reserved for tha customer. Then, if we check the tables occupation in [option B], table 6 will become vacant.
> [Option D] entered
> You are now reserving table 6.

> Are you sure you want to release table 6? (Yes/No): Yes

> Press E to exit: E

> Exiting [Option D]

> Back to main menu




