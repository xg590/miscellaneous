### Complete Tang Poems/全唐詩/全唐诗 in the format of json
* Source: 《全唐诗》作者：曹寅.txt from 无忧无虑中学语文网 / www.5156edu.com
* Convert to json: to_json.ipynb
* JSON file: complete_tang_poems.json.bz2
* Display in Pandas.DataFrame
```python
import pandas as pd
df = pd.read_json('complete_tang_poems.json',orient='index')
df.head()
```
* Format
```
  volume      title                      content
0 第一卷李世民 ◎卷.1【帝京篇十首】李世民    秦川雄帝宅，函谷壮皇居。绮殿千寻起，离宫百雉馀。\n连薨遥接汉
1 第一卷李世民 ◎卷.2【饮马长城窟行】李世民  塞外悲风切，交河冰已结。瀚海百重波，阴山千里雪。\n迥戍危烽火 
2 第一卷李世民 ◎卷.3【执契静三边】李世民    执契静三边，持衡临万姓。玉彩辉关烛，金华流日镜。\n无为宇宙清，
``` 
