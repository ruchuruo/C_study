/*
	Lesson4--栈和队列

		本节目标
			1. 栈
			2. 队列
			3. 栈和队列面试题

		======== ======== ======== ======== ======== ======== ========
		-------- -------- -------- -------- -------- -------- --------

		1. 栈

			1.1栈的概念及结构

				栈：一种特殊的线性表，其只允许在固定的一端进行插入和删除元素操作。
				进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。
				栈中的数据元素遵守后进先出LIFO（Last In First Out）的原则。

				压栈：栈的插入操作叫做进栈/压栈/入栈，入数据在栈顶。
				出栈：栈的删除操作叫做出栈。出数据也在栈顶。

				进栈
					  ↓          
					 [a]         
					|   |        |   |
					|   |        |[a]| 栈顶
					|[ ]|        |[ ]|
					|[ ]|        |[ ]| 栈底
					|---|        |---|

				出栈
					  ↑
					  ↑
					| ↑ |        |   |
					|[a]|        |   |
					|[ ]|        |[ ]| 栈顶
					|[ ]|        |[ ]| 栈底
					|---|        |---|

				数组栈
					[ ][ ][ ][ ][ ]

				链式栈
					[ ] → [ ] → [ ] → [ ] → [ ]

					如果用尾做栈顶，尾插尾删，要设计成双向链表，否则删除节点效率低。
					如果用头做栈顶，头插头删，单链表即可。


			1.2栈的实现

				栈的实现一般可以使用数组或者链表实现，相对而言数组的结构实现更优一些。因为数组在尾上插入数据的代价比较小。




		-------- -------- -------- -------- -------- -------- --------

		2. 队列
			
			2.1队列的概念及结构

				队列：只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表，
				队列具有先进先出 FIFO(First In First Out) 
				
				入队列：进行插入操作的一端称为队尾 
				出队列：进行删除操作的一端称为队头

				      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				出队 ←                                ← 入队
				      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
					  ↑                              ↑
					  队头                         队尾


			2.2队列的实现

				队列也可以数组和链表的结构实现，使用链表的结构实现更优一些，
				因为如果使用数组的结构，出队列在数组头上出数据，效率会比较低。


			抽号机

				抽号机里有一个队列，假设里面存放着 1 到 99 号，
				有3个窗口 A，B，C，

				A 按下按钮 从队列里取出 1 号，为 1 号服务
				B 按下按钮 从队列里取出 2 号，为 2 号服务
				C 按下按钮 从队列里取出 3 号，3 号没来
				C 按下按钮 从队列里取出 4 号，为 4 号服务

				保证公平性，先来先服务

				如果有两个及以上的窗口同时按下按钮，会同时 从队列里取出 5 号，

				涉及到 并发，加锁，互斥锁
				操作系统这门课会提到 互斥 和 同步

				这个例子本质上也叫做 生产者消费者模型


			循环队列

				另外扩展了解一下，实际中我们有时还会使用一种队列叫循环队列。
				如操作系统课程讲解生产者消费者模型时可以就会使用循环队列。
				环形队列可以使用数组实现，也可以使用循环链表实现。

							→
						[ ][ ][ ]
					 [ ]         [ ] ← 队列尾
					↑[ ]         [ ]↓
					 [ ]         [ ] ← 队列头
						[ ][ ][ ]
							←

				空的循环队列
							→
						[ ][ ][ ]
					 [ ]         [ ] ← 队列尾 ← 队列头
					↑[ ]         [ ]↓
					 [ ]         [ ]
						[ ][ ][ ]
							←

				满的循环队列
							→
						[i][j][k]
					 [h]         [ ] ← 队列尾
					↑[g]         [a] ← 队列头
					 [f]         [b]
						[e][d][c]
							←

				为了能使用 队列.头 = 队列.尾 来区别是空还是满，
				我们常常认为出现 上图 时的情况即为队满，
				此时 尾+1 = 头

				重点
					循环队列，无论使用数组实现还是链表实现，都要多开一个空间，
					要存k个数据的循环队列，要开k+1个空间，否则无法实现判空和判满。

					数组 循环队列 满：(尾+1)%(k+1) == 头
					链表 循环队列 满：尾->next == 头


			队列的应用

				树的层次遍历

					|                [1]
					|               ↙ ↘
					|             ↙     ↘
					|           ↙         ↘
					|        [2]            [3]
					|       ↙ ↘          ↙ ↘
					|     ↙     ↘      ↙     ↘
					|    [4]     [5]    [6]     [7]
					|           ↙ ↘          ↙ ↘
					|        [8]     [9]   [10]     [11]


					创建队列

						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ←                                ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|      ↑                              ↑
						|      队头                         队尾

					将根节点 [1] 入队

						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1]                            ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					将 [1] 节点的左右孩子 [2] [3] 放到队尾

						|      ~~↓~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3]                    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[1] 节点出队

						|      ~~×~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3]                    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					将 [2] 节点的左右孩子 [4] [5] 放到队尾

						|      ~~×~~~↓~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5]            ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[2] 节点出队

						|      ~~×~~~×~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5]            ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					将 [3] 节点的左右孩子 [6] [7] 放到队尾

						|      ~~×~~~×~~~↓~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7]    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[3] 节点出队

						|      ~~×~~~×~~~×~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7]    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[4] 节点没有孩子，直接出队

						|      ~~×~~~×~~~×~~~×~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7]    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					将 [5] 节点的左右孩子 [8] [9] 放到队尾

						|      ~~×~~~×~~~×~~~×~~~↓~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7] [8] [9] ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[5] 节点出队

						|      ~~×~~~×~~~×~~~×~~~×~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7] [8] [9] ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[6] 节点没有孩子，直接出队

						|      ~~×~~~×~~~×~~~×~~~×~~~×~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7] [8] [9] ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					将 [7] 节点的左右孩子 [10] [11] 放到队尾

						|      ~~×~~~×~~~×~~~×~~~×~~~×~~~↓~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[7] 节点出队

						|      ~~×~~~×~~~×~~~×~~~×~~~×~~~×~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


				图的广度优先遍历

					|    [2]→←[1]  [6]→←[8]
					|     ↓    ↓  ↙↓  ↙↓
					|     ↑    ↑↗  ↑↗  ↑
					|    [4]  [3]→←[5]→←[7]


					创建队列

						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ←                                ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|      ↑                              ↑
						|      队头                         队尾

					将节点 [1] 入队

						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1]                            ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					检查节点 [1] 相邻的节点 [2] [3] 是否被遍历过
					节点 [1] 相邻的节点 [2] [3] 没有被遍历过
					节点 [2] [3] 入队

						|      ~~↓~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3]                    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[1] 节点出队

						|      ~~×~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3]                    ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					检查节点 [2] 相邻的节点 [1] [4] 是否被遍历过
					节点 [2] 相邻的节点 [4] 没有被遍历过
					节点 [4] 入队

						|      ~~×~~~↓~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4]                ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[2] 节点出队

						|      ~~×~~~×~~~~~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4]                ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					检查节点 [3] 相邻的节点 [1] [5] [6] 是否被遍历过
					节点 [2] 相邻的节点 [5] [6] 没有被遍历过
					节点 [5] [6] 入队

						|      ~~×~~~×~~~↓~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6]        ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					[3] 节点出队

						|      ~~×~~~×~~~×~~~~~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6]        ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					检查节点 [4] 相邻的节点 [2] 是否被遍历过
					节点 [4] 相邻的节点 [2] 被遍历过
					[4] 节点出队

						|      ~~×~~~×~~~×~~~×~~~~~~~~~~~~~~~~~
						|出队 ← [1] [2] [3] [4] [5] [6]        ← 入队
						|      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


				操作系统中的应用

					多个进程争抢着使用有限的系统资源时，FCFS(first come first service，先来先服务)
					是一种常用策略。

		-------- -------- -------- -------- -------- -------- --------
		
		3. 栈和队列面试题

			1. 括号匹配问题。https://leetcode.cn/problems/valid-parentheses/
			2. 用队列实现栈。https://leetcode.cn/problems/implement-stack-using-queues/
			3. 用栈实现队列。https://leetcode.cn/problems/implement-queue-using-stacks/
			4. 设计循环队列。https://leetcode.cn/problems/design-circular-queue/

		-------- -------- -------- -------- -------- -------- --------

		栈：喝多了吐
		队列：吃多了拉

		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========
*/
/*
	======== ======== ======== ======== ======== ======== ========
	-------- -------- -------- -------- -------- -------- --------


*/