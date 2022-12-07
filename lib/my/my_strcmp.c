/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int compteur = 0;
    int value = 0;

    while (s1[compteur] != '\0' || s2[compteur] != '\0') {
        if (s1[compteur] == s2[compteur]) {
            value = value + 0;
            compteur = compteur + 1;
        } else {
            value = s1[compteur] - s2[compteur];
            compteur = compteur +1;
        }
    }
    if (value == 0) {
        return (0);
    } else {
        return (value);
    }
}
