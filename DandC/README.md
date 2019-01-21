# 分治与递归作业
## OJ题目
**A. The kth number**  
Find the kth largest element in an unsorted array A . Note that it is the kth largest element in the sorted order, not the kth distinct element. The range of length of A is N(1≤N≤5,000,000) and the element (integer) in A is no bigger than 10,000,00000.  
**Input**  
Line 1: the length of the unsorted array A and the index k.  
Line 2: the all elements in array A and split by spaces.  
**Output**  
Line 1: A single integer that is the kth largest element in an unsorted array A.  
**Sample Input&Output**  
```
8 2
1 3 5 7 4 2 6 8
```  
`7`  
### 解题思路  
&emsp;&emsp;第k选择问题，利用快速排序中的pivot方法，选定一个元素作为基准，将小于它的元素放在它前面，大于它的放在它之后。如果此时得到的pivot恰好为**k-1**那么便已经找到了第k大的数。如果pivot<k-1那么应该在pivot的右侧找寻第k - pivot大的数， 反之要在其左侧找第k大的数。  
&emsp;&emsp;当然在面对规模比较大的问题时上述方法可能会耗时较长，所以出现了上述方法的一种改进方法，将整个数组分割为许多小块（5个一组）找寻他们的(编辑中。。。  
&emsp;&emsp;此外还有第三种方法，就是利用采样的方式，整体数组比较大， 我们从中随机选取一部分元素组成一个新的数组，找出新数组的第k大元素，通过一些转换便可以得到原数组的第k大数，这也是上方代码中所实现的方法. 

------
**B. Minimum distance**  
Given N(2<=N<=100,000) points on the plane, find the nearest two points, print the minimum distance.  
**Input**  
Line 1: an integer N, stands for the total number of points.  
N lines follow: each line contains a pair of (x, y) which are the coordinates of a point and splited by spaces, each value is no bigger than 1,000,000,000.  
**Output**  
Line1: the minimum distance, accurate up to 2 decimal places.  
**Sample Input&Output**  
```
3
0 1
-1 1
-1 0
```  
`1`  
### 解题思路
&emsp;&emsp;最接近点对问题，先从简单的情况考虑：  
&emsp;&emsp;1.如果平面上只有两个点，他们的距离一定是最短的；  
&emsp;&emsp;2.如果平面上有三个点， 那么计算三者之间的距离，返回最短的即可。  
&emsp;&emsp;如果是平面上有多于3个的点，首先将所有点按照横轴（x轴）排序，对其不断分割至两个点计算其距离，因为是二分，所以我们会得到最左边两点距离和最右边两点距离。取其最小值δ作为条带的范围，所谓的条带，指的是以分割线为中心向左右扩展δ的范围。在这个范围内找寻是否有距离更近的两个点，当然，我们可以进一步缩小范围，（编辑中。。。。
