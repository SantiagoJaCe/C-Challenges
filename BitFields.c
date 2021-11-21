/* Challenge: Write a program that cointains the following bitfields
in a structure:
-The box can be opaque or transparent
-A fill color can be selected from the following pallete:
black, red, green, yellow, blue, magenta, cyan, white.
-A border can be shown or hidden
-A border color is selected from the same pallette
-A border can use one of three line styles: solid, dotted, dashed
A TOTAL OF 10 BITS IS ENOUGH FOR ALL PROPERTIES.
Modify the box.
 */
#include "stdio.h"

struct customBox{

    unsigned int transparent : 1;
    unsigned int fillcolor: 3;
    unsigned int border: 1;
    unsigned int bordercolor:3;
    unsigned int linestyle:2;

};

void printBox(struct customBox Box);

int main(void){

    struct customBox Box;

    printf("Original Box Settings:\n");
    printBox(Box);

    Box.transparent=1;
    Box.fillcolor=6;
    Box.border=1;
    Box.bordercolor=3;
    Box.linestyle=2;

    printf("\n\nModified Box Settings:\n");
    printBox(Box);

}

void printBox(struct customBox Box){
    if (Box.transparent) printf("Box is opaque.\n");
    else printf("Box is transparent.\n");

    unsigned int color=Box.fillcolor;
    if (color==0) printf("The fill color is black\n");
    else if (color==1) printf("The fill color is red\n");
    else if (color==2) printf("The fill color is green\n");
    else if (color==3) printf("The fill color is yellow\n");
    else if (color==4) printf("The fill color is blue\n");
    else if (color==5) printf("The fill color is magenta\n");
    else if (color==6) printf("The fill color is cyan\n");
    else if (color==7) printf("The fill color is white\n");
    
    if(Box.border) printf("Border is shown\n");
    else printf("Border is not shown\n");

    unsigned int bcolor=Box.bordercolor;
    if (bcolor==0) printf("The border color is black\n");
    else if (bcolor==1) printf("The border color is red\n");
    else if (bcolor==2) printf("The border color is green\n");
    else if (bcolor==3) printf("The border color is yellow\n");
    else if (bcolor==4) printf("The border color is blue\n");
    else if (bcolor==5) printf("The border color is magenta\n");
    else if (bcolor==6) printf("The border color is cyan\n");
    else if (bcolor==7) printf("The border color is white\n");

    unsigned int lstyle=Box.linestyle;
    if(lstyle==0) printf("The border style is solid\n");
    else if (lstyle==1) printf("The border style is dotted\n");
    else if (lstyle==2) printf("The border style is dashed\n");
}

