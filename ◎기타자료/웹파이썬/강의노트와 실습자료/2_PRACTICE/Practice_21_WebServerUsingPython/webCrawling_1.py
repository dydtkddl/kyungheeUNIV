import requests
from bs4 import BeautifulSoup

req = requests.get('https://khu.ac.kr/kor/focus/detail.do?seq=2164725&page=1&pageSize=5')
html = req.text
soup = BeautifulSoup(html, 'html.parser')
my_titles = soup.select(
    '#printArea > div > div.titNew > h4'
    )

for title in my_titles:
    print(title.text)


    