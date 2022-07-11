import MySQLdb

# mo ket noi toi Database
db = MySQLdb.connect("localhost","root","HTN","patron" )

# chuan bi mot doi tuong cursor boi su dung phuong thuc <i>cursor()</i>
cursor = db.cursor()

# Thuc thi truy van SQL boi su dung phuong thuc <i>execute()</i>.
cursor.execute("SELECT VERSION()")

# Lay mot hang boi su dung phuong thuc <i>fetchone()</i>.
data = cursor.fetchone()

print( "Database version : %s " % data)

# ngat ket noi voi server
db.close()