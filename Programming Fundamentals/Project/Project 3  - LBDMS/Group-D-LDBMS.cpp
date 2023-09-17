




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////      Library Database Management System      /////////////////////////////////////////////////////////////////////////////////////////////////////////

//                                                                                      Group Members
//                                                        Abdul Raheem 21L5218         Sarmad Siddique 21L5225                Abdullah Fayyaz 5208 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/***************************************                                  Structs                ********************************************************************/
const int c = 1000;
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };

const int leapmonthDays[12]
= { 31, 29, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };


struct Date
{
    int day = 0;
    int month = 0;
    int year = 0;

};
struct AddressData
{
    int houseno = 0;
    char block[5] = { 0,'0' };
    char town[15] = { 0,'0' };
    char city[10] = { 0,'0' };
};

struct BookData
{
    char author[30] = { 0,'0' };
    char co_author[30] = { 0,'0' };
    char title[30] = { 0,'0' };
    char publisher[30] = { 0,'0' };
    int year_publication = 0;
    char subject[20] = { 0,'0' };
    int accession_number = 0;
    bool issuable = 1;
    bool issued = 0;
    Date issuedate;
    Date returndate;

    char issued_toID[10] = { '0','\0' };

};

struct UserData
{
    char name[30] = { 0,'0' };
    char father_name[30] = { 0,'0' };
    char rank[10] = { 0,'0' };
    char department[30] = { 0,'0' };
    char ID[10] = { 0,'0' };
    Date birthday;
    AddressData address;
    long long int cell_num = 0;
};




/***********************************                                     Function Prototypes              ******************************************************/



//Functions to Display Menus and take user choices as input 
int MainMenu(int option);
int SearchBookMenu(int option);
int DisplayBookMenu(int option);
int AscendingSortMenu(int option);
int SearchUserMenu(int option);

//Functions to Get file names and current date
void UserFileName(char userfile[]);
void BookFileName(char bookfile[]);
Date GetCurrentDate(Date today);

//Functions to get data from files
void GetBookData(BookData books[c], int& i, const char bookfile[]);
void GetUserData(UserData users[c], int& j, const char userfile[]);

//Functions used to Insert a New Book
BookData GetNewBook();
void InsertBook(BookData books[], int& i, const char bookfile[]);

//Functions used to Issue a Book
int GetIssuanceData(char title[], char id[], const char userfile[], const char bookfile[]);
void IssueBook(struct BookData books[], int totalbooks, const char bookfile[], const char userfile[], Date today);
void GetIssueBook(char title[]);
void GetIssueID(char id[]);
bool IsLeapYear(int year);
bool IDisValid(char temp[], UserData users[], int total_users);
Date CalculateReturnDate(Date issuedate, int days, int month);

//Functions used to Return a Book
int GetReturnBook(char title[]);
void ReturnBook(BookData books[], int totalbooks, const char bookfile[], const Date today, const char userfile[]);
void GetBookTitle(char title[]);
Date ReturnDifference(Date today, Date returndate);
int TotalDays(Date returndifference, Date returndate);

//Functions used to edit a contact
void EditContact(UserData users[], UserData edituser, int userindex, int total_users, const char userfile[]);
void DisplayEditContact(UserData users[], int total_users, const char userfile[]);

//Functions used to Sort the books
void AscendingSortAccesion(BookData books[], int total_records);
void AscendingSortTitle(const BookData   books[], int total_records, char const bookfile[]);
void AscendingSortAuthor(const BookData books[], int total_records, char const bookfile[]);

// Functions used to delete a book record
void DeleteBook(BookData books[], int& total_records, char bookfile[]);
int SearchTitle(char temp[], BookData books[], int total_records);
void DeleteIndex(BookData TempArray[], BookData books[], int& total_records, int index);

// Functions used to search and display book records
void DisplayBooks(const int indexes[], const BookData books[], int total_indexes, int total_records);
void DisplayBook(int index, const BookData books[]);
void SearchAuthor(const BookData books[], int total_records);
void SearchCoAuthor(const BookData books[], int total_records);
void SearchAccessionNo(const BookData books[], int total_records);
void GetAuthorIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes);
void GetCoAuthorIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes);
int GetAccessionNoIndex(int temp, const BookData books[], int total_records);

// Functions used to display books 
void SearchSubject(const BookData books[], int total_records);
void GetSubjectIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes);

// Functions used to search and display record of a particular user
void DisplayUser(int index, const UserData users[], const BookData books[], int total_records, Date today);
void SearchUserName(const UserData users[], int total_users, const BookData books[], int total_records, Date today);
void SearchID(const UserData users[], int total_users, const BookData books[], int total_records, Date today);
void SearchCellNum(const UserData users[], int total_users, const BookData books[], int total_records, Date today);
int GetUserNameIndex(const char temp[], const UserData users[], int total_users);
int GetIDIndex(const char temp[], const UserData users[], int total_users);
int GetCellNumIndex(long long int temp, const UserData users[], int total_users);
void SearchIssuedBooks(int index, const UserData users[], const BookData books[], int total_records);




int main()
{

    BookData books[c];
    UserData users[c];
    BookData newbook;
    UserData edituser;

    int total_records = 0, total_users = 0;
    int userindex = 0;
    int search_option = 0;
    int option = 0;

    char id[10] = { '\0' };
    char title[30] = { '\0' };
    char bookfile[20] = { '\0' };
    char userfile[20] = { '\0' };

    Date new_issuedate;
    Date today;


    //The name of the input files is take from the user.
    BookFileName(bookfile);
    UserFileName(userfile);

    //Data is stored in struct arrays from the filenames.
    GetBookData(books, total_records, bookfile);
    GetUserData(users, total_users, userfile);
    

    //Current Date is obtained from the user. 
    today = GetCurrentDate(today);

    while (option != 10)
    {


        option = MainMenu(option);


        switch (option)
        {
        case 1:

            InsertBook(books, total_records, bookfile);
            break;
        case 2:
            DeleteBook(books, total_records, bookfile);
            break;
        case 3:
            IssueBook(books, total_records, bookfile, userfile, today);
            break;
        case 4:
            ReturnBook(books, total_records, bookfile, today,userfile);
            break;

        case 5:
            search_option = SearchBookMenu(search_option);
            switch (search_option)
            {

            case 1:
            {
                SearchAuthor(books, total_records);
            }
            break;
            case 2:
            {
                SearchCoAuthor(books, total_records);
            }
            break;
            case 3:
            {
                SearchAccessionNo(books, total_records);
            }
            break;

            };
            break;
        case 6:
            search_option = AscendingSortMenu(search_option);
            switch (search_option)
            {
            case 1:
                AscendingSortAuthor(books, total_records, bookfile);
                break;
            case 2:
                AscendingSortTitle(books, total_records, bookfile);
                break;


            };
            break;

        case 7:
            search_option = DisplayBookMenu(search_option);
            switch (search_option)
            {
            case 1:
            {
                SearchAuthor(books, total_records);
            }
            break;
            case 2:
            {
                SearchSubject(books, total_records);
            }

            break;
            }
            break;
        case 8:

            EditContact(users, edituser, userindex, total_users, userfile);
            break;

        case 9:
            search_option = SearchUserMenu(search_option);
            switch (search_option)
            {
            case 1:
            {
                SearchUserName(users, total_users, books, total_records, today);
            }
            break;
            case 2:
            {
                SearchID(users, total_users, books, total_records, today);
            }
            break;
            case 3:
            {
                SearchCellNum(users, total_users, books, total_records, today);
            }
            break;
            };
            break;
        case 10:
            cout << "---> thanks for using <--- ";
            break;
        default:
            cout << "Invalid Option (Enter option between 1-10): \n";
            cin >> option;
        };
    }
}

/********************************************************************************                            Function Bodies                                ****************************************************************************************/

/**************************************************************************************************************************************************************************************************************************************************/

/******************************************************************************************      User and Book File Name, Current Date      *****************************************************************************************************/






void BookFileName(char bookfile[])
{

    cout << "Enter the name of file containing book records (filename should have its file type at the end e.g books.dat): ";
    cin.get(bookfile, 10, '\n');


}
void UserFileName(char userfile[])
{
    cin.ignore(1);
    cout << "Enter the name of file containing user records (filename should have its file type at the end e.g users.dat): ";
    cin.get(userfile, 10, '\n');

}
Date GetCurrentDate(Date today)
{
    cout << "Enter today's date (dd/mm/yyyy): \n";
    cin >> today.day;
    cin.ignore(1, '/');
    cin >> today.month;
    cin.ignore(1, '/');
    cin >> today.year;
    cin.ignore(1, '/');
    return today;


}
/******************************************************************************************      User and Book Data Obtained from files    *********************************************************************************************************/



void GetBookData(BookData books[c], int& i, const char bookfile[])
{
    // opens the file using the name inputted by user and then stores the data in the file based on a specific format. The format cannot be changed in the file or it breaks.

    ifstream fin;
    i = 0;
    fin.open(bookfile);
    while (!(fin.eof()))
    {
        fin.get(books[i].author, 30, ',');
        fin.ignore(2);
        fin.get(books[i].co_author, 30, ',');
        fin.ignore(2);
        fin.get(books[i].title, 30, ',');
        fin.ignore(2);
        fin.get(books[i].publisher, 30, ',');
        fin.ignore();
        fin >> books[i].year_publication;
        fin.ignore(2);
        fin.get(books[i].subject, 20, ',');
        fin.ignore();
        fin >> books[i].accession_number;
        fin.ignore();
        fin >> books[i].issuable;
        fin.ignore();
        fin >> books[i].issued;
        fin.ignore();
        fin >> books[i].issuedate.day;
        fin.ignore();
        fin >> books[i].issuedate.month;
        fin.ignore();
        fin >> books[i].issuedate.year;
        fin.ignore(2);
        fin.get(books[i].issued_toID, 10, ',');
        fin.ignore();
        fin >> books[i].returndate.day;
        fin.ignore();
        fin >> books[i].returndate.month;
        fin.ignore();
        fin >> books[i].returndate.year;
        fin.ignore();
        i++;
    }
    fin.close();
    i--;
}



void GetUserData(UserData users[c], int& j, const char userfile[])
{
    // opens the file using the name inputted by user and then stores the data in the file based on a specific format. The format cannot be changed in the file or it breaks.

    ifstream fin;
    j = 0;
    fin.open(userfile);
    while (!(fin.eof()))
    {
        fin.get(users[j].name, 30, ',');
        fin.ignore(2);
        fin.get(users[j].father_name, 30, ',');
        fin.ignore(2);
        fin.get(users[j].rank, 10, ',');
        fin.ignore(2);
        fin.get(users[j].department, 30, ',');
        fin.ignore(2);
        fin.get(users[j].ID, 10, ',');
        fin.ignore(2);
        fin >> users[j].birthday.day;
        fin.ignore();
        fin >> users[j].birthday.month;
        fin.ignore();
        fin >> users[j].birthday.year;
        fin.ignore(2);
        fin >> users[j].address.houseno;
        fin.ignore();
        fin.get(users[j].address.block, 5, ',');
        fin.ignore(2);
        fin.get(users[j].address.town, 15, ',');
        fin.ignore(2);
        fin.get(users[j].address.city, 10, '.');
        fin.ignore(2);
        fin >> users[j].cell_num;
        fin.ignore();
        j++;
    }
    fin.close();
    j--;
}







/**********************************************************************************************              Menu Funcitons                 ***********************************************************************************************/


int MainMenu(int option)
{


    cout << "   ____________________________________________________________________ " << endl;
    cout << "   |                                                                  |" << endl;
    cout << "   |                            WELCOME TO THE                        |                " << endl;
    cout << "   |        NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES     | " << endl;
    cout << "   |                 LIBRARY DATA BASE MANAGEMENT SYSTEM              |" << endl;
    cout << "   |__________________________________________________________________|";
    cout << "                                                                          " << endl;
    cout << "      -----------Please select any of the following options---------- " << endl;
    cout << "   ____________________________________________________________________ " << endl;
    cout << "                                                                          " << endl;
    cout << "              |-->   1. Press 1 to insert a new book   <--|" << endl;
    cout << "              |-->   2. Press 2 to delete a book       <--|" << endl;
    cout << "              |-->   3. Press 3 to issue a book        <--|" << endl;
    cout << "              |-->   4. Press 4 to return a book       <--|" << endl;
    cout << "              |-->   5. Press 5 to search a book       <--|" << endl;
    cout << "              |-->   6. Press 6 to sort books          <--|" << endl;
    cout << "              |-->   7. Press 7 to display a book      <--|" << endl;
    cout << "              |-->   8. Press 8 to edit a contact      <--|" << endl;
    cout << "              |-->   9. Press 9 to search a user       <--|" << endl;
    cout << "              |-->   10. Press 10 to exit LDBMS        <--|" << endl;
    cout << "   ____________________________________________________________________ " << endl;
    cin >> option;
    return option;

}

int SearchBookMenu(int option)
{

    cout << "           __________________________________________" << endl;
    cout << "                                                       " << endl;
    cout << "           |    --->Select the option you want<---  |" << endl;
    cout << "           __________________________________________" << endl;
    cout << "                                                     " << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "|  -->1.Press 1 in order  to search through Author name      |" << endl;
    cout << "|  -->2.Press 2 in order to search through co-Author name    |" << endl;
    cout << "|  -->3.Press 3 in order to search through Accession number  |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cin >> option;
    return option;
}
int AscendingSortMenu(int option)
{
    cout << "           __________________________________________" << endl;
    cout << "                                                       " << endl;
    cout << "           |    --->Select the option you want<---  |" << endl;
    cout << "           __________________________________________" << endl;
    cout << "                                                     " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|  -->1.Press 1 in order to sort according to Author name     |" << endl;
    cout << "|  -->2.Press 2 in order to sort according to Book title      |" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cin >> option;
    return option;
}
int SearchUserMenu(int option)
{
    cout << "           __________________________________________" << endl;
    cout << "                                                       " << endl;
    cout << "           |    --->Select the option you want<---  |" << endl;
    cout << "           __________________________________________" << endl;
    cout << "                                                     " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "|  -->1.Press 1 in order to Search through Name                      |" << endl;
    cout << "|  -->2.Press 2 in order to Search through ID                        |" << endl;
    cout << "|  -->3.Press 3 in order to Search through Cell number               |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cin >> option;
    return option;
}

int DisplayBookMenu(int option)
{
    cout << "           __________________________________________" << endl;
    cout << "                                                       " << endl;
    cout << "           |    --->Select the option you want<---  |" << endl;
    cout << "           __________________________________________" << endl;
    cout << "                                                     " << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "|  -->1.Press 1 in order to Display books written by a specific author       |" << endl;
    cout << "|  -->2.Press 2 in order to Display books belonging to a particular subject  |" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cin >> option;
    return option;
}



/****************************************************************************************                    Functions              ***************************************************************************************************************/



/********************************************************************************                              -1-                           *****************************************************************************************************/
/******************************************************************************                        Insert Book & Sub functions              *************************************************************************************************/



//This Function takes the input of the new book from users
BookData GetNewBook()
{
    BookData newbook;

    cout << "Enter the name of the author(The first letter of each word should be capital i.e. Author Name): " << endl;
    cin.ignore();
    cin.getline(newbook.author, 30, '\n');


    cout << "Enter the name of the co author (The first letter of each word should be capital i.e. Coauthor Name): " << endl;
    //  cin.ignore();
    cin.getline(newbook.co_author, 30, '\n');

    cout << "Enter the name of the title(The first letter of each word should be capital i.e. Book Title): " << endl;
    // cin.ignore();
    cin.getline(newbook.title, 30, '\n');

    cout << "Enter the name of the publisher(The first letter of each word should be capital i.e. Publisher Name): " << endl;
    // cin.ignore();
    cin.getline(newbook.publisher, 30, '\n');

    cout << "Enter the year of publication(yyyy) : " << endl;

    cin >> newbook.year_publication;

    cout << "Enter the name of the subject (The first letter of each word should be capital i.e. Subject): " << endl;
    cin.ignore();
    cin.getline(newbook.subject, 30, '\n');

    cout << "Enter the accession number: \n";

    cin >> newbook.accession_number;

    return newbook;

}

//This function displays the newbook in the file 
void InsertBook(BookData books[], int& i, const char bookfile[])
{
    ofstream fout;
    BookData newbook;

    //function call to get new book
    newbook = GetNewBook();



    //Displaying newbook in the file
    fout.open(bookfile, ios::app);
    fout << newbook.author << ", " << newbook.co_author << ", " << newbook.title << ", " << newbook.publisher << ", "
        << newbook.year_publication << ", " << newbook.subject << ", " << newbook.accession_number << ", " << newbook.issuable << ", " << newbook.issued << ", "
        << newbook.issuedate.day << "/" << newbook.issuedate.month << "/" << newbook.issuedate.year << ", " << newbook.issued_toID << ", "
        << newbook.returndate.day << "/" << newbook.returndate.month << "/" << newbook.returndate.year << endl;
    i++;
    fout.close();
    i = 0;

    //Unsorted Data is again obtained from the file and updated into existing struct books array
    GetBookData(books, i, bookfile);

    //Books Data is sorted here
    AscendingSortAccesion(books, i);

    //The entire sorted array is then displayed in the book
    fout.open(bookfile);
    for (int c = 0; c < i; c++)
    {
        fout << books[c].author << ", " << books[c].co_author << ", " << books[c].title << ", " << books[c].publisher << ", "
            << books[c].year_publication << ", " << books[c].subject << ", " << books[c].accession_number << ", " << books[c].issuable << ", " << books[c].issued << ", "
            << books[c].issuedate.day << "/" << books[c].issuedate.month << "/" << books[c].issuedate.year << ", " << books[c].issued_toID << ", "
            << books[c].returndate.day << "/" << books[c].returndate.month << "/" << books[c].returndate.year << endl;
    }
    fout.close();


}


/*************************************************************************************************************************************************************************************************************************************************/


/*********************************************************************************                              -3-                             ************************************************************************************************/
/***************************************************************************************                Issue Book & Sub function              ************************************************************************************************/



void IssueBook(struct BookData books[], int totalbooks, const char bookfile[], const char userfile[], const Date today)
{
    ofstream fout;
    char id[10] = { '\0' };
    char title[30] = { '\0' };

    Date new_issuedate;
    Date new_returndate;
    int bookindex = 0;
    int rank = 0;

    int userindex = 0;
    UserData users[c];
    int total_users = 0;

    new_issuedate = today;


    //The title of the book and id and rank of the user is taken here 
    rank = GetIssuanceData(title, id, userfile, bookfile);


    //Getting userindex from the userfile
    GetUserData(users, total_users, userfile);
    userindex = GetIDIndex(id, users, total_users);
    
    //Rank is then obtained from user struct array
    if (strcmp(users[userindex].rank, "Student") == 0)
    {
        rank = 2;
    }
    else if (strcmp(users[userindex].rank, "Faculty") == 0 || strcmp(users[userindex].rank, "Staff") == 0)
    {
        rank = 1;
    }
    



    //Finding the index of the book through Search title function
    GetBookData(books, totalbooks, bookfile);
    bookindex = SearchTitle(title, books, totalbooks);

    //If the book is already issued 
    if (books[bookindex].issuable == 0)
    {
        cout << "Sorry the book is already issued. \n";

    }

    else
    {
        //if the rank is 1 ie. faculty or staff 4 months are added to issue date to calculate return date
        if (rank == 1)
        {
            new_returndate = CalculateReturnDate(new_issuedate, 0, 4);
            cout << "The book has been issued. \nReturn the book by: " << new_returndate.day << "/" << new_returndate.month << "/" << new_returndate.year << endl;
            //the issuance data of the issued book is changed in the array and file

            books[bookindex].issuable = 0;
            books[bookindex].issued = 1;
            books[bookindex].issuedate = new_issuedate;
            books[bookindex].returndate = new_returndate;
            strcpy_s(books[bookindex].issued_toID, id);

        }
        //if the rank is 2 i.e students 15 days are added to issue date to calculate return date
        else if (rank == 2)
        {
            new_returndate = CalculateReturnDate(new_issuedate, 15, 0);
            cout << "The book has been issued. \nReturn the book by: " << new_returndate.day << "/" << new_returndate.month << "/" << new_returndate.year << endl;
            //the issuance data of the issued book is changed in the array and file

            books[bookindex].issuable = 0;
            books[bookindex].issued = 1;
            books[bookindex].issuedate = new_issuedate;
            books[bookindex].returndate = new_returndate;
            strcpy_s(books[bookindex].issued_toID, id);

        }
        //input validation
        else
        {
            cout << "Invalid rank" << endl;
        }
    }


    fout.open(bookfile);
    for (int c = 0; c < totalbooks; c++)
    {
        fout << books[c].author << ", " << books[c].co_author << ", " << books[c].title << ", " << books[c].publisher << ", "
            << books[c].year_publication << ", " << books[c].subject << ", " << books[c].accession_number << ", " << books[c].issuable << ", " << books[c].issued << ", "
            << books[c].issuedate.day << "/" << books[c].issuedate.month << "/" << books[c].issuedate.year << ", " << books[c].issued_toID << ", "
            << books[c].returndate.day << "/" << books[c].returndate.month << "/" << books[c].returndate.year << endl;
    }
    fout.close();




}

int GetIssuanceData(char title[], char id[], const char userfile[], const char bookfile[])
{
    int bookindex = 0;
    int rank = 0;


    bool validID = true;

    UserData users[c];
    int total_users = 0;
    BookData books[c];
    int total_books = 0;


    GetUserData(users, total_users, userfile);
    GetBookData(books, total_books, bookfile);

    /*cout << "Select your rank: \n"
        << "1.Faculty or staff \n"
        << "2.Student \n";
    cin >> rank;


    while (rank < 1 || rank>2)
    {
        cout << "Invalid Rank!!!\n";
        cout << "Select your rank: \n"
            << "1.Faculty or staff \n"
            << "2.Student \n";
        cin >> rank;

    }
    */


    //checking validity of User ID            

    cout << "Enter your ID: \n";
    cin.ignore();
    cin.getline(id, 10, '\n');
    validID = IDisValid(id, users, total_users);
    while (!validID)
    {
        cout << "The user doesn't exist \nPlease Enter Again(Format is: 21L1234):\n";
        GetIssueID(id);
        validID = IDisValid(id, users, total_users);
    }

    //Checking validity of Book Title                
    cout << "Enter the title of the book you want to issue: \n";
    cin.getline(title, 30, '\n');
    bookindex = SearchTitle(title, books, total_books);
    while (bookindex < 0)
    {
        cout << "Invalid Book Name Please Enter Again" << endl;
        GetIssueBook(title);
        bookindex = SearchTitle(title, books, total_books);
    }


    return rank;

}

void GetIssueID(char id[])
{

    cout << "Enter your ID: \n";
    cin.getline(id, 10, '\n');

}

void GetIssueBook(char title[])
{


    cout << "Enter the title of the book you want to issue: \n";
    cin.getline(title, 30, '\n');
}



Date CalculateReturnDate(Date issuedate, int days, int month)
{
    Date returndate;

    //No. of day and/or months are added here
    returndate.day = issuedate.day + days;
    returndate.month = issuedate.month + month;
    returndate.year = issuedate.year;

    //condition for year swap i.e. the issue date and return date fall in different years
    if (returndate.month > 12)
    {
        returndate.month = returndate.month - 12;
        returndate.year++;
    }

    //if days of month exceed the total month days remaining days are added in the next month and the month is incremented
    switch (issuedate.month)
    {

    case 12:
        if (returndate.day > 31)
        {
            //condition for year swap i.e. the issue date and return date fall in different years
            returndate.day = returndate.day - 31;
            returndate.month++;
            returndate.month = returndate.month - 12;
            returndate.year++;
        }
    case 11:
        if (returndate.day > 30)
        {
            returndate.day = returndate.day - 30;
            returndate.month++;
        }
    case 10:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    case 9:
        if (returndate.day > 30)
        {
            returndate.day = returndate.day - 30;
            returndate.month++;
        }
    case 8:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    case 7:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    case 6:
        if (returndate.day > 30)
        {
            returndate.day = returndate.day - 30;
            returndate.month++;
        }
    case 5:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    case 4:
        if (returndate.day > 30)
        {
            returndate.day = returndate.day - 30;
            returndate.month++;
        }
    case 3:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    case 2:
        if (IsLeapYear(returndate.year))
        {
            if (returndate.day > 29)
            {
                returndate.day = returndate.day - 29;
                returndate.month++;
            }

        }

        else
        {
            if (returndate.day > 28)
            {
                returndate.day = returndate.day - 28;
                returndate.month++;
            }

        }
    case 1:
        if (returndate.day > 31)
        {
            returndate.day = returndate.day - 31;
            returndate.month++;
        }
    }

    return returndate;
}

bool IsLeapYear(int year)
{

    if (year % 400 == 0)
        return true;
    if (year % 100 != 0 && year % 4 == 0)
        return true;
    else
        return false;

}

//Function to check validity of user id by comparing it with every id in the file
bool IDisValid(char temp[], UserData users[], int total_users)
{
    bool validID = false;
    for (int i = 0; i < total_users; i++)
    {
        if (strcmp(temp, users[i].ID) == 0)
            return true;

    }
    return validID;
}

/*******************************************************************************                              -4-                             ***************************************************************************/
/************************************************************************************                Return Book & Sub function              ***************************************************************************/

void ReturnBook(BookData books[], int totalbooks, const char bookfile[], const Date today, const char userfile[])
{
    //variable declaration and initialization
    ofstream fout;
    char title[30] = { '\0' };
    char id[10] = { '\0' };

    Date returndifference;
    int returndays = 0;
    totalbooks = 0;

    int bookindex = 0, userindex = 0;
    int rank = 0;
    int fine = 0;
    UserData users[c];
    int total_users = 0;
    char default_id[10] = { '0','\0' };

    //Input is taken here and Validations 
    GetBookData(books, totalbooks, bookfile);

    rank = GetReturnBook(title);
    bookindex = SearchTitle(title, books, totalbooks);

    GetUserData(users, total_users, userfile);



    while (bookindex < 0 || books[bookindex].issued == 0)
    {
        if (bookindex < 0)
        {
            cout << "Invalid Book Name " << endl;
        }
        else if (books[bookindex].issued == 0)
        {
            cout << "The book has not been issued.\n";
        }
        GetBookTitle(title);
        bookindex = SearchTitle(title, books, totalbooks);


    }


    //The user is obtained from BookData struct array
    strcpy_s(id, books[bookindex].issued_toID);

    //The userindex os that id is obtained from userfile
    userindex = GetIDIndex(id, users, total_users);

    //Rank is then obtained from user struct array
    if (strcmp(users[userindex].rank, "Student") == 0)
    {
        rank = 2;
    }
    else if (strcmp(users[userindex].rank, "Faculty") == 0 || strcmp(users[userindex].rank, "Staff") == 0)
    {
        rank = 1;
    }
    


    returndifference = ReturnDifference(today, books[bookindex].returndate);
    returndays = TotalDays(returndifference, books[bookindex].returndate);



    // Fine is calculated and displayed here based on the rank

    if (rank == 1)
    {

        if (returndifference.month < 0 || returndifference.year)
            cout << "There is no fine. \n";
        else
        {
            fine = returndays * 50;
            cout << "The fine is: " << fine << endl;
        }
    }
    else if (rank == 2)
    {

        if (returndifference.month < 0 || returndifference.year < 0)
            cout << "There is no fine. \n";
        else
        {
            fine = returndays * 100;
            cout << "The fine is: " << fine << endl;
        }
    }

    //The issuance data is updated to default in the array here and then printed in the file
    strcpy_s(books[bookindex].issued_toID, default_id);
    books[bookindex].issuable = 1;
    books[bookindex].issued = 0;
    books[bookindex].issuedate.day = 0;
    books[bookindex].issuedate.month = 0;
    books[bookindex].issuedate.year = 0;
    books[bookindex].returndate.day = 0;
    books[bookindex].returndate.month = 0;
    books[bookindex].returndate.year = 0;



    fout.open(bookfile);
    for (int c = 0; c < totalbooks; c++)
    {
        fout << books[c].author << ", " << books[c].co_author << ", " << books[c].title << ", " << books[c].publisher << ", "
            << books[c].year_publication << ", " << books[c].subject << ", " << books[c].accession_number << ", " << books[c].issuable << ", " << books[c].issued << ", "
            << books[c].issuedate.day << "/" << books[c].issuedate.month << "/" << books[c].issuedate.year << ", " << books[c].issued_toID << ", "
            << books[c].returndate.day << "/" << books[c].returndate.month << "/" << books[c].returndate.year << endl;
    }
    fout.close();




}


int GetReturnBook(char title[])
{

    int totalbooks = 0;
    int rank = 0;
    /*   cout << "Select your rank: \n"
           << "1.Faculty or staff \n"
           << "2.Student \n";
       cin >> rank;


       while (rank < 1 || rank>2)
       {
           cout << "Invalid Rank!!!\n";
           cout << "Select your rank: \n"
               << "1.Faculty or staff \n"
               << "2.Student \n";
           cin >> rank;

       }*/


    cout << "Enter the title of the book you want to return : \n";
    cin.ignore();
    cin.getline(title, 30, '\n');
    

    return rank;

}
//FUnction needed for validation
void GetBookTitle(char title[])
{
    cout << "Enter the title of the book you want to return : \n";
    cin.getline(title, 30, '\n');
    
}



//This function subtracts two 


Date ReturnDifference(Date today, Date returndate)
{


    Date returndifference;
    int m = 0, n = 0;
    int totaldays = 0;

    //return date is subtracted from current date
    returndifference.day = today.day - returndate.day;
    returndifference.month = today.month - returndate.month;
    returndifference.year = today.year - returndate.year;


    {
        switch (today.month)
        {

        case 12:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;


            }
        case 11:
            if (returndifference.day < 0)
            {
                returndifference.day = 30 + returndifference.day;
                returndifference.month--;
            }
        case 10:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;
            }
        case 9:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;
            }
        case 8:
            if (returndifference.day < 0)
            {
                returndifference.day = 30 + returndifference.day;
                returndifference.month--;
            }
        case 7:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;
            }
        case 6:
            if (returndifference.day < 0)
            {
                returndifference.day = 30 + returndifference.day;
                returndifference.month--;
            }
        case 5:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;
            }
        case 4:
            if (returndifference.day < 0)
            {
                returndifference.day = 30 + returndifference.day;
                returndifference.month--;
            }
        case 3:
            if (IsLeapYear(returndifference.year))
            {
                if (returndifference.day < 0)
                {
                    returndifference.day = 29 + returndifference.day;
                    returndifference.month--;
                }

            }

            else
            {
                if (returndifference.day < 0)
                {
                    returndifference.day = 28 + returndifference.day;
                    returndifference.month--;
                }
            }

        case 2:

            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month--;
            }

        case 1:
            if (returndifference.day < 0)
            {
                returndifference.day = 31 + returndifference.day;
                returndifference.month += 12;
                returndifference.month--;

                returndifference.year--;
            }
        }
    }

    if (returndifference.month < 0 && returndifference.year>0)
    {
        returndifference.month += 12;
        returndifference.year--;
    }


    return returndifference;
}



int TotalDays(Date returndifference, Date returndate)
{
    int m = 0, n = 0;
    int totaldays = 0;


    if (IsLeapYear(returndate.year))
    {
        m = returndate.month;
        n = m - 1;
        totaldays = leapmonthDays[n];

        if (returndifference.month > 1)
        {
            for (int i = 1; i < returndifference.month; i++)
            {
                n++;
                totaldays += leapmonthDays[n];

            }
        }
        else if (returndifference.month == 0)
        {
            totaldays = 0;

        }
    }
    else
    {
        m = returndate.month;
        n = m - 1;

        totaldays = monthDays[n];

        if (returndifference.month > 1)
        {
            for (int i = 1; i < returndifference.month; i++)
            {
                n++;
                totaldays += monthDays[n];

            }
        }
        else if (returndifference.month == 0)
        {
            totaldays = 0;

        }
    }

    totaldays += returndifference.day;

    return totaldays;
}







/*************************************                              -6-                             ***************************************************************************/
/**************************                                     Accession                                                           *******************************/
void AscendingSortAccesion(BookData books[], int total_records)
{

    BookData temp;

    for (int i = 0; i < total_records; i++)
    {
        for (int j = 0; j < total_records - i - 1; j++)
        {
            if (books[j].accession_number > books[j + 1].accession_number)
            {

                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }





}
void AscendingSortAuthor(const BookData books[], int total_records, char const bookfile[])
{

    BookData temp;
    BookData sbooks[c] = {};
    GetBookData(sbooks, total_records, bookfile);
    char newfile[30] = { "\0" };
    cout << "Please enter the name of file: \n";
    cin.ignore();
    cin.getline(newfile, 30, '\n');
    cout << newfile;
    ofstream fout;
    fout.open(newfile);
    fout.close();

    for (int i = 0; i < total_records; i++)
    {
        for (int j = 0; j < total_records - i - 1; j++)
        {
            if (strcmp(sbooks[j].author, sbooks[j + 1].author) > 0)
            {

                temp = sbooks[j];
                sbooks[j] = sbooks[j + 1];
                sbooks[j + 1] = temp;
            }
        }
    }
    fout.open(newfile);
    for (int i = 0; i < total_records; i++)
    {
        fout << sbooks[i].author << ", " << sbooks[i].co_author << ", " << sbooks[i].title << ", " << sbooks[i].publisher << ", "
            << sbooks[i].year_publication << ", " << sbooks[i].subject << ", " << sbooks[i].accession_number << ", " << sbooks[i].issuable << ", " << sbooks[i].issued << ", "
            << sbooks[i].issuedate.day << "/" << sbooks[i].issuedate.month << "/" << sbooks[i].issuedate.year << ", " << sbooks[i].issued_toID << ", "
            << sbooks[i].returndate.day << "/" << sbooks[i].returndate.month << "/" << sbooks[i].returndate.year << endl;
    }
    fout.close();



}
void AscendingSortTitle(const BookData books[], int total_records, char const bookfile[])
{
    BookData temp;
    BookData sbooks[c] = {};
    GetBookData(sbooks, total_records, bookfile);

    char newfile[30] = { "\0" };
    cout << "Please enter the name of file: \n";
    cin.ignore();
    cin.getline(newfile, 30, '\n');
    cout << newfile;
    ofstream fout;
    fout.open(newfile);
    fout.close();

    for (int i = 0; i < total_records; i++)
    {
        for (int j = 0; j < total_records - i - 1; j++)
        {
            if (strcmp(sbooks[j].title, sbooks[j + 1].title) > 0)
            {

                temp = sbooks[j];
                sbooks[j] = sbooks[j + 1];
                sbooks[j + 1] = temp;
            }
        }
    }
    fout.open(newfile);
    for (int i = 0; i < total_records; i++)
    {
        fout << sbooks[i].author << ", " << sbooks[i].co_author << ", " << sbooks[i].title << ", " << sbooks[i].publisher << ", "
            << sbooks[i].year_publication << ", " << sbooks[i].subject << ", " << sbooks[i].accession_number << ", " << sbooks[i].issuable << ", " << sbooks[i].issued << ", "
            << sbooks[i].issuedate.day << "/" << sbooks[i].issuedate.month << "/" << sbooks[i].issuedate.year << ", " << sbooks[i].issued_toID << ", "
            << sbooks[i].returndate.day << "/" << sbooks[i].returndate.month << "/" << sbooks[i].returndate.year << endl;
    }
    fout.close();

}


/*************************************                              -8-                             ***************************************************************************/
/***************************************                Edit Contact & Sub function              ***************************************************************************/



void EditContact(UserData users[], UserData edituser, int userindex, int total_users, const char userfile[])
{
    char tempuser[10] = { '\0' };
    int option = 0;

    //Fresh Data is obtained from file
    GetUserData(users, total_users, userfile);


    //Taking Id and Validating
    cout << "Enter the ID of the user you want to edit: \n";
    cin.ignore();
    cin.getline(tempuser, 30, '\n');
    userindex = GetIDIndex(tempuser, users, total_users);

    while (userindex < 0)
    {
        cout << "The user doesn't exist. \n";
        cout << "Enter the ID of the user you want to edit: \n";
        cin.getline(tempuser, 30, '\n');
        userindex = GetIDIndex(tempuser, users, total_users);
    }


    //putting values of index to be edited in another structure
    edituser = users[userindex];

    //Asking user what he wants to edit
    cout << "The name of the user is: " << users[userindex].name << endl;
    cout << "What do you want to edit? \n "
        << "1.Name \n 2.Father Name \n "
        << "3.Rank \n 4.Department \n 5.ID \n 6.Birthday \n 7.Address \n 8.Cell Number \n";
    cin >> option;

    //making edits in the edituser struct based on users choice
    switch (option)
    {

    case 1:
        cout << "Enter new name: \n";
        cin.ignore();
        cin.get(edituser.name, 30, '\n');
        break;
    case 2:
        cout << "Enter new father name: \n";
        cin.ignore();
        cin.get(edituser.father_name, 30, '\n');
        break;
    case 3:
        cout << "Enter new rank: \n";
        cin.ignore();
        cin.get(edituser.rank, 10, '\n');
        break;
    case 4:
        cout << "Enter new Department: \n";
        cin.ignore();
        cin.get(edituser.department, 30, '\n');
        break;
    case 5:
        cout << "Enter new ID: \n";
        cin.ignore();
        cin.get(edituser.ID, 10, '\n');
        break;
    case 6:
        cout << "Enter new Birthday (dd/mm/yyyy): \n";
        cin >> edituser.birthday.day;
        cin.ignore(1, '/');
        cin >> edituser.birthday.month;
        cin.ignore(1, '/');
        cin >> edituser.birthday.year;
        cin.ignore(1, '/');
        break;
    case 7:
        cout << "Enter new address (H#/block/town/city): \n";
        cin >> edituser.address.houseno;
        cin.ignore(1, '/');
        cin.get(edituser.address.block, 5, '/');
        cin.ignore(1, '/');
        cin.get(edituser.address.town, 15, '/');
        cin.ignore();
        cin.get(edituser.address.city, 10, '\n');

        break;
    case 8:
        cout << "Enter new Cell number: \n";
        cin >> edituser.cell_num;
        break;

    default:
        cout << "Invalid choice!!!!!! (choose b/w 1-8): "
            << "What do you want to edit? \n "
            << "1.Name \n 2.Father Name \n "
            << "3.Rank \n 4.Department \n 5.ID \n 6.Birthday \n 7.Address \n 8.Cell Number \n";
        cin >> option;



    }
    //editing the users credentials 
    users[userindex] = edituser;

    DisplayEditContact(users, total_users, userfile);


}
void DisplayEditContact(UserData users[], int total_users, const char userfile[])
{




    ofstream fout;
    fout.open(userfile);
    for (int i = 0; i < total_users; i++)
    {
        fout << users[i].name << ", " << users[i].father_name << ", " << users[i].rank << ", " << users[i].department << ", "
            << users[i].ID << ", " << users[i].birthday.day << '/' << users[i].birthday.month << '/' << users[i].birthday.year << ", "
            << users[i].address.houseno << '-' << users[i].address.block << ", " << users[i].address.town << ", " << users[i].address.city << ". "
            << "0" << users[i].cell_num << endl;
    }
    fout.close();
}

/****************************************************************************   Delete Book   ************************************************************************************************/

void DeleteBook(BookData books[], int& total_records, char bookfile[])
{
    char temp[30];
    BookData TempArray[c];

    // Taking title of book to be deleted from the user
    cin.ignore();
    cout << "Enter the title of book you want to delete (Capitalize the letters correctly) : ";
    cin.get(temp, 30, '\n');

    // Searching for the index of the file with the specific title
    int index = SearchTitle(temp, books, total_records);

    // Exiting the function if no such file with the same title was found
    if (index == -1)
    {
        cout << "No book with that title exists in the records.";
        return;
    }

    // Deleting the index of the book from the books array
    DeleteIndex(TempArray, books, total_records, index);

    // Outputting the updated array into the books file
    ofstream fout;
    fout.open(bookfile);
    for (int i = 0; i < total_records; i++)
    {
        fout << books[i].author << ", " << books[i].co_author << ", " << books[i].title << ", " << books[i].publisher << ", "
            << books[i].year_publication << ", " << books[i].subject << ", " << books[i].accession_number << ", " << books[i].issuable << ", " << books[i].issued << ", "
            << books[i].issuedate.day << "/" << books[i].issuedate.month << "/" << books[i].issuedate.year << ", " << books[i].issued_toID << ", "
            << books[i].returndate.day << "/" << books[i].returndate.month << "/" << books[i].returndate.year << endl;
    }
    fout.close();
}

void DeleteIndex(BookData TempArray[], BookData books[], int& total_records, int index)
{
    // Storing the books array into a temp array but the loop skips the index that we want to delete
    for (int i = 0, j = 0; i < total_records; i++)
    {
        if (i == index)
        {
            continue;
        }
        TempArray[j] = books[i];
        j++;

    }

    BookData Temp;
    // Re-initializing the original array to an empty state
    for (int i = 0; i < total_records + 1; i++)
    {
        books[i] = Temp;
    }

    total_records--;
    // Storing the temp array into the original books array
    for (int i = 0; i < total_records; i++)
    {
        books[i] = TempArray[i];
    }
}


/**********************************************************************************   Functions to searhc books or users and display them  *************************************************************************************/


int SearchTitle(char temp[], BookData books[], int total_records)
{
    int index = -1;
    // loop that runs until the given data matches with data taken from the file and then that index is returned
    for (int i = 0; i < total_records; i++)
    {
        if (strcmp(books[i].title, temp) == 0)
        {
            index = i;
        }
    }
    return index;
}


void DisplayBooks(const int indexes[], const BookData books[], int total_indexes, int total_records)
{
    // Displays books using a loop for every index in the indexes array, displays a message if there are no indexes
    if (indexes[0] >= 0 && indexes[0] < total_records)
    {
        for (int j = 0; j < total_indexes; j++)
        {
            int i = indexes[j];
            DisplayBook(i, books);
        }
    }
    else
        cout << "No book with this input was found in library records. Either the input was wrong/wrongly spelled or no book of this author exists in the library." << endl;
}


void DisplayBook(int i, const BookData books[])
{
    // Displays the book records of the specific index
    cout << endl;
    cout << "Title: " << books[i].title << endl;
    cout << "Author: " << books[i].author << endl;
    cout << "Co-Author: " << books[i].co_author << endl;
    cout << "Subject: " << books[i].subject << endl;
    cout << "Publisher: " << books[i].publisher << endl;
    cout << "Title: " << books[i].title << endl;
    cout << "Year of Publication: " << books[i].year_publication << endl;
    cout << "Accession Number: " << books[i].accession_number << endl;
    if (books[i].issuable == 1)
    {
        cout << "Issuable: Yes" << endl;
    }
    else
    {
        cout << "Issuable: No" << endl;
    }
    if (books[i].issued == 1)
    {
        cout << "Issued: Yes" << endl;
    }
    else
    {
        cout << "Issued: No" << endl;
    }
    cout << "Issued to: " << books[i].issued_toID << endl;
    cout << "Issue Date: " << books[i].issuedate.day << "/" << books[i].issuedate.month << "/" << books[i].issuedate.year << endl;
    cout << "Return date: " << books[i].returndate.day << "/" << books[i].returndate.month << "/" << books[i].returndate.year << endl << endl;;
}


void DisplayUser(int index, const UserData users[], const BookData books[], int total_records, Date today)
{
    // Displays all the records of a given user, including age and books issued to the user
    Date Age;
    cout << endl;
    cout << "Name: " << users[index].name << endl;
    Age = ReturnDifference(today, users[index].birthday);
    cout << "Age: " << Age.year << " years " << Age.month << " months " << Age.day << " days." << endl;
    cout << "Fathers Name: " << users[index].father_name << endl;
    cout << "Rank: " << users[index].rank << endl;
    cout << "Department: " << users[index].department << endl;
    cout << "Student ID: " << users[index].ID << endl;
    cout << "Date of Birth: " << users[index].birthday.day << "/" << users[index].birthday.month << "/" << users[index].birthday.year << endl;
    cout << "Cell Phone Number: " << "0" << users[index].cell_num << endl << endl;
    SearchIssuedBooks(index, users, books, total_records);
}


void SearchIssuedBooks(int index, const UserData users[], const BookData books[], int total_records)
{
    int indexes[20] = { -1 };
    int total_indexes = 0;

    // This loop searches through the Issued_toID array and finds the indexes of books issued to the particular ID
    for (int i = 0, j = 0; i < total_records; i++)
    {
        if (strcmp(users[index].ID, books[i].issued_toID) == 0)
        {
            indexes[j] = i;
            j++;
            total_indexes++;
        }
    }
    cout << "Books issued to this user: ";

    // This loop outputs all the titles of the books in the indexes array
    if (indexes[0] >= 0 && indexes[0] < total_records)
    {
        for (int j = 0; j < total_indexes; j++)
        {
            int i = indexes[j];
            cout << j + 1 << "." << books[i].title << "  ";
        }
        cout << endl;
    }
    else
        cout << "None." << endl;
}


void SearchAuthor(const BookData books[], int total_records)
{
    // Inputs the name of author from user and passes it to other functions. The array indexes is 
    // used to find all the indexes where the name of author matches the name given by user and is then passed to the display function.
    char temp[30];
    int indexes[c] = { -1 }, total_indexes = 0;

    cin.ignore();
    cout << "Enter the name of author (Capitalize first letter of first and last name) : ";
    cin.get(temp, 30, '\n');

    GetAuthorIndex(temp, books, total_records, indexes, total_indexes);
    DisplayBooks(indexes, books, total_indexes, total_records);
}


void GetAuthorIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes)
{
    // Loop searches through the the array searching for the author name that matches the input given by user, it stores the indexes of all the matches in an array
    for (int i = 0, j = 0; i < total_records; i++)
    {
        if (strcmp(books[i].author, temp) == 0)
        {
            indexes[j] = i;
            j++;
            total_indexes++;
        }
    }
}


void SearchCoAuthor(const BookData books[], int total_records)
{
    // Inputs the name of CO-author from user and passes it to other functions. The array indexes is 
    // used to find all the indexes where the name of co-author matches the name given by user and is then passed to the display function.
    char temp[30];
    int indexes[c] = { -1 }, total_indexes = 0;

    cin.ignore();
    cout << "Enter the name of Co-author (Capitalize first letter of first and last name) : ";
    cin.get(temp, 30, '\n');

    GetCoAuthorIndex(temp, books, total_records, indexes, total_indexes);
    DisplayBooks(indexes, books, total_indexes, total_records);
}


void GetCoAuthorIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes)
{
    // Loop searches through the the array searching for the co-author name that matches the input given by user, it stores the indexes of all the matches in an array
    for (int i = 0, j = 0; i < total_records; i++)
    {
        if (strcmp(books[i].co_author, temp) == 0)
        {
            indexes[j] = i;
            j++;
            total_indexes++;
        }
    }
}


void SearchSubject(const BookData books[], int total_records)
{
    // Inputs the name of subject from user and passes it to other functions. The array indexes is 
    // used to find all the indexes where the name of subject matches the name given by user and is then passed to the display function
    char temp[30];
    int indexes[c] = { -1 }, total_indexes = 0;

    cin.ignore();
    cout << "Enter the Subject Name (Capitalize first letter of subject name) : ";
    cin.get(temp, 30, '\n');

    GetSubjectIndex(temp, books, total_records, indexes, total_indexes);
    DisplayBooks(indexes, books, total_indexes, total_records);
}


void GetSubjectIndex(const char temp[], const BookData books[], int total_records, int indexes[], int& total_indexes)
{
    // Loop searches through the the array searching for the SUbject name that matches the input given by user, it stores the indexes of all the matches in an array
    for (int i = 0, j = 0; i < total_records; i++)
    {
        if (strcmp(books[i].subject, temp) == 0)
        {
            indexes[j] = i;
            j++;
            total_indexes++;
        }
    }
}


void SearchAccessionNo(const BookData books[], int total_records)
{
    // Inputs the Accession Number from user and passes it to other functions. The array indexes is 
    // used to find all the indexes where Accession Number matches the input given by user and is then passed to the display function
    int temp = -1;
    int index = -1;
    cout << "Enter the accession number of the book: ";
    cin >> temp;

    index = GetAccessionNoIndex(temp, books, total_records);

    if (index >= 0 && index < total_records)
    {
        DisplayBook(index, books);
    }
    else
        cout << "No book with this Accession Number was found in library records. Either the input wasn't correct or no book with this accession number exists in the library." << endl;
}


int GetAccessionNoIndex(int temp, const BookData books[], int total_records)
{
    // Loop searches through the the array searching for the Accession Number that matches the input given by user
    int index = -1;
    for (int i = 0; i < total_records; i++)
    {
        if (books[i].accession_number == temp)
        {
            index = i;
        }
    }
    return index;
}


void SearchUserName(const UserData users[], int total_users, const BookData books[], int total_records, Date today)
{
    // Inputs the username from user and passes it to other functions. Index is found using a function and then its record are displayed using another function
    char temp[30];
    int index = -1;

    cin.ignore();
    cout << "Enter the name of user (Capitalize first letter of first and last name) : ";
    cin.get(temp, 30, '\n');

    index = GetUserNameIndex(temp, users, total_users);

    if (index >= 0 && index < total_users)
    {
        DisplayUser(index, users, books, total_records, today);
    }
    else
        cout << "No user with this name was found in library records. Either the input was wrong/wrongly spelled or no user of this name exists in the user records." << endl;
}


int GetUserNameIndex(const char temp[], const UserData users[], int total_users)
{
    // Loop searches through the the array searching for the username that matches the input given by user
    int index = -1;
    for (int i = 0; i < total_users; i++)
    {
        if (strcmp(users[i].name, temp) == 0)
        {
            index = i;
        }
    }
    return index;
}



void SearchID(const UserData users[], int total_users, const BookData books[], int total_records, Date today)
{
    // Inputs the ID from user and passes it to other functions. Index is found using a function and then its record are displayed using another function.
    char temp[30];
    int index = -1;

    cin.ignore();
    cout << "Enter the ID of user (for example: 21L5225) : ";
    cin.get(temp, 30, '\n');

    index = GetIDIndex(temp, users, total_users);

    if (index >= 0 && index < total_users)
    {
        DisplayUser(index, users, books, total_records, today);
    }
    else
        cout << "No user with this ID was found in library records. Either the input was wrong/wrongly spelled or no user of this ID exists in the user records." << endl;
}


int GetIDIndex(const char temp[], const UserData users[], int total_users)
{
    // Loop searches through an array and compares the user input with the entries and then returns the index if something matches otherwise it returns index of -1
    int index = -1;
    for (int i = 0; i < total_users; i++)
    {
        if (strcmp(users[i].ID, temp) == 0)
        {
            index = i;
        }
    }
    return index;
}


void SearchCellNum(const UserData users[], int total_users, const BookData books[], int total_records, Date today)
{
    // Inputs the Cell Number from user and passes it to other functions. Index is found using a function and then its record are displayed using another function.
    long long int temp = -1;
    int index = -1;
    cout << "Enter the Cell Phone Number of a user: ";
    cin >> temp;

    index = GetCellNumIndex(temp, users, total_users);

    if (index >= 0 && index < total_users)
    {
        DisplayUser(index, users, books, total_records, today);
    }
    else
        cout << "No user with this Cell Number was found in library records. Either the input wasn't correct or no user with this cell number exists in the library." << endl;
}


int GetCellNumIndex(long long int temp, const UserData users[], int total_users)
{
    // Loop searches through an array and compares the user input with the entries and then returns the index if something matches otherwise it returns index of -1
    int index = -1;
    for (int i = 0; i < total_users; i++)
    {
        if (users[i].cell_num == temp)
        {
            index = i;
        }
    }
    return index;
}



