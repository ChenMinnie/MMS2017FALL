# Assigment 3 report
## Method 1 -- Sequential Search
![sol1](https://user-images.githubusercontent.com/32957934/35378507-05e8829c-01ee-11e8-9e20-0d619c116baa.gif)
## Method 2 -- 2D logarithm search
![sol2](https://user-images.githubusercontent.com/32957934/35378516-0bdb7038-01ee-11e8-8f36-ecf50a21ca0d.gif)
## Result 
### Reference Image
![i2](https://user-images.githubusercontent.com/32957934/35378822-0ff54a8a-01ef-11e8-8d3e-2b4a70bf8ca8.jpg)
### Target Image
![i1](https://user-images.githubusercontent.com/32957934/35378820-0e1e4f2c-01ef-11e8-858e-5a5c29c2228f.jpg)
### Sequential Search
* #### Result Image
![sequential](https://user-images.githubusercontent.com/32957934/35378846-2245077a-01ef-11e8-80ee-e5f151f924f8.jpg)
* #### Speed -- 25sec
* #### SNR   -- 6.99
* [Demo Video](https://drive.google.com/open?id=1LfmeG-TdzEAbdtVgR9viPkM4XXR9AKph)
### 2D logarithm search
* #### Result Image
![twod_logarithm](https://user-images.githubusercontent.com/32957934/35378847-22701f1e-01ef-11e8-9faf-dad82c51df91.jpg)

* #### Speed -- 2sec
* #### SNR   -- 6.99
* [Demo Video](https://drive.google.com/open?id=1XqP8UPraJlG4hrFNwwDuKqoliyvGeqWv)

## Discussions

| Method | Sequential Search | 2D logarithm search |
|-------:|------------------:|--------------------:|
| Image  |![sequential](https://user-images.githubusercontent.com/32957934/35378846-2245077a-01ef-11e8-80ee-e5f151f924f8.jpg) | ![twod_logarithm](https://user-images.githubusercontent.com/32957934/35378847-22701f1e-01ef-11e8-9faf-dad82c51df91.jpg)|
| Speed  | 25sec | 2sec |
|  SNR   | 6.99 | 6.99 |

>#### 1. Image： 方法一的效果較方法二好
>#### 2. Speed： 方法一與方法二的速度差了十幾倍，方法二速度快
>#### 3. SNR：   方法一與方法二的SNR差距極小，取到小數點下第二位後還是相同

## 心得報告
>### 實作方法二時，沒將Taget image要比對的座標固定好，所以出來的結果很奇怪。後來仔細看演算法，發現問題所在，改正問題。 
>### 最常遇到的問題是比較像素質時超出圖片邊界，後來將超過邊界的部分省略後得以解決問題。 
