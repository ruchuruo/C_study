/*
	Lesson3--顺序表和链表

		本节目标
			1. 线性表
			2. 顺序表
			3. 链表
			4. 顺序表和链表的区别和联系

		======== ======== ======== ======== ======== ======== ========
		-------- -------- -------- -------- -------- -------- --------

		1. 线性表

			线性表（linear list）是n个具有相同特性的数据元素的有限序列。
			线性表是一种在实际中广泛使用的数据结构，常见的线性表：顺序表、链表、栈、队列、字符串...

			线性表在逻辑上是线性结构，也就说是连续的一条直线。但是在物理结构上并不一定是连续的，
			线性表在物理上存储时，通常以数组和链式结构的形式存储。

			顺序表
				[1][2][3][4][5][6][7]
					

			链表
				|data|   →|data|   →|data|   →|data|
				|----| ↗ |----| ↗ |----| ↗ |----|
				|next|→   |next|→   |next|→   |next|

				[data]
				[next] → [data]
						 [next] → [data]
								  [next] → [data]
										   [next]

		-------- -------- -------- -------- -------- -------- --------

		2. 顺序表

			2.1概念及结构

				顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。
				在数组上完成数据的增删查改。
				(顺序表就是数组，但是在数组的基础上，要求数据 从头开始 连续存储，不能跳跃间隔)

				顺序表一般可以分为：
					1. 静态顺序表：使用定长数组存储。

						// 顺序表的静态存储
						#define N 7
						typedef int SLDataType;

						typedef struct SeqList
						{
							SLDataType array[N];	// 定长数组
							size_t size;			// 有效数据的个数
						}SeqList;


						array       size    N
						↓             ↓     ↓
						[0][1][2][3][4][ ][ ]


					2. 动态顺序表：使用动态开辟的数组存储。

						// 顺序表的动态存储
						typedef struct SeqList
						{
							SLDataType* array;		// 指向动态开辟的数组
							size_t size;			// 有效数据个数
							size_t capacity;		// 容量空间的大小
						}SeqList;


						array       size    capacity
						↓             ↓     ↓
						[0][1][2][3][4][ ][ ] => 空间不够则增容


			2.2 接口实现：

				静态顺序表只适用于确定知道需要存多少数据的场景。
				静态顺序表的定长数组导致N定大了，空间开多了浪费，开少了不够用。
				所以现实中基本都是使用动态顺序表，根据需要动态的分配空间大小，
				所以下面我们实现动态顺序表。


			2.3 数组相关面试题

				1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。https://leetcode.cn/problems/remove-element/
				2. 删除排序数组中的重复项。https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
				3. 合并两个有序数组。https://leetcode.cn/problems/merge-sorted-array/


			OJ分类和原理
				Online Judge

				1. IO型
					需要直接写头文件，函数......
					测试用例：要用 scanf 获取
					结果：printf输出

				2. 接口型
					只给了函数，需要实现函数
					测试用例：通过参数传过来
					结果：一般通过返回值拿，或是输出型参数

					int* singleNumbers(int* nums, int numsSize, int* returnSize);
																	 输出型参数


			演示&讲解
				顺序表_静态();
				顺序表_动态();
				顺序表_接口实现();
				顺序表_接口实现_使用();
				顺序表_数组相关面试题();

		-------- -------- -------- -------- -------- -------- --------
		3. 链表
		-------- -------- -------- -------- -------- -------- --------
		4. 顺序表和链表的区别和联系
		-------- -------- -------- -------- -------- -------- --------
		======== ======== ======== ======== ======== ======== ========
*/

#include "My_function.h"
#include <stdlib.h>

/**************************************************************************************************************************************************/
/*================================================================================================================================================*/

void 顺序表_静态()
{
	printf("顺序表_静态\n");

	/*--------------------------------*/

	// 顺序表的静态存储
#define N 100
	struct SeqList
	{
		int a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	};

	/*--------------------------------*/

	// 完善 ，SL 是 SeqList 的缩写
	// 这样顺序表想存什么类型就从这里改 typedef double SLDataType;
	typedef int SLDataType;
	struct SeqList2
	{
		SLDataType a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	};

	// 接口函数
	//void 顺序表末尾插入数据(struct SeqList2* ps, int x);
	// ......

	/*--------------------------------*/

	// 修改
	typedef struct SeqList3
	{
		SLDataType a[N];// 定长数组
		int size;// 有效数据的个数(表示数组中存储了多少个数据)
	}SL3;

	// 接口函数
	//void 顺序表末尾插入数据(SL3* ps, int x);
	// ......

	/*--------------------------------*/

	/*
		接口函数 命名风格跟着STL走的
		SeqListPushBack
	*/

#undef N

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

void 顺序表_动态()
{
	printf("顺序表_动态\n");

	// 顺序表的动态存储
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType* arr;// 指向动态开辟的数组
		int size;		// 有效数据个数(表示数组中存储了多少个数据)
		int capacity;	// 容量空间的大小
	}SL;

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

typedef int SLDataType;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* arr;// 指向动态开辟的数组
	int size;		// 有效数据个数
	int capacity;	// 容量空间的大小
}SL;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

// 顺序表销毁
void SeqListDestory(SL* psl)
{
	free(psl->arr);
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

// 顺序表打印
void SeqListPrint(SL* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl)
{
	// 判断空间是否充足
	if (psl->size == psl->capacity)
	{
		// 空间不足 扩容
		// 扩容2倍适中，但是0*2还是0
		// int 新capacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		// 
		// void* realloc (void* ptr, size_t size);
		// 库函数realloc，如果ptr是NULL，就和 库函数malloc 功能一样。
		if (psl->capacity == 0)
		{
			int 新capacity = 4;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capacity = 新capacity;

		}
		else
		{
			int 新capacity = psl->capacity * 2;

			//SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity);
			// 参数 size_t size 是字节，所以要乘一个类型
			SLDataType* tmp = (SLDataType*)realloc(psl->arr, 新capacity * sizeof(SLDataType));
			if (tmp == NULL)
			{
				printf("无法扩容\n");
				exit(-1);
			}

			// 扩容成功
			psl->arr = tmp;
			psl->capacity = 新capacity;
		}
	}
}

// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x)
{
	SeqListCheckCapacity(psl);

	// 插入数据
	psl->arr[psl->size] = x;
	psl->size++;
}

// 顺序表尾删
void SeqListPopBack(SL* psl)
{
	if (psl->size > 0)
	{
		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x)
{
	/*
		把数据从后往前 逐个 向后移动一位
			[1][2][3][4][5]
			            end
			             →
			[1][2][3][4][ ][5]
			 →
			[ ][1][2][3][4][5]
	*/

	SeqListCheckCapacity(psl);

	// 移动前 最后一个数据的下标
	int end = psl->size - 1;

	// 移动数据
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	// 插入数据
	psl->arr[0] = x;
	psl->size++;
}

// 顺序表头删
void SeqListPopFront(SL* psl)
{
	/*
		把第二个数据开始 逐个 向前移动一位
		[1][2][3][4][5]
		   begin
		    ←
		[2][ ][3][4][5]
		             ←
		[2][3][4][5][ ]
	*/

	if (psl->size > 0)
	{
		// 移动前 第二个数据的下标
		int begin = 1;

		// 移动数据
		while (begin < psl->size)
		{
			psl->arr[begin - 1] = psl->arr[begin];
			begin++;
		}

		// 减减后 就访问不到后面的数据
		psl->size--;
	}
}

// 顺序表查找
int SeqListFind(SL* psl, SLDataType x)
{
	// 遍历一遍查找
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SL* psl, int pos, SLDataType x)
{
	/*
		      pos   end
		       ↓     ↓
		[0][1][2][3][4]
	*/

	// 判断是否越界
	if (pos > psl->size || pos < 0)
	{
		return;
	}

	SeqListCheckCapacity(psl);

	int end = psl->size - 1;

	// 移动数据
	while (end >= pos)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	// 插入数据
	psl->arr[pos] = x;
	psl->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SL* psl, size_t pos)
{
	/*
		      pos
		       ↓
		[0][1][2][3][4]
		          ↑
				begin
	*/

	// 判断是否越界
	if (pos >= psl->size || pos < 0)
	{
		return;
	}

	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->arr[begin - 1] = psl->arr[begin];
		begin++;
	}

	psl->size--;
}

void 顺序表_接口实现()
{
	printf("顺序表_接口实现\n");

	SL sl;

	// 顺序表初始化
	SeqListInit(&sl);

	// 顺序表尾插
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	// 顺序表打印
	SeqListPrint(&sl);

	// 顺序表尾删
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);

	SeqListPrint(&sl);

	// 顺序表头插
	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPushFront(&sl, 50);
	SeqListPushFront(&sl, 60);
	SeqListPushFront(&sl, 70);
	SeqListPushFront(&sl, 80);
	SeqListPushFront(&sl, 90);

	SeqListPrint(&sl);

	// 顺序表头删
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);

	// 顺序表查找
	printf("下标为 %d\n", SeqListFind(&sl, 60));

	// 顺序表在pos位置插入x
	SeqListInsert(&sl, 0, 999);

	SeqListPrint(&sl);

	// 顺序表删除pos位置的值
	SeqListErase(&sl, 2);

	SeqListPrint(&sl);


	// 顺序表销毁
	SeqListDestory(&sl);

	/*
		头尾 删除 插入 可以复用 SeqListInsert() 和 SeqListErase()
	*/

	n2(2, "-------- ", 4);
}

void 顺序表_接口实现_菜单()
{
	printf("******** ******** ******** ******** ********\n");
	printf("******** 1.头插              2.头删 ********\n");
	printf("******** 3.尾插              4.尾删 ********\n");
	printf("******** 5.查找              6.打印 ********\n");
	printf("******** 7.pos位置插入 8.pos位置删除 ********\n");
	printf("********           0.退出           ********\n");
	printf("******** ******** ******** ******** ********\n");
}

void 顺序表_接口实现_使用()
{
	SL sl;

	// 顺序表初始化
	SeqListInit(&sl);

	int 输入 = 1;
	int x;
	int pos;

	while (输入)
	{
		顺序表_接口实现_菜单();

		printf("选项>");
		scanf("%d", &输入);

		switch (输入)
		{
		case 1:
			printf("头插+L>");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
			break;
		case 2:
			printf("头删-L<\n");
			SeqListPopFront(&sl);
			break;
		case 3:
			printf("尾插L+>");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
			break;
		case 4:
			printf("尾删L-<\n");
			SeqListPopBack(&sl);
			break;
		case 5:
			printf("查找L?>");
			scanf("%d", &x);
			printf("下标为 %d\n", SeqListFind(&sl, x));
			break;
		case 6:
			SeqListPrint(&sl);
			break;
		case 7:
			printf("位置+L+>");
			scanf("%d", &pos);

			printf("值+L+>");
			scanf("%d", &x);

			SeqListInsert(&sl, pos, x);
			break;
		case 8:
			printf("位置-L->");
			SeqListErase(&sl, x);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}

	SeqListDestory(&sl);
}

/*================================================================================================================================================*/

int 移除元素(int* nums, int numsSize, int val)
{
	/*
		给你一个数组 nuns 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
		不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
		元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

		说明:
			为什么返回数值是整数，但输出的答案是数组呢?
			请注意，输入数组是以 引用 方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

		你可以想象内部操作如下:
			// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
			int len = removeElement(nums, val);

			// 在函数里修改输入数组对于调用者是可见的。
			// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
			for (int i = 0; i < len; i++) {
				print(nums[i]);
			}

		示例 1：
			输入：nums = [3,2,2,3], val = 3
			输出：2, nums = [2,2]
			解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
		
		示例 2：
			输入：nums = [0,1,2,2,3,0,4,2], val = 2
			输出：5, nums = [0,1,4,0,3]
			解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。

		提示：
			0 <= nums.length <= 100
			0 <= nums[i] <= 50
			0 <= val <= 100

		来源：力扣（LeetCode）
		链接：https://leetcode.cn/problems/remove-element
		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
	/*
		思路1：
			输入：nums = [3,2,2,3], val = 3
			输出：2, nums = [2,2]

			遍历，如果元素等于val
				 ↓
				[3][2][2][3]

			后面的数据向前移动一位
				 ↓
				[2][2][3][ ]

			如果元素不等于val，val向后走一位
					↓
				[2][2][3][ ]

			时间复杂度O(N^2)
			最坏情况：数组中大部分或全部元素等于val


		思路2：
			输入：nums = [3,2,2,3], val = 3
			输出：2, nums = [2,2]

			创建 临时 数组
				[ ][ ][ ][ ]

			遍历nums数组
				 ↓
				[3][2][2][3]

			把不是val的值放到 临时 数组
				[3][2][2][3]
				↓
				[2][2][ ][ ]

			再把 临时 数组的值拷贝回去
				[2][2][ ][ ]
				↓
				[2][2][ ][ ]

			时间复杂度O(2N)
			空间复杂度O(N)

			空间换时间


		思路3：
			输入：nums = [3,2,2,3], val = 3
			输出：2, nums = [2,2]

			时间复杂度 优化到O(N)
			空间复杂度 优化到O(1)

			双指针

			定义两个变量，src 和 dst

			src找nums数组中不等于val的值，放到dst指向的位置
				src→
				[3][2][2][3]
				dst

			等于val，src++
				   src→
				[3][2][2][3]
				dst

			不等于val，放到dst指向的位置
				   src→
				[2][2][2][3]
				dst

			再src++，dst++
					  src→
				[2][2][2][3]
				   dst
	*/

	int src = 0;
	int dst = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}

	return dst;
}

int 删除有序数组中的重复项(int* nums, int numsSize)
{
	/*
		给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
		由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
		将最终结果插入 nums 的前 k 个位置后返回 k 。

		不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

		判题标准:
			系统会用下面的代码来测试你的题解:
				int[] nums = [...]; // 输入数组
				int[] expectedNums = [...]; // 长度正确的期望答案

				int k = removeDuplicates(nums); // 调用

				assert k == expectedNums.length;
				for (int i = 0; i < k; i++) {
					assert nums[i] == expectedNums[i];
				}
				如果所有断言都通过，那么您的题解将被 通过。

		示例 1：
			输入：nums = [1,1,2]
			输出：2, nums = [1,2,_]
			解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
		
		示例 2：
			输入：nums = [0,0,1,1,1,2,2,3,3,4]
			输出：5, nums = [0,1,2,3,4]
			解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

		提示：
			1 <= nums.length <= 3 * 10^4
			-10^4 <= nums[i] <= 10^4
			nums 已按 升序 排列

		来源：力扣（LeetCode）
		链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array
		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
	/*
		思路：
			三指针

			 i  j
			 ↓  ↓
			[0][0][1][1][1][2][2][3][3][4]
			 ↑
			dst

			dst 重复保留一个
			i 和 j 重复区间

			i 和 j 相同 j++

				 i     j
				 ↓     ↓
				[0][0][1][1][1][2][2][3][3][4]
				 ↑
				dst

			i 和 j 不同 dst = i，dst++，i = j，j++

				       i  j
				       ↓  ↓
				[0][0][1][1][1][2][2][3][3][4]
				    ↑
				   dst

	*/
	if (numsSize == 0)
	{
		return 0;
	}

	// 去重
	int i = 0;
	int j = 1;
	int dst = 0;
	while (j < numsSize)
	{
		if (nums[i] == nums[j])
		{
			j++;
		}
		else
		{
			nums[dst] = nums[i];
			dst++;
			i = j;
			j++;
		}
	}

	// 剩余的数据
	nums[dst] = nums[i];

	// 数据个数
	dst++;

	return dst;
}

void 合并两个有序数组(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	/*
		给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
		请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
		注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

		示例 1：
			输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
			输出：[1,2,2,3,5,6]
			解释：需要合并 [1,2,3] 和 [2,5,6] 。
			合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

		示例 2：
			输入：nums1 = [1], m = 1, nums2 = [], n = 0
			输出：[1]
			解释：需要合并 [1] 和 [] 。
			合并结果是 [1] 。

		示例 3：
			输入：nums1 = [0], m = 0, nums2 = [1], n = 1
			输出：[1]
			解释：需要合并的数组是 [] 和 [1] 。
			合并结果是 [1] 。
			注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

		提示：
			nums1.length == m + n
			nums2.length == n
			0 <= m, n <= 200
			1 <= m + n <= 200
			-109 <= nums1[i], nums2[j] <= 109

		进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

		来源：力扣（LeetCode）
		链接：https://leetcode.cn/problems/merge-sorted-array
		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
	/*
		思路1：
			输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
			输出：[1,2,2,3,5,6]
			解释：需要合并 [1,2,3] 和 [2,5,6] 。
			合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

			创建临时数组
			先 nums1 和 nums2 的元素比较大小拷贝到 临时 数组
			再将 临时 数组的元素拷贝回 nums1

			空间复杂度O(N)

		思路2：
			输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
			输出：[1,2,2,3,5,6]
			解释：需要合并 [1,2,3] 和 [2,5,6] 。
			合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
			
			从 nums1 和 nums2 的最后位置开始

				       ↓
				[2][5][6]

				       ↓
				[1][2][3][ ][ ][ ]

			比大小，哪个元素大就放后面

				       ↓
				[2][5][6]

				       ↓
				[1][2][3][ ][ ][ ]

			6:3，6放最后，指向nums2元素的位置减减

				    ↓
				[2][5][6]

				       ↓
				[1][2][3][ ][ ][6]

			5:3，5放最后，指向nums2元素的位置减减

				 ↓
				[2][5][6]

				       ↓
				[1][2][3][ ][5][6]

			2:3，3放最后，指向nums1元素的位置减减

				 ↓
				[2][5][6]

				    ↓
				[1][2][3][3][5][6]

			2:2，2放，结束

				 ↓
				[2][5][6]

				    ↓
				[1][2][2][3][5][6]

			时间复杂度O(M+N)
			空间复杂度O(1)

			注意：
				如果 nums1 剩余数据，就结束，
				nums2 剩余数据，就拷贝到 nums1
	*/

	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}

	// 如果 nums2 剩余数据，就拷贝到 nums1
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}

void 顺序表_数组相关面试题()
{
	n2(2, "-------- ", 4);
	printf("顺序表_数组相关面试题\n");

	int arr[] = { 3,2,2,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	移除元素(arr, sz, 3);

	int arr2[] = { 0,0,1,1,1,2,2,3,3,4 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int ret = 删除有序数组中的重复项(arr2, sz2);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", arr2[i]);
	}
	n2(1, NULL, 0);

	// 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	// void 合并两个有序数组(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
	int nums1[6] = { 1,2,3 };
	int nums2[3] = { 2,5,6 };
	int m = 3;
	int n = 3;
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	合并两个有序数组(nums1, nums1Size, m, nums2, nums2Size, n);
	for (int i = 0; i < m + n; i++)
	{
		printf("%d ", nums1[i]);
	}
	n2(1, NULL, 0);

	n2(2, "-------- ", 4);
}

/*================================================================================================================================================*/

int main()
{
	顺序表_静态();
	顺序表_动态();
	//顺序表_接口实现();// 被 顺序表_接口实现_使用(); 替代
	顺序表_接口实现_使用();
	顺序表_数组相关面试题();

	return 0;
}

/*================================================================================================================================================*/
/**************************************************************************************************************************************************/