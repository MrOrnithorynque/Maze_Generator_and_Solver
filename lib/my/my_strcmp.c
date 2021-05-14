/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare 2 strings.
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
            return -1;
    }

    return 0;
}
