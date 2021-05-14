/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Find str in str.
*/

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            for (a = 0; to_find[a] == str[i] || str[i] != '\0'; i++)
                a++;
            if (to_find[a] == '\0')
                return str + (i - a);
        }
    }

    return 0;
}
