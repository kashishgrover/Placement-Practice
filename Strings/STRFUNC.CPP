//String Functions


int sLength(char str[])
{
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}


void sConcat(char str1[], char str2[])
{
  int i, j;
  for (i = 0; str1[i] != '\0'; i++);
  for (j = 0; str2[j] != '\0'; j++, i++)
    str1[i] = str2[j];
  str1[i] = '\0';

}


int sCompare(char str1[], char str2[])
{
  int i;
  for (i = 0; str1[i] != '\0'; i++)
  {
    if (str1[i] != str2[i])
      return (str1[i] - str2[i]);
  }
  return (str1[i] - str2[i]);
}

/*
void delSubstring(char str[],char substr[])
{
 int sublen=sLength(substr);
 char temp[20];
 for(int i=0;str[i]!='\0';i++)
 {
  for(int j=0,k=i;j<sublen;j++,k++)
  temp[j]=str[k];

  if(sCompare(temp,substr)==0)
  {
   cout<<"Substring found!";
   break;
  }
 }
}
*/


void insSubstring(char str1[20], char sub[20], int pos)
{
  int subsize = sLength(str1);

  //finding null char of s1
  int i;

  for ( i = 0; str1[i] != '\0'; i++);

  //shifting characters subsize ahead
  for (; i >= pos; i--)
    str1[i + subsize] = str1[i];

  //copying substring
  int j;
  for (j = 0, i = pos; sub[j] != '\0'; i++, j++)
    str1[i] = sub[j];

}