#include <stdio.h>
#include <string.h>
void Str(char *s1, char *s2, char *result) {
    char *token;
    char temp[1000] = ""; // тимчасовий рядок для зберігання результату
    char delimiter[] = " ,.!?"; // роздільник для слів
    token = strtok(s2, delimiter); // розбиваємо рядок s2 на слова та роздільні знаки між словами
    while (token != NULL)  //утворюємо цикл while та указуємо границю до першого пустого токена
	{
        strcat(temp, token); //створюємо конкатенацію між s2 та тимчасовим рядком
        strcat(temp, s1); // створюємо конкатенацію між s1 та тимчасовим рядком
        strcat(temp, " "); // додаємо пробіл до тимчасового рядка
        token = strtok(NULL, delimiter); // переходимо до наступного слова
    }
    strcpy(result, temp);// копіюємо результат у вихідний рядок
}
int main() {
    char s1[] = "=][";//ввод s1
    char s2[] = "how,many.more!time?";//ввод s2
    char result[1000];// тимчасовий рядок для результату

    Str(s1, s2, result);
    printf("Result: %s\n", result);

    return 0;
}
