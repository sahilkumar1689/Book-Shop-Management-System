using namespace std;
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include <conio.h>

class admin
{
    int a, flag;
    string password = "12";
    string email = "SK";

public:
    void admin_services();
    int admin_login();
    void addNewBooks();
    void updateBooksDetails();
    void deleteBooks();
    void searchBook();
    void showAllRecords();
};
class customer : public admin
{
public:
    void customer_Services();
};

int main()
{
    while (1)
    {
        system("cls");
        cout << setw(72) << "*******************************************" << endl;
        cout << setw(30) << "*" << setw(35) << "Online Book Management System" << setw(7) << "*" << endl;
        cout << setw(72) << "*******************************************" << endl
             << endl;
        cout << "1. Admin Pannel.\n"
             << endl;
        cout << "2. Customer Pannel.\n"
             << endl;
        cout << "3. Exit\n"
             << endl;
        int a = 0;
    label:
        cout << "Please enter(1-3):";
        cin >> a;
        if (a >= 1 && a <= 3)
        {
            switch (a)
            {
            case 1:
            {
                cout << "\n"
                     << setw(50) << "Inside Admin Pannel..." << endl;
                sleep(3);
                admin obj;
                obj.admin_services();
                break;
            }
            case 2:
            {
                cout << "\n"
                     << setw(50) << "Inside Customer Pannel..." << endl;
                sleep(3);
                // customer obj1;
                // obj1.customer_Services();
                break;
            }
            default:
            {
                cout << endl
                     << setw(70) << "********Thanks For visiting.********" << endl;
                exit(0);
                break;
            }
            }
        }
        else
        {
            cout << endl
                 << setw(60) << "Please enter the valid option." << endl
                 << endl;
            goto label;
        }
    }

    return 0;
}

// Admin Class Methods defination:

int admin::admin_login()
{
    int a;
    system("cls");
    cout << setw(72) << "*******************************************" << endl;
    cout << setw(30) << "*" << setw(35) << "Welcome to Admin Pannel login" << setw(7) << "*" << endl;
    cout << setw(72) << "*******************************************" << endl
         << endl;
label2:
    cout << "\n 1. Login To Admin Account" << endl;
    cout << "\n 2. Change The Admin Account" << endl;
label1:
    cout << "\n Please enter(1-2):";
    cin >> a;
    if (a == 1 || a == 2)
    {
        switch (a)
        {
        case 1:
        {
            system("cls");
            string str1;
            cout << "Please enter you email:";
            cin >> str1;
            if (str1 == email)
            {
                string temp;
                cout << "Please enter the password:";
                cin >> temp;
                if (temp == password)
                {
                    cout << setw(70) << "********You successfully login.********\n"
                         << endl;
                    sleep(3);
                    return 1;
                }
                else
                {
                    cout << setw(70) << "########You Enter the wrong Password.########\n"
                         << endl;
                    sleep(3);
                    return 0;
                }
            }
            else
            {
                cout << setw(70) << "########You Enter the wrong E-mail.########\n"
                     << endl;
                sleep(3);
                return 0;
            }
            break;
        }
        default:
        {
            system("cls");
            string str;
            string passw;
            cout << "Please enter the new email:";
            // getline(cin,str);
            cin >> str;
            email = str;
            cout << "Please enter the new password:";
            // getline(cin,passw);
            cin >> passw;
            password = passw;
            cout << setw(70) << "********Changes successfull.********\n"
                 << endl;
            sleep(3);
            goto label2;
            break;
        }
        }
    }
    else
    {
        cout << setw(60) << "Please enter the correct option." << endl;
        sleep(2);
        goto label1;
    }
}

void admin::addNewBooks()
{
    string book_name, author_name, option;
    int book_id, pages, copies;
    float price;
    // Take user input:
    do
    {
        system("cls");
        cout << setw(72) << "*******************************************" << endl;
        cout << setw(30) << "*" << setw(30) << "Add New Books:" << setw(12) << "*" << endl;
        cout << setw(72) << "*******************************************" << endl
             << endl;
        cout << "\n Enter the book id (in digits):";
        cin >> book_id;
        cout << "\n Enter the book name:";
        // getline(cin,book_name);
        cin >> book_name;
        cout << "\n Enter the author name:";
        // getline(cin,author_name);
        cin >> author_name;
        cout << "\n Enter the number of pages:";
        cin >> pages;
        cout << "\n Enter the prices:";
        cin >> price;
        cout << "\n Enter the number of copies:";
        cin >> copies;

        // Store in the file:
        fstream addBook;
        addBook.open("BooksRecord.txt", ios::out | ios::app);
        addBook << " " << book_id << " " << book_name << " "
                << " " << author_name << " " << pages << " " << price << " " << copies << "\n";
        addBook.close();

        // Ask add new file or not:
        cout << setw(70) << "******** Book Add successfully.********\n"
             << endl;

        cout << "You want to enter another book(y/n):";
        cin >> option;
        for (auto &it : option)
        {
            it = tolower(it);
        }
    } while (option == "yes" || option == "y");
}

void admin::showAllRecords()
{
    system("cls");
    string book_name, author_name, option;
    int book_id, pages, copies;
    float price;
    cout << setw(72) << "*******************************************" << endl;
    cout << setw(30) << "*" << setw(30) << "All Books Details:" << setw(12) << "*" << endl;
    cout << setw(72) << "*******************************************" << endl
         << endl;
    fstream readBook;
    readBook.open("BooksRecord.txt", ios::in);
    if (!readBook)
        cout << "File opening error." << endl;
    else
    {
        cout << "\n\nBookID\t\tName\t\tAuthor\t\tPrice\t\tcopies\t\tNo.ofpages\n\n";
        readBook >> book_id >> book_name >> author_name >> pages >> price >> copies;
        while (!readBook.eof())
        {
            cout << " " << book_id << "\t\t" << book_name << "\t\t" << author_name << "\t\t" << price << "\t\t" << copies << "\t\t" << pages << "\n\n";
            readBook >> book_id >> book_name >> author_name >> pages >> price >> copies;
        }
        cout << "\nPlease enter any key to go back:";
        getch();
    }
    readBook.close();
}

void admin::searchBook()
{
    string book_name, author_name, option;
    int book_id, pages, copies, count = 0;
    float price;
    system("cls");
    cout << setw(72) << "*******************************************" << endl;
    cout << setw(30) << "*" << setw(30) << "Search Books Details:" << setw(12) << "*" << endl;
    cout << setw(72) << "*******************************************" << endl
         << endl;

    cout << "\n1. Search By ID." << endl;
    cout << "\n2. Search By Name." << endl;
    int temp = 0;
label:
    cout << "\nPlease Enter(1-2):";
    cin >> temp;
    switch (temp)
    {
    case 1:
    {
        system("cls");
        int temp_book_id;
        cout << "\n Please enter the book ID:";
        cin >> temp_book_id;
        fstream search;
        search.open("BooksRecord.txt", ios::in);
        search >> book_id >> book_name >> author_name >> pages >> price >> copies;
        while (!search.eof())
        {
            if (book_id == temp_book_id)
            {
                system("cls");
                cout << "\n"
                     << setw(60) << "Book Details are:\n"
                     << endl;
                cout << "Book Id is:" << book_id << "\t\t"
                     << "Book Name is:" << book_name << "\n"
                     << "Book Author Name is:" << author_name << "\t\t"
                     << "Prices is:" << price << "\n"
                     << "Total No. of pages:" << pages << "\t\t"
                     << "Total No. of copies:" << copies << endl;
                count++;
                break;
            }
            else
            {
                search >> book_id >> book_name >> author_name >> pages >> price >> copies;
            }
        }
        search.close();
        if (count == 0)
        {
            cout << "Sorry we can't have a book with " << temp_book_id << " book ID." << endl;
        }
        cout << "\n\nPress any key to exit:";
        getch();
        break;
    }
    case 2:
    {
        system("cls");
        string temp_book_name;
        cout << "\n Please enter the book name:";
        cin >> temp_book_name;
        fstream search;
        search.open("BooksRecord.txt", ios::in);
        search >> book_id >> book_name >> author_name >> pages >> price >> copies;
        while (!search.eof())
        {
            if (book_name == temp_book_name)
            {
                system("cls");
                cout << "\n"
                     << setw(60) << "Book Details are:\n"
                     << endl;
                cout << "Book Id is:" << book_id << "\t\t"
                     << "Book Name is:" << book_name << "\n"
                     << "Book Author Name is:" << author_name << "\t\t"
                     << "Prices is:" << price << "\n"
                     << "Total No. of pages:" << pages << "\t\t"
                     << "Total No. of copies:" << copies << endl;
                count++;
                break;
            }
            else
            {
                search >> book_id >> book_name >> author_name >> pages >> price >> copies;
            }
        }
        search.close();
        if (count == 0)
        {
            cout << "Sorry we can't have a book with " << temp_book_name << " book Name." << endl;
        }
        cout << "\n\nPress any key to exit:";
        getch();
        break;
    }
    default:
    {
        cout << "\n\t\tPlease enter the valid option." << endl;
        goto label;
        break;
    }
    }
}

void admin::updateBooksDetails()
{
    system("cls");
    string book_name, author_name;
    int book_id, pages, copies, count = 0;
    float price;
    string b_name, a_name;
    int pag, copy;
    float pri;
    cout << setw(72) << "*******************************************" << endl;
    cout << setw(30) << "*" << setw(30) << "Update Books Details:" << setw(12) << "*" << endl;
    cout << setw(72) << "*******************************************" << endl
         << endl;

    int temp_book_id;
    cout << "\nPlease enter the book Id:";
    cin >> temp_book_id;

    fstream file, file1;
    file1.open("tempFile.txt", ios::app | ios::out);
    file.open("BooksRecord.txt", ios::in);

    file >> book_id >> book_name >> author_name >> pages >> price >> copies;

    while (!file.eof())
    {
        if (temp_book_id == book_id)
        {
            system("cls");
            cout << "\n Enter the new book name:";
            cin >> b_name;
            cout << "\n Enter the new author name:";
            cin >> a_name;
            cout << "\n Enter the pages:";
            cin >> pag;
            cout << "\n Enter the price:";
            cin >> pri;
            cout << "\n Enter the copies:";
            cin >> copy;
            file1 << " " << temp_book_id << " " << b_name << " "
                  << " " << a_name << " " << pag<< " " << pri << " " << copy << "\n";
            count++;
        }
        else
        {
            file1 << " " << book_id << " " << book_name << " "
                  << " " << author_name << " " << pages << " " << price << " " << copies << "\n";
        }
        file >> book_id >> book_name >> author_name >> pages >> price >> copies;
    }
    if (count == 0)
    {
        cout << "Sorry we can't have a book with " << temp_book_id << " book ID." << endl;
    }
    else cout<<setw(60)<<"********Update Successfull.********"<<endl;
    file.close();
    file1.close();
    remove("BooksRecord.txt");
    rename("tempFile.txt","BooksRecord.txt");
    cout << "\n\nPress any key to exit:";
    getch();
}

void admin::deleteBooks(){
    system("cls");
    string book_name, author_name;
    int book_id, pages, copies, count = 0;
    float price;

    cout << setw(72) << "*******************************************" << endl;
    cout << setw(30) << "*" << setw(30) << "Delete Books Details:" << setw(12) << "*" << endl;
    cout << setw(72) << "*******************************************" << endl
         << endl;

    int temp_book_id;
    cout << "\nPlease enter the book Id:";
    cin >> temp_book_id;

    fstream file, file1;
    file1.open("tempFile.txt", ios::app | ios::out);
    file.open("BooksRecord.txt", ios::in);

    file >> book_id >> book_name >> author_name >> pages >> price >> copies;

    while (!file.eof())
    {
        if (temp_book_id == book_id)
        {
            count++;
        }
        else
        {
            file1 << " " << book_id << " " << book_name << " "
                  << " " << author_name << " " << pages << " " << price << " " << copies << "\n";
        }
        file >> book_id >> book_name >> author_name >> pages >> price >> copies;
    }
    if (count == 0)
    {
        cout << "Sorry we can't have a book with " << temp_book_id << " book ID." << endl;
    }
    else cout<<setw(60)<<"********Deletion Successfull.********"<<endl;
    file.close();
    file1.close();
    remove("BooksRecord.txt");
    rename("tempFile.txt","BooksRecord.txt");
    cout << "\n\nPress any key to exit:";
    getch();
}

void admin::admin_services()
{
    if (admin_login())
    {
        while (1)
        {
            system("cls");
            cout << setw(72) << "*******************************************" << endl;
            cout << setw(30) << "*" << setw(35) << "Welcome to Admin Pannel" << setw(7) << "*" << endl;
            cout << setw(72) << "*******************************************" << endl
                 << endl;
            cout << "1. Add New Books." << endl;
            cout << "2. Update Books Details." << endl;
            cout << "3. Delete Books." << endl;
            cout << "4. Search Book." << endl;
            cout << "5. Show All Books." << endl;
            cout << "6. Exit" << endl;
        label:
            cout << "Please enter(1-6):";
            cin >> a;
            if (a >= 1 && a <= 6)
            {
                flag = 0;
                switch (a)
                {
                case 1:
                {
                    addNewBooks();
                    break;
                }
                case 2:
                    updateBooksDetails();
                    break;
                case 3:
                    deleteBooks(); 
                    break;
                case 4:
                    searchBook();
                    break;
                case 5:
                    showAllRecords();
                    break;
                default:
                    flag = 1;
                    break;
                }
            }
            else
            {
                cout << endl
                     << setw(60) << "Please enter the valid option." << endl
                     << endl;
                goto label;
            }
            if (flag == 1)
                break;
        }
    }
    else
    {
        cout << setw(40) << "Sorry,you can't login please check your email and password." << endl;
        sleep(3);
    }
}


// Customer class Methods Defination:
