
/*
	template之模板中class与typename区别

		总结

			这里对typename做了一个浅显的分析, 这也足够我们可以分析traits编程的基础了. 我再将以上的分析做一个归纳.

			typename和class在作为参数类型时用法一样, 没有区别
			typename主要用于对嵌套依赖类型进行提取(萃取). 而class没有这样的功能.
			typename提取的一个例外是在继承或成员初始化列表中对基类进行初始化时不用加typename关键字
			————————————————
			版权声明：本文为CSDN博主「Function_18」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
			原文链接：https://blog.csdn.net/Function_Dou/article/details/84644963
*/