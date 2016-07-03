# JuniorProj
Codes for project done in Junior


(1)similarity_test1
a.功能:計算資料定義的不同屬性的各個相似度。
b.輸入格式:不同file，file中會有1~11共11項attribute，分別為:
1姓名
2性別	
3生日	
4血型	
5出沒地	
6學校	
7公司	
8職業	
9興趣	
10婚姻狀況	
11各種網址。
c.程式的輸出:格式為libSVM要求的輸入資料格式，共4個檔案，
1._result:為全部資料的對應結果，1代表同位使用者，0代表不同位。
2._report:相似度輸出結果不符合規定或者超過0~1之間的範圍時會被輸出到這裡。
3._label_0:所有為不同使用者的相似度結果。
4._label_1:所有為相同使用者的相似度結果。

(2)sim_rng
a.功能:將計算出label為0的資料亂數取出符合label1數量的個數，以便進行之後的機器學習訓練。
b.輸入格式:(1)的_label_0，並且在程式中需要更改今天要取的個數的資料。
例如今天有N筆資料則需要更改數值成N(rng)以及N*(N-1)(total)。
c.程式的輸出:為一檔案，內容是所取個數N的N筆label0的資料。

(3)fromat
a.功能:將原本libSVM格式的檔案轉換成WEKA的格式。
b.輸入格式:libSVM格式的任何檔案。
c.程式的輸出:為一檔案，WEKA格式的輸入檔案。

(4)data_provide_rate
a.功能:計算不同的資料量中資料的提供率。
b.輸入格式:不同平台中各資料量的紀錄檔案。
c.程式的輸出:為一double數值。

(5)attribute_decrease
a.功能:將原本libSVM格式的檔案刪去想要移除的attribute。
b.輸入格式:libSVM格式的任何檔案。
並且需要更改程式中
#define fileNum 1//第幾批檔案
string fileType = "low";//資料量的多少
#define attrNum 11//想要刪去的資料attribute編號。
c.程式的輸出:為一檔案，刪去指定attribute後的資料。

(6)attr_sort(後來的專題成果中並未使用到)
a.功能:找出在某一個檔案中以某特定attribute來排序結果中前N筆資料。
b.輸入格式:libSVM格式，並且在程式中需要更改今天要取的個數的資料。
#define attrNum 10//所指定的attribute ***請注意此程式的attribute從0開始計數。
#define bound 51//總共要取多少筆
c.程式的輸出:為一排序好的檔案，為libSVM的格式。

(7)threshold_cal(後來的專題成果中並未使用到)
a.功能:計算不同的資料量中各attribute資料的平均數值。
b.輸入格式:libSVM格式，並且在程式中需要指定今天輸入的檔案總共含有多少筆資料。
#define DATA 2550
c.程式的輸出:為一檔案，含有attribute1~11的各項的平均，型態為double。

(8)filter(後來的專題成果中並未使用到)
a.功能:利用(7)中的結果篩去那些在平均指數之下的資料筆數。
b.輸入格式:libSVM格式，並且在程式中需要指定今天欲篩選的資料的threshold。
例如:
double thres[12] = { 0
		, 0.548981
		, 0.000626959
		, 0.0104493
		, 0.0993665
		, 0.00264484
		, 0
		, 0.000522466
		, 0.306153
		, 0.0135841
		, 0
		, 0 };
c.程式的輸出:2個libSVM格式檔案，包含篩選後的資料以及資料對應的紀錄。
