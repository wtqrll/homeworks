#include <stdio.h>
int main(){
    int a, b;
    printf("Delky koleji\n");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0 || a == b ) {
    printf("Nespravny vstup.\n");
    return 0;
}

char sign;
int length;

printf("Vzdalenost\n");
if (scanf(" %c%d", &sign, &length) != 2 || (sign != '+' && sign != '-') || length < 0) {
    printf("Nespravny vstup.\n");
    return 0;
}
int count = 0;
  for (int x = 0; x * a <= length; x++) {
    int rest = length - x * a;
  if (rest % b == 0) {
    int y = rest / b;
    count++;

  if (sign == '+') {
    printf("= %d * %d + %d * %d\n", a, x, b, y);
     }
      }
    }

    if (count == 0) {
        printf("Reseni neexistuje.\n");
    }

    printf("Celkem variant: %d\n", count);
    return 0;

}