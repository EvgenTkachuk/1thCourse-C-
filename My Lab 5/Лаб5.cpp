#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100//встановлоюємо межі кількості студентів

typedef struct Student {//вводимо структуру данних з інформацією про студентів 'Student'
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
        //можливе додання(за неохідністю)кількості студентів
    };
    int n = 6; //кількість студентів

    findCourseWithMostMaleStudents(students, n);//призначення змінних до результатів значеннь пошуку курсу з більшістью студентів чоловічої статі
    findMostCommonNames(students, n);//призначення змінних до результатів значеннь пошуку найпоширінеших імен
    listStudentsByGenderAndCourse(students, n, "female", 1);//призначення змінних до результатів значеннь пошуку кількості студентів заданної статі на заданніім курсі

    return 0;
}

void findCourseWithMostMaleStudents(Student students[], int n) {//створюємо алгоритм пошуку курсу з більшістью студентів чоловічої статі
    int courseCount[10] = {0};//вводимо зміннну курсу
    int maleCount[10] = {0};//вводимо зміннну студентів чоловічої статі

    for (int i = 0; i < n; i++) {//створюємо лічильник для курсу та студентів чоловічої статі через цикл 'for'
        courseCount[students[i].course]++;
        if (strcmp(students[i].gender, "male") == 0) {//створюємо умову за допомогою 'strcmp"(порівняння з шукаємими елементами у циклі 'for')
            maleCount[students[i].course]++;
        }
    }

    int maxCourse = 0;//змінна для підрахунку кількості студентів на курсі
    double maxPercentage = 0.0;//змінна для підрахунку проценту студентів на курсі
    for (int i = 0; i < 10; i++) {//використовуємо цикл 'for' для циклу підрахунку
        if (courseCount[i] > 0) {//лічильник для курсу
            double percentage = (double)maleCount[i] / courseCount[i] * 100;//лічильник для процентажу
            if (percentage > maxPercentage) {//задаємо умову для обновлення показників для змінної maxPercentage 
                maxPercentage = percentage;//доповнення показника maxPercentage
                maxCourse = i;
            }
        }
    }

    printf("The course with the highest percentage of male students: %d\n", maxCourse);
}

void findMostCommonNames(Student students[], int n) {//пошук найпоширінеших імен	
    char maleNames[MAX_STUDENTS][50];//змінна для підрахунку кількості чоловічих імен
    char femaleNames[MAX_STUDENTS][50];//змінна для підрахунку кількості жіночих імен
    int maleCount = 0, femaleCount = 0;//змінна для лічильника підрахунку

    for (int i = 0; i < n; i++) {//цикл 'for' для підрахунку кількості
        if (strcmp(students[i].gender, "male") == 0) // функція strcmp для порівняння статі студента з рядком "male".
		// Якщо вони рівні, то виконується копіювання імені студента в масив maleNames
		{
		    strcpy(maleNames[maleCount++], students[i].firstName);//Якщо стать студента - чоловіча, ім’я копіюється в масив maleNames, і лічильник maleCount збільшується на 1.
        } else if (strcmp(students[i].gender, "female") == 0)// Якщо стать студента - жіноча, ім’я копіюється в масив femaleNames,  
		{
            strcpy(femaleNames[femaleCount++], students[i].firstName);// і лічильник femaleCount збільшується на 1.
        }
    }

    char mostCommonMaleName[50] = "";//рядки для зберігання найпоширеніших імен серед чоловіків
    char mostCommonFemaleName[50] = "";//рядки для зберігання найпоширеніших імен серед жінок
    int maxMaleCount = 0, maxFemaleCount = 0;//змінні для зберігання максимального числа повторень імен серед чоловіків і жінок
    for (int i = 0; i < maleCount; i++)//Пошук найпоширенішого чоловічого імені
	{
        int count = 0;//зовнішній цикл проходить через всі імена в масиві maleNames.
        for (int j = 0; j < maleCount; j++) {
            if (strcmp(maleNames[i], maleNames[j]) == 0) {
                count++;
            }//Внутрішній цикл порівнює кожне ім’я з усіма іншими іменами в масиві, підраховуючи кількість повторень.
        }
        if (count > maxMaleCount) {
            maxMaleCount = count;//Якщо кількість повторень поточного імені більше, ніж maxMaleCount, оновлюється maxMaleCount
            strcpy(mostCommonMaleName, maleNames[i]);//і копіюється поточне ім’я в mostCommonMaleName.
        }
    }
//Аналогічно до попереднього блоку коду, але для масиву femaleNames.
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

    printf("The most common male name: %s\n", mostCommonMaleName);//Виводяться найпоширеніші чоловічі імена.
    printf("The most common female name: %s\n", mostCommonFemaleName);//Виводяться найпоширеніші жіночі імена.
}

void listStudentsByGenderAndCourse(Student students[], int n, const char* gender, int course)
//Іниціалізація функції, яка приймає масив студентів, їх кількість, рядок зі статтю та номер курсу.
 {
    printf("List of gender students %s in course %d:\n", gender, course);//виводить заголовок списку студентів певної статі та курсу
    for (int i = 0; i < n; i++) //цикл, який проходить через всі елементи масиву students
	{
        if (strcmp(students[i].gender, gender) == 0 && students[i].course == course)//перевіряє, чи відповідає стать студента заданій статі та чи знаходиться студент на заданому курсі.
		 {
            printf("%s %s %s\n", students[i].lastName, students[i].firstName, students[i].middleName);//виводить прізвище, ім’я та по батькові студента, якщо умови перевірки виконуються.
        }
    }
}

