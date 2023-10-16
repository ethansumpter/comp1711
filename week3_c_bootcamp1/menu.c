#include <stdio.h>
int main() {
    int num;
    printf("Choose a menu item: ");
    scanf("%d",&num);

    switch (num) {
        case 1:
            printf("Menu item 1 is selected\n");
            break;
        case 2:
            printf("Menu item 2 is selected\n");
            break;
        case 3:
            printf("Menu item 3 is selected\n");
            break;
        case 4:
            printf("Menu item 4 is selected\n");
            break;
        case 5:
            printf("Menu item 5 is selected\n");
            break;
        default:
            printf("An invalid menu item has been selected.\n");
    }

    return 0;

}