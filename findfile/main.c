#include <stdio.h>
#include <string.h>

int main()
{
    char key[10];  //�ؼ���
    int count = 0; //��¼�ؼ��ʵĸ���
    int linenumber = 0; //��¼����
    char lines[256]; //ÿһ�е��ַ���
    //Ҫ�������ļ�
    FILE * fp = fopen ("C:/lessons/car.cpp", "r");
    if (fp == NULL)
    {
        printf ("Open file failed.");
    }
    //������������ݵ�����ļ�
    FILE * out = fopen ("C:/lessons/car.txt", "w");
    if (out == NULL)
    {
        printf ("Open file failed.");
    }
    puts ("Enter the word to search: \n");
//    fgets (key, 11, stdin);  fgets���л��У����Բ���
    scanf ("%s", key);
    fflush(stdin);
    if (key != NULL && key[0] != '\0')
    {
        while (fgets (lines, 256, fp))
        {
            linenumber++;
            if (strstr (lines, key))
            {
                printf ("��%d�� %s",linenumber, lines);
//                fputs (lines, out);  //Ӧ�ð�����Ҳ����ȥ
                fprintf (out, "��%d�� %s", linenumber, lines);
                printf ("\n");
                count++;
            }
        }
        printf ("�ܹ�����%d��", count);
    }
    else
        printf ("no enter!\n");
    fclose (fp);
    fclose (out);
    return 0;
}




