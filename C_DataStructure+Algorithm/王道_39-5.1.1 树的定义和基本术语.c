
/*
	第五章 树与二叉树

		知识总览

			树
				基本概念
					结点、边、根结点、叶子结点、分支结点、子树

				基本术语

					结点之间的关系描述
						父结点(双亲结点)、孩子结点
						祖先结点、子孙结点
						兄弟结点、堂兄弟结点
						结点之间的路径————只能从上往下
						路径长度————路径上经过多少条边

					结点、树的属性描述
						结点的层次(深度)、结点的高度
						树的深度(高度)
						结点的度
							结点的分支数

						数的度
							树中各结点的度的最大值

					有序树、无序树
						逻辑上看，各子树是否有序，位置是否可以互换

					森林
						由m（m≥0）棵互不相交的树的集合。


		树的基本概念

			树：从树根生长，逐级分支

			|                     根结点    边           分支结点      叶子结点
			|                       ↓       ↓             ↙            ↙
			|           +-----------A----------------+  ↙            ↙
			|           |           |                |↙            ↙
			|      +----B----+      C      +---------D---------+  ↙
			|      |         |      |      |         |         |↙
			|   +--E--+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M

			空树：结点数为0的树。

			非空树的特性：
				有且仅有一个根节点
				没有后继的结点称为“叶子结点”（或终端结点）
				有后继的结点称为“分支结点”（或非终端结点）
				除了根节点外，任何一个结点都有且仅有一个前驱
				每个结点可以有0个或多个后继。

				|   这种属于 图 或 网，因为结点有多个前驱
				|           +
				|           |
				|      +----B----+
				|      |         |
				|   +--E--+------F
				|   |     |
				|   K     L

			树是n（n≥0）个结点的有限集合，n = 0时，称为空树，这是一种特殊情况。
			在任意一棵非空树中应满足：
				1）有且仅有一个特定的称为根的结点。
				2）当n > 1时，其余结点可分为m（m > 0）个互不相交的有限集合T1, T2,…, Tm，其中每个集合本身又是一棵树，并且称为根结点的子树。

			树是一种递归定义的数据结构


		树形逻辑结构的应用

			中国
				陕西
					西安
					渭南市
					......
				山东
					烟台
					青岛
					......
				云南
					昆明
					大理
					......
				......

			E:
				电影
					*.avi
					xxx.avi
				学习资料
					xxx.ppt


		结点之间的关系描述

			|           +----------爷爷--------------+
			|           |           |                |
			|      +---父亲--+     二叔    +--------三叔--------+
			|      |         |      |      |         |         |
			|   +--你-+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M

			什么是祖先结点？
				从一个结点出发，一直往上，直到走到根结点为止，路径上所经过的结点都是 祖先结点。

			什么是子孙结点？
				从一个结点出发，它的分支下面的都是 子孙结点。

			什么是双亲结点（父结点）？
				一个结点的直接前驱就是 父结点。
			
			什么是孩子结点？
				一个结点的直接后继就是 孩子结点

			什么是兄弟结点？
				一个爹生的都是 兄弟结点。

			什么是堂兄弟结点？
				同层结点，但不是同个前驱的就是 堂兄弟结点。

			什么是两个结点之间的路径？(只能从上往下)
				爷爷到你需要经过父亲。

			什么是路径长度？
				经过几条边。


		结点、树的属性描述

			|                                             非叶子结点的度 > 0
			|                                             ↙
			|           +-----------A----------------+  ↙
			|           |           |                |↙
			|      +----B----+      C      +---------D---------+
			|      |         |      |      |         |         |
			|   +--E--+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M
			|                                ↖
			|                                叶子结点的度 = 0

			属性：
				结点的层次（深度）——从上往下数(默认从1开始)
				结点的高度——从下往上数
				树的高度（深度）——总共多少层
				结点的度——有几个孩子（分支）
				树的度——各结点的度的最大值


		有序树 V.S 无序树

			有序树——逻辑上看，树中结点的各子树从左至右是有次序的，不能互换。
			无序树——逻辑上看，树中结点的各子树从左至右是无次序的，可以互换。

			具体看你用树存什么，是否需要用结点的左右位置反映某些逻辑关系。

			|   有序树
			|
			|           +----------爷爷--------------+
			|           |           |                |
			|      +---父亲--+     二叔    +--------三叔--------+
			|      |         |      |      |         |         |
			|   +--你-+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M

			|   无序树
			|
			|   中国
			|   	陕西
			|   		西安
			|   		渭南市
			|   		......
			|   	山东
			|   		烟台
			|   		青岛
			|   		......
			|   	云南
			|   		昆明
			|   		大理
			|   		......
			|   	......


		树 V.S 森林

			森林。森林是m（m≥0）棵互不相交的树的集合。
				(m可为0，空森林)

			|   森林
			|
			|      +----B----+      C      +---------D---------+
			|      |         |      |      |         |         |
			|   +--E--+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M

			|   树
			|
			|           +-----------A----------------+
			|           |           |                |
			|      +----B----+      C      +---------D---------+
			|      |         |      |      |         |         |
			|   +--E--+      F      G      H         I         J
			|   |     |                    |
			|   K     L                    M

			什么时候会用到森林这种数据结构？
				eg：全中国所有人家的家谱。
*/