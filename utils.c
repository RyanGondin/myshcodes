#include "utils.h"



int aleatorio(int min, int max)
{
   return min + rand() % (max + 1);
}

void lerString(char * texto, char * string)
{
   if(string)
   {
   printf(" %s \n", texto);
   scanf("%s", string);
   }

}

int lerInteiro(char * texto)
{
      int ret;
      printf(" %s \n", texto);
      scanf("%d", &ret );
      return ret;
}


int lerFloat(char * texto)
{
      float ret;
      printf(" %s \n", texto);
      scanf("%f", &ret );
      return ret;
}

void debugInt(char * txt, char * file, int num)
{

      time_t t = time(NULL);
      struct tm *tm = localtime(&t);
      FILE *f = fopen(file, "a");
      fprintf(f, "%s %d ----  %d/%d/%d %d:%d:%d\n",
       txt, num, tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900,
       tm->tm_hour, tm->tm_min, tm->tm_sec);
      fclose(f);
}

void debugFloat (char * txt, char * file, float num)
{

      time_t t = time(NULL);
      struct tm *tm = localtime(&t);
      FILE *f = fopen(file, "a");
      fprintf(f, "%s %f ----  %d/%d/%d %d:%d:%d\n",
       txt, num, tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900,
       tm->tm_hour, tm->tm_min, tm->tm_sec);
      fclose(f);
}

void debugTxt(char * txt, char * file)
{
      time_t t = time(NULL);
      struct tm *tm = localtime(&t);
      FILE *f = fopen(file, "a");
      fprintf(f, "%s ----  %d/%d/%d %d:%d:%d\n",
       txt,  tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900,
       tm->tm_hour, tm->tm_min, tm->tm_sec);
      fclose(f);
}

