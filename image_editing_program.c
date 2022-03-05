/*
Image editing program
---------------------

Input : .ppm image (make sure the image is in the same folder as the program)
Output: image_edit.ppm image with the applied modifications

Short description:
Enter the file name, and then you may select any option from the menu.
If you want to apply multiple modifications on the same image, please select the "Use modified image" option, when asked what file you want to use.
After you close the program you will find in the same folder a file with the name "image_edit.ppm" which contains all the modifications.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define X_MAXVAL 700
#define Y_MAXVAL 700
#define DARKEN 0
#define LIGHTEN 1
#define RED 1
#define GREEN 2
#define BLUE 3
#define STANGA 0
#define DREAPTA 1
int xval=0,yval=0,rgbval=0;
FILE *img,*img_new,*temp_img;
int save_img_flag=0;
int red[700][700],green[700][700],blue[700][700];
char new_file_name[20]="image_edit.ppm",temp_img_name[20]="temp_img.ppm";

void copy_file_to_tmp(char *dest_file_name,char *source_file_name);
int bounded (int px_lower_bound,int px_upper_bound,int value);
void swap_number(int *a,int *b);
void reverse_rows(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax);
void reverse_rows(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax);
void reverse_columns(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax);
void transpose(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax);
void create_console_file(char *file_name,int maxlen);
void use_console_file(char *file_name,int maxlen);
void color_to_black_white(char *file_name);
void filter(char *file_name,float factor,int rgb);
float filter_menu(char *file_name,int rgb);
void get_ppm_px(char *file_name);
float luminozitate(char *file_name,float factor,int dark_light);
void rotate_img(char *file_name,int direction);
int luminance_mean(char *file_name);
void contrast_adjust(char *file_name);
void invert(char *file_name);
void show_exposure(char *file_name);
void s_black_white(char *file_name);

int main()
{
    char file_name[20];
    int opt=-1,opt1=-1;
    float fact=100;
    use_console_file(file_name,sizeof(file_name));
    get_ppm_px(file_name);
    copy_file_to_tmp(temp_img_name,file_name);
    while(opt!=11)
    {
        printf("----Program de editare a imaginilor----\n");
        printf("------------------------------------------\n\n");
        printf("1.Transformare din color in alb-negru.\n");
        printf("2.Filtru culoare albastra.\n");
        printf("3.Filtru culoare rosie.\n");
        printf("4.Filtru culoare verde.\n");
        printf("5.Modificare luminozitate imagine.\n");
        printf("6.Rotire imagine stanga.\n");
        printf("7.Rotire imagine dreapta.\n");
        printf("8.Ajustare contrast.\n");
        printf("9.Inversare culori imagine.\n");
        printf("10.Arata expunerea imaginii.\n");
        printf("11.Iesire program.\n\n");
        printf("Introduceti optiunea:");
        scanf(" %d",&opt);
        switch(opt)
        {
        case 1:
        {
            printf("\n\n----1.Transformare din color in alb-negru.\n");
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    color_to_black_white(file_name);
                }
                else if(opt1==2)
                {
                    color_to_black_white(new_file_name);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }
        break;
        case 2:
        {
            printf("\n\n----2.Filtru culoare albastra.\n");
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    filter_menu(file_name,BLUE);
                }
                else if(opt1==2)
                {
                    filter_menu(new_file_name,BLUE);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }break;
        case 3:
        {
            printf("\n\n----3.Filtru culoare rosie.\n");

                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    filter_menu(file_name,RED);
                }
                else if(opt1==2)
                {
                    filter_menu(new_file_name,RED);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }break;
        case 4:
        {
            printf("\n\n----4.Filtru culoare verde.\n");
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    filter_menu(file_name,GREEN);
                }
                else if(opt1==2)
                {
                    filter_menu(new_file_name,GREEN);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }break;
        case 5:
        {
        printf("\n\n----5.Modificare luminozitate.\n");
        if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    luminozitate(file_name,fact,DARKEN);
                }
                else if(opt1==2)
                {
                    luminozitate(new_file_name,fact,DARKEN);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }

        printf("Image modified succesfully!\nPress any button...\n");
        getch();
        system("cls");
        }
        break;
                case 6:
        {
        printf("\n\n----6.Rotire imagine stanga.\n");
        if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    rotate_img(file_name,STANGA);
                }
                else if(opt1==2)
                {
                    rotate_img(new_file_name,STANGA);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }

        printf("Image modified succesfully!\nPress any button...\n");
        getch();
        system("cls");
        }}
        break;
                        case 7:
        {
        printf("\n\n----7.Rotire imagine dreapta.\n");
        if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    rotate_img(file_name,DREAPTA);
                }
                else if(opt1==2)
                {
                    rotate_img(new_file_name,DREAPTA);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }

        printf("Image modified succesfully!\nPress any button...\n");
        getch();
        system("cls");
        }}
        break;
        case 8:
        {
            printf("\n\n----8.Ajustare contrast.\n");
            if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    contrast_adjust(file_name);
                }
                else if(opt1==2)
                {
                    contrast_adjust(new_file_name);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }}
        break;
                case 9:
        {
            printf("\n\n----9.Inversare culori imagine.\n");
            if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    invert(file_name);
                }
                else if(opt1==2)
                {
                    invert(new_file_name);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }}
        break;
                        case 10:
        {
            printf("\n\n----10.Arata expunerea imaginii.\n");
            if(save_img_flag)
            {
                printf("   1.Use the original image:");
                printf("%s\n",file_name);
                printf("   2.Use the modified image:");
                printf("%s\n",new_file_name);
                printf("   3.Return to main menu.\n");
                printf("   Introduceti optiunea:");
                scanf(" %d",&opt1);
                if(opt1==1)
                {
                    show_exposure(file_name);
                }
                else if(opt1==2)
                {
                    show_exposure(new_file_name);
                }
                else if(opt1==3)
                {}
                else
                {
                    printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
                }
            printf("Image modified succesfully!\nPress any button...\n");
            getch();
            system("cls");
        }}
        break;
        case 11:
        {

            printf("Ati inchis programul cu succes!\n");
        }
        break;
        default:
        {
            printf("Introduceti o optiune valida.\nPress any button...\n");
            getch();
            system("cls");
        }
        break;
        }
       }
    }
        fclose(img);
    fclose(img_new);
    fclose(temp_img);
remove("temp_img.ppm");
    return 0;
}


void copy_file_to_tmp(char *dest_file_name,char *source_file_name)
{
int i,j,r=0,g=0,b=0;
    char type_ppm[20];
    int valid_px=0;

        if((img_new=fopen(source_file_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    fgets(type_ppm,20,img_new);
    fscanf(img_new,"%d %d\n",&xval,&yval);
    fscanf(img_new,"%d\n",&rgbval);
    if((temp_img=fopen(dest_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(temp_img,"P3\n");
    fprintf(temp_img,"%d %d\n",xval,yval);
    fprintf(temp_img,"%d\n",rgbval);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(img_new,"%d %d %d",&r,&g,&b);
            fprintf(temp_img,"%d %d %d\n",r,g,b);
        }
    }
    fclose(temp_img);
    fclose(img_new);
}
int bounded (int px_lower_bound,int px_upper_bound,int value)
{
    if(value<px_lower_bound)
    return px_lower_bound;
    else if(value>px_upper_bound)
        return px_upper_bound;
    return value;

}
void swap_number(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void reverse_rows(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax){
    int i,j;
    for(i=1;i<=ymax;i++)
        for(j=1;j<=xmax/2;j++)
        swap_number(&a[i][j],&a[i][xmax-j+1]);
}
void reverse_columns(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax){
    int i,j;
    for(j=1;j<=xmax;j++)
    for(i=1;i<=ymax/2;i++)
        swap_number(&a[i][j],&a[ymax-i+1][j]);
}
void transpose(int a[Y_MAXVAL][X_MAXVAL],int xmax,int ymax){
    int i,j,x_tmp=ymax,y_tmp=xmax;
    if(xmax<ymax)
        swap_number(&x_tmp,&y_tmp);
    for(i=1;i<=x_tmp;i++)
        for(j=i;j<=y_tmp;j++)
        swap_number(&a[i][j],&a[j][i]);
}
void create_console_file(char *file_name,int maxlen)
{
    printf("Enter file name:");
    fgets(file_name,maxlen,stdin);
    file_name[strlen(file_name)-1]='\0';
    if((img=fopen(file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Succesfully created file:%s\n",file_name);
    fclose(img);
}
void use_console_file(char *file_name,int maxlen)
{
    printf("Please use a .ppm format image.\n");
    printf("Enter the file name:");
    if(save_img_flag)
   getchar();
    fgets(file_name,maxlen,stdin);
    file_name[strlen(file_name)-1]='\0';
    save_img_flag++;
}
void color_to_black_white(char *file_name)
{
    int i,j,r=0,g=0,b=0,imean=0;
    float calc=0,aux=0,mean=0;
    char type_ppm[20];
    int valid_px=0;
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    int L=luminance_mean(file_name);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            mean=(r+g+b)/3.0;
            imean=(int)mean;
            r=bounded(0,255,imean);
            g=bounded(0,255,imean);
            b=bounded(0,255,imean);
            fprintf(img_new,"%d %d %d\n",r,g,b);
        }
    }
    fclose(img);
    fclose(img_new);
}
void filter(char *file_name,float factor,int rgb)
{
    int i,j,r=0,g=0,b=0,imean=0;
    float calc=0,aux=0,mean=0;
    char type_ppm[20];
    int xval=70,yval=70,valid_px=0;
     copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            if(rgb==BLUE)
            b=b-b*factor;
            if(rgb==GREEN)
            g=g-g*factor;
            if(rgb==RED)
            r=r-r*factor;
            fprintf(img_new,"%d %d %d\n",bounded(0,255,r),bounded(0,255,g),bounded(0,255,b));
        }
    }
    save_img_flag++;
    fclose(temp_img);
    fclose(img_new);
}
float filter_menu(char *file_name,int rgb)
{
    int opt=-1;
    float fact=1.0;
            if(rgb==BLUE)
            {
                     printf("    1.Aplicare filtru albastru intensitate 100%\n");
                     printf("    2.Aplicare filtru albastru alta intensitate\n");
            }
            if(rgb==GREEN)
            {
                     printf("    1.Aplicare filtru verde intensitate 100%\n");
                     printf("    2.Aplicare filtru verde alta intensitate\n");
            }
            if(rgb==RED)
            {
                     printf("    1.Aplicare filtru rosu intensitate 100%\n");
                     printf("    2.Aplicare filtru rosu alta intensitate\n");
            }
    printf("    Introduceti optiunea:");
    scanf(" %d",&opt);
    if(opt==1)
    {
        fact=1.0;
        filter(file_name,fact,rgb);
    }
    else if(opt==2)
    {
        printf("    Introduceti intensitatea (nr. 0-100):");
        scanf(" %f",&fact);
        fact=fact/100.0;
        filter(file_name,fact,rgb);
    }
    else if(opt==3)
    {}
    else
    {
        printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
    }
    return fact;
}
void get_ppm_px(char *file_name)
{
    char type_ppm[20];
    int i=0,j=0;
       if((img=fopen(file_name,"r"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fgets(type_ppm,20,img);
    fscanf(img,"%d %d\n",&xval,&yval);
    fscanf(img,"%d\n",&rgbval);
        for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(img,"%d %d %d",&red[i][j],&green[i][j],&blue[i][j]);
        }
    }
    fclose(img);
}
float luminozitate(char *file_name,float factor,int dark_light)
{
    float factor_history=1;
    char type_ppm[20];
    float fact=factor/100.0;
    int i,j;
         copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    int opt=-1;
    printf("    1.Luminati imagine.\n");
    printf("    2.Intunecati imaginea.\n");
    printf("    Introduceti optiunea:");
    scanf(" %d",&opt);
    if(opt==1)
    {
        printf("    Introduceti un numar (nr. 0-100) corespunzator procentului cu care doriti sa se lumineze imaginea:");
        dark_light=LIGHTEN;
        scanf(" %f",&fact);
        fact=fact/100.0;
    }
    else if(opt==2)
    {
        printf("    Introduceti un numar (nr. 0-100) corespunzator procentului cu care doriti sa se intunece imaginea:");
        dark_light=DARKEN;
        scanf(" %f",&fact);
        fact=fact/100.0;
    }
    else if(opt==3)
    {}
    else
    {
        printf("   Introduceti o optiune valida.\nPress any button to return to main menu...\n");
    }

    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&red[i][j],&green[i][j],&blue[i][j]);
            if(dark_light==DARKEN)
            {
                red[i][j]=red[i][j]-red[i][j]*fact;
                green[i][j]=green[i][j]-green[i][j]*fact;
                blue[i][j]=blue[i][j]-blue[i][j]*fact;

            }
            else if(dark_light==LIGHTEN)
                {
                red[i][j]=red[i][j]+red[i][j]*fact;
                green[i][j]=green[i][j]+green[i][j]*fact;
                blue[i][j]=blue[i][j]+blue[i][j]*fact;
                }
                    red[i][j]=bounded(0,255,red[i][j]);
                    green[i][j]=bounded(0,255,green[i][j]);
                    blue[i][j]=bounded(0,255,blue[i][j]);
            fprintf(img_new,"%d %d %d\n",red[i][j],green[i][j],blue[i][j]);
        }
    }
    if(dark_light==DARKEN)
        factor_history=factor_history*fact;
    else if(dark_light==LIGHTEN)
        factor_history=factor_history/fact;
    save_img_flag++;
    fclose(img);
    fclose(img_new);
    return factor_history;
}
void rotate_img(char *file_name,int direction){
    int i,j,r=0,g=0,b=0,imean=0;
    float calc=0,aux=0,mean=0;
    char type_ppm[20];
    int xval=70,yval=70,valid_px=0;
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");

        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            red[i][j]=r;
            green[i][j]=g;
            blue[i][j]=b;
        }
    }
    if(direction==STANGA){
    reverse_rows(red,xval,yval);
    transpose(red,xval,yval);
    reverse_rows(green,xval,yval);
    transpose(green,xval,yval);
    reverse_rows(blue,xval,yval);
    transpose(blue,xval,yval);
    }
    if(direction==DREAPTA)
    {
    reverse_columns(red,xval,yval);
    transpose(red,xval,yval);
    reverse_columns(green,xval,yval);
    transpose(green,xval,yval);
    reverse_columns(blue,xval,yval);
    transpose(blue,xval,yval);
    }
    swap_number(&xval,&yval);
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            r=red[i][j];
            g=green[i][j];
            b=blue[i][j];
            fprintf(img_new,"%d %d %d\n",bounded(0,255,r),bounded(0,255,g),bounded(0,255,b));
        }
    }
    save_img_flag++;
    fclose(temp_img);
    fclose(img_new);
}
int luminance_mean(char *file_name){
    char type_ppm[20];
    int i=0,j=0,r,g,b,k=0;
    float mean=0.0,sum=0.0;
       if((img=fopen(file_name,"r"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fgets(type_ppm,20,img);
    fscanf(img,"%d %d\n",&xval,&yval);
    fscanf(img,"%d\n",&rgbval);
        for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(img,"%d %d %d",&r,&g,&b);
            sum+=0.30*r+0.59*g+0.11*b;
            k++;
        }
    }
    mean=sum/k;
    fclose(img);
    return (int)mean;
}
void contrast_adjust(char *file_name)
{
    char type_ppm[20];
    int i,j,L=luminance_mean(file_name);
    int r,g,b;
    float a;
    printf("    1.Introduceti intensitatea contrastului [1.00,10.00]: ");
    scanf(" %f",&a);
    if(a>=1&&a<=10){
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
  for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            r=bounded(0,255,r+(int)(1.0*(r-L)/(10-a+1)));
            g=bounded(0,255,g+(int)(1.0*(g-L)/(10-a+1)));
            b=bounded(0,255,b+(int)(1.0*(b-L)/(10-a+1)));
            fprintf(img_new,"%d %d %d\n",r,g,b);
        }
    }
    save_img_flag++;
    fclose(img);
    fclose(img_new);
    }
    else{
        printf("    Trebuie sa introduceti o valoare intre 1.0 si 10.0\n");
    }
}
void invert(char *file_name)
{
    char type_ppm[20];
    int i,j;
    int r,g,b;
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
  for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            r=bounded(0,255,255-r);
            g=bounded(0,255,255-g);
            b=bounded(0,255,255-b);
            fprintf(img_new,"%d %d %d\n",r,g,b);
        }
    }
    save_img_flag++;
    fclose(img);
    fclose(img_new);
}
void show_exposure(char *file_name)
{
    int i,j,r=0,g=0,b=0,imean=0;
    float calc=0,aux=0,mean=0;
    char type_ppm[20];
    int valid_px=0;
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    int L=luminance_mean(file_name);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            mean=(r+g+b)/3.0;
            imean=(int)mean;
            if(2*L>imean){
            r=bounded(0,255,0);
            g=bounded(0,255,0);
            b=bounded(0,255,0);
            }else{
            r=bounded(0,255,255);
            g=bounded(0,255,255);
            b=bounded(0,255,255);
            }

            fprintf(img_new,"%d %d %d\n",r,g,b);
        }
    }
    fclose(img);
    fclose(img_new);
}
void s_black_white(char *file_name)
{
    int i,j,r=0,g=0,b=0,imean=0;
    float calc=0,aux=0,mean=0;
    char type_ppm[20];
    int valid_px=0;
    copy_file_to_tmp(temp_img_name,file_name);
    if(strlen(temp_img_name)>0)
    {
        if((temp_img=fopen(temp_img_name,"r"))==NULL)
        {
            printf("eroare la deschidere a fisierului introdus\n");
        }
    }
    fgets(type_ppm,20,temp_img);
    fscanf(temp_img,"%d %d\n",&xval,&yval);
    fscanf(temp_img,"%d\n",&rgbval);
    if((img_new=fopen(new_file_name,"w"))==NULL)
    {
        printf("eroare la deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(img_new,"P3\n");
    fprintf(img_new,"%d %d\n",xval,yval);
    fprintf(img_new,"%d\n",rgbval);
    int L=luminance_mean(file_name);
    for(i=1; i<=yval; i++)
    {
        for(j=1; j<=xval; j++)
        {
            fscanf(temp_img,"%d %d %d",&r,&g,&b);
            mean=(r+g+b)/3.0;
            imean=(int)mean;
            if(imean>(int)(2.00*L)&&r>(int)(1.042*L))
                {
            r=bounded(0,255,r);
            g=bounded(0,255,(int)g/1.2);
            b=bounded(0,255,(int)b/1.2);

            }
            else{
            r=bounded(0,255,imean);
            g=bounded(0,255,imean);
            b=bounded(0,255,imean);
            }
       fprintf(img_new,"%d %d %d\n",r,g,b);
        }
    }
    fclose(img);
    fclose(img_new);
}

