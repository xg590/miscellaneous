### Build the Database as Root
```shell
apt-get install -y postgresql python3-dev libpq-dev python3-pip  
pip3 install psycopg2  
pip3 install pandas  
sudo -u postgres createuser -s www-data
sudo -u www-data createdb newDB       
apt install -y apache2 python3 python3-pip
a2enmod cgid
systemctl restart apache2
wget https://github.com/xg590/miscellaneous/raw/master/complete_tang_poems/complete_tang_poems.json.bz2
bzip -dk complete_tang_poems.json.bz2
mv complete_tang_poems.json /tmp

sudo -u www-data python3
```
```python
import psycopg2
conn = psycopg2.connect("dbname=newDB") 
cur = conn.cursor() 
cur.execute("""
CREATE TABLE tang_poems(
    id SERIAL PRIMARY KEY, 
    volume  TEXT NOT NULL,
    title   TEXT NOT NULL,
    content TEXT NOT NULL);
""") 
import pandas as pd
df = pd.read_json('/tmp/complete_tang_poems.json',orient='index') 
for i, volume, title, content in df.itertuples():
	cur.execute(f"INSERT INTO tang_poems VALUES('{i}', '{volume}','{title}', '{content}');") 
cur.execute("commit;")
cur.execute("SELECT * FROM tang_poems LIMIT 2;") 
cur.fetchall()
```
### Test CGI
```python
cat << EOF > /usr/lib/cgi-bin/test.py
#!/usr/bin/python3
# -*- coding: UTF-8 -*- 
import sys 
import psycopg2
print(f"""Content-type:text/html

<html>
    <head>
        <meta charset=\"utf-8\"> 
        <title>This is a TEST</title>  
    </head> 
    <body>
        Your psycopg2's version is {psycopg2.__version__} <br>
    </body> 
</html>""")
EOF
chmod o+x /usr/lib/cgi-bin/test.py
```
