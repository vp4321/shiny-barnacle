import mysql.connector as connector


class MyLibrary:
    def __init__(self):
        self.con = connector.connect(
            host='localhost', port='3306', user='root', password='Raj@1299', database='MyLibrary')
        query = "create table if not exists allBooks(BookId int primary key, BookName varchar(200), AuthorName varchar(200), Type varchar(200), Location varchar(200), IssuedBy varchar(200))"

        cur = self.con.cursor()
        cur.execute(query)

    # Insert
    def addBook(self, BookId, BookName, AuthorName, Type, Location, IssuedBy):
        query = "insert into allBooks(BookId, BookName, AuthorName, Type, Location, IssuedBy) values({}, '{}', '{}', '{}', '{}', '{}')".format(
            BookId, BookName, AuthorName, Type, Location, IssuedBy)
        cur = self.con.cursor()
        cur.execute(query)
        self.con.commit()
        print("Book added to database")

    # Read
    def fetchAll(self):
        query = "select * from allBooks"
        cur = self.con.cursor()
        cur.execute(query)
        for row in cur:
            print("BookId: " + str(row[0]))
            print("BookName: " + row[1])
            print("AuthorName: " + row[2])
            print("Type: " + row[3])
            print("Location: " + row[4])
            print("Issued by Reg. No.: " + row[5])
            print()

    # Delete
    def deleteBook(self, BookId):
        query = "delete from allBooks where BookId = {}".format(BookId)
        cur = self.con.cursor()
        cur.execute(query)
        self.con.commit()
        print("Book deleted from database")

    # Update
    def updateBook(self, BookId, IssuedBy):
        query = "update allBooks set IssuedBy='{}' where BookId={}".format(
            IssuedBy, BookId)
        cur = self.con.cursor()
        cur.execute(query)
        self.con.commit()
        print("Book updated in the database")

    # Search
    def searchBook(self, BookName):
        query = "select * from allBooks where BookName = '{}'".format(BookName)
        cur = self.con.cursor()
        cur.execute(query)
        for row in cur:
            print("BookId: " + str(row[0]))
            print("BookName: " + row[1])
            print("AuthorName: " + row[2])
            print("Type: " + row[3])
            print("Location: " + row[4])
            print("Issued by Reg. No.: " + row[5])
        if (cur.rowcount == 0):
            print("Book not found")
