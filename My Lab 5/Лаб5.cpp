#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100//������������� ��� ������� ��������

typedef struct Student {//������� ��������� ������ � ����������� ��� �������� 'Student'
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char gender[10];
    int age;
    int course;
};

void findCourseWithMostMaleStudents(Student students[], int n);
void findMostCommonNames(Student students[], int n);
void listStudentsByGenderAndCourse(Student students[], int n, const char* gender, int course);

int main() {
    Student students[MAX_STUDENTS] = {
        {"Tkachuk", "Evgen", "Sergiovich", "male", 34, 2},
        {"Gerasimchuk", "Anna", "Petrivna", "female", 19, 1},
        {"Sidorov", "Petro", "Andriovich", "male", 21, 2},
        {"Galiuk", "Evgen", "Alexandrovich", "male", 20, 1},
        {"Plohotnik", "Anna", "Viktorivna", "female", 29, 1},
        {"Somov", "Viktor", "Fiodorovich", "male", 21, 2},
        //������� �������(�� ����������)������� ��������
    };
    int n = 6; //������� ��������

    findCourseWithMostMaleStudents(students, n);//����������� ������ �� ���������� �������� ������ ����� � ��������� �������� ������� ����
    findMostCommonNames(students, n);//����������� ������ �� ���������� �������� ������ ������������� ����
    listStudentsByGenderAndCourse(students, n, "female", 1);//����������� ������ �� ���������� �������� ������ ������� �������� ������� ���� �� ������� ����

    return 0;
}

void findCourseWithMostMaleStudents(Student students[], int n) {//��������� �������� ������ ����� � ��������� �������� ������� ����
    int courseCount[10] = {0};//������� ������ �����
    int maleCount[10] = {0};//������� ������ �������� ������� ����

    for (int i = 0; i < n; i++) {//��������� �������� ��� ����� �� �������� ������� ���� ����� ���� 'for'
        courseCount[students[i].course]++;
        if (strcmp(students[i].gender, "male") == 0) {//��������� ����� �� ��������� 'strcmp"(��������� � �������� ���������� � ���� 'for')
            maleCount[students[i].course]++;
        }
    }

    int maxCourse = 0;//����� ��� ��������� ������� �������� �� ����
    double maxPercentage = 0.0;//����� ��� ��������� �������� �������� �� ����
    for (int i = 0; i < 10; i++) {//������������� ���� 'for' ��� ����� ���������
        if (courseCount[i] > 0) {//�������� ��� �����
            double percentage = (double)maleCount[i] / courseCount[i] * 100;//�������� ��� ����������
            if (percentage > maxPercentage) {//������ ����� ��� ���������� ��������� ��� ����� maxPercentage 
                maxPercentage = percentage;//���������� ��������� maxPercentage
                maxCourse = i;
            }
        }
    }

    printf("The course with the highest percentage of male students: %d\n", maxCourse);
}

void findMostCommonNames(Student students[], int n) {//����� ������������� ����	
    char maleNames[MAX_STUDENTS][50];//����� ��� ��������� ������� �������� ����
    char femaleNames[MAX_STUDENTS][50];//����� ��� ��������� ������� ������ ����
    int maleCount = 0, femaleCount = 0;//����� ��� ��������� ���������

    for (int i = 0; i < n; i++) {//���� 'for' ��� ��������� �������
        if (strcmp(students[i].gender, "male") == 0) // ������� strcmp ��� ��������� ���� �������� � ������ "male".
		// ���� ���� ���, �� ���������� ��������� ���� �������� � ����� maleNames
		{
		    strcpy(maleNames[maleCount++], students[i].firstName);//���� ����� �������� - �������, ��� ��������� � ����� maleNames, � �������� maleCount ���������� �� 1.
        } else if (strcmp(students[i].gender, "female") == 0)// ���� ����� �������� - �����, ��� ��������� � ����� femaleNames,  
		{
            strcpy(femaleNames[femaleCount++], students[i].firstName);// � �������� femaleCount ���������� �� 1.
        }
    }

    char mostCommonMaleName[50] = "";//����� ��� ��������� ������������� ���� ����� �������
    char mostCommonFemaleName[50] = "";//����� ��� ��������� ������������� ���� ����� ����
    int maxMaleCount = 0, maxFemaleCount = 0;//���� ��� ��������� ������������� ����� ��������� ���� ����� ������� � ����
    for (int i = 0; i < maleCount; i++)//����� �������������� ��������� ����
	{
        int count = 0;//������� ���� ��������� ����� �� ����� � ����� maleNames.
        for (int j = 0; j < maleCount; j++) {
            if (strcmp(maleNames[i], maleNames[j]) == 0) {
                count++;
            }//�������� ���� ������� ����� ��� � ���� ������ ������� � �����, ����������� ������� ���������.
        }
        if (count > maxMaleCount) {
            maxMaleCount = count;//���� ������� ��������� ��������� ���� �����, �� maxMaleCount, ����������� maxMaleCount
            strcpy(mostCommonMaleName, maleNames[i]);//� ��������� ������� ��� � mostCommonMaleName.
        }
    }
//��������� �� ������������ ����� ����, ��� ��� ������ femaleNames.
    for (int i = 0; i < femaleCount; i++) {
        int count = 0;
        for (int j = 0; j < femaleCount; j++) {
            if (strcmp(femaleNames[i], femaleNames[j]) == 0) {
                count++;
            }
        }
        if (count > maxFemaleCount) {
            maxFemaleCount = count;
            strcpy(mostCommonFemaleName, femaleNames[i]);
        }
    }

    printf("The most common male name: %s\n", mostCommonMaleName);//���������� ������������ ������� �����.
    printf("The most common female name: %s\n", mostCommonFemaleName);//���������� ������������ ����� �����.
}

void listStudentsByGenderAndCourse(Student students[], int n, const char* gender, int course)
//������������ �������, ��� ������ ����� ��������, �� �������, ����� � ������ �� ����� �����.
 {
    printf("List of gender students %s in course %d:\n", gender, course);//�������� ��������� ������ �������� ����� ���� �� �����
    for (int i = 0; i < n; i++) //����, ���� ��������� ����� �� �������� ������ students
	{
        if (strcmp(students[i].gender, gender) == 0 && students[i].course == course)//��������, �� ������� ����� �������� ������ ���� �� �� ����������� ������� �� �������� ����.
		 {
            printf("%s %s %s\n", students[i].lastName, students[i].firstName, students[i].middleName);//�������� �������, ��� �� �� ������� ��������, ���� ����� �������� �����������.
        }
    }
}

