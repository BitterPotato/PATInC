### 用C/ C++刷PAT所需要知道的

#### 字符串
涉及头文件
	#include<string> // 引入string
	#include<string.h> // strXXX()等方法

字符串输出
	printf("%s", str.c_str());
> string.c_str()，返回一个const char的指针

将输出暂存在字符串中
	char temp[string_size];
	sprintf(temp, "xxx", para_1, …);

判断字符串是否为空
	s.length() == 0 //s为string
	strlen(s) == 0 //s为char[]的char*

[char指针与char数组的区别](http://blog.csdn.net/johnny710vip/article/details/6725637)

char*  `cstr`与string `str`相互转换
	1. char* cstr = str.c_str();
	2. str = cstr;

> 方法的形参与返回类型尽量使用string

字符串复制
strcpy()
> 深复制字符串，在字符串运算中的作用等价于赋值运算符

若printf("%s", str)行不通
> str为char *,则可通过以下代码输出字符串
	while(*str != '\0') {
	  putchar(*str);
	  str++;
	}

#### math
涉及头文件
	#include <math.h>

绝对值
	abs(int_val)
	labs(long_val)
	llabs(long long_val)
开方
	sqrt(int_val)
平方
	pow(int_val, expo)

#### 输入输出

| 类型        | 占位符  |
| --------- | ---- |
| long      | %ld  |
| long long | %lld |
| float     | %f   |
| double    | %lf  |
| char      | %c   |
| string    | %s   |

读取一行字符串
	#include <iostream>
	string s;
	getline(cin, s);
> 注意：getline的第一次调用必定读取无用的“”，得从第二次getline开始处理

格式化输出
	%05d
> 占用宽度为5，空白用0填充

空格或者换行的简易输出
	printf("%d%c", num, i!=n-1?' ':'\n');

#### 结构体
声明
	struct struct_name{
		…
	} ;

struct数组
	struct struct_name array_name[array_size]

struct实例
	struct struct_name var_name;

赋初值
	struct node {
		int val;
		int next=-2;
	};
	struct node nodes[100000];
> 若已赋初值，那么之后只能使用nodes[?].val来修改赋值，而不能重新通过nodes[?]={?, ? }重新赋予结构体实例

使用结构体可不用struct关键则
	struct Node{
		Node* left;
		Node(Node* ileft) {
	  		ileft = left;
		}
	};
	Node* left = NULL;
	if(left != NULL)
		Node* node = new Node(left);
	node->left = left;

#### 基本数据结构
##### set
涉及头文件
	#include<set>

基本使用
	set<XX> set_name;
	set_name.insert(key);
	set_name.erase(key);
	set_name.find(key) == set_name.end();
	set_name.size()

set默认从小到大排序，可使用如下语句声明默认从大到小排序的set
	#include <functional>
	set<int, greater<int> > ss;

multiset是可包含重复元素的set

##### vector
涉及头文件
	#include<vector>

基本使用
	vector<element> a;	
	a.push_back(element);
	a.erase(pos);
	a.insert(pos, element);
	a.resize(num);
	a.begin();/a.end();
	a.clear();
	
	// 下标访问
	a[pos_int]
	// 迭代器迭代
	for(vector<element>::iterator it = a.begin(); it!=a.end(); it++)
		printf("?", *it);

队列用法
	vec.push_back(element);
	element = vec.front();
	vec.erase(vec.begin());

栈用法
	a.push_back(element);
	element = a.back();
	a.pop_back();

全局使用
	vector<int> v;
		scanf("%d", &n);
		v.resize(n);

二维vector
	vector<vector<discost> > graph;
	graph.resize(n);
	for(int i=0; i<n; i++) {
	    graph[i].resize(n);
	}
	graph[x][y].dis = ...

选择
如果涉及到某个array的不断缩小，可以考虑使用队列

##### map
[参考链接](http://mropengate.blogspot.com/2015/12/cc-map-stl.html)
map的key不能使用指针

##### stack
[参考链接](http://blog.csdn.net/wallwind/article/details/6858634)

#### 常用代码段/ 方法
##### 求最大公约数
	long divisor(long a, long b) {
		a = a>0?a:-a;
		b = b>0?b:-b;
	
		long c = a % b;
		if(c == 0)
	    	return b;
		return divisor(b, c);
	}

##### 排序
涉及头文件
	#include<algorithm>

两个参数
	sort(begin, end); (end不包含)

	数组用法：sort(&narr[0], &narr[size]);
	或者sort(narr, narr+size);
	
	vector用法
	sort(vec.begin(), vec.end());

三个参数
	para_3 为 比较函数
	// 从小到大排
	bool mycmp(int a, int b) {
	  return a-b < 0;
	}

#### 常见错误
1. 将数组[i][j]写成[i, j]
2. 把!=map.end()写成<map.end()
3. 有时候出错的不是题目的边界，而是自己代码的边界
4. 若使用char的指针读入字符串，那么必须声明该数组大小（大小比字符串长度+1，需要给\0腾位置）
   可直接将char* push到string数组中
5. &与*是否使用正确
6. 数组大小声明得不正确，比如想着n+1却声明成n
7. segmentation faults段错误
> 访问的内存超出了合法的内存空间，一般为数组越界


#### 超时处理
1. 将邻接矩阵换成邻接表
2. 能否将set的使用换成标志位的使用，特别是在复杂度相乘的时候
3. 特别地，如果是一道关于字符串的题，可能输入没有换行符，此时通过换行符判断输入终止会超时。这时候，需要直接读入字符串，并根据字符串的大小循环

#### 方法论
1. 预先设计测试用例，书写较为详尽的伪代码
2. 当所使用的方法有错误的时候，不要急于在代码上修改，先对伪代码进行修改、检查
3. 太过于想当然的地方其实都有待商榷

#### 考试心得
1. 必须首先熟悉机房电脑的程序编译调试环境以及机房，很重要！！！说出来你可能不信，第一次考PAT时，VS 2008无法解析namespace std，大小不是常量的数组无法通过编译；MyEclipse没有被激活；不小心踩到电源线导致电脑重启。
2. 看清题意！看清题意！！看清题意！！！尤其是在时间所剩不多的时候更应如此！！！！

#### 常备头文件
	#include<stdio.h>
	#include<stdlib.h>