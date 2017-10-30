# Assigment 1 report
## Testing results
|| Origin image | Gray image | Method one  | Method two | Method two test |
| ------------ |:----------:| -----------:|-----------:|----------------:|----------------:|
|Show image|![lena256](https://user-images.githubusercontent.com/32957934/32135775-39c2a27a-bc37-11e7-8e96-9c031129eed6.jpg)|![gray image](https://user-images.githubusercontent.com/32957934/32135789-3fdded72-bc37-11e7-94ef-958c12dd1591.jpg)|![method one](https://user-images.githubusercontent.com/32957934/32135790-439547da-bc37-11e7-92ee-5b8ffeb35d3a.jpg)|![method two](https://user-images.githubusercontent.com/32957934/32135792-47550112-bc37-11e7-9e58-1ff40edff107.jpg)|![method two test](https://user-images.githubusercontent.com/32957934/32135795-4a8aa86e-bc37-11e7-9fa1-2216722bba41.jpg)|
|Method | 使用256*256彩色圖| 用 (R+G+B)/3 來產生灰階圖 |將讀取到的圖片依級距處理，分別點上相對應的黑點數|依照陣列判斷相對位置的值 |依照陣列判斷相對位置的值|
|Result Discussion | -- | -- |圖片放大兩倍，大致可看出圖片的內容，明亮處多為白色，陰暗處多為黑色|圖片大小與原圖相同，可看出圖片內容，色塊略明顯 |圖片大小與原圖相同，色塊明顯 |
|Comparison Discussion | -- | -- |輪廓處較不明顯，圖片深淺也區分的較粗略 | 圖片顏色大致與灰階圖相近，只是畫質不好，呈現格子狀|試過多種陣列組合，效果還是無法像原陣列一樣好| 

## Learned in this assignment
 * 方法一：學習到將圖片色彩值分級距，依照級距在色塊中打上不相等的黑點。雖然圖片會放大兩倍，但這種最直覺式的方法也能表現出原本的圖片內容。
 * 方法二：這方法非常神奇，將圖案依照陣列裡的數值判斷大小給黑白色，就可以呈現出跟原本內容一樣的圖案，雖然畫質較差。搜尋一下資料，這方法是先量化之後再混色，但陣列裡的值為何這樣擺置，就是經由多次實驗後獲得的結果。此方法不但不會放大圖片大小，也能大致呈現出原圖面貌。
 
 ## Reference
 [課程講義](http://www.elearn.ndhu.edu.tw/moodle/file.php/72180/L2_ImageGraphics_Rep.pdf)

<http://monkeycoding.com/?p=540>

<http://monkeycoding.com/?p=531>

<http://web.nuu.edu.tw/~stgue/DIP/CH03-2.PPT>


# Teacher Comments: 
Excellent work and excellent report. Please submit the link to this repository through the assignment submission link on 東華e學苑。:)
