#include <stdio.h>
#include <string.h>

int main()
{
    char key[10];  //关键词
    int count = 0; //记录关键词的个数
    int linenumber = 0; //记录行数
    char lines[256]; //每一行的字符串
    //要搜索的文件
    FILE * fp = fopen ("C:/lessons/car.cpp", "r");
    if (fp == NULL)
    {
        printf ("Open file failed.");
    }
    //输出搜索的内容到这个文件
    FILE * out = fopen ("C:/lessons/car.txt", "w");
    if (out == NULL)
    {
        printf ("Open file failed.");
    }
    puts ("Enter the word to search: \n");
//    fgets (key, 11, stdin);  fgets带有换行，所以不行
    scanf ("%s", key);
    fflush(stdin);
    if (key != NULL && key[0] != '\0')
    {
        while (fgets (lines, 256, fp))
        {
            linenumber++;
            if (strstr (lines, key))
            {
                printf ("第%d行 %s",linenumber, lines);
//                fputs (lines, out);  //应该把行数也传进去
                fprintf (out, "第%d行 %s", linenumber, lines);
                printf ("\n");
                count++;
            }
        }
        printf ("总共出现%d次", count);
    }
    else
        printf ("no enter!\n");
    fclose (fp);
    fclose (out);
    return 0;
}




