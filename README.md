# PATInC
A Big Nerd Doing PAT [it seems a little hard to be accepted by using java, so ...]

---
#### [1076_Forwards on Weibo](https://www.patest.cn/contests/pat-a-practise/1076)
解题思路：
1. 构建表示图，注意输入的数据是反向的
2. 构造level和每个顶点的访问标识 —>  BFS
3. 累加限定level内的访问节点个数

避免超时：
> 最后一个测试用例可能超时
1. 将邻接矩阵换做邻接表
2. 一开始我使用set存储各个顶点是否访问的信息，若使用邻接表则复杂度为Elog(V)；若对各个顶点设置访问标识，则复杂度降为E

About：BFS

---
#### ~~[1079_Total Sales of Supply Chain](https://www.patest.cn/contests/pat-a-practise/1079)~~
解题思路：
1. 构建表示图
2. 构造level —>  BFS
3. 当访问到叶子节点时累加该retailer的sales

About：BFS