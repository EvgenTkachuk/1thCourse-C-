#include <stdio.h>
#include <string.h>
void Str(char *s1, char *s2, char *result) {
    char *token;
    char temp[1000] = ""; // ���������� ����� ��� ��������� ����������
    char delimiter[] = " ,.!?"; // ��������� ��� ���
    token = strtok(s2, delimiter); // ��������� ����� s2 �� ����� �� ������� ����� �� �������
    while (token != NULL)  //��������� ���� while �� ������� ������� �� ������� ������� ������
	{
        strcat(temp, token); //��������� ������������ �� s2 �� ���������� ������
        strcat(temp, s1); // ��������� ������������ �� s1 �� ���������� ������
        strcat(temp, " "); // ������ ����� �� ����������� �����
        token = strtok(NULL, delimiter); // ���������� �� ���������� �����
    }
    strcpy(result, temp);// ������� ��������� � �������� �����
}
int main() {
    char s1[] = "=][";//���� s1
    char s2[] = "how,many.more!time?";//���� s2
    char result[1000];// ���������� ����� ��� ����������

    Str(s1, s2, result);
    printf("Result: %s\n", result);

    return 0;
}
