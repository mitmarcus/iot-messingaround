int utils_find_char_index_in_string(char *string, char c)
{
    char *e = strchr(string, c);
    return (int)(e - string);
}