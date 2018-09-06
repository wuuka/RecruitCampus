# 1 菜鸟教程 c++  http://www.runoob.com/cplusplus/cpp-polymorphism.html
# 2 计算感受野 https://fomoro.com/tools/receptive-fields/#3,2,1,VALID;2,2,1,VALID;3,1,1,VALID;2,2,1,VALID;3,1,1,VALID;3,1,1,VALID;3,2,1,VALID;3,2,1,VALID;3,2,1,SAME;3,2,1,SAME;3,2,1,SAME

# RecruitCampus 2018/4/8
Major companies online programming training.
练习在线编程题
c++/g++/linux

# offer文件

剑指offer面试编程题


# 001
【构造回文】     [腾讯编程题]：http://blog.csdn.net/sinat_35512245/article/details/53675660

给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。

学到：
在memset函数在c++中头文件用<cstring>,以及字符串翻转函数reverse()，对于两两比较的函数可以使用一个差矩阵进行调整。


# 002
【字符移位】     [腾讯编程题] 算法基础：http://blog.csdn.net/xubinlxb/article/details/52432291

小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。你能帮帮小Q吗？
输入描述:输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.

学到：
掌握数据结构才能在编写算法中灵活应用，减少工作量。

# 003
【混合颜色（异或）】   //http://blog.csdn.net/huzhigenlaohu/article/details/52264154
//https://www.nowcoder.com/profile/7109426/codeBookDetail?submissionId=15604075

你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，我们用正整数表示不同颜色的颜料。你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,XOR表示异或操作)。本着勤俭节约的精神，你想购买更少的颜料就满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？

# 004
【二叉搜索树与双向链表】      //http://blog.csdn.net/zengzhen_csdn/article/details/51198530

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

# 005
【数字串转换的最少步骤】     阿里面试在线编程：http://blog.csdn.net/libin_vincent/article/details/79601786

给定两个长度为 n ( 0 < n <= 8 ) 的 数字串 (由1到9构成)  ，我们希望对第一个数字串做一系列如下操作：
1、将数字串的某一位加1
2、将数字串的某一位减1
3、交换数字串中任意两个数字的位置
最终使得第一个数字串变成第二个数字串， 请问最少需要多少操作。

学到：
针对情况比较多的算法编写，一定要转换到一种思想上，才能不至于漏掉一些其他情况。

# 006
【A-Z子集遍历】     腾讯编程 http://blog.csdn.net/sinat_30071459/article/details/72867136

集合是由大字字母（A-Z）组成的，要求输出集合的所有子集，每个子集一行，不能使用递归。

学到：
有时候灵活的技巧可以节省很多行代码？

# 007
【递归函数的案例】     https://blog.csdn.net/sinat_38052999/article/details/73303111

学到：
‘人用迭代，神用递归’。递归方法的三要素：明确递归终止条件；递归终止的处理方法；提取重复的逻辑，缩小问题的规模。

# 008
【两点之间路径个数】  

# 009
【指针和引用的区别】     //https://blog.csdn.net/qq_27678917/article/details/70224813

# 010
【买帽子】     https://www.cnblogs.com/omelet/p/6798358.html

//度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？ 
//输入描述:首先输入一个正整数N（N<=50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）
//输出描述:如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1

# 011
//字符串循环

# 012
【关联信息排序】     网易笔试链接：https://www.nowcoder.com/questionTerminal/46e837a4ea9144f5ad2021658cb54c4d

为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。 

学到：
关联信息排序可以用结构体和关联容器，map的用法。

# 013
【模板用法】     https://blog.csdn.net/qq_35637562/article/details/55194097

# 014
将一个数分解出最小奇数和最小偶数项

# 015
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
