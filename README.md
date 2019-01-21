# UCAS算法设计作业
卜东波老师的算法课程作业，包括简答题和上机实验题。

简答题包括自然语言描述、伪代码以及时间复杂度分析。
上机题用C++实现，部分采用了c++11标准，代码通过OJ测试。

目前学业较忙，暂且只更新上机题:D  
课程OJ链接:http://theory.ict.ac.cn/grad_oj
## Update
+ **2018.1.21** 网络流OJ题已更新。
+ **2018.1.13** 更新Take-Home Message内容，网络流OJ题待更新～（一周考三科，尼玛要死了
+ **2018.12.21** 更新贪心OJ，更新LP算法OJ。LP算法OJ第二题未AC，且不是用单纯形解决，仅供参考。  
+ **before 2018.12.21** 更新分治递归、动态规划OJ题，全部AC。（懒得去写什么时候上传的了=_=
## Take-Home Message
1. 先观察问题的结构、解的形式，再设计算法;
2. 能分解成子问题，是非常有效的信息;
3. 优化问题时，下界很重要;
4. 给一个问题，从最简单的case入手;
5. 观察INPUT的关键结构，看能否分解、能否combine;
6. 观察OUTPUT，不要坚持追求optimal，适当放松标准追求sub-optimal;
7. 采样！采样！采样！;
8. 手动执行最基本的算法，发现冗余；
9. merge时，考虑引入结构；
10. 离散化;
11. 省内存：分问题的另一种思路;
12. 省时间：Banded DP;
13. 还是optimal和sub-optimal;
14. (老师忘了要说啥了;
15. 子问题的描述方式:  
   a.背包-子集：指数多-{1,2,3,...}前i个：多项式;  
   b.最短路径-子图：指数多-引入新变量表示解：k步;
16. 递归中有at most如何表示？加一个递归项;
17. DP需要空间太多→用神经网络表示函数;
18. 每一个Greedy的背后都有一个more cumbersome DP;
19. weight加强后，有可能不用枚举;
20. 先做一个笨方法，再发现冗余;
21. loose the structure but don't loost it too much;
22. 分析时：一个操作慢，但随后操作快，均摊;
23. 求和：每一项转乘phi的差，相约;
24. 要允许剪枝，但不要剪太多→不要偏离完美的树太远;
25. 抽象，就能推广;
26. 写LP时，先写自然语言，再转成不等式约束;
27. 不要只用不等式约束，再加上目标函数约束;
28. Lagrange乘子就是对偶变量;
29. 千方百计构造一个对手出来
30. 构造对手:  
   a.y 直接构造 x;  
   b.找一个隐含变量B，同时构造x和y;
31. 目标:
   ![original](https://github.com/9kalikali/Algorithm_Course/blob/master/Others/CodeCogsEqn1.png)  
   Releaxed!
   ![releaxed](https://github.com/9kalikali/Algorithm_Course/blob/master/Others/CodeCogsEqn2.png)
32. 还是optimal和Sub-Optimal;
33. Scaling;
34. 分析一个event的发生次数：找一个量\Phi，考察连续两次event中间发生了什么;
35. 既然已经花了很多时间，索性把opt的所有油水全榨干。
## Code Tips
1. 当问题规模比较大时，采用cin接收输入会比较耗时。  
   解决方法：a. 换成 `scanf` ; b. 用 `std::ios::sync_with_stdio(false)` 提升cin效率;
2. 学会选择合适的数据结构，如优先队列、双端队列等
3. 线性规划可用GLPK、matlab等工具解决；原问题不好解决找其对偶
4. 程序写的6不如板子找的好（胡说八道
