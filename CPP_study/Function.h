#pragma once

#include <stdio.h>
#include <io.h>

void n2(int 换行次数, char* 换行符号, int 符号个数);

// 判断文件是否存在，判断文件权限
int fileAccess(const char* FileName, int mode);