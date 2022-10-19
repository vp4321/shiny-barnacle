from LibraryDBConnect import MyLibrary 

#Main Code:
book = MyLibrary()
while True:
    print()
    print("**********WELCOME**********")
    print()
    print("Enter 1 to insert book into the database")
    print("Enter 2 to display all books")
    print("Enter 3 to delete book from the database")
    print("Enter 4 to update book")
    print("Enter 5 to search book in the database")
    print("Enter 6 to exit the program")
    print()

    try:
        choice = int(input())
        if choice==1:
            #insert
            bid = int(input("Enter Book Id: "))
            bname = input("Enter book name: ")
            aname = input("Enter author name: ")
            btype = input("Enter type of the book: ")
            blocation = input("Enter location of the book: ")
            isby = input("Enter issued by (Reg. No.): ")
            book.addBook(bid, bname, aname, btype, blocation, isby)
        elif choice==2:
            #display
            book.fetchAll()
        elif choice==3:
            #delete
            bid = int(input("Enter Book Id: "))
            book.deleteBook(bid)
        elif choice==4:
            #update
            bid = int(input("Enter Book Id: "))
            isby = input("Enter new issued by (Reg. No.): ")
            book.updateBook(bid, isby)
        elif choice==5:
            #search
            bname = input("Enter book name: ")
            book.searchBook(bname)
        elif choice==6:
            #exit
            break
        else:
            print("Invalid input! Try again")
    
    except Exception as e:
        print(e)
        print("Try again")