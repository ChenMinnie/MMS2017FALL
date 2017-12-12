# Assigment 2 report
## Musical Notes Format
### 1.音調格式
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | -  |
|--:|--:|--:|--:|--:|--:|--:|---:|
| C | D | E | F | G | A | B | 無聲一拍 |

### 2.節拍格式
| (　拍數　) |
|--:|
## Flowchart Of Program
![flowchat](https://user-images.githubusercontent.com/32957934/33895570-c1b4d7fc-df9b-11e7-9242-0874a6d93162.JPG)

## The Way To Set Up And Run Program

#### 1.讀取檔案
#### 2.找尋檔案數字相對的頻率
#### 3.將數值代入 "x(t) = Asin(2πft)" 公式， Fs = 8000, A =100
#### 4.輸出 .WAV 檔
#### 5.抓取使用者選取變音頻率值 f 
#### 6.將輸出的 .WAV檔 乘上 cos(2πft)，再輸出 .WAV 檔
#### 7.讀取 .WAV 檔並播放或停止

## Demonstrate The Results
### GUI
![demonstrate](https://user-images.githubusercontent.com/32957934/33895585-c9e79b4e-df9b-11e7-83b4-357546d9d155.JPG)

### 功能

#### 1.自行輸入簡譜
![demonstrate1](https://user-images.githubusercontent.com/32957934/33895610-d7373e94-df9b-11e7-8873-4f47c276c9a3.jpg)

#### 2.選擇範例簡譜
![demonstrate2](https://user-images.githubusercontent.com/32957934/33895613-d9d732b2-df9b-11e7-8793-43e2c8e584d2.jpg)

#### 3.清除輸入
![demonstrate3](https://user-images.githubusercontent.com/32957934/33895615-db5df3a0-df9b-11e7-83ef-63ada361177f.jpg)

#### 4.建造音檔
![demonstrate4](https://user-images.githubusercontent.com/32957934/33895619-dc6a214c-df9b-11e7-8f4d-c12d1cb62788.jpg)

#### 5.選擇變音頻率
![demonstrate5](https://user-images.githubusercontent.com/32957934/33895621-dda8a2f4-df9b-11e7-881d-12fb8ef774bd.jpg)

#### 5.播放與停止
![demonstrate6](https://user-images.githubusercontent.com/32957934/33895627-df248a4e-df9b-11e7-8259-d42efc396123.jpg)

### Sound
#### 1. 小蜜蜂 ( 正常 )
##### * [音檔](https://drive.google.com/open?id=195PZ8T0GqHlQkM2bbgeGmO2jij5qkDSg)
##### * 頻譜圖
![beenormal](https://user-images.githubusercontent.com/32957934/33895719-170928f2-df9c-11e7-9af3-9b3f353f52b8.JPG)

#### 2. 小蜜蜂 ( f = 100 )
##### * [音檔](https://drive.google.com/open?id=1cAMux1iyLW3vPiVwn00eEOUkKoV39_7o)
##### * 頻譜圖
![bee100](https://user-images.githubusercontent.com/32957934/33895718-16dda5ba-df9c-11e7-94cc-b104787d9878.JPG)

#### 3. 小星星 ( 正常 )
##### * [音檔](https://drive.google.com/open?id=1RMhHTgZEVOSCyl2q0W13ryfOtBmIGJEr)
##### * 頻譜圖
![starnormal](https://user-images.githubusercontent.com/32957934/33895667-f8f52bea-df9b-11e7-9dad-09189aee201a.JPG)

#### 4. 小星星 ( f = 500 )
##### * [音檔](https://drive.google.com/open?id=1TFNMC3YA6Ni8oMXolNJA7V4RdMFGvFMb)
##### * 頻譜圖
![star500](https://user-images.githubusercontent.com/32957934/33895666-f8c8cbc2-df9b-11e7-96ab-320d3031576c.JPG)



#### 5. 王先生有塊地 ( 正常 )
##### * [音檔](https://drive.google.com/open?id=1d64va2x1DX5uIwXFGjTDcZKxKoHCVHz0)
##### * 頻譜圖
![sirnormal](https://user-images.githubusercontent.com/32957934/33895665-f89d3746-df9b-11e7-8d80-9854007ac2dc.JPG)

#### 6. 王先生有塊地 ( f = 800 )
##### * [音檔](https://drive.google.com/open?id=1VQjmflxfosjK9d_zHLDJ9YLKHivZUfoJ)
##### * 頻譜圖
![sir800](https://user-images.githubusercontent.com/32957934/33895664-f870d868-df9b-11e7-919c-13c1e1931f28.JPG)

### Demo Video
[Video](https://drive.google.com/open?id=11omIr6nRdzMHa2XksV20qG3Y_0CHwF7m)
## Problem And Solve

### 1.產生出無效的 .WAV檔 
#### Sol:複製現成.WAV檔的數值後可以播放。問題出在.WAV檔的數值，後來轉成Byte來存取
### 2.爆音問題 
#### Sol:音量值(A)給太大，將值改小就解決了
### 3.乘cos(2πft)時發生音調沒變及空間不足 
#### Sol:這個問題卡在t這個地方，一開始以為前面的檔案已經有乘過t了所以這邊就沒有乘，結果發生音調沒變的問題，cos(2π * 100)就是 1 所以沒變是當然的 。後來知道要把t乘進去，但前面的音檔每個音已經產生4000個點，現在又從一個音4000個點的一個點取值在乘上4000，這樣當然空間會不足。後然將t跑整串音檔的長度才比較正常，不過我還是不確定是否正確。

## Discussions
### 音訊乘上cos(2πft)之後，音高會變高，而且音調不是全音，會有升降半音的感覺。
### 從頻譜圖觀察，變音後的頻譜圖上下震動變小，且波型較稀疏。

## What I Have Learned
### 1. 音訊處理 
### 2. 如何產生 .WAV檔
### 3. 各種InputStream與OutputStream使用
### 4. JavaFx
