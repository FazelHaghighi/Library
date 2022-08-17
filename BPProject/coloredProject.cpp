#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

//Function ProtoTypes
void firstpage(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed);
void manager(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed);
void member(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed);
void managerOption(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed);
void memberOption(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed);
int loadMemberID();
void saveMemberID();
void saveBookID();
int loadBookID();
void sortByBorrowed(int bookSaver, string books[100][10]);

/*
*This function is for sorting books
*by number of how many times a book
*has been borrowed from the lowest to
*the greatest.
*Gets books array and number of books
*as input 
*/
void sortByBorrowed(int bookSaver, string books[100][10]){
    string temp[100][10];
    for (int i = 0; i < bookSaver; i++){
        for (int j = i + 1; j < bookSaver; j++){
            if (stoi(books[i][8]) > stoi(books[j][8])){
                for (int k = 0; k < 10; k++){
                    temp[i][k] = books[i][k];
                    books[i][k] = books[j][k];
                    books[j][k] = temp[i][k];
                }  
            }    
        }   
    }  
}

/*
*This function is for loading
*member id from file.
*/
int loadMemberID(){
    int number;
    ifstream memberID ("MemberID.txt");
    memberID >> number;
    memberID.close();
    return number;
}

/*
*This function is for saving
*member id to file.
*/
void saveMemberID(){
    int number = loadMemberID();
    ofstream memberID ("MemberID.txt");
    memberID << number + 1;
    memberID.close();
}

/*
*This function is for loading
*book id from file.
*/
int loadBookID(){
    int number;
    ifstream bookID ("BookID.txt");
    bookID >> number;
    bookID.close();
    return number;
}

/*
*This function is for loading
*book id from file.
*/
void saveBookID(){
    int number = loadBookID();
    ofstream bookID ("BookID.txt");
    bookID << number + 1;
    bookID.close();
}

/*
*This function is the first page
*that the user faces and gives
*him/her the option to enter as
*a member or manager.
*/
void firstpage(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed){
    system("cls");
    int n;
    cout << "\u001B[36m***Welocome***\u001B[0m\n";
    cout << "\n\u001B[31m1.Manager\u001B[0m" << "\n\u001B[34m2.Member\u001B[0m" << "\n\u001B[32m0.Exit\u001B[0m\n";
    cin >> n;
    
    switch (n){
    case 1 :
        manager(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        break;
    case 2 :
        member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        break;
    case 0 :
        system("cls");
        cout << "\u001B[35mThanks for coming.\u001B[0m";
        exit(0);
    default :
        system("cls");
        firstpage(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        break;
    }
}

/*
*This function checks that if the user
*is actually a manager and knowes the password
*or not.
*/
void manager(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed){

    system("cls");
    int guess;
    do {
        cout << "\u001B[36mPlease Enter The Password:(Type 0 To Go Back)\u001B[0m\n";
        cin >> guess;
        if (guess == 0){
            firstpage(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        }
        
        system("cls");
        cout << "\u001B[31mWrong Password!\u001B[0m\n";

    } while (guess != 1234);
    managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);

}

/*
*This function showes manager's options
*to him/her.
*/
void managerOption(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed){

    string title, author, last_borrow, fine, borrow_day, return_day, genre, bookInfo, bookInfoPrint, zero, editBookID, new_title, new_author, new_genre, new_id, remove_id, s, del, total_borrow, who_borrowed;
    int bookID, editOpt, start, end;
    int dateSaver[3];
    system("cls");
    cout << "\u001B[36mPlease Select The Option You Want:\u001B[0m\n\n";
    cout << "1.Show Books\n" << "2.Add Books\n" << "3.Edit Books\n" << "4.Remove Books\n" << "5.Sort By Total Borrowing\n" << "0.Back\n";
    int bookOpt;
    cin >> bookOpt;
    switch (bookOpt){

    //showes all books to manager.    
    case 1 :
        system("cls");
        for (int i = 0; i < bookSaver; i++){
            cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
            cout << "\n";
        }
        
        cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
        cin >> zero;
        managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        break;

    //adding new books by entering the requested information.
    case 2 :
        system("cls");
        cout << "Enter Book's Title:\n";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Book's genre:\n";
        getline(cin, genre);
        cout << "Enter Book's author:\n";
        getline(cin, author);

        last_borrow = " ";
        fine = "$0.5";
        borrow_day = " ";
        return_day = " ";
        total_borrow = "0";
        who_borrowed = " ";


        bookInfoPrint = "Title: " + title + "\nAuthor: " + author + "\nGenre: " + genre + "\nLast One Borrowed: " + last_borrow + "\nFine Per Day For Delay: " + fine + "\nBorrowing Day: " + borrow_day + "\nReturning Day: " + return_day + "\nTotal Borrow: " + total_borrow + "\nWho Borrowed: " + who_borrowed;

        system("cls");        
        cout << bookInfoPrint;

        bookID = loadBookID();
        cout << "\n\nBook's ID: " << genre << "-" << to_string(bookID) << "\n";
        saveBookID();

        books[bookSaver][0] = title;
        books[bookSaver][1] = author;
        books[bookSaver][2] = genre;
        books[bookSaver][3] = last_borrow;
        books[bookSaver][4] = fine;
        books[bookSaver][5] = borrow_day;
        books[bookSaver][6] = return_day;
        books[bookSaver][7] = genre + "-" + to_string(bookID);
        books[bookSaver][8] = total_borrow;
        books[bookSaver][9] = who_borrowed;
            
        bookSaver++;

        cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
        cin >> zero;
        managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
        break;

        //editing the information of a book
        //by choosing what you wanna change about
        //that book.
        case 3 :
            system("cls");
            cout << "\u001B[36mPlease Select The Option You Want:\u001B[0m\n\n";
            cout << "1.Edit Title\n" << "2.Edit Author\n" << "3.Edit Genre\n" << "4.Edit ID\n" << "0.Back\n";
            cin >> editOpt;

            //the same process for all of them
            //checks if the book exists or not
            //then changes that info with the one
            //that user enters.
            switch (editOpt)
            {
            case 1 :
                system("cls");
                cout << "Enter Book's ID:\n";
                cin >> editBookID;
                cout << "Enter New Title:\n";
                cin.ignore();
                getline(cin, new_title);
                for (int i = 0; i < bookSaver; i++){
                    if(editBookID == books[i][7]){
                        books[i][0] = new_title;
                        cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                        cout << "\n";
                    }
                }
                cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 2 :
                system("cls");
                cout << "Enter Book's ID:\n";
                cin >> editBookID;
                cout << "Enter New Author:\n";
                cin.ignore();
                getline(cin, new_author);
                for (int i = 0; i < bookSaver; i++){
                    if(editBookID == books[i][7]){
                        books[i][1] = new_author;
                        cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                        cout << "\n";
                    }
                }
                cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 3 :
                system("cls");
                cout << "Enter Book's ID:\n";
                cin >> editBookID;
                cout << "Enter New Genre:\n";
                cin.ignore();
                getline(cin, new_genre);
                for (int i = 0; i < bookSaver; i++){
                    if(editBookID == books[i][7]){
                        books[i][2] = new_genre;
                        cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                        cout << "\n";
                    }
                }
                cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 4 :
                system("cls");
                cout << "Enter Book's ID:\n";
                cin >> editBookID;
                cout << "Enter New ID:\n";
                cin.ignore();
                getline(cin, new_id);
                for (int i = 0; i < bookSaver; i++){
                    if(editBookID == books[i][7]){
                        books[i][7] = new_id;
                        cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                        cout << "\n";
                    }
                }
                cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 0 :
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            default:
                managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;
            }
            break;

        //first returns the book to library if
        //it exists then removes it from the books
        //array and write the array all over again.
        case 4 :
            system("cls");
            cout << "Enter Book's ID You Wanna Remove:\n";
            cin.ignore();
            getline(cin, remove_id);

            for (int i = 0; i < bookSaver; i++){
                if (remove_id == books[i][7]){
                    for (int j = 0; j < stoi(members[idSaver - 1][6]); j++){
                        s = members[idSaver - 1][7];
                        del = "|";
                        start = 0;
                        end = s.find(del);
                        while (end != -1) {
                            if (remove_id != s.substr(start, end - start)){
                                borrowedBooks[borrowed] = s.substr(start, end - start);
                                borrowed++;
                            }
                            start = end + del.size();
                            end = s.find(del, start);
                        }
                    }   
                }
            }

            for (int i = 0; i < bookSaver; i++){
                if (remove_id == books[i][7]){
                    s = books[i][6];
                    del = "/";
                    start = 0;
                    end = s.find(del);
                    for (int j = 0; j < 3; j++){
                        dateSaver[j] = stoi(s.substr(start, end - start));
                        start = end + del.size();
                        end = s.find(del, start);  
                    }
                }
            }
            
            members[idSaver - 1][8] = "0";
            
            members[idSaver - 1][6] = to_string(stoi(members[idSaver - 1][6]) - 1);
            members[idSaver - 1][7] = "";
            
            for (int i = 0; i < borrowed - 1; i++){
                members[idSaver - 1][7] += borrowedBooks[i] + "|";
            }
            
            borrowed = 0;

            for (int i = 0; i < bookSaver; i++){
                if (remove_id == books[i][7]){
                    for (int j = i; j < bookSaver; j++){
                        for (int k = 0; k < 10; k++){
                            books[j][k] = books[j + 1][k];
                        }
                    }      
                }
            }
            bookSaver--;

            cout << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        //just sorts the books using
        //sortByBorrowed function.
        case 5 :
            system("cls");
            sortByBorrowed(bookSaver, books);
            cout << "Done!\n" << "\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        case 0 :
            firstpage(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        default:
            managerOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;
            
        } 
}

/*
*This function gives the user the option
*to sign in or creating an account in case
*of not having one.
*/
void member(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed){
    system("cls");
    string name, phone, join, end, book_limit, time_limit, booknum, books_borrowed, total_Delay, infoPrint, fileName, zero, password;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int memberID;

    cout << "\u001B[36mPlease Select The Option You Want:\u001B[0m\n\n";
    cout << "1.Sign in\n" << "2.Craet Acoount\n" << "0.Back\n";
    int n;
    cin >> n;
    switch (n){
        case 1 :
            system("cls");
            int id, pass;
            cout << "Please Enter Your ID:\n";
            cin >> id;
            idSaver = id;
            cout << "Please Enter Your Password:\n";
            cin >> pass;
            if(to_string(pass) == members[idSaver - 1][10]){
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            }
            else member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        //in this case we create an acoount
        //for user by getting some infotmation
        //from him/her.
        case 2 :
            system("cls");
            cout << "Please Enter Your Name:\n";
            cin.ignore();
            getline(cin, name);
            cout << "Please Enter Your Phone Number:\n";
            getline(cin, phone);
            cout << "Please Enter A Password For Yourself:\n";
            getline(cin, password);
            
            join = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
            if ((ltm->tm_mon + 6) > 12){
                end = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon - 6) + "/" + to_string(1901 + ltm->tm_year);
            }
            else end = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon + 6) + "/" + to_string(1900 + ltm->tm_year);
            
            book_limit = "10";
            time_limit = "2 weeks";

            books_borrowed = "";
            booknum = "0";
            total_Delay = "0";

            infoPrint = "Name: " + name + "\nPhone Number: " + phone + "\nMembership Date: " + join + "\nEnd Of Membership Date: " + end + "\nBook Limit To Borrow: " + book_limit + "\nTime Limit Of Borrowing: " + time_limit + "\nNumber Of Borrowed Books: " + booknum + "\nBooks You Borrowed: " + books_borrowed + "\nTotal Delay: " + total_Delay;
            
            system("cls");
            cout << infoPrint;

            memberID = loadMemberID();
            cout << "\n\nYour ID: " << memberID << "\n";
            cout << "Your PassWord: " << password;
            saveMemberID();
            
            members[memberSaver][0] = name;
            members[memberSaver][1] = phone;
            members[memberSaver][2] = join;
            members[memberSaver][3] = end;
            members[memberSaver][4] = book_limit;
            members[memberSaver][5] = time_limit;
            members[memberSaver][6] = booknum;
            members[memberSaver][7] = books_borrowed;
            members[memberSaver][8] = total_Delay;
            members[memberSaver][9] = to_string(memberID);
            members[memberSaver][10] = password;
            
            memberSaver++;

            cout << "\n\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        case 0 :
            firstpage(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        default :
            member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;
    }
}

/*
*This function showes manager's options
*to him/her.
*/
void memberOption(int memberSaver, string members[100][11], int bookSaver, string books[100][10], int idSaver, string borrowedBooks[100], int borrowed){
    system("cls");
    int n, searchOpt, tempNumber, start, end, return_day, today;
    string zero, author_name, genre_choice, borrowing_id, s, del, payOpt, extendOpt, membership_end;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int dateSaver[3];

    cout << "\u001B[36mPlease Select The Option You Want:\u001B[0m\n\n";
    cout << "1.Show Info\n" << "2.Search Books\n" << "3.Borrow Book\n" << "4.Return Book\n" << "5.Pay Fine\n" << "6.Extend Membership\n" << "0.Back\n";
    cin >> n;
    switch (n){
        
        //showes member's info to him/her.
        case 1 :
            system("cls");
            cout << "Name: " << members[idSaver - 1][0] << "\nPhone Number: " << members[idSaver - 1][1] << "\nMembership Date: " << members[idSaver - 1][2] << "\nEnd Of Membership Date: " << members[idSaver - 1][3] << "\nBook Limit To Borrow: " << members[idSaver - 1][4] << "\nTime Limit Of Borrowing: " << members[idSaver - 1][5] << "\nNumber Of Borrowed Books: " << members[idSaver - 1][6] << "\nBooks You Borrowed: " << members[idSaver - 1][7] << "\nTotal Delay: " << members[idSaver - 1][8] << "\nYour ID: " << members[idSaver - 1][9] << "\nYour Password: " << members[idSaver - 1][10];
            cout << "\n\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        //searches among the books
        //by author or genre or showes
        //all of them.
        case 2 :
            system("cls");
            cout << "\u001B[36mPlease Select The Option You Want:\u001B[0m\n\n";
            cout << "1.Search By Auhtor\n" << "2.Search By Genre\n" << "3.Show All Books\n" << "0.Back\n";
            cin >> searchOpt;

            switch (searchOpt){
            case 1 :
                system("cls");
                cout << "Enter Author's Name:\n";
                cin.ignore();
                getline(cin, author_name);
                for(int i = 0; i < bookSaver; i++){
                    if(books[i][1] == author_name){
                    cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                    cout << "\n"; 
                    }
                }
                cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 2 :
                system("cls");
                cout << "Enter Book's Genre:\n";
                cin.ignore();
                getline(cin, genre_choice);
                for(int i = 0; i < bookSaver; i++){
                    if(books[i][2] == genre_choice){
                    cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                    cout << "\n"; 
                    }
                }
                cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            case 3 :
                system("cls");
                for (int i = 0; i < bookSaver; i++){
                    cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                    cout << "\n";
                }
        
                cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;
            
            case 0 :
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;

            default:
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
                break;
            }
            break;

        //borrowes a book from available
        //books and adds it to member's borrowed list
        //and changes the borrowing informations
        //about that book.
        case 3 :
            system("cls");
            cout << "Enter Book's ID:\n";
            cin.ignore();
            getline(cin, borrowing_id);
            for (int i = 0; i < bookSaver; i++){
                if (borrowing_id == books[i][7]){
                    books[i][3] = to_string(idSaver);
                    books[i][5] = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
                    if ((ltm->tm_mday + 14) > 30){
                        books[i][6] = to_string(ltm->tm_mday - 16) + "/" + to_string(ltm->tm_mon + 1) + "/" + to_string(1900 + ltm->tm_year);
                    }
                    else to_string(ltm->tm_mday + 14) + "/" + to_string(ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
                
                    tempNumber = stoi(members[idSaver - 1][6]);
                    tempNumber++;
                    members[idSaver - 1][6] = to_string(tempNumber);
                    members[idSaver - 1][7] += borrowing_id + "|";
                    
                    books[i][8] = to_string(stoi(books[i][8]) + 1);
                    books[i][9] +=  to_string(idSaver) + " ";
                }  
            }
            system("cls");
            for (int i = 0; i < bookSaver; i++){
                if (borrowing_id == books[i][7]){
                    cout << "\u001B[31mTitle:\u001B[0m " << books[i][0] << "  \u001B[34mAuthor:\u001B[0m " << books[i][1] << "  \u001B[32mGenre:\u001B[0m " << books[i][2] << "  \u001B[31mLast One Borrowed:\u001B[0m " << books[i][3] << "  \u001B[34mFine Per Day For Delay:\u001B[0m " << books[i][4] << "  \u001B[32mBorrowing Day:\u001B[0m " << books[i][5] << "  \u001B[31mReturning Day:\u001B[0m " << books[i][6] << " \u001B[34mBook's ID:\u001B[0m " << books[i][7] << "  \u001B[32mTotal Borrow:\u001B[0m " + books[i][8] << "  \u001B[31mWho Borrowed:\u001B[0m " + books[i][9];
                }
            }
            
            cout << "\n\nNumber Of Borrowed Books: " << members[idSaver - 1][6] << "\nBooks You Borrowed: " << members[idSaver - 1][7];
            
            cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;
        
        //returns a book to book's list
        //and changes the borrowing informations
        //about that book.
        case 4 :
            system("cls");
            cout << "Enter Book's ID:\n";
            cin.ignore();
            getline(cin, borrowing_id);
            for (int i = 0; i < bookSaver; i++){
                if (borrowing_id == books[i][7]){
                    for (int j = 0; j < stoi(members[idSaver - 1][6]); j++){
                        s = members[idSaver - 1][7];
                        del = "|";
                        start = 0;
                        end = s.find(del);
                        while (end != -1) {
                            if (borrowing_id != s.substr(start, end - start)){
                                borrowedBooks[borrowed] = s.substr(start, end - start);
                                borrowed++;
                            }
                            start = end + del.size();
                            end = s.find(del, start);
                        }
                    }  
                }
            }

            for (int i = 0; i < bookSaver; i++){
                if (borrowing_id == books[i][7]){
                    s = books[i][6];
                    del = "/";
                    start = 0;
                    end = s.find(del);
                    for (int j = 0; j < 3; j++){
                        dateSaver[j] = stoi(s.substr(start, end - start));
                        start = end + del.size();
                        end = s.find(del, start);  
                    }
                }
            }
            
            return_day = dateSaver[0] + (dateSaver[1] * 30) + (dateSaver[2] * 365);
            today = ltm->tm_mday + (ltm->tm_mon * 30) + ((1900 + ltm->tm_year) * 365);

            if ((return_day - today) < 0){
                members[idSaver - 1][8] = to_string((return_day - today) * -1);
            }
            
            members[idSaver - 1][6] = to_string(stoi(members[idSaver - 1][6]) - 1);
            members[idSaver - 1][7] = "";
            
            for (int i = 0; i < borrowed - 1; i++){
                members[idSaver - 1][7] += borrowedBooks[i] + "|";
            }
            
            borrowed = 0;
            
            system("cls");
            cout << "Number Of Borrowed Books: " << members[idSaver - 1][6] << "\nBooks You Borrowed: " << members[idSaver - 1][7] << "\nTotal Delay: " << members[idSaver - 1][8];

            cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        //paying the fine on the base of
        //total delay.
        case 5 :
            system("cls");
            cout << "Total Fine You Have To Pay: $" << (stoi(members[idSaver - 1][8]) * 0.5);
            cout << "\n1.Pay" << "\n0.Back\n";
            cin >> payOpt;
            if (payOpt == "1"){
                members[idSaver - 1][8] = "0";

                cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
                cin >> zero;
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            }
            else if (payOpt == "0"){
                memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            }

            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        //adds 6 months to today's date
        //and sets it as the end of membership date.    
        case 6 :
            system("cls");
            cout << "1.Extend\n" << "0.Back\n";
            cin >> extendOpt;
            if (extendOpt == "1"){
                if ((ltm->tm_mon + 6) > 12){
                membership_end = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon - 6) + "/" + to_string(1901 + ltm->tm_year);
            }
            else membership_end = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon + 6) + "/" + to_string(1900 + ltm->tm_year);
            
            members[idSaver - 1][3] = membership_end;

            cout << "\n\u001B[33mType 0 To Go Back!\u001B[0m\n";
            cin >> zero;
            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            }
            else member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;
            
        case 0 :
            member(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;

        default:
            memberOption(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
            break;
    } 
}

int main(){

    /*
    *here we declare the most important variables
    *that we use all over the program and save our
    *data into them.
    *
    *members : for saving members' informations
    *memberSaver : for saving the number of all members
    *books : for saving books' informations
    *bookSaver : for saving the number of all books
    *idSaver : for saving the id we sign in with and use it in the program
    *borrowedBooks : for saving the list of borrowed books
    *borrowed : for saving the number of borrowed books
    */
    int memberSaver = 0, bookSaver = 0, idSaver, borrowed = 0;
    string members[100][11];
    string books[100][10];
    string borrowedBooks[100];
    firstpage(memberSaver, members, bookSaver, books, idSaver, borrowedBooks, borrowed);
}
