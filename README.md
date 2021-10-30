##Online banking management system using system calls in C programming .

=> COMPILE :-

$gcc ser.c -o server
$gcc cl.c -o client

=> RUN :-

$./server --- first in one terminal
$./client --- in the other terminal


=> INFORMATION ABOUT THE FILES & FOLDERS used in the program:

1. cl.c and ser.c just connects client and server to each other through sockets.
2. server_utils.h contains all the functions implemented on server side.
3. client_utils.h contains all the functions implemented on server side.
4. databases folder has all the databases created for the project : 1)Admin 2)Agent 3)Booking 4)Customer 5)Train
5. structures.h file has structures for building tables for the databases.





=> DETAILS :- ------------------------Online Railway Reservation System-------------------------------

	The project aims to develop a Railway Reservation System that is user-friendly and multi-functional. 



CLIENT :- 

1. The system will give you 3 options: 1) Sign up 2) Sign In 3) Exit. 
	1. Sign up --> Create mode will launch giving 3 options: 1) Customer 2) Agent 3) Admin 4) Back
-->Initially no user or admin will exist in the system. So, one has to setup admin credential. System owner can create default customer accounts, too in the create mode. 

	2. Sign in: --> Login mode will launch giving 4 options : 1) Customer 2) Agent 3) Admin 4) Back
Now Login with your credentials, If successful you get different options, then you choose one of them to perform its action.


SERVER :-

1. The server checks the login credentials entered by the client and sends the notification.
2. Validates the Database Values to ensure that client can actually perform the operation or not.
3. Performs the actions chosen by the client.
4. Implements suitable WRITE & READ locks when required.
5. Can handle 10 customers at a time




ADMIN FUNCTIONS :-

1. Add Train
2. Delete Train
3. Modify Train
4. Display users
5. Delete User
6. Logout
7. View Booking'
8. View Train

=> CUSTOMER & AGENT FUNCTIONS :-

1. Book Ticket
2. View Bookings
3. Update Booking
4. Cancel booking
5. Logout

-> Agent can do multiple Logins.





FEATURES :-

1. Used Socket Programming for exchanging information between server and client .
-> Used MULTITHREADING to handle concurrent connections, the main thread keeps waiting for new connections , while a new thread is created to handle a new customer arrival.

2. Successful record based locking mechanism on database.

3. Modularized into different files and folders & commented the code for better understandability.

4. Password hidden, and protected admin access, authentication done on server side.

5. After deleting account the records will not be deleted, just the account will be marked as closed.


P.S. 3 files will be created after you sign up for each user. admin, normal_user, joint_user. Right now no limitations on no of possible admin accounts.