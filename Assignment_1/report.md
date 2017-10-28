# Assigment 1 report
## Testing results
|| Origin image | Gray image | Method one  | Method two | Method two test |
| ------------ |:----------:| -----------:|-----------:|----------------:|----------------:|
|Show image|![lena256](https://user-images.githubusercontent.com/32957934/32135775-39c2a27a-bc37-11e7-8e96-9c031129eed6.jpg)|![gray image](https://user-images.githubusercontent.com/32957934/32135789-3fdded72-bc37-11e7-94ef-958c12dd1591.jpg)|![method one](https://user-images.githubusercontent.com/32957934/32135790-439547da-bc37-11e7-92ee-5b8ffeb35d3a.jpg)|![method two](https://user-images.githubusercontent.com/32957934/32135792-47550112-bc37-11e7-9e58-1ff40edff107.jpg)|![method two test](https://user-images.githubusercontent.com/32957934/32135795-4a8aa86e-bc37-11e7-9fa1-2216722bba41.jpg)|
|Method | 使用256*256彩色圖| 用 (R+G+B)/3 來產生灰階圖 |將讀取到的圖片依級距處理，分別點上相對應的黑點數|依照陣列判斷相對位置的值 |依照陣列判斷相對位置的值|
|Result Discussion | -- | -- |圖片放大兩倍，大致可看出圖片的內容，明亮處多為白色，陰暗處多為黑色|圖片大小與原圖相同，可看出圖片內容，色塊略明顯 |圖片大小與原圖相同，色塊明顯 |
|Comparison Discussion | | |輪廓處較不明顯，圖片深淺也區分的較粗略 | 圖片顏色大致與灰階圖相近，只是畫質不好，呈現格子狀|試過多種陣列組合，效果還是無法像原陣列一樣好| 


